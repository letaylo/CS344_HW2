CC = g++
FLAGS = -g
SRC = main.cpp sorts.cpp
OBJ = main.o sorts.o
EXEC = test_me

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJ)

.cpp.o: 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJ)

