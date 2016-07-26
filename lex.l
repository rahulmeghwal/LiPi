%{

int lineno;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
void yyerror(char *);
extern YYSTYPE yylval;

int errorline=0;
long int value;
int type;
													
struct attrid* install_id(char* name,int l,int r,long int value,int type);
struct attrlit* install_lit(char *name,int value,int type);


%}

letter [a-zA-Z]
digit [0-9]
ops [%/+*)(=-]
comma [,]

%% 
"fx " 											{ return FX; 		}
"main"											{ return MAIN; 		}
"print"											{ return PRINT; 	}
"let" 											{ return LET; 		}
"int"											{ return INT; 		}
"point"											{ return POINT; 	}
"char" 											{ return CHAR; 		}
"return" 										{ return RETURN; 	}
"scan"	 										{ return SCAN;	 	}
"if"											{ return IF;   		}	
"else"											{ return ELSE; 		}
"while"											{ return WHILE; 	}
{ops}											{ return yytext[0]; }
"{"							 					{ return OCB; 		}
"}"  											{ return CCB; 		}
"[" 											{ return OSB; 		}
"]"  											{ return CSB; 		}
"<"												{ return RL; 		}
">"												{ return RG; 		}
"<="											{ return RLE; 		}
">="											{ return RGE; 		}
"=="											{ return RE; 		}
"!="											{ return RNE; 		}
"\n"											{ lineno++;	}
[ \t]+											{ ; 				}

{letter}({letter}|{digit})* 					{	
													char *s=malloc(yyleng);
													strcpy(s,yytext);
													yylval.attrid=install_id(s,0,1,0,VAR);
													return ID;
												}
{comma}											{ return COMMA; 	}
{digit}+										{ 	
													value=atoi(yytext);
													char *s=malloc(yyleng);
													strcpy(s,yytext);
													yylval.attrid=install_id(s,0,1,value,INT);
													return INTLIT; 	
												}		
{digit}+"."{digit}+								{ 	
													value=atof(yytext);
													type=POINT;
													char *s=malloc(yyleng);
													strcpy(s,yytext);
													yylval.attrid=install_id(s,0,1,value,POINT);
													return POINTLIT;  
												}
"'"{letter}"'"									{ 	
													value=yytext[0];
													type=CHAR;
													char *s=malloc(yyleng);
													strcpy(s,yytext);
													yylval.attrid=install_id(s,0,1,0,CHAR);
													return CHARLIT; 	
												}
";" 											{ return DELIMITER; }
. 												{  printf("\nUnexpected character Line No:%d\n",lineno); }

%%
struct attrid* install_id(char* name,int l,int r,long int value,int type)
{
	struct attrid* attrs=malloc(sizeof(struct attrid));
	attrs->name=name;
	attrs->l=0;
	attrs->r=0;
	//attrs->value=value;
	//attrs->type=type;
	return attrs;
}
struct attrlit* install_lit(char *name,int value,int type)
{
	struct attrlit* attrs=malloc(sizeof(struct attrlit));
	attrs->name=name;
	
	return attrs;
}


int yywrap(void) {
 return 1;
}

