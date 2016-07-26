calc: lex.yy.c y.tab.c
	gcc -g lex.yy.c y.tab.c -o lipi

lex.yy.c: y.tab.c lex.l
	lex -d lex.l

y.tab.c: yacc.y
	yacc -v -d yacc.y 

clean: 
	rm -f lex.yy.c y.tab.c y.tab.h lipi

