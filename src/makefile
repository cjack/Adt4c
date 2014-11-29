EXECUTABLE = adtpp
VERSION = Ver1.141129
CC = gcc
LEX = parser.l
YACC = parser.y
YFLAG = -d
OFLAG = -o
CFLAG = -Wall -Wformat
ADT_SUPPORT = adtpp.c
ADT_MASTER = adt_master
SOURCE = parser.l parser.y adtpp.c $(ADT_MASTER).adt $(ADT_MASTER).h makefile ../doc/Documentation.pdf

all : lex.yy.c y.tab.c
	cp $(ADT_MASTER).h adt_t.h
	$(CC) $(CFLAG) lex.yy.c y.tab.c $(ADT_SUPPORT) $(OFLAG) $(EXECUTABLE)
	make clean

lex.yy.c : $(LEX)
	flex $(LEX)

y.tab.c : $(YACC)
	yacc $(YFLAG) $(YACC)

clean :
	rm -rf lex.yy.c y.tab.c y.output y.tab.h a.out *.exe *.o

test : adt_t.h $(ADT_MASTER).h
	diff $(ADT_MASTER).h adt_t.h

dist : $(SOURCE)
	tar -cvzf adt_archive_$(VERSION).tar.gz $(SOURCE)

install : $(EXECUTABLE)
	cp $(EXECUTABLE) $(HOME)/bin/
