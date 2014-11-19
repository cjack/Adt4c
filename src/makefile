EXECUTABLE = adtpp
CC = gcc
LEX = parser.l
YACC = parser.y
YFLAG = -d
OFLAG = -o
ADT_SUPPORT = adtpp.c
ADT_MASTER = adt_master
SOURCE = parser.l parser.y adtpp.c $(ADT_MASTER).adt $(ADT_MASTER).h makefile

all : lex.yy.c y.tab.c
	cp $(ADT_MASTER).h adt_t.h
	$(CC) lex.yy.c y.tab.c $(ADT_SUPPORT) $(OFLAG) $(EXECUTABLE)
	make clean

lex.yy.c : $(LEX)
	flex $(LEX)

y.tab.c : $(YACC)
	yacc $(YFLAG) $(YACC)

clean :
	rm -rf lex.yy.c y.tab.c y.output y.tab.h a.out a.exe *.o

test : adt_t.h $(ADT_MASTER).h
	diff $(ADT_MASTER).h adt_t.h

dist : $(SOURCE)
	zip adt_archive $(SOURCE)

install : $(EXECUTABLE)
	cp $(EXECUTABLE) $(HOME)/bin/
