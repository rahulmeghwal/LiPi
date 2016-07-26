#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "new.y"

extern lineno;
void yyerror (char *s);
#include <stdio.h>     
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
int lineno=1;
int ln=1;
int rcode;
int tempCount=0;
int funcno=1;
int vartype,tvartype;
int end;
char x[10]={'0','1','2','3','4','5','6','7','8','9'};
	

int add_to_symtab(char *name,int type,int ivalue,float fvalue,char cvalue,int l,int r);
char * createCode(char *l,char op[],char *r);
/*int look_in_symtab(char *name);*/
char * printCode(char *op1,char op,char *op2);


struct symtab{

	char *name;
	int type;
	struct symtab *next;
	int l,r;
	union {
		long int ivalue;
		float fvalue;
		char cvalue;
	};
	
};
struct code{

	char *code;
	struct code *next;
};
void printcode(struct code *c);

struct symtab *symtab=NULL;
	
#line 50 "new.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	
	struct attrid {
		char* name;
		int type;
		long int value;
		int l;
		int r;
		struct code *head;
	
	}*attrid;
	
	struct attrlit {
		char *name;
		int value;
		int type;
	}*attrlit;
	
	struct ccode {
		char *name;
		struct code *head;
	}*ccode;
		
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 97 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define VAR 257
#define FX 258
#define MAIN 259
#define PRINT 260
#define LET 261
#define INT 262
#define POINT 263
#define CHAR 264
#define RETURN 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define OCB 269
#define CCB 270
#define OSB 271
#define CSB 272
#define RL 273
#define RG 274
#define RLE 275
#define RGE 276
#define RE 277
#define RNE 278
#define COMMA 279
#define DELIMITER 280
#define SCAN 281
#define FUNCTION 282
#define ID 283
#define INTLIT 284
#define POINTLIT 285
#define CHARLIT 286
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   30,   25,   25,   23,   13,   13,   11,   11,   17,
   26,   26,   24,   16,   15,   15,   15,   15,   15,   15,
   15,   20,   18,   18,   18,   19,   19,    5,    4,    4,
   31,   31,    6,    1,    1,    1,    2,    2,    2,    2,
    3,    3,    3,    3,   28,   28,   29,    9,   12,   12,
   10,   10,   14,   14,   27,   27,   27,   27,   27,   27,
    7,    7,    8,    8,   22,   21,   21,
};
static const short yylen[] = {                            2,
    1,    2,    2,    0,    6,    1,    0,    1,    3,    4,
    3,    0,    6,    3,    3,    3,    3,    3,    2,    2,
    0,    2,    1,    1,    1,    1,    3,    1,    1,    1,
    4,    7,    4,    3,    3,    1,    3,    3,    3,    1,
    3,    1,    1,    1,    5,    7,    5,    4,    1,    0,
    1,    3,    1,    1,    3,    3,    3,    3,    3,    3,
    1,    1,    1,    1,    4,    1,    3,
};
static const short yydefred[] = {                         4,
    0,    0,    1,    0,    3,    2,    0,    0,    0,    0,
   28,    8,    0,    0,    0,    0,    0,    0,    9,   21,
   13,    5,    0,    0,   23,   25,   24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   20,
    0,    0,   44,    0,    0,    0,   40,   43,    0,    0,
    0,    0,   16,   17,    0,   26,    0,   30,   15,   18,
   10,    0,    0,   11,    0,    0,    0,    0,    0,   61,
   63,   64,    0,   62,    0,    0,   66,    0,   53,   54,
    0,    0,   51,    0,    0,    0,   41,    0,    0,   37,
   38,   39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   65,    0,   48,    0,   27,   55,   56,   57,   58,
   59,   60,   21,    0,   47,   67,   52,    0,    0,    0,
    0,   14,   46,    0,   32,
};
static const short yydgoto[] = {                          1,
   45,   46,   47,   56,   12,   33,   73,   74,   48,   81,
   13,   82,   14,   83,   23,  114,   21,   35,   57,   36,
   78,   37,    5,    6,    2,   38,   75,   39,   40,    3,
   58,
};
static const short yysindex[] = {                         0,
    0, -237,    0, -255,    0,    0,    8,   31, -233, -233,
    0,    0, -203,   28,   53, -233, -174, -174,    0,    0,
    0,    0, -222, -187,    0,    0,    0,  -40,   58,   59,
   60,   61, -178, -177, -179, -175, -173, -164,    0,    0,
   47,   61,    0,  -40,  -23,   10,    0,    0, -260, -260,
 -172, -197,    0,    0, -162,    0, -169,    0,    0,    0,
    0,  -40,   29,    0,  -40,  -40,  -40,  -40,  -40,    0,
    0,    0, -210,    0,   71,   72,    0,  -38,    0,    0,
 -165,   74,    0, -168, -179,   -8,    0,   10,   10,    0,
    0,    0, -260, -260, -260, -260, -260, -260, -152, -152,
 -163,    0, -197,    0, -154,    0,    0,    0,    0,    0,
    0,    0,    0, -148,    0,    0,    0, -150, -208, -152,
 -161,    0,    0, -147,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   81,   81,
    0,    0,   83,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -144,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -35,    0,    0,    0,  -32,    0,    0,    0,    0,
    0,   86,    0,    0, -191,    0, -151,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   87,    0,    0,    0,    0, -149,    0,  -27,  -26,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -232,    0,    0,    0, -189,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -17,   27,   16,   45,  116,    0,  -16,    0,  -22,    0,
    0,    0,  123,   32,   21,  -95,  118,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   88,    0,    0,    0,
    0,
};
#define YYTABLESIZE 257
static const short yytable[] = {                         44,
   34,   42,  102,    7,  115,   42,   42,   42,   36,   42,
   36,   42,   36,   34,   35,   34,   35,   34,   35,   65,
    4,   66,   70,   71,  123,   72,   63,    8,   45,   45,
   45,   45,   45,   45,   65,   45,   66,   45,   24,   25,
   26,   27,   28,   29,   86,   30,   69,    9,   45,   11,
   45,   67,   24,   25,   26,   27,   68,   29,   31,   30,
   32,  122,   93,   94,   95,   96,   97,   98,   17,   87,
   10,   65,   31,   66,   32,   16,  107,  108,  109,  110,
  111,  112,   90,   91,   92,   79,   80,   29,   29,   31,
   31,   88,   89,   18,   20,   41,   34,   49,   50,   51,
   52,   53,   54,   55,   59,   61,   60,   62,   84,   85,
   77,   99,  100,  103,  104,  105,  113,  118,  120,  116,
  121,    7,  124,    6,  125,   12,   50,   49,   22,  106,
   33,   19,   15,  119,  117,   22,    0,   76,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  101,    0,   42,   43,   42,    0,    0,   36,    0,    0,
    0,    0,   34,   35,    0,    0,   64,
};
static const short yycheck[] = {                         40,
   23,   37,   41,  259,  100,   41,   42,   43,   41,   45,
   43,   47,   45,   41,   41,   43,   43,   45,   45,   43,
  258,   45,  283,  284,  120,  286,   44,  283,  261,  262,
  263,  264,  265,  266,   43,  268,   45,  270,  261,  262,
  263,  264,  265,  266,   62,  268,   37,   40,  281,  283,
  283,   42,  261,  262,  263,  264,   47,  266,  281,  268,
  283,  270,  273,  274,  275,  276,  277,  278,   41,   41,
   40,   43,  281,   45,  283,  279,   93,   94,   95,   96,
   97,   98,   67,   68,   69,  283,  284,  279,  280,  279,
  280,   65,   66,   41,  269,  283,  119,   40,   40,   40,
   40,  280,  280,  283,  280,  270,  280,   61,  271,  279,
  283,   41,   41,  279,   41,  284,  269,  272,  267,  283,
  271,   41,  284,   41,  272,  270,   41,   41,  280,   85,
  280,   16,   10,  113,  103,   18,   -1,   50,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  279,   -1,  283,  284,  280,   -1,   -1,  280,   -1,   -1,
   -1,   -1,  280,  280,   -1,   -1,  280,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,0,
0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"VAR","FX","MAIN","PRINT","LET","INT","POINT","CHAR","RETURN","IF","ELSE",
"WHILE","OCB","CCB","OSB","CSB","RL","RG","RLE","RGE","RE","RNE","COMMA",
"DELIMITER","SCAN","FUNCTION","ID","INTLIT","POINTLIT","CHARLIT",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : file",
"file : program",
"program : funcs funcmain",
"funcs : funcs func",
"funcs :",
"func : FX ID '(' fparameters ')' funcblock",
"fparameters : formal",
"fparameters :",
"formal : fvar",
"formal : formal COMMA fvar",
"funcblock : OCB stmt return CCB",
"return : RETURN expr DELIMITER",
"return :",
"funcmain : FX MAIN '(' fparameters ')' funcblock",
"block : OCB stmt CCB",
"stmt : stmt declare DELIMITER",
"stmt : stmt assign DELIMITER",
"stmt : stmt call DELIMITER",
"stmt : stmt input DELIMITER",
"stmt : stmt compare",
"stmt : stmt wloop",
"stmt :",
"declare : type stream",
"type : INT",
"type : CHAR",
"type : POINT",
"stream : var",
"stream : stream COMMA var",
"fvar : ID",
"var : ID",
"var : array",
"array : ID OSB INTLIT CSB",
"array : ID OSB INTLIT CSB OSB INTLIT CSB",
"assign : LET ID '=' expr",
"expr : expr '+' term",
"expr : expr '-' term",
"expr : term",
"term : term '*' factor",
"term : term '/' factor",
"term : term '%' factor",
"term : factor",
"factor : '(' expr ')'",
"factor : ID",
"factor : call",
"factor : INTLIT",
"compare : IF '(' condition ')' block",
"compare : IF '(' condition ')' block ELSE block",
"wloop : WHILE '(' condition ')' block",
"call : ID '(' aparameters ')'",
"aparameters : actual",
"aparameters :",
"actual : var1",
"actual : actual COMMA var1",
"var1 : ID",
"var1 : INTLIT",
"condition : XID RL XID",
"condition : XID RG XID",
"condition : XID RLE XID",
"condition : XID RGE XID",
"condition : XID RE XID",
"condition : XID RNE XID",
"XID : ID",
"XID : lits",
"lits : INTLIT",
"lits : CHARLIT",
"input : SCAN '(' sstream ')'",
"sstream : ID",
"sstream : sstream COMMA ID",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 1085 "new.y"

char * createCode(char *l,char op[],char *r){

	int i=0,j=0,k=0,ll=strlen(l),lr=strlen(r),lo=lr=strlen(op);
	
	char *code=(char *)malloc((ll+lo+lr+3)*sizeof(char));	
	
	while(i<ll){
		code[i]=l[i];
		i++;
	}
	code[i]=' ';i++;
	
	while(k<lo){
	code[i+k]=op[k];k++;
	}	
	code[i+k]=' ';k++;

	while(j<lr){
		code[i+j+k]=r[j];
		j++;
	}
	return code;
}

void appendcode(struct code *c,char *code){
	
	struct code *temp=c,*temp1;
	
	while(temp->next){
		temp=temp->next;				
	}
	temp1=(struct code *)malloc(sizeof(struct code));
	temp1->code=code;
	temp1->next=NULL;
	temp->next=temp1;
}


char * genTempVar(){

	char *s;
	s=malloc(3*sizeof(char));
	s[0]='$';
	s[1]='a'+tempCount/10;
	s[2]=x[tempCount%10];
	tempCount++;
	return s;

}
struct code * addcode(struct code *n1,struct code *n2){
	
	if(n1==n2 && n1==NULL)
		return NULL;
	if(n1==NULL){
		n1=n2;
		return n1;
	}
	if(n2==NULL)
		return n1;
	struct code *temp=n1;
	
	while(temp->next){
		temp=temp->next;				
	}
	temp->next=n2;
	return n1;
}

void yyerror (char *message) {

	fprintf (stderr, "%s \n",message);

}
void printcode(struct code *c){
	
	struct code *temp=c;
	int count=0;
	
	while(temp){
		if(count==0)
			printf("%s\n",temp->code);
		else
			printf("%s\n",temp->code);
	
		count++;
		temp=temp->next;				
	}
}
/*
char * tempVar(char *op1,char op,char *op2){
	
	char * tempVar=genTempVar();
	printf("%s = %s %c %s\n",tempVar,op1,op,op2);
	return tempVar;
													
}
*/
char * getTempVar(){
	char *s;
	s=malloc(3*sizeof(char));
	s[0]='$';
	s[1]='a'+tempCount/10;
	s[2]=x[tempCount%10];
	return s;
}

char * genCode(char *tempVar,char *op1,char *op,char *op2){
	
	char s,e;
	char *code=(char *)malloc(sizeof(char)*(sizeof(tempVar)+sizeof(op1)+sizeof(op)+sizeof(op2)+sizeof(s)+sizeof(e)));
	int i=0,j=0,k=0;
	int lt=strlen(tempVar),l1=strlen(op1),l2=strlen(op2);
	while(i<lt){
		code[i]=tempVar[i];
		i++;
	}
	code[i]=' ';i++;
	code[i]='=';i++;
	code[i]=' ';i++;
	while(j<l1){
		code[i+j]=op1[j];
		j++;
	}
	code[i+j]=' ';j++;
	code[i+j]=*op;j++;
	code[i+j]=' ';j++;

	while(k<l2){
		code[i+j+k]=op2[k];
		k++;
	}
	return code;
													
}

char * printCode(char *op1,char op,char *op2){
	
	char * tempVar=genTempVar();
	printf("%s = %s %c %s\n",tempVar,op1,op,op2);
	return tempVar;
													
}

/*
void printifCode(char *op1,int op,char *op2){
	
	printf("if %s ",op1);
	switch(op){
		case:printf("<");break;
		case:printf("<");break;
		case:printf("<");break;
		case:printf("<");break;
		case:printf("<");break;
	}
	printf("if %s  %s %c %s\n",tempVar,op1,op,op2);
													
}
*/
struct symtab* search_symtab(char *name){
	
	struct symtab *temp,*last;
	temp=symtab;
		
	while(temp){
		if(strcmp(temp->name,name)==0){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

struct symtab* create_new_entry(char *name,int type,int ivalue,float fvalue,char cvalue,int l,int r){
	
	struct symtab *new = malloc(sizeof(struct symtab));
	new->name=name;
	new->type=type;
	new->next=NULL;
	new->l=l;
	new->r=r;
	if(type==INT)
		new->ivalue=ivalue;
	else if(type==POINT)
		new->fvalue=fvalue;
	else if(type==CHAR)
		new->cvalue=cvalue;
	return new;
}
int add_to_symtab(char *name,int type,int ivalue,float fvalue,char cvalue,int l,int r){

	
	struct symtab *temp,*last;
	
	
	//printf("VARIABLE NAME :%s\n",name);
	//printf("VARIABLE TYPE :%d\n\n",type);
														 
	if(symtab==NULL){
		//printf("oh");
		symtab=create_new_entry(name,type,ivalue,fvalue,cvalue,l,r);
	}
	else{
		temp=symtab;
		
		while(temp){
			//printf("Comparing [%s] to [%s] \n",temp->name,name);
				
			if(strcmp(temp->name,name)==0){
				return 0;
			}
			last=temp;
			temp=temp->next;
		}
		//if(!found){
		last->next=create_new_entry(name,type,ivalue,fvalue,cvalue,l,r);
		//}
	}
	
	return 1;
	
}
int isDeclared(char *name){

	
	struct symtab *temp,*last;
	if(symtab==NULL){
		return 0;
	}
	else{
		temp=symtab;
		
		while(temp){
			if(strcmp(temp->name,name)==0)
				return 1;
			temp=temp->next;
		}
	
	}
	
	return 0;
	
}

 
int main (void) {

	yyparse();
	struct symtab *temp=symtab;
	/*
	printf("\n\n\t\t  SYMBOL TABLE\n");
	printf("    +------------------------------------------+\n");
	
	printf("\tNAME\tTYPE\tLB\tUB\n");
	printf("    +------------------------------------------+\n");
	int i=0;	
	while(temp){
		char type[][10]={"INT","CHAR","POINT","FUNC","VAR"};
		if(temp->type==INT)			{i=0;}
		if(temp->type==CHAR)		{i=1;}
		if(temp->type==POINT)		{i=2;}
		if(temp->type==FUNCTION)	{i=3;}
		if(temp->type==VAR)			{i=4;}
		
		printf("\t%s\t%s\t%d\t%d\n",temp->name,type[i],temp->l,temp->r);
		
		temp=temp->next;
	}
	printf("    +------------------------------------------+\n\n");
	*/

	
}

#line 694 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 114 "new.y"
	{printcode(yystack.l_mark[0].ccode->head);}
break;
case 2:
#line 115 "new.y"
	{yyval.ccode->head=addcode(yystack.l_mark[-1].ccode->head,yystack.l_mark[0].ccode->head);}
break;
case 3:
#line 117 "new.y"
	{
														if(!yystack.l_mark[-1].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[0].ccode->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-1].ccode->head,yystack.l_mark[0].ccode->head);
														}
													}
break;
case 4:
#line 127 "new.y"
	{{yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));yyval.ccode->head=NULL;}}
break;
case 5:
#line 129 "new.y"
	{
																				
														char *n=yystack.l_mark[-4].attrid->name;
														rcode=add_to_symtab(yystack.l_mark[-4].attrid->name,FUNCTION,-1,-1,'0',-1,-1);
														if(!rcode){
														 	printf("\n\nFunction name (%s) already taken.\n",yystack.l_mark[-4].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	exit(0);
														}
														char *funcheader=(char *)malloc(sizeof(yystack.l_mark[-4].attrid->name)+2*sizeof(char));
														char *funcname=yystack.l_mark[-4].attrid->name;
														int l=strlen(yystack.l_mark[-4].attrid->name);
														int i=0;
														while(i<l){
															funcheader[i]=funcname[i];
															i++;
														}
														funcheader[i]=' ';i++;
														funcheader[i]=':';
														
														struct ccode *c=(struct ccode *)malloc(sizeof(struct ccode));
														
														
														struct code *funcCode= (struct code *)malloc(sizeof(struct code));
														funcCode->code=funcheader;
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														funcCode->next=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[0].ccode->head);
														yyval.ccode->name=yystack.l_mark[-4].attrid->name;
														yyval.ccode->head=funcCode;
													    /*printcode($$->head);*/
														/*else*/
														/*printf("%s :\n",$2->name);*/
														/*printcode($4->head);*/
														/*printcode($6->head);														 */
														/* $$=$2;*/
														
														
													}
break;
case 6:
#line 168 "new.y"
	{yyval.ccode=yystack.l_mark[0].ccode;}
break;
case 7:
#line 169 "new.y"
	{yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));yyval.ccode->head=NULL;}
break;
case 8:
#line 171 "new.y"
	{

 															
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+6*sizeof(char));
														code[0]='f'; code[1]='e'; code[2]='t'; code[3]='c';
														code[4]='h';
														code[5]=' ';
														
														int l=strlen(yystack.l_mark[0].attrid->name);
														
														int i=0;
														char *pa=yystack.l_mark[0].attrid->name;
														while(i<l){
															code[i+6]=pa[i];
															i++;
														}
														/*printf("code :%s\n",code);*/
														if(yystack.l_mark[0].attrid->head==NULL){
															yystack.l_mark[0].attrid->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[0].attrid->head->code=code;
															yystack.l_mark[0].attrid->head->next=NULL;
															/*printf("aw");*/
														}
														else{
															appendcode(yystack.l_mark[0].attrid->head,code);
														
														}
														yyval.ccode->head=yystack.l_mark[0].attrid->head;
														/*printcode($$->head);*/
													
														
														
															/*printf("allocate %s %d\n",$1->name,size);*/

													}
break;
case 9:
#line 206 "new.y"
	{
														char *code=(char *)malloc(sizeof(yystack.l_mark[-2].ccode->name)+6*sizeof(char));
														code[0]='f'; code[1]='e'; code[2]='t'; code[3]='c';
														code[4]='h';
														code[5]=' ';
														
														int l=strlen(yystack.l_mark[0].attrid->name);
														
														int i=0;
														char *pa=yystack.l_mark[0].attrid->name;
														while(i<l){
															code[i+6]=pa[i];
															i++;
														}
														/*printf("code :%s\n",code);*/
														if(yystack.l_mark[-2].ccode->head==NULL){
															yystack.l_mark[-2].ccode->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[-2].ccode->head->code=code;
															yystack.l_mark[-2].ccode->head->next=NULL;
															/*printf("aw");*/
														}
														else{
															appendcode(yystack.l_mark[-2].ccode->head,code);
														
														}
														yyval.ccode->head=yystack.l_mark[-2].ccode->head;

													}
break;
case 10:
#line 236 "new.y"
	{
														yystack.l_mark[-2].ccode->head=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[-1].ccode->head);
														yyval.ccode=yystack.l_mark[-2].ccode;
													}
break;
case 11:
#line 241 "new.y"
	{
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														char *code=(char *)malloc(sizeof(yystack.l_mark[-1].attrid->name)+8*sizeof(char));
														code[0]='r'; code[1]='e'; code[2]='t'; code[3]='u';
														code[4]='r'; code[5]='n'; code[6]=' '; 
														char *pa=yystack.l_mark[-1].attrid->name;
														int i=0,l=strlen(pa);
														while(i<l){
															code[i+7]=pa[i];
															i++;
														}
														struct code *retCode= (struct code *)malloc(sizeof(struct code));
														retCode->code=code;
														retCode->next=NULL;
														
														yyval.ccode->head=addcode(yystack.l_mark[-1].attrid->head,retCode);
														
														
														
/*														$$->head=NULL;//addcode($2->code,$1->code);*/
													}
break;
case 12:
#line 263 "new.y"
	{
														char *code=(char *)malloc(8*sizeof(char));
														code[0]='r'; code[1]='e'; code[2]='t'; code[3]='u';
														code[4]='r'; code[5]='n'; code[6]=' '; 
														
														struct code *retCode= (struct code *)malloc(sizeof(struct code));
														retCode->code=code;
														
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=retCode;
														
													}
break;
case 13:
#line 277 "new.y"
	{	

														char *funcheader=(char *)malloc(6*sizeof(char));
														funcheader[0]='m';
														funcheader[1]='a';
														funcheader[2]='i';
														funcheader[3]='n';
														funcheader[4]=' ';
														funcheader[5]=':';
														
														struct ccode *c=(struct ccode *)malloc(sizeof(struct ccode));
														
														
														struct code *funcCode= (struct code *)malloc(sizeof(struct code));
														funcCode->code=funcheader;
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														funcCode->next=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[0].ccode->head);
														yyval.ccode->head=funcCode;
														/*printcode($$->head);*/
													
													/*	printf("\nmain:\n");*/
													/*	printcode($5->head);*/
													}
break;
case 14:
#line 301 "new.y"
	{yyval.ccode=yystack.l_mark[-1].ccode;}
break;
case 15:
#line 303 "new.y"
	{
														if(!yystack.l_mark[-2].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[-1].ccode->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[-1].ccode->head);
														}
													}
break;
case 16:
#line 313 "new.y"
	{
														if(!yystack.l_mark[-2].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[-1].attrid->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[-1].attrid->head);
														}
														/*$$->head=$2->head;*/
													}
break;
case 17:
#line 324 "new.y"
	{
														if(!yystack.l_mark[-2].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[-1].ccode->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[-1].ccode->head);
														}
														/*$$->head=$2->head);*/
													}
break;
case 18:
#line 335 "new.y"
	{
														if(!yystack.l_mark[-2].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[-1].ccode->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-2].ccode->head,yystack.l_mark[-1].ccode->head);
														}

													}
break;
case 19:
#line 346 "new.y"
	{
														if(!yystack.l_mark[-1].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[0].ccode->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-1].ccode->head,yystack.l_mark[0].ccode->head);
														}

													}
break;
case 20:
#line 357 "new.y"
	{
															if(!yystack.l_mark[-1].ccode){
															/*printf("Yes");*/
															yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
															yyval.ccode->head=yystack.l_mark[0].ccode->head;
														}
														else{
															yyval.ccode->head=addcode(yystack.l_mark[-1].ccode->head,yystack.l_mark[0].ccode->head);
														}

													}
break;
case 21:
#line 368 "new.y"
	{
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=NULL;
													}
break;
case 22:
#line 373 "new.y"
	{yyval.ccode=yystack.l_mark[0].ccode;}
break;
case 23:
#line 376 "new.y"
	{ vartype=INT;}
break;
case 24:
#line 377 "new.y"
	{ vartype=CHAR;}
break;
case 25:
#line 378 "new.y"
	{ vartype=POINT;}
break;
case 26:
#line 380 "new.y"
	{
														int size=16;
														 if(vartype==INT)
														 	size=8;
														 else if(vartype==POINT)
														 	size=16;
														 else if(vartype==CHAR)
														 	size=2;
															
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+12*sizeof(char));
														code[0]='a'; code[4]='c'; code[1]='l'; code[5]='a';
														code[2]='l'; code[6]='t'; code[3]='o'; code[7]='e';
														code[8]=' ';
														int l=strlen(yystack.l_mark[0].attrid->name);
														
														int i=0;
														char *pa=yystack.l_mark[0].attrid->name;
														while(i<l){
															code[i+9]=pa[i];
															i++;
														}
														code[l+9]=' ';
														i=9+l+1;
														if(size == 2)
															code[i]='2';
														else if(size == 8)
															code[i]='8';
														else if(size == 16){
															code[i]='1';
															code[i+1]='6';
														}
														 	
														
														/*printf("code :%s\n",code);*/
														if(yystack.l_mark[0].attrid->head==NULL){
															yystack.l_mark[0].attrid->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[0].attrid->head->code=code;
															yystack.l_mark[0].attrid->head->next=NULL;
															/*printf("aw");*/
														}
														else{
															appendcode(yystack.l_mark[0].attrid->head,code);
														
														}
														yyval.ccode->head=yystack.l_mark[0].attrid->head;
														/*printcode($$->head);*/
													
														
														
															/*printf("allocate %s %d\n",$1->name,size);*/
													}
break;
case 27:
#line 431 "new.y"
	{
														int size=16;
														 if(vartype==INT)
														 	size=8;
														 else if(vartype==POINT)
														 	size=16;
														 else if(vartype==CHAR)
														 	size=2;
															
														char *code=(char *)malloc(sizeof(yystack.l_mark[-2].ccode->name)+12*sizeof(char));
														code[0]='a'; code[4]='c'; code[1]='l'; code[5]='a';
														code[2]='l'; code[6]='t'; code[3]='o'; code[7]='e';
														code[8]=' ';
														int l=strlen(yystack.l_mark[0].attrid->name);
														
														int i=0;
														char *pa=yystack.l_mark[0].attrid->name;
														while(i<l){
															code[i+9]=pa[i];
															i++;
														}
														code[l+9]=' ';
														i=9+l+1;
														if(size == 2)
															code[i]='2';
														else if(size == 8)
															code[i]='8';
														else if(size == 16){
															code[i]='1';
															code[i+1]='6';
														}
														 	
														
														/*printf("code :%s\n",code);*/
														if(yystack.l_mark[-2].ccode->head==NULL){
															yystack.l_mark[-2].ccode->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[-2].ccode->head->code=code;
															yystack.l_mark[-2].ccode->head->next=NULL;
															/*printf("aw");*/
														}
														else{
															appendcode(yystack.l_mark[-2].ccode->head,code);
														
														}
														yyval.ccode->head=yystack.l_mark[-2].ccode->head;
														/*printcode($$->head);*/
													
														
														
															/*printf("allocate %s %d\n",$1->name,size);*/
													}
break;
case 28:
#line 483 "new.y"
	{
														 rcode=add_to_symtab(yystack.l_mark[0].attrid->name,VAR,0,0,'-',0,1);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",yystack.l_mark[0].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	
														 	exit(0);
														 }
														 
														 	
														/*printf("allocate %s %d\n",$1->name,size);*/
														yyval.attrid=yystack.l_mark[0].attrid;
													}
break;
case 29:
#line 496 "new.y"
	{
														 rcode=add_to_symtab(yystack.l_mark[0].attrid->name,vartype,0,0,'0',0,1);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",yystack.l_mark[0].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	exit(0);
														 }
														 
														 	
														/*printf("allocate %s %d\n",$1->name,size);*/
														yyval.attrid=yystack.l_mark[0].attrid;
													}
break;
case 30:
#line 508 "new.y"
	{;}
break;
case 31:
#line 510 "new.y"
	{ 	  
														 rcode=add_to_symtab(yystack.l_mark[-3].attrid->name,vartype,0,0,'0',0,yystack.l_mark[-1].attrid->value);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",yystack.l_mark[-3].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	
														 	exit(0);
														 }
													}
break;
case 32:
#line 519 "new.y"
	{ 	 
														 
														 int rbound=(yystack.l_mark[-4].attrid->value)*(yystack.l_mark[-1].attrid->value);
														 rcode=add_to_symtab(yystack.l_mark[-6].attrid->name,vartype,0,0,'0',0,rbound);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",yystack.l_mark[-6].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	exit(0);
														 }
													}
break;
case 33:
#line 530 "new.y"
	{		
														char opr='=';
														char s=' ';
														char *code=(char *)malloc(sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char)+sizeof(yystack.l_mark[0].attrid->name));
														char *operator=&opr;
														char *id=yystack.l_mark[-2].attrid->name,*exp=yystack.l_mark[0].attrid->name;
														int li=strlen(id),le=strlen(exp);
														int i=0,j=0;
														while(i<li){
															code[i]=id[i];
															i++;
														}
														code[i]=' ';i++;
														code[i]='=';i++;
														code[i]=' ';i++;
														while(j<le){
															code[i+j]=exp[j];
															j++;
														}
														
														if(!yystack.l_mark[0].attrid->head){
															yystack.l_mark[0].attrid->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[0].attrid->head->next=NULL;
															yystack.l_mark[0].attrid->head->code=code;
															
														}
														else{
															appendcode(yystack.l_mark[0].attrid->head,code);		
														}
														
														yyval.attrid->head=yystack.l_mark[0].attrid->head;
													}
break;
case 34:
#line 563 "new.y"
	{	
														char opr='+';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,yystack.l_mark[-2].attrid->name,operator,yystack.l_mark[0].attrid->name);
														yyval.attrid->name=tempVar;
														struct code *n1,*n2,*n;
														n1=yystack.l_mark[-2].attrid->head; 
														n2=yystack.l_mark[0].attrid->head;
														n=addcode(n1,n2);
														/*printf("asd\n");*/
														/*printcode(n);*/
														/*printf("asd\n");*/
														yyval.attrid->head=n;
														if(yyval.attrid->head==NULL){
															yyval.attrid->head=(struct code *)malloc(sizeof(struct code));
															yyval.attrid->head->code=addrcode;
															yyval.attrid->head->next=NULL;
															
														}
														else
															appendcode(yyval.attrid->head,addrcode);
														/*if()*/
													}
break;
case 35:
#line 591 "new.y"
	{	
														char opr='-';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,yystack.l_mark[-2].attrid->name,operator,yystack.l_mark[0].attrid->name);
														yyval.attrid->name=tempVar;
														struct code *n1,*n2,*n;
														n1=yystack.l_mark[-2].attrid->head; 
														n2=yystack.l_mark[0].attrid->head;
														n=addcode(n1,n2);
														/*printf("asd\n");*/
														/*printcode(n);*/
														/*printf("asd\n");*/
														yyval.attrid->head=n;
														if(yyval.attrid->head==NULL){
															yyval.attrid->head=(struct code *)malloc(sizeof(struct code));
															yyval.attrid->head->code=addrcode;
															yyval.attrid->head->next=NULL;
															
														}
														else
															appendcode(yyval.attrid->head,addrcode);
													}
break;
case 36:
#line 615 "new.y"
	{
														yyval.attrid=yystack.l_mark[0].attrid;
													}
break;
case 37:
#line 618 "new.y"
	{	
														char opr='*';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,yystack.l_mark[-2].attrid->name,operator,yystack.l_mark[0].attrid->name);
														yyval.attrid->name=tempVar;
														struct code *n1,*n2,*n;
														n1=yystack.l_mark[-2].attrid->head; 
														n2=yystack.l_mark[0].attrid->head;
														n=addcode(n1,n2);
														/*printf("asd\n");*/
														/*printcode(n);*/
														/*printf("asd\n");*/
														yyval.attrid->head=n;
														if(yyval.attrid->head==NULL){
															yyval.attrid->head=(struct code *)malloc(sizeof(struct code));
															yyval.attrid->head->code=addrcode;
															yyval.attrid->head->next=NULL;
															
														}
														else
															appendcode(yyval.attrid->head,addrcode);
													}
break;
case 38:
#line 642 "new.y"
	{	
														char opr='/';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,yystack.l_mark[-2].attrid->name,operator,yystack.l_mark[0].attrid->name);
														yyval.attrid->name=tempVar;
														struct code *n1,*n2,*n;
														n1=yystack.l_mark[-2].attrid->head; 
														n2=yystack.l_mark[0].attrid->head;
														n=addcode(n1,n2);
														/*printf("asd\n");*/
														/*printcode(n);*/
														/*printf("asd\n");*/
														yyval.attrid->head=n;
														if(yyval.attrid->head==NULL){
															yyval.attrid->head=(struct code *)malloc(sizeof(struct code));
															yyval.attrid->head->code=addrcode;
															yyval.attrid->head->next=NULL;
															
														}
														else
															appendcode(yyval.attrid->head,addrcode);
													}
break;
case 39:
#line 666 "new.y"
	{
														char opr='%';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,yystack.l_mark[-2].attrid->name,operator,yystack.l_mark[0].attrid->name);
														yyval.attrid->name=tempVar;
														struct code *n1,*n2,*n;
														n1=yystack.l_mark[-2].attrid->head; 
														n2=yystack.l_mark[0].attrid->head;
														n=addcode(n1,n2);
														/*printf("asd\n");*/
														/*printcode(n);*/
														/*printf("asd\n");*/
														yyval.attrid->head=n;
														if(yyval.attrid->head==NULL){
															yyval.attrid->head=(struct code *)malloc(sizeof(struct code));
															yyval.attrid->head->code=addrcode;
															yyval.attrid->head->next=NULL;
															
														}
														else
															appendcode(yyval.attrid->head,addrcode);
													}
break;
case 40:
#line 690 "new.y"
	{ yyval.attrid=yystack.l_mark[0].attrid;}
break;
case 41:
#line 691 "new.y"
	{ yyval.attrid=yystack.l_mark[-1].attrid;}
break;
case 42:
#line 693 "new.y"
	{
														if(!isDeclared(yystack.l_mark[0].attrid->name)){
															printf("\n\nVariable undeclared : %s\n",yystack.l_mark[0].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
															
														exit(0);
														}
														/*printf("%s\n",$1->name);*/
													
														yyval.attrid=yystack.l_mark[0].attrid;
														
													}
break;
case 43:
#line 705 "new.y"
	{;}
break;
case 44:
#line 706 "new.y"
	{/*$$->name=$1->name;*/
													}
break;
case 45:
#line 709 "new.y"
	{
														char *condCode=yystack.l_mark[-2].ccode->head->code;
														char *temp=genTempVar();
														char *newCode=(char *)malloc(8*sizeof(char)+sizeof(condCode)+sizeof(temp));
														newCode=createCode("if",condCode,"goto");
														newCode=createCode(newCode,temp,"");
														
														struct code *labelCode= (struct code *)malloc(sizeof(struct code));
														labelCode->code=createCode(temp,":","");
														labelCode->next=NULL;
														yystack.l_mark[0].ccode->head=addcode(yystack.l_mark[0].ccode->head,labelCode);
														
														struct code *finCode= (struct code *)malloc(sizeof(struct code));
														finCode->code=newCode;
														finCode->next=yystack.l_mark[0].ccode->head;
														
														yyval.ccode->head=finCode;
														
														/*printf("[%s]",newCode);*/
														/*	appendcode($5->head);*/
													
													}
break;
case 46:
#line 731 "new.y"
	{
														char *condCode=yystack.l_mark[-4].ccode->head->code;
														char *temp1=genTempVar();
														char *temp2=genTempVar();
														char *newCode=(char *)malloc(8*sizeof(char)+sizeof(condCode)+sizeof(temp1));
														newCode=createCode("if",condCode,"goto");
														newCode=createCode(newCode,temp1,"");
														
														struct code *jumpCode= (struct code *)malloc(sizeof(struct code));
														jumpCode->code=createCode("jump",temp2,":");
														jumpCode->next=NULL;
														yystack.l_mark[-2].ccode->head=addcode(yystack.l_mark[-2].ccode->head,jumpCode);
														
														struct code *ifCode= (struct code *)malloc(sizeof(struct code));
														ifCode->code=newCode;
														ifCode->next=yystack.l_mark[-2].ccode->head;
														
														
														struct code *labelCode= (struct code *)malloc(sizeof(struct code));
														labelCode->code=createCode(temp2,":","");
														labelCode->next=NULL;
														yystack.l_mark[-2].ccode->head=addcode(yystack.l_mark[0].ccode->head,labelCode);

														struct code *elseCode= (struct code *)malloc(sizeof(struct code));
														elseCode->code=createCode(temp1,":","");
														elseCode->next=yystack.l_mark[0].ccode->head;
														
														
														yyval.ccode->head=addcode(ifCode,elseCode);
														/*printcode($7->head);*/

													}
break;
case 47:
#line 764 "new.y"
	{
														char *condCode=yystack.l_mark[-2].ccode->head->code;
														char *temp1=genTempVar();
														char *temp2=genTempVar();
														char *newCode=(char *)malloc(8*sizeof(char)+sizeof(condCode)+sizeof(temp1));
														newCode=createCode("if",condCode,"goto");
														newCode=createCode(newCode,temp2,"");
														
														struct code *jumpCode= (struct code *)malloc(sizeof(struct code));
														jumpCode->code=createCode("jump",temp1,":");
														jumpCode->next=NULL;
														yystack.l_mark[0].ccode->head=addcode(yystack.l_mark[0].ccode->head,jumpCode);
														
														struct code *ifCode= (struct code *)malloc(sizeof(struct code));
														ifCode->code=newCode;
														ifCode->next=yystack.l_mark[0].ccode->head;

														struct code *whileCode= (struct code *)malloc(sizeof(struct code));
														whileCode->code=createCode(temp1,":","");
														whileCode->next=ifCode;
														
														struct code *labelCode= (struct code *)malloc(sizeof(struct code));
														labelCode->code=createCode(temp2,":","");
														labelCode->next=NULL;
														
														
														
														yyval.ccode->head=addcode(whileCode,labelCode);
														/*printcode($7->head);*/
													}
break;
case 48:
#line 795 "new.y"
	{
													if(!search_symtab(yystack.l_mark[-3].attrid->name)){
														printf("\n\nIndefined reference to function %s\n",yystack.l_mark[-3].attrid->name);
													 	printf("Line no. : %d\n\n\n",lineno);
														
														exit(0);
													}
														
													char *code=(char *)malloc(sizeof(yystack.l_mark[-3].attrid->name)+4*sizeof(char)+2*sizeof(char));
													
													code[0]='c';
													code[1]='a';
													code[2]='l';
													code[3]='l';
													code[4]=' ';
													int l=strlen(yystack.l_mark[-3].attrid->name);
													int i=0;
													char *pa=yystack.l_mark[-3].attrid->name;
													/*printf("%s %d",$1->name,l);*/
													strcat(code,pa);
													while(i<l){
														code[i+5]=pa[i];
														i++;
													}
													/*printf("code :%s\n",code);*/
													
													if(!yystack.l_mark[-1].ccode){
														yyval.ccode->head=(struct code *)malloc(sizeof(struct code));
														yyval.ccode->head->code=code;
														yyval.ccode->head->next=NULL;
														/*printf("Yes");*/
													}
													else{
														appendcode(yystack.l_mark[-1].ccode->head,code);
														yyval.ccode=yystack.l_mark[-1].ccode;
													}
													}
break;
case 49:
#line 834 "new.y"
	{yyval.ccode=yystack.l_mark[0].ccode;}
break;
case 50:
#line 835 "new.y"
	{yyval.ccode=NULL;}
break;
case 51:
#line 837 "new.y"
	{	
													char p[]="para";
													char *code=(char *)malloc(sizeof(yystack.l_mark[0].ccode->name)+sizeof(p)+2*sizeof(char));
													code[0]='p';
													code[1]='a';
													code[2]='r';
													code[3]='a';
													code[4]=' ';
													int l=strlen(yystack.l_mark[0].ccode->name);
													int i=0;
													char *pa=yystack.l_mark[0].ccode->name;
													while(i<l){
														code[i+5]=pa[i];
														i++;
													}
													/*printf("code :%s\n",code);*/
													if(yystack.l_mark[0].ccode->head==NULL){
														yystack.l_mark[0].ccode->head=(struct code *)malloc(sizeof(struct code));
														yystack.l_mark[0].ccode->head->code=code;
														yystack.l_mark[0].ccode->head->next=NULL;
														/*printf("aw");*/
													}
													else{
														appendcode(yystack.l_mark[0].ccode->head,code);
														
													}
													yyval.ccode->head=yystack.l_mark[0].ccode->head;
													/*printcode($$->head);*/
													
													}
break;
case 52:
#line 867 "new.y"
	{
													char p[]="para";
													char *code=(char *)malloc(sizeof(yystack.l_mark[0].ccode->name)+sizeof(p)+2*sizeof(char));
													code[0]='p';
													code[1]='a';
													code[2]='r';
													code[3]='a';
													code[4]=' ';
													int l=strlen(yystack.l_mark[0].ccode->name);
													int i=0;
													char *pa=yystack.l_mark[0].ccode->name;
													while(i<l){
														code[i+5]=pa[i];
														i++;
													}
													/*printf("code :[%s]",code);*/
													appendcode(yystack.l_mark[-2].ccode->head,code);
													/*printcode($1->head);*/
													}
break;
case 53:
#line 887 "new.y"
	{
														if(!isDeclared(yystack.l_mark[0].attrid->name)){
															printf("\n\nVariable undeclared : %s\n",yystack.l_mark[0].attrid->name);
														 	printf("Line no. : %d\n\n\n",lineno);
															
														exit(0);
														}
														yyval.ccode->name=yystack.l_mark[0].attrid->name;
														
													}
break;
case 54:
#line 897 "new.y"
	{	
														yyval.ccode->name=yystack.l_mark[0].attrid->name;
													}
break;
case 55:
#line 901 "new.y"
	{
														
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char));
														code=createCode(yystack.l_mark[-2].attrid->name,">=",yystack.l_mark[0].attrid->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														/*printf("[%s]",code);*/
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=condCode;
													}
break;
case 56:
#line 912 "new.y"
	{
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char));
														code=createCode(yystack.l_mark[-2].attrid->name,"<=",yystack.l_mark[0].attrid->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														/*printf("[%s]",code);*/
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=condCode;

													}
break;
case 57:
#line 923 "new.y"
	{
														
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char));
														code=createCode(yystack.l_mark[-2].attrid->name,">",yystack.l_mark[0].attrid->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														/*printf("[%s]",code);*/
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=condCode;
													}
break;
case 58:
#line 934 "new.y"
	{
														
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char));
														code=createCode(yystack.l_mark[-2].attrid->name,"<",yystack.l_mark[0].attrid->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														/*printf("[%s]",code);*/
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=condCode;
													}
break;
case 59:
#line 945 "new.y"
	{
														
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char));
														code=createCode(yystack.l_mark[-2].attrid->name,"!=",yystack.l_mark[0].attrid->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														/*printf("[%s]",code);*/
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=condCode;
													}
break;
case 60:
#line 956 "new.y"
	{
														
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+sizeof(yystack.l_mark[-2].attrid->name)+3*sizeof(char));
														code=createCode(yystack.l_mark[-2].attrid->name,"==",yystack.l_mark[0].attrid->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														/*printf("[%s]",code);*/
														yyval.ccode=(struct ccode *)malloc(sizeof(struct ccode));
														yyval.ccode->head=condCode;
													}
break;
case 61:
#line 1021 "new.y"
	{;}
break;
case 62:
#line 1022 "new.y"
	{;}
break;
case 63:
#line 1024 "new.y"
	{yyval.attrid->name=yystack.l_mark[0].attrid->name;}
break;
case 64:
#line 1025 "new.y"
	{yyval.attrid->name=yystack.l_mark[0].attrid->name;}
break;
case 65:
#line 1027 "new.y"
	{yyval.ccode=yystack.l_mark[-1].ccode;}
break;
case 66:
#line 1029 "new.y"
	{
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+6*sizeof(char));
														code[0]='s'; code[1]='c'; code[2]='a'; code[3]='n';
														code[4]=' ';
														int l=strlen(yystack.l_mark[0].attrid->name);
														
														int i=0;
														char *pa=yystack.l_mark[0].attrid->name;
														while(i<l){
															code[i+5]=pa[i];
															i++;
														}
														/*printf("code :%s\n",code);*/
														if(yystack.l_mark[0].attrid->head==NULL){
															yystack.l_mark[0].attrid->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[0].attrid->head->code=code;
															yystack.l_mark[0].attrid->head->next=NULL;
															/*printf("aw");*/
														}
														else{
															appendcode(yystack.l_mark[0].attrid->head,code);
														
														}
														yyval.ccode->head=yystack.l_mark[0].attrid->head;
														/*printcode($$->head);*/
														
													
													}
break;
case 67:
#line 1057 "new.y"
	{
														char *code=(char *)malloc(sizeof(yystack.l_mark[0].attrid->name)+6*sizeof(char));
														code[0]='s'; code[1]='c'; code[2]='a'; code[3]='n';
														code[4]=' ';
														int l=strlen(yystack.l_mark[0].attrid->name);
														
														int i=0;
														char *pa=yystack.l_mark[0].attrid->name;
														while(i<l){
															code[i+5]=pa[i];
															i++;
														}
														/*printf("code :%s\n",code);*/
														if(yystack.l_mark[-2].ccode->head==NULL){
															yystack.l_mark[-2].ccode->head=(struct code *)malloc(sizeof(struct code));
															yystack.l_mark[-2].ccode->head->code=code;
															yystack.l_mark[-2].ccode->head->next=NULL;
															/*printf("aw");*/
														}
														else{
															appendcode(yystack.l_mark[-2].ccode->head,code);
														
														}
														yyval.ccode->head=yystack.l_mark[-2].ccode->head;
													}
break;
#line 1976 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
