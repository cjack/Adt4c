#include<stdio.h>
#include<string.h>
#include "adt_t_master.h"

#define TYPE_LENGTH 500

#define LOW_BIT_USED 7


//----------------------   Definition for functions  ---------------------------
//Type definition for .h file
//If users want to use their typedefs, should add the primitive type here.


/*
basic logic about this function, assume the low 3 bits are used

    ( T_NUM_NONCONST>0 && v > T_NUM_CONST-1 ?     // 1.
        ( T_NUM_NONCONST==1 ?                     // 2.
            T_NUM_CONST
        :
            // tag = v&7,                         // 3.
            ( T_NUM_NONCONST>8 && (v&7) == 7 ?    // 4.
                *(Tstruct*)(v-(v&7))->ftag + T_NUM_CONST
            :
                (v&7) + T_NUM_CONST
            )
        )
    :
        v
    )

 */
int constructor_number(uintptr_t v, int T_NUM_CONST, int T_NUM_NONCONST, int tag){
	return  ( T_NUM_NONCONST>0 && v > T_NUM_CONST-1 ?     // 1.
        ( T_NUM_NONCONST==1 ?                     // 2.
            T_NUM_CONST
        :
            // tag = v&(LOW_BIT_USED),                         // 3.
            (  ( T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?    // 4.
                tag + T_NUM_CONST
            :
                (v&(LOW_BIT_USED)) + T_NUM_CONST

        )
    :
        v
    );
}


void field_if_rhs(stringlist_t arg_list, c_string Type, c_string Con, FILE* fp, int Tag, int num, int is_const){
	int i = num;
	if_nextlist(arg_list, a_val, a_next)
		if_string(a_val, a_str)
			//if is a const constructor
			if(is_const == 1){
				fprintf(fp, "\\\n%s v%d=((struct _ADT_%s_%s*)((uintptr_t)_ADT_v))->f%d; ", a_str, i, Type, Con, i);
			}
			//check if the tag is larger than or equals to 7
			else if(Tag >= LOW_BIT_USED){
				fprintf(fp, "\\\n%s v%d=((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f%d; ", a_str, i, Type, Con, i);
			}else{
				fprintf(fp, "\\\n%s v%d=((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-%d))->f%d; ", a_str, i, Type, Con, Tag, i);
			}
			i++;
			field_if_rhs(a_next, Type, Con, fp, Tag, i, is_const);
		end_if()
	end_if()

	if_nil(arg_list)
		return;
	end_if()
}


void field_if_args(stringlist_t arg_list, FILE* fp, int num){
	int i = num;
	if_nextlist(arg_list, a_val, a_next)
		fprintf(fp, ", v%d", i++);
		field_if_args(a_next, fp, i);
	end_if()

	if_nil(arg_list)
		return;
	end_if()
}


void field_defs(stringlist_t arg_list, FILE* fp, int num){
	int i = num;
	if_nextlist(arg_list, a_val, a_next)
		if_string(a_val, a_str)
			fprintf(fp, "\n    %s f%d;", a_str, i++);
			field_defs(a_next, fp, i);
		end_if()
	end_if()

	if_nil(arg_list)
		return;
	end_if()
}


void field_case_args(stringlist_t arg_list, FILE* fp, int num){
	int i = num;

	if_nextlist(arg_list, a_val, a_next)
		if_string(a_val, a_str)
			if(i == 0){
				fprintf(fp, "v%d", i++);
			}
			else{
				fprintf(fp, ", v%d", i++);
			}
			field_case_args(a_next, fp, i);
		end_if()
	end_if()

	if_nil(arg_list)
		return;
	end_if()

}


void field_if_ptr_rhs(stringlist_t arg_list, c_string Type, c_string Con, FILE* fp, int Tag, int num, int is_const){
	int i = num;
	if_nextlist(arg_list, a_val, a_next)
		if_string(a_val, a_str)
			if(is_const == 1){
				fprintf(fp, "\\\n%s *v%d=&((struct _ADT_%s_%s*)((uintptr_t)_ADT_v))->f%d; ", a_str, i, Type, Con, i);
			}
			else if(Tag >= LOW_BIT_USED){
				fprintf(fp, "\\\n%s *v%d=&((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-LOW_BIT_USED))->f%d; ", a_str, i, Type, Con, i);
			}else{
				fprintf(fp, "\\\n%s *v%d=&((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-%d))->f%d; ", a_str, i, Type, Con, Tag, i);
			}
			i++;
			field_if_ptr_rhs(a_next, Type, Con, fp, Tag, i, is_const);
		end_if()
	end_if()

	if_nil(arg_list)
		return;
	end_if()
}


void arg_defs(stringlist_t arg_list, FILE* fp, int num){
	int i = num;
	if_nextlist(arg_list, a_val, a_next)

		if_string(a_val, a_str)
			if(i == 0){
				fprintf(fp, "%s v%d", a_str, i);
			}else{
				fprintf(fp, ", %s v%d", a_str, i);
			}
			i++;
		end_if()
		arg_defs(a_next, fp, i);
	end_if()

	if_nil(arg_list)

		return;
	end_if()

}

void malloc_prototype(c_string Type, c_string Con, stringlist_t arg_list, FILE *fp){
	fprintf(fp, "\nstatic __inline %s %s(", Type, Con);


	arg_defs(arg_list, fp, 0);
	fprintf(fp, ")");
}

//generate a free function for each type
//like void free_TYPE(TYPE v);
void free_prototype(c_string Type, FILE* fp){
	fprintf(fp, "static __inline void free_%s(%s v)", Type, Type);
}



//----------------------   Definition for h file   -----------------------------



//_-----------------------------------------------------------------------------


//char* Type, char* Con, char input_list[][TYPE_LENGTH], int c_num, int num, int Tag, FILE* fp, int fnum
void hfile_generation(c_string Type, c_string Con, stringlist_t arg_list, FILE* fp, int Tag, int is_const, int cp, int np){

	int i = 0;

	// This if branch only address the non-const constructor and its
	// number of args larger than 8 but not equal to 8
 	if(Tag >= LOW_BIT_USED && is_const == 0 && np > LOW_BIT_USED + 1){

		// malloc_prototype(Type, Con, arg_list, fp);
		fprintf(fp, "\nstruct _ADT_%s_%s {", Type, Con);

		fprintf(fp, "\n\tint ftag;");
		field_defs(arg_list, fp, 0);

		fprintf(fp, "};\n#define if_%s(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);", Type);

		fprintf(fp, "\\\nif ((uintptr_t)(_ADT_v) >= %d && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == %d)){", cp, Type, Con, Tag);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define else_if_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n} else if ((uintptr_t)(_ADT_v) >= %d && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == %d)) {", cp, Type, Con, Tag);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define if_%s_ptr(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);{", Type);

		fprintf(fp, "\\\nif ((uintptr_t)(_ADT_v) >= %d && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==LOW_BIT_USED && (((struct _ADT_%s_%s*)((uintptr_t)_ADT_v-LOW_BIT_USED))->ftag == %d)) {",cp, Type, Con, Tag);

		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define case_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define case_%s_ptr(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);
		fprintf(fp, "\n");


	}else if(cp == 1 && np == 0){
		// The number of constant constructor is 1 and the
		// non-constructor is 0
		fprintf(fp, "\nstruct _ADT_%s_%s {", Type, Con);

		field_defs(arg_list, fp, 0);
		fprintf(fp, "};\n#define if_%s(v", Con);

		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if (1) {", Type);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define else_if_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n} else if (1) {");
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define if_%s_ptr(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if (1) {", Type);

		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define case_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag, Type, Type, Type);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define case_%s_ptr(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag, Type, Type, Type);
		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);
		fprintf(fp, "\n");

}else if(cp == 0 && np == 1){
		// handle the very specially case.
		// when only have a non-const
		// malloc_prototype(Type, Con, arg_list, fp);
		fprintf(fp, "\nstruct _ADT_%s_%s {", Type, Con);

		field_defs(arg_list, fp, 0);
		fprintf(fp, "};\n#define if_%s(v", Con);

		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if (1) {", Type);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define else_if_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n} else if (1) {");
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define if_%s_ptr(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if (1) {", Type);

		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define case_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define case_%s_ptr(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);
		fprintf(fp, "\n");
	}else if(is_const == 0 && np == 1){
		// handle the very specially case.
		// when only have a non-const
		// malloc_prototype(Type, Con, arg_list, fp);
		fprintf(fp, "\nstruct _ADT_%s_%s {", Type, Con);

		field_defs(arg_list, fp, 0);
		fprintf(fp, "};\n#define if_%s(v", Con);

		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= %d) {", Type, cp);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define else_if_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n} else if ((uintptr_t)(_ADT_v) >= %d) {", cp);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define if_%s_ptr(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= %d) {", Type, cp);

		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define case_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define case_%s_ptr(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);
		fprintf(fp, "\n");
	// for constant constructors
	}else if(is_const == 1){
		// malloc_prototype(Type, Con, arg_list, fp);
		fprintf(fp, "\nstruct _ADT_%s_%s {", Type, Con);

		field_defs(arg_list, fp, 0);
		fprintf(fp, "};\n#define if_%s(v", Con);

		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if (((uintptr_t)(_ADT_v))==%d) {", Type, Tag);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define else_if_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n} else if (((uintptr_t)(_ADT_v))==%d) {", (Tag));
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define if_%s_ptr(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if (((uintptr_t)(_ADT_v))==%d) {", Type, (Tag));

		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define case_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag, Type, Type, Type);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define case_%s_ptr(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag, Type, Type, Type);
		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);
		fprintf(fp, "\n");

	}else {
		// malloc_prototype(Type, Con, arg_list, fp);
		fprintf(fp, "\nstruct _ADT_%s_%s {", Type, Con);

		field_defs(arg_list, fp, 0);
		fprintf(fp, "};\n#define if_%s(v", Con);

		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= %d && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==%d) {", Type, Tag, cp);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define else_if_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n} else if ((uintptr_t)(_ADT_v) >= %d && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==%d)  {", (Tag), cp);

		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define if_%s_ptr(v", Con);
		field_if_args(arg_list, fp, 0);

		fprintf(fp, ") \\\n{%s _ADT_v=(v);if ((uintptr_t)(_ADT_v) >= %d && ((uintptr_t)(_ADT_v)&LOW_BIT_USED)==%d)  {", Type, (Tag), cp);

		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);

		fprintf(fp, "\n#define case_%s(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);


		fprintf(fp, "\n#define case_%s_ptr(", Con);
		field_case_args(arg_list, fp, 0);

		fprintf(fp, ") \\\nbreak;}} case %d: {{%s _SW_tchk=_%s_tchk;}{char _%s_tchk; ", Tag + cp, Type, Type, Type);
		field_if_ptr_rhs(arg_list, Type, Con, fp, Tag, 0, is_const);
		fprintf(fp, "\n");

	}



}
/*

int _ADT_lowbit = (((uintptr_t)(_ADT_v)&LOW_BIT_USED); \
int ftag = _ADT_lowbit ==LOW_BIT_USED) ? _ADT_lowbit : 0; \

#define constructorNum(v, ftag) \\\n
{( T_NUM_NONCONST>0 && v > T_NUM_CONST-1 ?  \\\n
        ( T_NUM_NONCONST==1 ?  T_NUM_CONST   : \\\n
            (  ( T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \\\n
               				ftag + T_NUM_CONST  : \\\n
                   (v&(LOW_BIT_USED)) + T_NUM_CONST) : v ) }\\\n



 */
void def_of_constructor_num(c_string Type, c_string Con, FILE *fp, int cp, int np){
	fprintf(fp, "#define %s_T_NUM_CONST (%d) \n", Type, cp);
	fprintf(fp, "#define %s_T_NUM_NONCONST (%d) \n", Type, np);

	fprintf(fp, "#define %s_constructorNum(v) \\\n", Type);
	fprintf(fp, "(( %s_T_NUM_NONCONST>0 && v > %s_T_NUM_CONST-1 ?  \\\n", Type, Type);
	fprintf(fp, " ( %s_T_NUM_NONCONST==1 ?  %s_T_NUM_CONST   : \\\n", Type, Type);
	fprintf(fp, "(( %s_T_NUM_NONCONST > (LOW_BIT_USED + 1))  && ((v&LOW_BIT_USED) == (LOW_BIT_USED))  )  ?   \\\n", Type);
	fprintf(fp, " (*(int*)((uintptr_t)_ADT_v-LOW_BIT_USED)) + %s_T_NUM_CONST  : \\\n", Type);
	fprintf(fp, "((v&(LOW_BIT_USED)) + %s_T_NUM_CONST)) : v ) )\n\n", Type);

}
void mono_type_def_h_file(c_string Type, c_string Con, FILE *fp, int cp, int np, int is_enum){

	fprintf(fp, "\n/***************************/\ntypedef struct _ADT_%s{} *%s;\n",Type, Type);
	def_of_constructor_num(Type, Con, fp, cp, np);
	if(is_enum == 1){
		//Modi 1XXX should still have free function but do nothing
		// if the data structure is an enum, no free function should be given
		fprintf(fp, "\n#define switch_%s(v) \\\n{%s _%s_tchk, _ADT_v=(v);", Type, Type, Type);
	}else{
		// free_prototype(Type, fp);
		fprintf(fp, ";\n#define switch_%s(v) \\\n{%s _%s_tchk, _ADT_v=(v);", Type, Type, Type);
	}

	fprintf(fp, " \\\nint t = %s_constructorNum((uintptr_t)(_ADT_v));", Type);
	fprintf(fp, " \\\nswitch(t) {{{\n");


}
//------------------------------------------------------------------------------







//--------------------------  Definition of .c file    -------------------------

#define STC_LENGTH 100

void field_malloc_eqs(stringlist_t arg_list, FILE* fp, int num){
	int i = num;
	if_nextlist(arg_list, a_val, a_next)
		fprintf(fp, "\n\tv->f%d=v%d; ", i, i);
		i++;
		field_malloc_eqs(a_next, fp, i);
	end_if()

	if_nil(arg_list)
		return;
	end_if()
}

void function_generation(c_string Type, c_string Con, stringlist_t arg_list, FILE* fp, int Tag, int is_const, int np){
	char STC[STC_LENGTH] = "struct _ADT_";
	strcat(STC, Type);
	strcat(STC, "_");
	strcat(STC, Con);

	malloc_prototype(Type, Con, arg_list, fp);

	if(is_const == 1){
		//a const should read the whole word
		fprintf(fp, "{\n\t%s *v=(%s*)%d;", STC, STC, Tag);
		field_malloc_eqs(arg_list, fp, 0);    // The subscript starts from 0
		fprintf(fp, "\n\treturn (%s)((uintptr_t)v);\n}\n", Type);
	}
	else if(Tag >= LOW_BIT_USED && np > LOW_BIT_USED + 1){
		//add extra space for second-tag
		fprintf(fp, "{\n\t%s *v=(%s*)malloc(sizeof(%s));", STC, STC, STC);
		fprintf(fp, "\n\tv->ftag = %d; ", Tag);
		field_malloc_eqs(arg_list, fp, 0);    // The subscript starts from 0
		fprintf(fp, "\n\treturn (%s)(LOW_BIT_USED+(uintptr_t)v);\n}\n", Type);
	}else{
		fprintf(fp, "{\n\t%s *v=(%s*)malloc(sizeof(%s));", STC, STC, STC);
		field_malloc_eqs(arg_list, fp, 0);    // The subscript starts from 0
		fprintf(fp, "\n\treturn (%s)(%d+(uintptr_t)v);\n}\n", Type, Tag);
	}


}


void mono_type_def_function(c_string Type, FILE* fp, int is_const, int is_enum, int cp, int np){
	fprintf(fp, "\n\n/******************************************************************************/\n");
	free_prototype(Type, fp);
	if(is_enum == 0){
		// Only need to free the non-constant constructor
		if(cp != 0){
			//if there is at least 1 constant construtor
			//then need to avoid these pointers to free
			fprintf(fp, "{\n\tif ((uintptr_t)(v) >= %d){\n\t\t", cp);
		}else{
			fprintf(fp, "{\n\t");
		}
		if(np == 1){
			//if the number of non-const is exactly 1 then free the struct directly
			fprintf(fp, "free((void*)((uintptr_t)v));");
		}else{
			//if the number of non-const is larger than 1, then mask and free
			fprintf(fp, "free((void*)((uintptr_t)v&~LOW_BIT_USED));");
		}
		// align space for presentation
	if(cp != 0){
		//close bound for if statement
		fprintf(fp, "\n\t}");
	}
	}else{
	fprintf(fp, "{");
	}
	fprintf(fp, "\n}\n\n");
}
//------------------------------------------------------------------------------


//-------------------------    Main Fuction        -----------------------------


#define ARRAY_SIZE 200
#define CONTENT_SIZE 50000
#define FILENAME_SIZE 200

void adt_main(char filename[], c_string Type, c_string Con, stringlist_t arg_list, FILE* fp_h, int tag, int is_const, int cp, int np, int *is_init){


	//define the file name to be generated
	char file_name[FILENAME_SIZE];
	strcpy(file_name, filename);

	char path[] = "./";
	char suffix[] = ".h";
	char suffix_2[] = ".c";
	char h_file_name[ARRAY_SIZE];

	//definition for .h file name and path
	strcpy(h_file_name, path);
	strcat(h_file_name, file_name);
	strcat(h_file_name, suffix);

	fp_h =fopen(h_file_name, "a+");
	int is_enum = 0;
	// if the number of non-const is 0, then
	// this data structure is an enum
	if(np == 0 && cp >= 0){
		is_enum = 1;
	}

	if(*is_init == 0){
		*is_init = 1;
		mono_type_def_h_file(Type, Con, fp_h, cp, np, is_enum);
		mono_type_def_function(Type, fp_h, is_const, is_enum, cp, np);
	}

	hfile_generation(Type, Con, arg_list, fp_h, tag, is_const, cp, np);

    function_generation(Type, Con, arg_list, fp_h, tag, is_const, np);

	fclose(fp_h);
}

//------------------------------------------------------------------------------
