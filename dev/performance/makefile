EXECUTABLE = adtpp
CC = gcc
LEX = parser.l
YACC = parser.y
YFLAG = -d
OFLAG = -o
ADT_SUPPORT = adtpp.c
ADT_MASTER = adt_t_master
SOURCE = parser.l parser.y adtpp.c $(ADT_MASTER).c $(ADT_MASTER).h makefile

TEST = check.c adt_t.adt checkLowBits.c
TEST_NAME = check
TEST_FLAG = -O3 -c

all : lex.yy.c y.tab.c
	cp $(ADT_MASTER).h adt_t.h
	$(CC) lex.yy.c y.tab.c $(ADT_MASTER).c $(ADT_SUPPORT) $(OFLAG) $(EXECUTABLE)
	make clean

lex.yy.c : $(LEX)
	flex $(LEX)

y.tab.c : $(YACC)
	yacc $(YFLAG) $(YACC)

clean : 
	rm -rf lex.yy.c y.tab.c y.output y.tab.h a.out a.exe *.o

test : adtpp $(ADT_MASTER).c $(ADT_MASTER).h adt_t.adt
	diff $(ADT_MASTER).h adt_t.h

dist : $(SOURCE) $(TEST)
	zip adt_archive $(SOURCE) $(TEST)


testW :
	$(CC) $(TEST_FLAG) $(TEST_NAME).c
	$(CC) -o $(TEST_NAME) $(TEST_NAME).o
	./$(TEST_NAME)
testL :
	$(CC) $(TEST_FLAG) $(TEST_NAME).c
	$(CC) -o $(TEST_NAME) $(TEST_NAME).o 
	./$(TEST_NAME)

bits : 
	gcc -c checkLowBits.c
	gcc -o checkLowBits checkLowBits.o
	./checkLowBits

Go :
	make
	./adtpp adt_t.adt
	make testW


