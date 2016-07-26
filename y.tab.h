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
extern YYSTYPE yylval;
