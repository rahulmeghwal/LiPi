%{

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
//int look_in_symtab(char *name);
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
	
%}


%union{
	
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
		
};
%start file
%token VAR
%token FX
%token MAIN
%token PRINT
%token LET
%token INT
%token POINT
%token CHAR
%token RETURN
%token IF
%token ELSE
%token WHILE
%token OCB
%token CCB
%token OSB
%token CSB
%token RL
%token RG
%token RLE
%token RGE
%token RE
%token RNE
%token COMMA
%token DELIMITER
%token SCAN
%token FUNCTION
%token <attrid> ID
%token <attrid> INTLIT
%token <attrid> POINTLIT
%token <attrid> CHARLIT

%type <attrid> expr term factor var fvar assign 
%type <attrid> XID lits
%type <ccode> call actual formal aparameters fparameters var1 stmt block funcblock type stream declare sstream input func funcmain funcs return condition compare wloop file program
 



%%
file	: program									{printcode($1->head);}
program	: funcs funcmain 							{$$->head=addcode($1->head,$2->head);}
		;											
funcs	: funcs func 								{
														if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}
													}
		|											{{$$=(struct ccode *)malloc(sizeof(struct ccode));$$->head=NULL;}}
		;
func	: FX ID '(' fparameters ')' funcblock 		{
																				
														char *n=$2->name;
														rcode=add_to_symtab($2->name,FUNCTION,-1,-1,'0',-1,-1);
														if(!rcode){
														 	printf("\n\nFunction name (%s) already taken.\n",$2->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	exit(0);
														}
														char *funcheader=(char *)malloc(sizeof($2->name)+2*sizeof(char));
														char *funcname=$2->name;
														int l=strlen($2->name);
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
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														funcCode->next=addcode($4->head,$6->head);
														$$->name=$2->name;
														$$->head=funcCode;
													    //printcode($$->head);
														//else
														//printf("%s :\n",$2->name);
														//printcode($4->head);
														//printcode($6->head);														 
														// $$=$2;
														
														
													}
		;
fparameters : formal								{$$=$1;}
			|										{$$=(struct ccode *)malloc(sizeof(struct ccode));$$->head=NULL;}
			;
formal	: fvar										{

 															
														char *code=(char *)malloc(sizeof($1->name)+6*sizeof(char));
														code[0]='f'; code[1]='e'; code[2]='t'; code[3]='c';
														code[4]='h';
														code[5]=' ';
														
														int l=strlen($1->name);
														
														int i=0;
														char *pa=$1->name;
														while(i<l){
															code[i+6]=pa[i];
															i++;
														}
														//printf("code :%s\n",code);
														if($1->head==NULL){
															$1->head=(struct code *)malloc(sizeof(struct code));
															$1->head->code=code;
															$1->head->next=NULL;
															//printf("aw");
														}
														else{
															appendcode($1->head,code);
														
														}
														$$->head=$1->head;
														//printcode($$->head);
													
														
														
															//printf("allocate %s %d\n",$1->name,size);

													}
		| formal COMMA fvar							{
														char *code=(char *)malloc(sizeof($1->name)+6*sizeof(char));
														code[0]='f'; code[1]='e'; code[2]='t'; code[3]='c';
														code[4]='h';
														code[5]=' ';
														
														int l=strlen($3->name);
														
														int i=0;
														char *pa=$3->name;
														while(i<l){
															code[i+6]=pa[i];
															i++;
														}
														//printf("code :%s\n",code);
														if($1->head==NULL){
															$1->head=(struct code *)malloc(sizeof(struct code));
															$1->head->code=code;
															$1->head->next=NULL;
															//printf("aw");
														}
														else{
															appendcode($1->head,code);
														
														}
														$$->head=$1->head;

													}
		;

funcblock	: OCB stmt return CCB					{
														$2->head=addcode($2->head,$3->head);
														$$=$2;
													}
			;
return	: RETURN expr DELIMITER					{
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														char *code=(char *)malloc(sizeof($2->name)+8*sizeof(char));
														code[0]='r'; code[1]='e'; code[2]='t'; code[3]='u';
														code[4]='r'; code[5]='n'; code[6]=' '; 
														char *pa=$2->name;
														int i=0,l=strlen(pa);
														while(i<l){
															code[i+7]=pa[i];
															i++;
														}
														struct code *retCode= (struct code *)malloc(sizeof(struct code));
														retCode->code=code;
														retCode->next=NULL;
														
														$$->head=addcode($2->head,retCode);
														
														
														
//														$$->head=NULL;//addcode($2->code,$1->code);
													}

		|										    {
														char *code=(char *)malloc(8*sizeof(char));
														code[0]='r'; code[1]='e'; code[2]='t'; code[3]='u';
														code[4]='r'; code[5]='n'; code[6]=' '; 
														
														struct code *retCode= (struct code *)malloc(sizeof(struct code));
														retCode->code=code;
														
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=retCode;
														
													}
		; 

funcmain: FX MAIN '(' fparameters ')' funcblock 	{	

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
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														funcCode->next=addcode($4->head,$6->head);
														$$->head=funcCode;
														//printcode($$->head);
													
													//	printf("\nmain:\n");
													//	printcode($5->head);
													}														 
		;
block	: OCB stmt CCB								{$$=$2;}
		;
stmt	: stmt declare DELIMITER					{
														if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}
													}
		| stmt assign DELIMITER 					{
														if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}
														//$$->head=$2->head;
													}
		| stmt call DELIMITER						{
														if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}
														//$$->head=$2->head);
													}
		| stmt input DELIMITER						{
														if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}

													}
		| stmt compare  							{
														if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}

													}
		| stmt wloop								{
															if(!$1){
															//printf("Yes");
															$$=(struct ccode *)malloc(sizeof(struct ccode));
															$$->head=$2->head;
														}
														else{
															$$->head=addcode($1->head,$2->head);
														}

													}
		|											{
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=NULL;
													}
		;
declare	: type stream 								{$$=$2;}
		;

type	: INT 										{ vartype=INT;}
		| CHAR 										{ vartype=CHAR;}
		| POINT										{ vartype=POINT;}
		;
stream	: var										{
														int size=16;
														 if(vartype==INT)
														 	size=8;
														 else if(vartype==POINT)
														 	size=16;
														 else if(vartype==CHAR)
														 	size=2;
															
														char *code=(char *)malloc(sizeof($1->name)+12*sizeof(char));
														code[0]='a'; code[4]='c'; code[1]='l'; code[5]='a';
														code[2]='l'; code[6]='t'; code[3]='o'; code[7]='e';
														code[8]=' ';
														int l=strlen($1->name);
														
														int i=0;
														char *pa=$1->name;
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
														 	
														
														//printf("code :%s\n",code);
														if($1->head==NULL){
															$1->head=(struct code *)malloc(sizeof(struct code));
															$1->head->code=code;
															$1->head->next=NULL;
															//printf("aw");
														}
														else{
															appendcode($1->head,code);
														
														}
														$$->head=$1->head;
														//printcode($$->head);
													
														
														
															//printf("allocate %s %d\n",$1->name,size);
													}
		| stream COMMA var							{
														int size=16;
														 if(vartype==INT)
														 	size=8;
														 else if(vartype==POINT)
														 	size=16;
														 else if(vartype==CHAR)
														 	size=2;
															
														char *code=(char *)malloc(sizeof($1->name)+12*sizeof(char));
														code[0]='a'; code[4]='c'; code[1]='l'; code[5]='a';
														code[2]='l'; code[6]='t'; code[3]='o'; code[7]='e';
														code[8]=' ';
														int l=strlen($3->name);
														
														int i=0;
														char *pa=$3->name;
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
														 	
														
														//printf("code :%s\n",code);
														if($1->head==NULL){
															$1->head=(struct code *)malloc(sizeof(struct code));
															$1->head->code=code;
															$1->head->next=NULL;
															//printf("aw");
														}
														else{
															appendcode($1->head,code);
														
														}
														$$->head=$1->head;
														//printcode($$->head);
													
														
														
															//printf("allocate %s %d\n",$1->name,size);
													}
		;
fvar 	: ID										{
														 rcode=add_to_symtab($1->name,VAR,0,0,'-',0,1);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",$1->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	
														 	exit(0);
														 }
														 
														 	
														//printf("allocate %s %d\n",$1->name,size);
														$$=$1;
													}
var 	: ID										{
														 rcode=add_to_symtab($1->name,vartype,0,0,'0',0,1);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",$1->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	exit(0);
														 }
														 
														 	
														//printf("allocate %s %d\n",$1->name,size);
														$$=$1;
													}
		| array										{;}
		;
array	: ID OSB INTLIT CSB 						{ 	  
														 rcode=add_to_symtab($1->name,vartype,0,0,'0',0,$3->value);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",$1->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	
														 	exit(0);
														 }
													}
		| ID OSB INTLIT CSB OSB INTLIT CSB 			{ 	 
														 
														 int rbound=($3->value)*($6->value);
														 rcode=add_to_symtab($1->name,vartype,0,0,'0',0,rbound);
														 if(!rcode){
														 	printf("\n\nVariable (%s) already declared.\n",$1->name);
														 	printf("Line no. : %d\n\n\n",lineno);
														 	exit(0);
														 }
													}	
		;	
assign	: LET ID '=' expr  							{		
														char opr='=';
														char s=' ';
														char *code=(char *)malloc(sizeof($2->name)+3*sizeof(char)+sizeof($4->name));
														char *operator=&opr;
														char *id=$2->name,*exp=$4->name;
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
														
														if(!$4->head){
															$4->head=(struct code *)malloc(sizeof(struct code));
															$4->head->next=NULL;
															$4->head->code=code;
															
														}
														else{
															appendcode($4->head,code);		
														}
														
														$$->head=$4->head;
													}
		;
expr 	: expr '+' term 							{	
														char opr='+';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,$1->name,operator,$3->name);
														$$->name=tempVar;
														struct code *n1,*n2,*n;
														n1=$1->head; 
														n2=$3->head;
														n=addcode(n1,n2);
														//printf("asd\n");
														//printcode(n);
														//printf("asd\n");
														$$->head=n;
														if($$->head==NULL){
															$$->head=(struct code *)malloc(sizeof(struct code));
															$$->head->code=addrcode;
															$$->head->next=NULL;
															
														}
														else
															appendcode($$->head,addrcode);
														//if()
													}
														
														
													
		| expr '-' term 							{	
														char opr='-';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,$1->name,operator,$3->name);
														$$->name=tempVar;
														struct code *n1,*n2,*n;
														n1=$1->head; 
														n2=$3->head;
														n=addcode(n1,n2);
														//printf("asd\n");
														//printcode(n);
														//printf("asd\n");
														$$->head=n;
														if($$->head==NULL){
															$$->head=(struct code *)malloc(sizeof(struct code));
															$$->head->code=addrcode;
															$$->head->next=NULL;
															
														}
														else
															appendcode($$->head,addrcode);
													}
		| term										{
														$$=$1;
													}
term 	: term '*' factor 							{	
														char opr='*';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,$1->name,operator,$3->name);
														$$->name=tempVar;
														struct code *n1,*n2,*n;
														n1=$1->head; 
														n2=$3->head;
														n=addcode(n1,n2);
														//printf("asd\n");
														//printcode(n);
														//printf("asd\n");
														$$->head=n;
														if($$->head==NULL){
															$$->head=(struct code *)malloc(sizeof(struct code));
															$$->head->code=addrcode;
															$$->head->next=NULL;
															
														}
														else
															appendcode($$->head,addrcode);
													}
		| term '/' factor 							{	
														char opr='/';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,$1->name,operator,$3->name);
														$$->name=tempVar;
														struct code *n1,*n2,*n;
														n1=$1->head; 
														n2=$3->head;
														n=addcode(n1,n2);
														//printf("asd\n");
														//printcode(n);
														//printf("asd\n");
														$$->head=n;
														if($$->head==NULL){
															$$->head=(struct code *)malloc(sizeof(struct code));
															$$->head->code=addrcode;
															$$->head->next=NULL;
															
														}
														else
															appendcode($$->head,addrcode);
													}
		| term '%' factor 							{
														char opr='%';
														char *addrcode,*operator=&opr;
														char *tempVar;		
														tempVar=genTempVar();
														addrcode=genCode(tempVar,$1->name,operator,$3->name);
														$$->name=tempVar;
														struct code *n1,*n2,*n;
														n1=$1->head; 
														n2=$3->head;
														n=addcode(n1,n2);
														//printf("asd\n");
														//printcode(n);
														//printf("asd\n");
														$$->head=n;
														if($$->head==NULL){
															$$->head=(struct code *)malloc(sizeof(struct code));
															$$->head->code=addrcode;
															$$->head->next=NULL;
															
														}
														else
															appendcode($$->head,addrcode);
													}
		| factor									{ $$=$1;}
factor	: '(' expr ')'								{ $$=$2;}

		| ID										{
														if(!isDeclared($1->name)){
															printf("\n\nVariable undeclared : %s\n",$1->name);
														 	printf("Line no. : %d\n\n\n",lineno);
															
														exit(0);
														}
														//printf("%s\n",$1->name);
													
														$$=$1;
														
													}
		| call										{;}
		| INTLIT									{//$$->name=$1->name;
													}
		;
compare	: IF '(' condition ')' block				{
														char *condCode=$3->head->code;
														char *temp=genTempVar();
														char *newCode=(char *)malloc(8*sizeof(char)+sizeof(condCode)+sizeof(temp));
														newCode=createCode("if",condCode,"goto");
														newCode=createCode(newCode,temp,"");
														
														struct code *labelCode= (struct code *)malloc(sizeof(struct code));
														labelCode->code=createCode(temp,":","");
														labelCode->next=NULL;
														$5->head=addcode($5->head,labelCode);
														
														struct code *finCode= (struct code *)malloc(sizeof(struct code));
														finCode->code=newCode;
														finCode->next=$5->head;
														
														$$->head=finCode;
														
														//printf("[%s]",newCode);
														//	appendcode($5->head);
													
													}
		| IF '(' condition ')' block ELSE block		{
														char *condCode=$3->head->code;
														char *temp1=genTempVar();
														char *temp2=genTempVar();
														char *newCode=(char *)malloc(8*sizeof(char)+sizeof(condCode)+sizeof(temp1));
														newCode=createCode("if",condCode,"goto");
														newCode=createCode(newCode,temp1,"");
														
														struct code *jumpCode= (struct code *)malloc(sizeof(struct code));
														jumpCode->code=createCode("jump",temp2,":");
														jumpCode->next=NULL;
														$5->head=addcode($5->head,jumpCode);
														
														struct code *ifCode= (struct code *)malloc(sizeof(struct code));
														ifCode->code=newCode;
														ifCode->next=$5->head;
														
														
														struct code *labelCode= (struct code *)malloc(sizeof(struct code));
														labelCode->code=createCode(temp2,":","");
														labelCode->next=NULL;
														$5->head=addcode($7->head,labelCode);

														struct code *elseCode= (struct code *)malloc(sizeof(struct code));
														elseCode->code=createCode(temp1,":","");
														elseCode->next=$7->head;
														
														
														$$->head=addcode(ifCode,elseCode);
														//printcode($7->head);

													}
		;
wloop	: WHILE '(' condition ')' block				{
														char *condCode=$3->head->code;
														char *temp1=genTempVar();
														char *temp2=genTempVar();
														char *newCode=(char *)malloc(8*sizeof(char)+sizeof(condCode)+sizeof(temp1));
														newCode=createCode("if",condCode,"goto");
														newCode=createCode(newCode,temp2,"");
														
														struct code *jumpCode= (struct code *)malloc(sizeof(struct code));
														jumpCode->code=createCode("jump",temp1,":");
														jumpCode->next=NULL;
														$5->head=addcode($5->head,jumpCode);
														
														struct code *ifCode= (struct code *)malloc(sizeof(struct code));
														ifCode->code=newCode;
														ifCode->next=$5->head;

														struct code *whileCode= (struct code *)malloc(sizeof(struct code));
														whileCode->code=createCode(temp1,":","");
														whileCode->next=ifCode;
														
														struct code *labelCode= (struct code *)malloc(sizeof(struct code));
														labelCode->code=createCode(temp2,":","");
														labelCode->next=NULL;
														
														
														
														$$->head=addcode(whileCode,labelCode);
														//printcode($7->head);
													}
		;
call	: ID '(' aparameters ')'					{
													if(!search_symtab($1->name)){
														printf("\n\nIndefined reference to function %s\n",$1->name);
													 	printf("Line no. : %d\n\n\n",lineno);
														
														exit(0);
													}
														
													char *code=(char *)malloc(sizeof($1->name)+4*sizeof(char)+2*sizeof(char));
													
													code[0]='c';
													code[1]='a';
													code[2]='l';
													code[3]='l';
													code[4]=' ';
													int l=strlen($1->name);
													int i=0;
													char *pa=$1->name;
													//printf("%s %d",$1->name,l);
													strcat(code,pa);
													while(i<l){
														code[i+5]=pa[i];
														i++;
													}
													//printf("code :%s\n",code);
													
													if(!$3){
														$$->head=(struct code *)malloc(sizeof(struct code));
														$$->head->code=code;
														$$->head->next=NULL;
														//printf("Yes");
													}
													else{
														appendcode($3->head,code);
														$$=$3;
													}
													}
													
		;
aparameters : actual								{$$=$1;}
			|										{$$=NULL;}
			;
actual	: var1										{	
													char p[]="para";
													char *code=(char *)malloc(sizeof($1->name)+sizeof(p)+2*sizeof(char));
													code[0]='p';
													code[1]='a';
													code[2]='r';
													code[3]='a';
													code[4]=' ';
													int l=strlen($1->name);
													int i=0;
													char *pa=$1->name;
													while(i<l){
														code[i+5]=pa[i];
														i++;
													}
													//printf("code :%s\n",code);
													if($1->head==NULL){
														$1->head=(struct code *)malloc(sizeof(struct code));
														$1->head->code=code;
														$1->head->next=NULL;
														//printf("aw");
													}
													else{
														appendcode($1->head,code);
														
													}
													$$->head=$1->head;
													//printcode($$->head);
													
													}
		| actual COMMA var1 						{
													char p[]="para";
													char *code=(char *)malloc(sizeof($3->name)+sizeof(p)+2*sizeof(char));
													code[0]='p';
													code[1]='a';
													code[2]='r';
													code[3]='a';
													code[4]=' ';
													int l=strlen($3->name);
													int i=0;
													char *pa=$3->name;
													while(i<l){
														code[i+5]=pa[i];
														i++;
													}
													//printf("code :[%s]",code);
													appendcode($1->head,code);
													//printcode($1->head);
													}
		;
var1	: ID										{
														if(!isDeclared($1->name)){
															printf("\n\nVariable undeclared : %s\n",$1->name);
														 	printf("Line no. : %d\n\n\n",lineno);
															
														exit(0);
														}
														$$->name=$1->name;
														
													}
		| INTLIT									{	
														$$->name=$1->name;
													}
		;
condition	: XID RL XID							{
														
														char *code=(char *)malloc(sizeof($3->name)+sizeof($1->name)+3*sizeof(char));
														code=createCode($1->name,">=",$3->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														//printf("[%s]",code);
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=condCode;
													}
			| XID RG XID							{
														char *code=(char *)malloc(sizeof($3->name)+sizeof($1->name)+3*sizeof(char));
														code=createCode($1->name,"<=",$3->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														//printf("[%s]",code);
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=condCode;

													}
			| XID RLE XID							{
														
														char *code=(char *)malloc(sizeof($3->name)+sizeof($1->name)+3*sizeof(char));
														code=createCode($1->name,">",$3->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														//printf("[%s]",code);
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=condCode;
													}
			| XID RGE XID							{
														
														char *code=(char *)malloc(sizeof($3->name)+sizeof($1->name)+3*sizeof(char));
														code=createCode($1->name,"<",$3->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														//printf("[%s]",code);
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=condCode;
													}
			| XID RE XID							{
														
														char *code=(char *)malloc(sizeof($3->name)+sizeof($1->name)+3*sizeof(char));
														code=createCode($1->name,"!=",$3->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														//printf("[%s]",code);
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=condCode;
													}
			| XID RNE XID							{
														
														char *code=(char *)malloc(sizeof($3->name)+sizeof($1->name)+3*sizeof(char));
														code=createCode($1->name,"==",$3->name);
														struct code *condCode= (struct code *)malloc(sizeof(struct code));
														condCode->code=code;
														condCode->next=NULL;
														//printf("[%s]",code);
														$$=(struct ccode *)malloc(sizeof(struct ccode));
														$$->head=condCode;
													}
			;
	/*
condition	: XID RL XID							{
														$$->op=o;
														$$->l=$1->name;
														$$->r=$3->name;
														
													}	
														
			| XID RG XID							{
														char *o=malloc(2*sizeof(char));
														o[0]='<';
														o[1]='=';
														$$->op=o;
														$$->l=$1->name;
														$$->r=$3->name;
														
													}
			| XID RLE XID							{
														char *o=malloc(1*sizeof(char));
														o[0]='>';
														$$->op=o;
														$$->l=$1->name;
														$$->r=$3->name;
														
													}
			| XID RGE XID							{
														char *o=malloc(1*sizeof(char));
														oss[0]='<';
														$$->op=o;
														$$->l=$1->name;
														$$->r=$3->name;
														
													}
			| XID RE XID							{
														char *o=malloc(2*sizeof(char));
														o[0]='!';
														o[1]='=';
														$$->op=o;
														$$->l=$1->name;
														$$->r=$3->name;
														
													}
			| XID RNE XID							{
														char *o=malloc(2*sizeof(char));
														o[0]='=';
														o[1]='=';
														$$->op=o;
														$$->l=$1->name;
														$$->r=$3->name;
														
													}
			;
*/
XID		: ID										{;}//$$->name=$1->name;}
		| lits										{;}//$$->name=$1->name;}
		;
lits	: INTLIT									{$$->name=$1->name;}
		| CHARLIT 									{$$->name=$1->name;}
		;
input	: SCAN '(' sstream ')'						{$$=$3;}
		;
sstream	: ID										{
														char *code=(char *)malloc(sizeof($1->name)+6*sizeof(char));
														code[0]='s'; code[1]='c'; code[2]='a'; code[3]='n';
														code[4]=' ';
														int l=strlen($1->name);
														
														int i=0;
														char *pa=$1->name;
														while(i<l){
															code[i+5]=pa[i];
															i++;
														}
														//printf("code :%s\n",code);
														if($1->head==NULL){
															$1->head=(struct code *)malloc(sizeof(struct code));
															$1->head->code=code;
															$1->head->next=NULL;
															//printf("aw");
														}
														else{
															appendcode($1->head,code);
														
														}
														$$->head=$1->head;
														//printcode($$->head);
														
													
													}
		| sstream COMMA ID  						{
														char *code=(char *)malloc(sizeof($3->name)+6*sizeof(char));
														code[0]='s'; code[1]='c'; code[2]='a'; code[3]='n';
														code[4]=' ';
														int l=strlen($3->name);
														
														int i=0;
														char *pa=$3->name;
														while(i<l){
															code[i+5]=pa[i];
															i++;
														}
														//printf("code :%s\n",code);
														if($1->head==NULL){
															$1->head=(struct code *)malloc(sizeof(struct code));
															$1->head->code=code;
															$1->head->next=NULL;
															//printf("aw");
														}
														else{
															appendcode($1->head,code);
														
														}
														$$->head=$1->head;
													}
		;
			
%%

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

