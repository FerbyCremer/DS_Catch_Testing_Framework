makefile:
.DEFAULT_GOAL := all
CC=g++
DEBUG_FLAGS=-g
COMPILE_FLAGS=-I ./nodes

all: alltests
clean:
	rm -rf *.o testaddnode testdivnode

alltests: testaddnode testdivnode
	./testaddnode && ./testdivnode

alltestsv: testaddnode testdivnode
	./testaddnode -s && ./testdivnode -s

testaddnode: test_main.o test_main.o Numeric_Node.o Addition_Node.o test_Addition_Node.o
	$(CC) $(DEBUG_FLAGS) -o testaddnode test_main.o Numeric_Node.o Addition_Node.o test_Addition_Node.o

testdivnode: test_main.o test_main.o Numeric_Node.o Addition_Node.o Division_Node.o test_Division_Node.o
	$(CC) $(DEBUG_FLAGS) -o testdivnode test_main.o Numeric_Node.o Addition_Node.o Division_Node.o test_Division_Node.o

test_Division_Node.o: tests/test_Division_Node.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) tests/test_Division_Node.cpp

test_Addition_Node.o: tests/test_Addition_Node.cpp 
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) tests/test_Addition_Node.cpp

Numeric_Node.o: nodes/Numeric_Node.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) nodes/Numeric_Node.cpp

Addition_Node.o: nodes/Addition_Node.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) nodes/Addition_Node.cpp

Division_Node.o: nodes/Division_Node.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) nodes/Division_Node.cpp

test_main.o: tests/test_main.cpp
	$(CC) -c $(DEBUG_FLAGS) $(COMPILE_FLAGS) tests/test_main.cpp