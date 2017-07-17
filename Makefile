CC=gcc
CFLAGS= -Wall -lm

all:	coordinate_driver binary_matrix_driver list_driver conways_game_of_life_driver

clean: 
	rm -f *.o
	rm -f *_driver

binary_matrix_driver: binary_matrix_driver.o binary_matrix.o
	$(CC) $(CFLAGS) -o binary_matrix_driver binary_matrix_driver.o binary_matrix.o

coordinate_driver: coordinate_driver.o coordinate.o
	 $(CC) $(CFLAGS) -o coordinate_driver coordinate_driver.o coordinate.o

conways_game_of_life_driver: conways_game_of_life_driver.o conways_game_of_life.o list.o coordinate.o binary_matrix.o
	 $(CC) $(CFLAGS) -o conways_game_of_life_driver conways_game_of_life_driver.o conways_game_of_life.o coordinate.o list.o binary_matrix.o 

list_driver: list_driver.o list.o coordinate.o
	$(CC) $(CFLAGS) -o list_driver list_driver.o list.o coordinate.o

binary_matrix_driver.o: binary_matrix_driver.c
	$(CC) $(CFLAGS) -c binary_matrix_driver.c

coordinate_driver.o: coordinate_driver.c
	$(CC) $(CFLAGS) -c coordinate_driver.c

conways_game_of_life_driver.o: conways_game_of_life_driver.c
	$(CC) $(CFLAGS) -c conways_game_of_life_driver.c

list_driver.o: list_driver.c
	$(CC) $(CFLAGS) -c list_driver.c

binary_matrix.o: binary_matrix.c
	$(CC) $(CFLAGS) -c binary_matrix.c

coordinate.o: coordinate.c
	$(CC) $(CFLAGS) -c coordinate.c

conways_game_of_life.o: conways_game_of_life.c 
	$(CC) $(CFLAGS) -c conways_game_of_life.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c
