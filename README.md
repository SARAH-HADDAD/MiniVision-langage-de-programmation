# Projet-de-compilation-du-langage-MiniVision
## cmd pour lexicale: 
### flex lexical.l           
### gcc lex.yy.c -o MonTP -ll (-lfl pour windows)
### ./MonTP < programme.txt 
## cmd pour syntaxique: 
### flex lexical.l    
### bison -d syntax.y        
### gcc lex.yy.c syntax.tab.c -o TP -ll -ly (-lfl pour windows)
### ./TP < programme.txt 
## debugging tools:
### bison -v grammar.y -o parser.c > output.txt

git add .  
git commit -m " "  
git push -u origin main
