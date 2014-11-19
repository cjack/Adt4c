EXECUTABLE_1 = c_version_list
EXECUTABLE_2 = adt_version_list
SOURCE_C = benchmark_checker.c
SOURCE_ADT = benchmark_adt.c
CC = gcc
CFLAG = -o
OTHER_FLAG = -O3

all : $(EXECUTABLE_1) $(EXECUTABLE_2)
	./$(EXECUTABLE_1)
	./$(EXECUTABLE_2)
	make clean

$(EXECUTABLE_1) :
	$(CC) $(OTHER_FLAG) $(SOURCE_C) $(CFLAG) $(EXECUTABLE_1)

$(EXECUTABLE_2) :
	$(CC) $(OTHER_FLAG) $(SOURCE_ADT) $(CFLAG) $(EXECUTABLE_2)

clean :
	rm -rf  $(EXECUTABLE_1) $(EXECUTABLE_2) *.o

Go :
	gcc -O3 benchmark_checker.c -o c_version
	gcc -O3 benchmark_adt.c -o adt_version

install : adtpp
	cp adt.exe $(HOME)/bin/

Free :
	gcc -O3 free_adt.c -o free_adt
	gcc -O3 free_c.c -o free_c

Bin :
	gcc -O3 temp.c -o temp
	gcc -O3 execute.c -o execuate
	./execuate
