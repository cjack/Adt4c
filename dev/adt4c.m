
% prototype ADT for C support

:- module adt4c.
:- interface.

:- import_module io.

:- pred main(io::di, io::uo) is det.

:- implementation.

:- import_module list.
:- import_module int.
:- import_module map.
:- import_module string.
:- import_module require.

% (definitions of) monomorphic types
:- type mono_type == string.
:- type strings == list(string).
:- type mono_types == list(mono_type).
:- type mono_type_def --->
	type_def(mono_type, cons).
:- type mono_type_defs == list(mono_type_def).
:- type cons == list(con).
:- type con ---> constructor(string, mono_types).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Top level
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

main(!IO) :-
	% XXX should look at cmd line arg to get filename etc
%  	Basename = "cordlist",
% 	Basename = "cord_adt",
% 	Basename = "bst_adt",
% 	Basename = "eval_adt",
  	Basename = "wam_adt",
	% XXX should read type defs etc in from file
	% (in some ywt to be determined format...)
	eg_mono_type_defs(Ds),
	append(Basename, ".h", HFileName),
	io.open_output(HFileName, OutputResult, !IO),
	(
		OutputResult = ok(OutputStream),
		write_h_file(Ds, OutputStream, !IO),
		io.close_output(OutputStream, !IO)
	;
		OutputResult = error(Err),
		io.error_message(Err, Msg),
		io.stderr_stream(StdErr, !IO),
		io.format(StdErr, "error: %s\n", [s(Msg)], !IO)
	),
	append(Basename, ".c", CFileName),
	io.open_output(CFileName, OutputResult1, !IO),
	(
		OutputResult1 = ok(OutputStream1),
		write_c_file(Basename, Ds, OutputStream1, !IO),
		io.close_output(OutputStream1, !IO)
	;
		OutputResult1 = error(Err1),
		io.error_message(Err1, Msg1),
		io.stderr_stream(StdErr1, !IO),
		io.format(StdErr1, "error: %s\n", [s(Msg1)], !IO)
	).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Stuff for .h file:
% intptr_t defn
% end_switch(), default(), else(), end_if()
% plus for each type T we need
%	FREE_t() PROTOTYPE
%	C type
%	switch_T (should we have separate switch_T_ptr?)
%	plus for each constructor CON
%		CON() prototype
%		C type
%		if_CON, else_if_CON, if_CON_ptr, else_if_CON_ptr
%		case_CON
%		case_CON_ptr (TODO)
%		etc (TODO)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% More TODO:
% Avoid () in cases (and perhaps other places) for nullary constructors??
% Maybe not such a good idea - () make syntax compatible with function calls
% so its better for IDEs etc which know C syntax (we can also optional ';').
% Allow names fields + use for var names instead of params in
% if/case/...

:- pred write_h_file(mono_type_defs::in, io.output_stream::in, io::di, io::uo) is det.
write_h_file(Ds, OutputStream, !IO) :-
	% intptr_t is an int type the same size as void* etc
	% we need to #include <stdint.h> so its defined
	io.format(OutputStream,
"#include <stdint.h>\n\
#define end_switch() }}}}\n\
#define default() break;}} default: {{\n\
#define else() } else {\n\
#define end_if() }}\n",
		[], !IO),
	% XXX need to output type defns before all constructors etc,
	% otherwise when types are mutually recursive the types are used
	% before they are defined and things break
	map(mono_type_def_h_file, Ds, Stringss),
	% whats the lib name???
	% string.concat(Strings, String),
	Strings = foldr((++), Stringss, []),
	print_strings(OutputStream, Strings, !IO).
	% io.format(OutputStream, "%s\n", [s(String)], !IO).

% use map_acc/lib pred
:- pred print_strings(io.output_stream::in, list(string)::in, io::di, io::uo) is det.
print_strings(_, [], !IO).
print_strings(OutputStream, [As|Ass], !IO) :-
	io.format(OutputStream, "%s\n", [s(As)], !IO),
	print_strings(OutputStream, Ass, !IO).

:- pred mono_type_def_h_file(mono_type_def::in, strings::out) is det.
mono_type_def_h_file(type_def(Type, Cons), [STD|Ss]) :-
	STD = "/***************************/\ntypedef struct _ADT_" ++
	Type  ++ "{} *" ++ Type ++ ";\n" ++
	free_prototype(Type) ++
	";\n#define switch_" ++ Type ++ "(v) \\\n{" ++ Type ++ " _" ++ Type ++
	"_tchk, _ADT_v=(v); \\\nswitch(((intptr_t)(_ADT_v)&7)) {{{\n",
	% "#define end_switch_" ++ Type ++ "};{" ++ Type ++ " _SW_tchk=" ++
	% Type ++ "_tchk;}}}}\n" ++
	% Tags = cons_to_tags(Cons,0),
	% Ss = map(cons_string(Type, 0), Cons).
	Ss = mymap2(cons_hfile_string(Type), cons_to_tags(Cons,0), Cons).

% :-( map2 is not defined with the modes we want, or as a function
% inferred type not general enough!
% :- func mymap2((func(T, T) = T), list.list(T), list.list(T)) = list.list(T).
:- func mymap2((func(R, S) = T), list.list(R), list.list(S)) = list.list(T).
mymap2(_F, [], []) = [].
mymap2(_F, [_|_], []) = [].
mymap2(_F, [], [_|_]) = [].
mymap2(F, [H | T], [A|As]) = [F(H,A) | mymap2(F, T, As)].

% from list of constructors, define tags for each one
% XXX STUB - just use successive ints
% Need to process in much more detail and determine representation
% properly (eg, separate all zero-arity constructors) and have more
% expressive type for tags (call it something else also) - need ways
% to build representation and extract stuff from it
:- func cons_to_tags(list(T), int) = list(int).
cons_to_tags([], _) = [].
cons_to_tags([_C|Cs], N) = [N | cons_to_tags(Cs, N+1)].

:- func cons_hfile_string(string, int, con) = string.
cons_hfile_string(Type, Tag, constructor(Con, FieldTypes)) =
	malloc_prototype(Type, Con, CFieldTypes) ++
	";\nstruct _ADT_" ++ Type ++ "_" ++ Con ++ " {" ++
	field_defs(CFieldTypes, 0) ++ "};\n" ++
	"#define if_" ++ Con ++ "(v" ++
	field_if_args(CFieldTypes, 0) ++ ") \\\n" ++
	"{" ++ Type ++ " _ADT_v=(v);" ++
	"if (((intptr_t)(_ADT_v)&7)==" ++ string.format("%d",[i(Tag)]) ++ ") {" ++
	field_if_rhs(CFieldTypes, 0, Tag, Type, Con)
	++
	% XXX refactor all this - add Bool arg for ptr case and for
	% else etc
	"\n#define else_if_" ++ Con ++ "(" ++
	field_case_args(CFieldTypes, 0) ++ ") \\\n" ++
	"} else " ++
	"if (((intptr_t)(_ADT_v)&7)==" ++ string.format("%d",[i(Tag)]) ++ ") {" ++
	field_if_rhs(CFieldTypes, 0, Tag, Type, Con)
	++
	"\n#define if_" ++ Con ++ "_ptr(v" ++
	field_if_args(CFieldTypes, 0) ++ ") \\\n" ++
	"{" ++ Type ++ " _ADT_v=(v);" ++
	"if (((intptr_t)(_ADT_v)&7)==" ++ string.format("%d",[i(Tag)]) ++ ") {" ++
	field_if_ptr_rhs(CFieldTypes, 0, Tag, Type, Con) ++
	%
	"\n#define case_" ++ Con ++ "(" ++ field_case_args(CFieldTypes, 0) ++
	") \\\nbreak;}} case " ++ string.format("%d",[i(Tag)]) ++
	": {{" ++ Type ++ " _SW_tchk=_" ++ Type ++ "_tchk;}{char _" ++
	Type ++ "_tchk; " ++
	field_if_rhs(CFieldTypes, 0, Tag, Type, Con)
	++
	"\n#define case_" ++ Con ++ "_ptr(" ++ field_case_args(CFieldTypes, 0) ++
	") \\\nbreak;}} case " ++ string.format("%d",[i(Tag)]) ++
	": {{" ++ Type ++ " _SW_tchk=_" ++ Type ++ "_tchk;}{char _" ++
	Type ++ "_tchk; " ++
	field_if_ptr_rhs(CFieldTypes, 0, Tag, Type, Con) ++ "\n"
	:-
	CFieldTypes = map(c_field_type, FieldTypes).

% want non-defaulty representation for types, eg adt(ADTtype) and
% c(Ctype) - currently just list a few special C types
:- pred prim_type(string::in) is semidet.
prim_type("int").
prim_type("char").
prim_type("long").
prim_type("float").
prim_type("double").

% would be nice to return (eg) "list_int" rather than
% "struct _ADT_list_int*" for top level types we define
% (we could also spit out other typedefs)
:- func c_field_type(string) = string.
c_field_type(FT) =
	(prim_type(FT) -> FT
	; "struct _ADT_" ++ FT ++ "*").

:- func field_defs(strings, int) = string.
field_defs([], _) = "".
field_defs([F|Fs], FNum) =
	string.format("\n    %s f%d;", [s(F),i(FNum)]) ++
	field_defs(Fs, FNum+1).

:- func field_if_args(strings, int) = string.
field_if_args([], _) = "".
field_if_args([_F|Fs], FNum) =
	% string.format("v%d_%s, ", [i(FNum),s(F)]) ++
	string.format(", v%d", [i(FNum)]) ++
	field_if_args(Fs, FNum+1).

:- func field_case_args(strings, int) = string.
field_case_args([], _) = "".
field_case_args([_F], FNum) =
	string.format("v%d", [i(FNum)]).
field_case_args([_F,F1|Fs], FNum) =
	% string.format("v%d_%s, ", [i(FNum),s(F)]) ++
	string.format("v%d, ", [i(FNum)]) ++
	field_case_args([F1|Fs], FNum+1).

:- func field_if_rhs(strings, int, int, string, string) = string.
field_if_rhs([], _, _, _, _) = "".
field_if_rhs([F|Fs], FNum, Tag, Type, Con) =
	string.format(
 "\\\n%s v%d=((struct _ADT_%s_%s*)((intptr_t)_ADT_v-%d))->f%d; ",
		[s(F),i(FNum),s(Type),s(Con),i(Tag),i(FNum)]) ++
	field_if_rhs(Fs, FNum+1, Tag, Type, Con).

:- func field_if_ptr_rhs(strings, int, int, string, string) = string.
field_if_ptr_rhs([], _, _, _, _) = "".
field_if_ptr_rhs([F|Fs], FNum, Tag, Type, Con) =
	string.format(
 "\\\n%s *v%d=&((struct _ADT_%s_%s*)((intptr_t)_ADT_v-%d))->f%d; ",
		[s(F),i(FNum),s(Type),s(Con),i(Tag),i(FNum)]) ++
	field_if_ptr_rhs(Fs, FNum+1, Tag, Type, Con).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Stuff for .c file
% We need some standard header stuff
% plus for each type T we need
%	free_T()
%	plus for each constructor CON
%		CON()
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Need to include Basename.h for type defns, stdlib.h for malloc
:- pred write_c_file(string::in, mono_type_defs::in,
		io.output_stream::in, io::di, io::uo) is det.
write_c_file(Basename, Ds, OutputStream, !IO) :-
	io.format(OutputStream, "#include \"%s.h\"\n", [s(Basename)], !IO),
	io.format(OutputStream, "#include <stdlib.h>\n", [], !IO),
	map(mono_type_def_c_file, Ds, Stringss),
	% whats the lib name???
	% string.concat(Strings, String),
	Strings = foldr((++), Stringss, []),
	print_strings(OutputStream, Strings, !IO).
	% io.format(OutputStream, "%s\n", [s(String)], !IO).

% XXX free_ADT defn should be changed depending on representation
% (look at tag/val, if its a pointer remove tag and call free...)
:- pred mono_type_def_c_file(mono_type_def::in, strings::out) is det.
mono_type_def_c_file(type_def(Type, Cons), [STD|Ss]) :-
	STD = "/***************************/\n" ++
	free_prototype(Type) ++ "{free((void*)((intptr_t)v&~7));};\n",
	Ss = mymap2(cons_cfile_string(Type), Cons, cons_to_tags(Cons, 0)).

:- func free_prototype(string) = string.
free_prototype(Type) =
	"void free_" ++ Type ++ "(" ++ Type ++ " v)".

% XXX needs to depend on representation
% this may not be most efficient as tag is a added at end
% (a bit simpler that way)
:- func cons_cfile_string(string, con, int) = string.
cons_cfile_string(Type, constructor(Con, FieldTypes), Tag) =
	malloc_prototype(Type, Con, CFieldTypes) ++ "{\n" ++ STC ++
	" *v=(" ++ STC ++ "*)malloc(sizeof(" ++
	STC ++ "));\n" ++
	field_malloc_eqs(CFieldTypes, 0) ++
	"return (" ++ Type ++
	string.format(")(%d+(intptr_t)v);\n}\n", [i(Tag)])
	:-
	STC = "struct _ADT_" ++ Type ++"_" ++ Con,
	CFieldTypes = mymap(c_field_type, FieldTypes).

% avoids overloaded type in cons_cfile_string
% mmc didn't know if map was a func or pred - seems like a bug
:- func mymap(((func X) = Y), list(X)) = list(Y).
mymap(_, []) = [].
mymap(F, [A|As]) = [F(A) | mymap(F, As)].

:- func malloc_prototype(string, string, strings) = string.
malloc_prototype(Type, Con, CFieldTypes) =
	Type ++
	% " malloc_" % if we want malloc_ prefix
	" "
	++ Con ++ "(" ++

	% from string library in recent versions
	adt4c.remove_prefix_if_present(", ", arg_defs(CFieldTypes, 0)) ++ ")".

% should abstract this pattern
:- func arg_defs(strings, int) = string.
arg_defs([], _) = "".
arg_defs([F|Fs], FNum) =
	string.format(", %s v%d", [s(F),i(FNum)]) ++
	arg_defs(Fs, FNum+1).

:- func field_malloc_eqs(strings, int) = string.
field_malloc_eqs([], _) = "".
field_malloc_eqs([_F|Fs], FNum) =
	string.format( "v->f%d=v%d; ",
		[i(FNum),i(FNum)]) ++
	field_malloc_eqs(Fs, FNum+1).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Stubs, testing, etc
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- pred eg_mono_type_defs(mono_type_defs::out) is det.
eg_mono_type_defs([
	% Long has single data constructor -> should optimise away
	% entirely assuming it fits in a void*
	% XXX here we avoid overloading the symbol because in the
	% C code we can't overload the type and function; we could
	% use a malloc_/new_ prefix for the function but currently
	% don't.  Or we could use Upper case for just data constructors
	% by convention (might be good for Types also, so we could
	% use Long rather than eg, adt_long).
	% Maybe use Upper case for both and add _ to constructor name.
	% - Go with this for now...
	type_def("Long", [
		constructor("Long_", ["long"])]),
	% polymorphic List (kind of) - V1 acts as a skolemized variable
	type_def("V1", []),
	type_def("List", [
		constructor("Nil", []),
		constructor("Cons", ["V1", "List"])]),
	% List of Long - should generate this from polymorphic defn.
	% This could be the default name but we should be able to rename
	% it as type Longs, for example.
	type_def("List_Long", [
		constructor("Nil_Long", []),
		constructor("Cons_Long", ["Long", "List_Long"])]),
	% another instance
	type_def("ListList", [
		constructor("Nil_ListList", []),
		constructor("Cons_ListList", ["List_Long", "ListList"])]),
	% lower level version of [(char,char,char,char)] - can't use
	% polymorphism but more efficient (saves space, indirection)
	type_def("List_4char", [
		constructor("Nil_4char", []),
		constructor("Cons_4char", ["char", "char",
			"char", "char", "List_4char"])]),
	type_def("Cord_int", [
		constructor("Empty", []),
		constructor("Leaf", ["int"]),
		constructor("Branch", ["Cord_int", "Cord_int"])])

% 	% stuff for dufl/bst.pns
% 	type_def("ints", [
% 		constructor("nil", []),
% 		constructor("cons", ["int", "ints"])]),
% 	type_def("bst", [
% 		constructor("mt", []),
% 		constructor("node", ["bst", "int", "bst"])]),
% 	type_def("bool", [
% 		constructor("true", []),
% 		constructor("false", [])])
% 	% stuff for dufl/cord.pns
% 	type_def("list", [
% 		constructor("nil", []),
% 		constructor("cons", ["int", "list"])]),
% 	type_def("cordlist", [
% 		constructor("Empty", []),
% 		constructor("Leaf", ["list"]),
% 		constructor("Branch", ["cordlist", "cordlist"])])
% 	% stuff for dufl/eval*.pns
% 	type_def("expr", [
% 		constructor("zero", []),
% 		constructor("shared", ["expr"]),
% 		constructor("s", ["expr"]),
% 		constructor("plus", ["expr", "expr"]),
% 		constructor("times", ["expr", "expr"])])
% 	% stuff for dufl/wam.pns
% 	type_def("bool", [
% 		constructor("true", []),
% 		constructor("false", [])]),
% 	type_def("fs", [
% 		constructor("f0", []),
% 		constructor("f1", []),
% 		constructor("f2", [])]),
% 	type_def("terms", [
% 		constructor("nil", []),
% 		constructor("cons", ["term", "terms"])]),
% 	type_def("term", [
% 		constructor("var", ["term"]),
% 		constructor("nv", ["fs", "terms"])])
	]).
% eg_mono_type_defs([
% 	type_def("t234_int", [
% 		% optional optimised cases (see Haskell code)
% 		constructor("two_leaf", ["int"]),
% 		constructor("three_leaf", ["int","int"]),
% 		constructor("four_leaf", ["int","int","int"])])
% 		% general cases
% 		constructor("two", ["t234_int","int","t234_int"]),
% 		constructor("three", ["t234_int","int","t234_int",
% 			"int","t234_int"]),
% 		constructor("four", ["t234_int","int","t234_int",
% 			"int","t234_int","int","t234_int"])]),
% 		constructor("empty", [])
% 	]).


% from string library in recent versions
:- func remove_prefix_if_present(string, string) = string. 

remove_prefix_if_present(Prefix, String) = Out :- 
    ( adt4c.remove_prefix(Prefix, String, Suffix) -> 
        Out = Suffix 
    ; 
        Out = String 
    ). 
    
:- pred remove_prefix(string::in, string::in, string::out) is semidet. 
 remove_prefix(Prefix, String, Suffix) :- 
     string.append(Prefix, Suffix, String).


