CC =clang
OFLAGS =-O2 -march=native
GFLAGS =-g2
LFLAGS =-pthread
SRC =main.c
BIN =simple-parallel
WARN =-Wall

all:
	$(CC) -o $(BIN) $(OFLAGS) $(LFLAGS) $(WARN) $(SRC)

debug:
	$(CC) -o $(BIN) $(GFLAGS) $(LFLAGS) $(WARN) -fsanitize=thread $(SRC)

run:
	./$(BIN)