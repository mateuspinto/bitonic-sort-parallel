CC =clang
CFLAGS =-O2 -march=native
LFLAGS =-pthread
SRC =main.c
BIN =simple-parallel
WARN =-Wall

all:
	$(CC) -o $(BIN) $(CFLAGS) $(LFLAGS) $(WARN) $(SRC)

run:
	./$(BIN)