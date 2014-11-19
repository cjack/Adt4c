% 234tree implementation bits based on two34.hs
%	
% Doesn't (yet) provide all functionality wanted but does
% specialise leaves
% Allows duplicate keys

:- module t234_dup.
:- interface.

:- import_module io.
:- pred main(io::di, io::uo) is det.

% so code is generated and we can look at it
:-pred test(t234(KV)::in, int::out) is det.

% We just use a single parameter KV for now - in general
% we may want separate Key and Value params (or we could
% use a typeclass constraint so we can extract key and value
% from the parameter - this reduces the overhead if we just
% want to represent a set of ints as a 234tree, for example).
:- type t234(KV)
	% specialised cases for leaves
	--->	n2l(KV)
	;	n3l(KV, KV)
	;	n4l(KV, KV, KV)
	% general cases
	;	n2(t234(KV), KV, t234(KV))
	;	n3(t234(KV), KV, t234(KV), KV, t234(KV))
	;	n4(t234(KV), KV, t234(KV), KV, t234(KV), KV, t234(KV))
	% ; e1 ; e2 ; e3; e4 ; e5 % test nullary constructor representation
	% empty tree special case
	;	empty.

:- implementation.
:- import_module int.
:- import_module require.

% for insertion we return a single tree or two trees plus
% an extra key/value which are promoted higher in tree
:- type ins_res(KV) --->
	same(t234(KV)) ; promote(t234(KV), KV, t234(KV)).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Top level for testing
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

main(!IO) :-
	big2(T0),
	insert(T0, 42, T),
	( search(T, 1) ->
		print(T, !IO),
		print("\nfound\n", !IO)
	;
		test(n2l(123), N),
		print(N, !IO)
	).

:-pred search(t234(KV)::in, KV::in) is semidet.
% search(empty, _) :- fail.
search(n2l(KV), KV).
search(n3l(KV, _), KV).
search(n3l(_, KV), KV).
search(n4l(_, KV, _), KV).
search(n4l(KV, _, _), KV).
search(n4l(_, _, KV), KV).
search(n2(L, KVm, R), KV) :-
	compare(Cmp, KV, KVm),
	(	Cmp = (=)
	; 	Cmp = (<),
		search(L, KV)
	;	Cmp = (>),
		search(R, KV)
	).
search(n3(L, KVl, M, KVr, R), KV) :-
	compare(Cmp, KV, KVl),
	(	Cmp = (=)
	; 	Cmp = (<),
		search(L, KV)
	;	Cmp = (>),
		compare(Cmp1, KV, KVr),
		(	Cmp1 = (=)
		; 	Cmp1 = (<),
			search(M, KV)
		;	Cmp1 = (>),
			search(R, KV)
		)
	).
search(n4(LL, KVl, LR, KVm, RL, KVr, RR), KV) :-
	compare(Cmp, KV, KVm),
	(	Cmp = (=)
	; 	Cmp = (<),
		compare(Cmp1, KV, KVl),
		(	Cmp1 = (=)
		; 	Cmp1 = (<),
			search(LL, KV)
		;	Cmp1 = (>),
			search(LR, KV)
		)
	;	Cmp = (>),
		compare(Cmp1, KV, KVr),
		(	Cmp1 = (=)
		; 	Cmp1 = (<),
			search(RL, KV)
		;	Cmp1 = (>),
			search(RR, KV)
		)
	).

:- pred insert(t234(KV)::in, KV::in, t234(KV)::out) is det.
insert(T0, KV, T) :-
	(T0 = empty ->
		T = n2l(KV)
	;
		insert1(T0, KV, IR),
		(	IR = same(T1),
			T = T1
		;
			IR = promote(LX, KVX, RX),
			T = n2(LX, KVX, RX)
		)
	).

:- pred insert1(t234(KV)::in, KV::in, ins_res(KV)::out) is det.
insert1(empty, KV, same(n2l(KV))). % never used
insert1(n2l(KVm), KV, T) :-
	compare(Cmp, KVm, KV),
	((      Cmp = (=) ; Cmp = (<)),
		T = same(n3l(KVm, KV))
	; 	Cmp = (>),
		T = same(n3l(KV, KVm))
	).
insert1(n3l(KVl, KVr), KV, T) :-
	compare(Cmp, KV, KVl),
	((      Cmp = (=) ; Cmp = (<)),
		T = same(n4l(KV, KVl, KVr))
	; 	Cmp = (>),
		compare(Cmp1, KV, KVr),
		((      Cmp1 = (=) ; Cmp1 = (<)),
			T = same(n4l(KVl, KV, KVr))
		; 	Cmp1 = (>),
			T = same(n4l(KVl, KVr, KV))
		)
	).
insert1(n4l(KVl, KVm, KVr), KV, T) :-
	compare(Cmp, KV, KVm),
	((	Cmp = (=) ; Cmp = (<)),
		compare(Cmp1, KV, KVl),
		((      Cmp1 = (=) ; Cmp1 = (<)),
			T = promote(n3l(KV, KVl), KVm, n2l(KVr))
		;
			Cmp1 = (>),
			T = promote(n3l(KVl, KV), KVm, n2l(KVr))
		)
	;	Cmp = (>),
		compare(Cmp1, KV, KVr),
		((      Cmp1 = (=) ; Cmp1 = (<)),
			T = promote(n2l(KVl), KVm, n3l(KV, KVr))
		;
			Cmp1 = (>),
			T = promote(n2l(KVl), KVm, n3l(KVr, KV))
		)
	).
insert1(n2(L, KVm, R), KV, T) :-
	compare(Cmp, KV, KVm),
	((      Cmp = (=) ; Cmp = (<)),
		insert1(L, KV, IR),
		(	IR = same(T1),
			T = same(n2(T1, KVm, R))
		;
			IR = promote(LX, KVX, RX),
			T = same(n3(LX, KVX, RX, KVm, R))
		)
	; 	Cmp = (>),
		insert1(R, KV, IR),
		(	IR = same(T1),
			T = same(n2(L, KVm, T1))
		;
			IR = promote(LX, KVX, RX),
			T = same(n3(L, KVm, LX, KVX, RX))
		)
	).
insert1(n3(L, KVl, M, KVr, R), KV, T) :-
	compare(Cmp, KV, KVl),
	((      Cmp = (=) ; Cmp = (<)),
		insert1(L, KV, IR),
		(	IR = same(T1),
			T = same(n3(T1, KVl, M, KVr, R))
		;
			IR = promote(LX, KVX, RX),
			T = same(n4(LX, KVX, RX, KVl, M, KVr, R))
		)
	; 	Cmp = (>),
		compare(Cmp1, KV, KVr),
		((      Cmp1 = (=) ; Cmp1 = (<)),
			insert1(M, KV, IR),
			(	IR = same(T1),
				T = same(n3(L, KVl, T1, KVr, R))
			;
				IR = promote(LX, KVX, RX),
				T = same(n4(L, KVl, LX, KVX, RX, KVr, R))
			)
		
		; 	Cmp1 = (>),
			insert1(R, KV, IR),
			(	IR = same(T1),
				T = same(n3(L, KVl, M, KVr, T1))
			;
				IR = promote(LX, KVX, RX),
				T = same(n4(L, KVl, M, KVr, LX, KVX, RX))
			)
		)
	).
insert1(n4(LL, KVl, LR, KVm, RL, KVr, RR), KV, T) :-
	compare(Cmp, KV, KVm),
	TwoL = n2(LL, KVl, LR),
	TwoR = n2(RL, KVr, RR),
	((	Cmp = (=) ; Cmp = (<)),
		insert1(TwoL, KV, IR),
		(	IR = same(T1),
			T = promote(T1, KVm, TwoR)
		;
			IR = promote(_, _, _),
			error("promotion from 2node\n")
		)
	;	Cmp = (>),
		insert1(TwoR, KV, IR),
		(	IR = same(T1),
			T = promote(TwoL, KVm, T1)
		;
			IR = promote(_, _, _),
			error("promotion from 2node\n")
		)
	).

:- pred big1(t234(int)::out) is det.
big1(T) :-
	big1a(150000, 650000, empty, T).

:- pred big2(t234(int)::out) is det.
big2(T) :-
	big1a(1, 10, empty, T).

:- pred big1a(int::in, int::in, t234(int)::in, t234(int)::out) is det.
big1a(N0, N, T0, T) :-
	(N0 = N ->
		T = T0
	;
		I is (N0*N0) mod 9999997,
		insert(T0, I, T1),
		big1a(N0+1, N, T1, T)
	).


% test C code produced
test(empty, 0).
test(n2l(_), 1).
test(n3l(_, _), 2).
test(n4l(_, _, _), 3).
test(n2(_, _, _), 4).
test(n3(_, _, _, _, _), 5).
test(n4(_, _, _, _, _, _, _), 6).
% test(e1, 10).
% test(e2, 20).
% test(e3, 30).
% test(e4, 40).
% test(e5, 50).



