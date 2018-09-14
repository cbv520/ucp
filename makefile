CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
FLAGS_DEBUG = -DDEBUG
FLAGS_SIMPLE = -DSIMPLE
OBJ = turtle_graphics.o effects.o file_io.o drawer.o linked_list.o strings.o
OBJ_SIMPLE = turtle_graphics.o effects.o file_io.o drawer_simple.o \
             linked_list.o strings.o
OBJ_DEBUG = turtle_graphics.o effects.o file_io_debug.o drawer.o \
            linked_list.o strings.o
EXEC_DEFAULT = TurtleGraphics
EXEC_SIMPLE	 = TurtleGraphicsSimple
EXEC_DEBUG = TurtleGraphicsDebug

default: $(OBJ)
	$(CC) $(OBJ) -lm -o $(EXEC_DEFAULT)

simple: $(OBJ_SIMPLE)
	$(CC) $(OBJ) -lm -o $(EXEC_SIMPLE)

debug: $(OBJ_DEBUG)
	$(CC) $(OBJ) -lm -o $(EXEC_DEBUG)

turtle_graphics.o: turtle_graphics.c drawer.h linked_list.h \
                   file_io.h error.h
	$(CC) $(CFLAGS) -c turtle_graphics.c

drawer_simple.o: drawer.c drawer.h linked_list.h file_io.h effects.h \
                 error.h strings.h
	$(CC) $(CFLAGS) $(FLAGS_SIMPLE) -c drawer.c

drawer.o: drawer.c drawer.h linked_list.h file_io.h effects.h \
          error.h strings.h
	$(CC) $(CFLAGS) -c drawer.c

file_io.o: file_io.c file_io.h linked_list.h drawer.h error.h
	$(CC) $(CFLAGS) -c file_io.c

file_io_debug.o: file_io.c file_io.h linked_list.h drawer.h error.h
	$(CC) $(CFLAGS) $(FLAGS_DEBUG) -c file_io.c

strings.o: strings.c strings.h
	$(CC) $(CFLAGS) -c strings.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

effects.o: effects.c effects.h
	$(CC) -c effects.c

clean :
	rm -f $(EXEC_DEFAULT) $(EXEC_SIMPLE) $(EXEC_DEBUG) $(OBJ)
