%{#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "adt_t_master.h"
extern int yylex();
extern int yyparse();
extern FILE *yyin;

#define CON_NUM_SIZE 5000
#define FILENAME_SIZE 200
#define ARRAY_SIZE 200
#define CONTENT_SIZE 50000
#define TYPE_LENGTH 500
#define TYPE_NUM 1000
// #define FILENAME "decllist_test"


// char prim_type[][TYPE_LENGTH] = {"int", "char", "long", "double", "long double"
// 	"float", "void", "long long", "short int", "unsigned int",
// 	"unsigned long", "unsigned long int", "signed char", "unsigned char",
// 	"short", "unsigned short", "enum","long long int", "long int", "unsigned long long"};
// const int PRIM_TYPE_LENGTH = 8;

extern void adt_main(char file_name[], c_string Type, c_string Con, stringlist_t arg_list, FILE* fp_h, int tag, int is_const, int cp, int np, int *is_init);

//---------------         Definition of global variables       -----------------

decllist_t d_list;			//global decllist

decl_t decl_temp;			//global decl

ctrlist_t c_list;			//global ctrlist

ctr_t ctr_temp;				//global ctr

arglist_t a_list;			//global arglist

arg_t arg_temp;				//global arg

FILE *fp_h;

char constructor_list[CON_NUM_SIZE][TYPE_LENGTH];
int constructor_num = 0;

char file_name[FILENAME_SIZE];		//filename without the suffix
char file[FILENAME_SIZE];			//filename includes the suffix
char type_list[TYPE_NUM][TYPE_LENGTH]; //store the total type name
int type_list_length = 0;

void print_decl(decl_t input);
void print_ctrlist(c_string d_str, stringlist_t con_list, stringlist_t arg_list, ctrlist_t input, int tag, int *cp, int *np);
void print_decllist(decllist_t input);
void print_arglist(c_string d_str, c_string c_str, stringlist_t con_list, stringlist_t arg_list, arglist_t input, int tag, int *cp, int *np);

//-----------------------     Collection of type name    -----------------------

int collect_type_name(char filename[], char type_list[][TYPE_LENGTH]){
	FILE *fp;
	if((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "Cannot open file %s\n", filename);
		exit(-1);
	}
	char indicator[TYPE_LENGTH], type_name[TYPE_LENGTH];
	int wrong_position = 0;
	char target[] = "data";

	int p = 0;
	while(fscanf(fp, "%s %s", &indicator, &type_name) != EOF){
		if(strcmp(indicator, target) == 0 && wrong_position == 0){
			//if indicater is "data", then type_name should be the type name
			int l = strlen(type_name);
			if(type_name[l - 1] == '{'){
				type_name[l - 1] = '\0';
				strcpy(type_list[p++], type_name);
			}else{
				strcpy(type_list[p++], type_name);
			}
		}else if(strcmp(type_name, target) == 0){
			//if the type_name is "data", then the type_name is in next round
			wrong_position = 1;
			continue;
		}else if(wrong_position == 1){
			//indicator should be the type name
			//clean the signal of wrong_position
			int l = strlen(indicator);
			wrong_position = 0;
			if(indicator[l - 1] == '{'){
				indicator[l - 1] = '\0';
				strcpy(type_list[p++], indicator);
			}else{
				strcpy(type_list[p++], indicator);
			}
		}
	}
	fclose(fp);
	return p;
}

int check_in_array(char type_list[][TYPE_LENGTH], int size, char input[]){
	int i;
	for(i = 0; i < size; i++){
		if(strcmp(type_list[i], input) == 0){
			return 1;
		}
	}
	return 0;
}


//------------------------------------------------------------------------------

char *remove_file_suffix(char* mystr) {
    char *retstr;
    if (mystr == NULL)
         return NULL;
    if ((retstr = (char *)malloc(strlen(mystr) + 1)) == NULL)
        return NULL;
    strcpy (retstr, mystr);
    char *lastdot = strrchr (retstr, '.');
    if (lastdot != NULL)
        *lastdot = '\0';
    return retstr;
}

void initializaion_files(FILE* fp_h){
	char content[CONTENT_SIZE];
	char type_content[CONTENT_SIZE];
	char h_file_include_content[] =
	"#include <stdint.h>\n\
#include <stdlib.h>\n\
typedef char *c_string;\n\
#define end_switch() }}}}\n\
#define default() break;}} default: {{\n\
#define else() } else {\n\
#define end_if() }}\n\
#define LOW_BIT_USED 7";

//define the file name to be generated

	char path[] = "./";
	char suffix_1[] = ".h";
	char h_file_name[ARRAY_SIZE];


//definition for .h file name and path
	strcpy(h_file_name, path);
	strcat(h_file_name, file_name);
	strcat(h_file_name, suffix_1);


	fp_h =fopen(h_file_name, "w+");
	strcpy(content, h_file_include_content);
	fputs(content, fp_h);

	fclose(fp_h);
	printf("Initialize.h files successfully\n");
}

//check whether the constructors have been defined before
void check_exist_con(char *s){
	int i = 0;
	for(i = 0; i < constructor_num; i++){
		if(strcmp(constructor_list[i], s) == 0){
			fprintf(stderr, "\nERROR: same constructor \"%s\" has been defined previously\n\n", s);
	      	exit(-1);
		}
	}
}

void con_list_print(stringlist_t con_list){
		if_nextlist(con_list, con_val, con_next)
			if_string(con_val, con_str)
				printf("print out the con : %s\n", con_str);
				con_list_print(con_next);
			end_if()
		end_if()

		if_nil(con_list)
			return;
		end_if()
}

// Reverse the stringlist
stringlist_t reverse_stringlist(stringlist_t input){
	stringlist_t temp_stringlist;
	temp_stringlist = nil();
	while(1){
		if_nextlist(input, head, tail){
			if_string(head, str)
				temp_stringlist = nextlist(string(str), temp_stringlist);
				input = tail;
			end_if()
		end_if()

		if_nil(input)
			return temp_stringlist;
		end_if()
		}
	}
}

//reverse the ctrlist
ctrlist_t reverse_ctrlist(ctrlist_t input){
	ctrlist_t temp_ctrlist;
	temp_ctrlist = noctr();
	while(1){
		if_nextctr(input, head, tail){
			temp_ctrlist = nextctr(head, temp_ctrlist);
			input = tail;
		end_if()

		if_noctr(input)
			return temp_ctrlist;
		end_if()
		}
	}
}



c_string type_normalization(c_string input, c_string temp){
	//Check if the type is within the prim_types.
	//normalize the type when out of range of prim types.
	int i = 0;
	int NOT_PRIM_TPYE = check_in_array(type_list, type_list_length, input);

	if(NOT_PRIM_TPYE == 0){
		return input;
	}else{
		// temp[strlen(input)] = '\0';
		// printf("input is : %s\n", input);

		//X101
		strcpy(temp, "struct _ADT_");
		strcat(temp, input);
		// strcat(temp, "_t*");
		strcat(temp, "*");
		temp[strlen(temp)] = '\0';
		return temp;

	}


}

int is_const(ctr_t input){
	if_ctr(input, c_val, c_arglist)
		if_nextarg(c_arglist, c_arg, c_next)
			return 0;
		end_if()

		if_noarg(c_arglist)
			return 1;
		end_if()
	end_if()
	return 0;
}
//------------------------------------------------------------------------------

void fetch_arglist(arglist_t input, stringlist_t *temp_arglist){

	while(1){
	if_nextarg(input, al_head, al_tail)
		if_arg(al_head, a_val)
			if_string(a_val, a_str)
				if(check_in_array(type_list, type_list_length, a_str)){
					char *temp_string_for_type = (char *)malloc(sizeof(char) * (TYPE_LENGTH));	// add space for normalization
					a_str = type_normalization(a_str , temp_string_for_type);
				}
				*temp_arglist = nextlist(string(a_str), *temp_arglist);
				input = al_tail;
			end_if()
		end_if()
	end_if()

	if_noarg(input)
		return;
	end_if()
	}


}
// arg_list = nextlist(string(a_str), arg_list);

//-----------------------     Function Definition     --------------------------


void print_decllist(decllist_t input){
	if_nextdecl(input, dl_head, dl_tail)
		printf("\nGet a decl\n");
		print_decl(dl_head);			//print out current decl
		print_decllist(dl_tail);		//turn to next decl
	end_if()

	if_nodecl(input)	//end of decllist
		return;
	end_if()
}

// print out the string in decl
void print_decl(decl_t input){
	//store the list of cons and arguments for each decl
	stringlist_t con_list, arg_list;
	//count the number of const and non-const for tagging
	int const_num = 0;
	int non_const_num = 0;
	int *const_pointer;
	int *non_const_pointer;
	const_pointer = &const_num;
	non_const_pointer = &non_const_num;

	con_list = nil();
	arg_list = nil();
	if_decl(input, d_head, d_tail)
		if_string(d_head, d_str)
			printf("decl name: %s\n", d_str);
			// strcat(d_str, "_t");
			print_ctrlist(d_str, con_list, arg_list, d_tail, 0, const_pointer, non_const_pointer);
			//before enter the next decl, generate the corresponding codes.
			//print out the number of const and non-const
			printf("the number of const is: %d, and the nubmer of non-cosnt is: %d\n", *const_pointer, *non_const_pointer);
			int const_tag = 0;
			int non_const_tag = 0;
			stringlist_t temp_arglist;
			stringlist_t *p_arglist;
			p_arglist = &temp_arglist;
			ctrlist_t temp_ctrlist = reverse_ctrlist(d_tail);
			int initial = 0;
			int *init = &initial;
			while(1){
				if_nextctr(temp_ctrlist, con_val, con_next)
					//initial the temp arglist for each con
					temp_arglist = nil();
					if_ctr(con_val, c_val, c_arglist)
						if_string(c_val, c_str)
							fetch_arglist(c_arglist, p_arglist);
							// For non-const
							if_nextarg(c_arglist, al_head, al_tail)
								adt_main(file_name, d_str, c_str, reverse_stringlist(temp_arglist), fp_h, non_const_tag++, 0, *const_pointer, *non_const_pointer, init);
							end_if()

							// For const
							if_noarg(c_arglist)
								adt_main(file_name, d_str, c_str, reverse_stringlist(temp_arglist), fp_h, const_tag++, 1, *const_pointer, *non_const_pointer, init);
							end_if()

						end_if()
						temp_ctrlist = con_next;
					end_if()
				end_if()

				// end of conlist, then break
				if_noctr(temp_ctrlist)
					break;
				end_if()
			}

		end_if()
	end_if();

}

// count the number of const and non-const
void count_number_of_const_nonconst(arglist_t input, int *cp, int *np){
	//if there is a number of arguments, the number of
	//non-const add 1
	if_nextarg(input, arg_val, arg_next)
		*np = *np + 1;
	end_if()

	//if there is no any argument, then it is a const
	//the number of const add 1
	if_noarg(input)
		*cp = *cp + 1;
	end_if()
}

//print out the ctrlist
void print_ctrlist(c_string d_str, stringlist_t con_list, stringlist_t arg_list, ctrlist_t input, int tag, int *cp, int *np){
	if_nextctr(input, cl_head, cl_tail)
		// For each nextctr contains ctr and the rest of ctrlist
		if_ctr(cl_head, c_head, c_tail)
			if_string(c_head, c_str)
				check_exist_con(c_str);
				strcpy(constructor_list[constructor_num++], c_str);
				printf("ctr is: %s\n", c_str);
				//count the number of const and non-const
				count_number_of_const_nonconst(c_tail, cp, np);
				// Add up the new con
				con_list = nextlist(string(c_str), con_list);
				print_arglist(d_str, c_str, con_list, arg_list, c_tail, tag, cp, np);
				print_ctrlist(d_str, con_list, arg_list, cl_tail, ++tag, cp, np);

			end_if()
		end_if()

	end_if()

	if_noctr(input){ 					// end of ctrlist
		con_list = reverse_stringlist(con_list);
		return;
	}
	end_if()
}

void print_arglist(c_string d_str, c_string c_str, stringlist_t con_list, stringlist_t arg_list, arglist_t input, int tag, int *cp, int *np){
	if_nextarg(input, al_head, al_tail)
		if_arg(al_head, a)
			if_string(a, a_str)
				printf("arg: %s\n", a_str);
				// printf("Check here CCCCCCCC %s\n", a_str); XXX
				if(check_in_array(type_list, type_list_length, a_str)){
					char *temp_string_for_type = (char *)malloc(sizeof(char) * (TYPE_LENGTH));	// add space for normalization
					a_str = type_normalization(a_str , temp_string_for_type);
				}
				// printf("Check here %s\n", a_str);XXX
				// char temp_string_for_type[TYPE_LENGTH];							// add space for normalization
				// a_str = type_normalization(a_str , temp_string_for_type);
				arg_list = nextlist(string(a_str), arg_list);
				print_arglist(d_str, c_str, con_list, arg_list, al_tail, tag, cp, np);			//turn to tail arglist
			end_if()
		end_if()
	end_if()

	//end of arglist
	if_noarg(input)
		return;
	end_if()
}


void check_suffix(char *target, char *suffix){
	int t_len = strlen(target);
	int s_len = strlen(suffix);
	int i = 0;
	while(s_len > 0){
		//printf("%c and %c\n", target[t_len - s_len], suffix[i]);
		if(target[t_len - s_len] != suffix[i]){
			fprintf(stderr, "\nERROR: filename should end with \"%s\"\n\n",  suffix);
			exit(-1);
		}
		i++;
		s_len = s_len - 1;
	}
}





int yydebug=0;
//------------------------------------------------------------------------------


void yyerror(const char *str)			//default function for handliing errors
										//in yacc
{
	fprintf(stderr,"error: %s\n",str);
}


int yywrap()
{
	return 1;
}



//------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	//Too many arguments

	if(argc > 2){
		fprintf(stderr, "\nERROR: Too many parameters, please input the name of adt file, should end with \".adt\"\n\n");
      	exit(-1);
	}else if(argc == 1){
		fprintf(stderr, "\nERROR: Too less parameters, please input the name of adt file, should end with \".adt\"\n\n");
      	exit(-1);
	}else{
		char suffix[] = ".adt";
		check_suffix(argv[1], suffix);
	}

	strcpy(file_name, remove_file_suffix(argv[1]));

	strcpy(file, argv[1]);
	FILE *f;
	if((f = fopen(file, "r")) == NULL){
		fprintf(stderr, "\nERROR: Cannot find %s, please check the filename, should end with \".adt\"\n\n", file);
      	exit(-1);
	}
	// parse the ADT file and get the whole type name
	// type_list_length is the total number of type name
	type_list_length = collect_type_name(file, type_list);

	printf("filename is: %s and the file is %s\n", file_name, file);
	printf("New version started\n");
	initializaion_files(fp_h);
	//-------------    global variables initializaion     ----------------------
	d_list = nodecl();
	c_list = noctr();
    a_list = noarg();
	//--------------------------------------------------------------------------
	// parse the input files




	yyin = f;
	do{
		if(yyparse() != 0)
		printf("sytex of error");
	}while(!feof(yyin));


	fclose(yyin);

	//print out decllist
	print_decllist(d_list);


	printf("\nAll done\n");
	return 0;
}
%}


//------------------------------------------------------------------------------





//--------------------  Token Definition ---------------------------------------


%union 					//redifine the global variable of yylval
						// which used in the test.l file
{
        int number;
        char *string;
}

%token <number> NUMBER
%token <string> WORD
%token OBRACE EBRACE SEMICOLON FBRACE SBRACE COMMA DATA TYPE


//------------------------------------------------------------------------------






//-----------------------Parsing Structure Definition --------------------------

%%

commands:					//regards all strings as "commands" and each
							//"commands"  contain a number of "command"
	|
	commands command
	;


command:
	data_type_definition	//in the big picture, regards each date type
							//definition as a command
	;


data_type_definition:		//each type definition need a token of DATA, and
							//data type name as WORD which can be any string
							//with a detail content of definition
	DATA WORD definition_content
	{

		decl_temp = decl(string($2), c_list);
		d_list = nextdecl(decl_temp, d_list);

		c_list = noctr(); // clean up previous ctrlist
		a_list = noarg(); // clean up previous arglist

	}
	;


definition_content:			//a definition content contains an open brace, type
							//statements and a close brace
	OBRACE type_statements EBRACE


type_statements:
	|
	type_statements type_statement SEMICOLON
	;


type_statement:				//There are two kinds of type statement: with
							//arguments and non-argument
    WORD FBRACE arguments SBRACE
    {
		ctr_temp = ctr(string($1), a_list);
		// clean up previous arglist
		// for next cons
		a_list = noarg();
    	c_list = nextctr(ctr_temp, c_list);


    }
    |
    WORD FBRACE SBRACE
    {
    	ctr_temp = ctr(string($1), noarg());
    	c_list = nextctr(ctr_temp, c_list);

    }

    ;
arguments:				//for recursion, each argument can be regards as "arg, "
						//and "arg"

	WORD WORD WORD COMMA arguments
	{
		int temp_len = strlen($1) + strlen($2) + strlen($3);
		char temp_str[TYPE_LENGTH];
		char space[] = " ";
		strcpy(temp_str, $1);
		strcat(temp_str, space);
		strcat(temp_str, $2);
		strcat(temp_str, space);
		strcat(temp_str, $3);
		// arg_temp = arg(string($1));
		printf("Test %s\n", temp_str);
		arg_temp = arg(string(temp_str));
		a_list = nextarg(arg_temp, a_list);
	}
	|
	WORD WORD COMMA arguments
	{
		int temp_len = strlen($1) + strlen($2);
		char temp_str[TYPE_LENGTH];
		char space[] = " ";
		strcpy(temp_str, $1);
		strcat(temp_str, space);
		strcat(temp_str, $2);
		// arg_temp = arg(string($1));
		printf("Test %s\n", temp_str);
		arg_temp = arg(string(temp_str));
		a_list = nextarg(arg_temp, a_list);
	}
	|
	WORD COMMA arguments
	{
		arg_temp = arg(string($1));
		a_list = nextarg(arg_temp, a_list);

	}
	|
	WORD WORD WORD
	{
		int temp_len = strlen($1) + strlen($2) + strlen($3);
		char temp_str[TYPE_LENGTH];
		char space[] = " ";
		strcpy(temp_str, $1);
		strcat(temp_str, space);
		strcat(temp_str, $2);
		strcat(temp_str, space);
		strcat(temp_str, $3);
		// arg_temp = arg(string($1));
		arg_temp = arg(string(temp_str));
		a_list = nextarg(arg_temp, a_list);
	}
	|
	WORD WORD
	{
		int temp_len = strlen($1) + strlen($2);
		char temp_str[TYPE_LENGTH];
		char space[] = " ";
		strcpy(temp_str, $1);
		strcat(temp_str, space);
		strcat(temp_str, $2);
		// arg_temp = arg(string($1));
		arg_temp = arg(string(temp_str));
		a_list = nextarg(arg_temp, a_list);
	}
	|
	WORD
	{
		arg_temp = arg(string($1));
		a_list = nextarg(arg_temp, a_list);

	}
	;

%%

//------------------------------------------------------------------------------
