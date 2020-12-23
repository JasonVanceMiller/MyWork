#Makefile for NET

ADT_NAME = Net
ADT2_NAME = Matrix

SOURCES = $(ADT_NAME).c $(ADT2_NAME).c $(ADT_NAME)Client.c
OBJECTS = $(ADT_NAME).o $(ADT2_NAME).o $(ADT_NAME)Client.o
HEADERS = $(ADT_NAME).h $(ADT2_NAME).h 
EXEBIN  = $(ADT_NAME)Client
FLAGS   = -std=c99 -Wall

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS) -lm

$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)

clean : 
	rm -f $(EXEBIN) $(OBJECTS)

check:
	valgrind --leak-check=full $(EXEBIN)



