DEBUG=yes
CC=g++
EXEC=./Donkey
SRC= $(wildcard ./src/*)
OBJ= $(wildcard ./bin/*.o)
LIB= $(wildcard ./ext/)
USED_LIB= -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

all: $(EXEC)

create: $(OBJ)
	$(CC) -g -o $(EXEC) $(SRC) $(USED_LIB)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)
