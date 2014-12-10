# makefile for adtpp tool which supports algebraic data types
# for C by preprocessing a foo.adt file to produce a foo.h
# file to be #included in C code

EXECUTABLE = adtpp
ADTPP = ./$(EXECUTABLE)
# Generate VERSION line with: date +'VERSION = 1.%y%m%d'
# or in vim: :/^VERSION /!date +'VERSION = 1.\%y\%m\%d'
VERSION = 1.141210
CC = gcc
LEX = parser.l
YACC = parser.y
YFLAG = -d
OFLAG = -o
CFLAG = -Wall -Wformat
ADT_SUPPORT = adtpp.c
# to make adtpp we need adt_t.h, which is generated from adt_t.adt
# by adtpp.  To avoid the cyclic dependency and do some basic
# testing we provide a master version of adt_t.h.
ADT_MASTER = adt_master
SOURCE = parser.l parser.y adtpp.c $(ADT_MASTER).adt $(ADT_MASTER).h makefile ../doc/Documentation.pdf

# adtpp takes a foo.adt file and generates a foo.h file
# This generic rule is used here for testing and can be copied
# to user-defined makefiles for convenience
%.h : %.adt
	$(ADTPP) $<

$(EXECUTABLE) : lex.yy.c y.tab.c $(ADT_MASTER).h
	cp $(ADT_MASTER).h adt_t.h
	$(CC) $(CFLAG) -DADTPP_VERSION=\"$(VERSION)\" lex.yy.c y.tab.c $(ADT_SUPPORT) $(OFLAG) $(EXECUTABLE)
	make clean

lex.yy.c : $(LEX)
	flex $(LEX)

y.tab.c : $(YACC)
	yacc $(YFLAG) $(YACC)

clean :
	rm -rf lex.yy.c y.tab.c y.output y.tab.h adt_t.h a.out *.exe *.o

# test currently just checks that the system bootstraps itself
# consistently.  ie, when it generates adt_t.h from adt_t.adt
# it gets a file identical to $(ADT_MASTER).h
# XXX should do some other testing also
test : adt_t.adt $(ADT_MASTER).h $(EXECUTABLE)
	./$(EXECUTABLE) adt_t.adt
	diff $(ADT_MASTER).h adt_t.h

dist : $(SOURCE)
	tar -cvzf adt_archive_$(VERSION).tar.gz $(SOURCE)

install : $(EXECUTABLE)
	cp $(EXECUTABLE) $(HOME)/bin/
