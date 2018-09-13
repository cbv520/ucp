CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
DFLAGS = -DDEBUG
OBJ = linked_list.o
EXEC_DEFAULT = TurtleGraphics

$(EXEC_DEFAULT) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC_DEFAULT)

linked_list.o : linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

clean :
	rm -f $(EXEC_DEFAULT) $(OBJ)