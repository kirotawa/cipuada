CC = gcc
CFLAGS = -Wall
DEPS = ../include
SRC = ../src/*            #../src/
OBJ = tests.o

%.o: %.c
	$(CC) $(CFLAGS) -I$(DEPS) -c -o $@ $<
tests: $(OBJ)
	$(CC) $(CFLAGS) -o tests tests.c $(SRC) -I$(DEPS)
clean:
	rm tests *.o

