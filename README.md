### flex lexical.l    
### bison -d syntax.y        
### gcc lex.yy.c syntax.tab.c -o TP -ll -ly (-lfl pour windows)
### ./TP < programme.txt 

## debugging tools:
### bison -v grammar.y -o parser.c > output.txt
