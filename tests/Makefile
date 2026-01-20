CC = gcc
CFLAGS = -Wall
DEPS = ../include
SRC = ../src/*
OBJ = tests.o

%.o: %.c
	$(CC) $(CFLAGS) -I$(DEPS) -c -o $@ $<
tests: $(OBJ)
	$(CC) $(CFLAGS) -o test_runner tests.c $(SRC) -I$(DEPS)
	@echo
	@echo "Running tests..."
	./test_runner
	@echo
clean:
	rm test_runner *.o

