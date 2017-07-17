/*
 * conways_game_of_life.c
 * Kavitha Dhanukodi / 912916237
 * An implementation of Conways Game of Life
 */

#include "conways_game_of_life.h"

#include <stdio.h>
#include <stdlib.h>

#include "binary_matrix.h"
#include "coordinate.h"

/*
 * Input:
 *      int num_rows, the number of rows in the game
 *      int num_cols, the number of cols in the game
 * Output:
 *      Returns a BinaryMatrix* that corresponds to the
 *      first generation game state
 * Summary:
 *      Returns the game state of the first generation
 */
BinaryMatrix* FirstGeneration(int num_rows, int num_cols, List* seed_cells)
{
	BinaryMatrix* matrix;
	matrix = ConstructBinaryMatrix(num_rows, num_cols);
	ListNode* current;
	current = seed_cells->head;
	while (current != (ListNode*) NULL)
	{
		UpdateEntry(matrix, current->data.x, current->data.y, 1);
		current = current->next;
	}
	return matrix;
}
/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 * Output:
 *      Returns a BinaryMatrix*, a pointer to a game state
 * Summary:
 *      Calculates the game state of the generation directly
 *      after *generation and returns it
 */
BinaryMatrix* NextGeneration(BinaryMatrix* generation)
{
	BinaryMatrix* next_gen;
	Coordinate coord;
	List* neighbor_list;
	next_gen = ConstructBinaryMatrix(generation->num_rows, generation->num_cols);
	int i, j, neighbors = 0, element;
	for (i = 0; i < generation->num_rows; i++)
	{
		for(j = 0; j < generation->num_cols; j++)
		{
			element = generation->data[i][j];
			coord.x = i;
			coord.y = j;
			neighbor_list = NeighboringCells(coord, generation);
			neighbors = LivingNeighbors(generation, neighbor_list);
			/*A cell is born in the next generation if it was dead, that is, the entry was 0, and had 3 neighbors*/
			if ((element == 0) && (neighbors == 3))
			{
				next_gen->data[i][j] = 1;
			}
			else if (element == 1)
			{
				/*A cell survives if it was alive and had either 2 or 3 neighbors*/
				if ((neighbors == 2) || (neighbors == 3))
				{
					next_gen->data[i][j] = 1;
				}
				/*Else if a cell was alive and does not have 2 or 3 neighbors, it dies*/
				else
				{
					next_gen->data[i][j] = 0;
				}
			}
			else
			{
				next_gen->data[i][j] = 0;
			}
		}
	}
	return next_gen;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      Coordinate coord, a cell of the game state
 * Output:
 *      Returns true if the cell is Live
 * Summary:
 *      Checks if coord is a valid index of *generation and
 *      its corresponding cell is Live
 */
int Live(BinaryMatrix* generation, Coordinate coord) 
{
	/*If the entry at coordinate coord is 1, the cell is live and true is 
 	 *returned*/	 
	if ((IsMatrixIndex(generation, coord.x, coord.y)) && (generation->data[coord.x][coord.y] == 1))
	{ 
		return 1;
	}
	else
	{
		return 0;
	}
}
		

/*
 * Input:
 *      Coordinate coord, a cell of the game state
 *      BinaryMatrix* generation, a pointer to a game state
 * Output:
 *      Returns a List* to a List of neighboring cells
 * Summary:
 *      Calculates neighboring cells of *generation at coord and
 *      returns them as a List
 */
List* NeighboringCells(Coordinate coord, BinaryMatrix* generation) {
	List* result = ConstructList();
	int i, j;
	if (result == (List*) NULL) {
		printf("Error in NeighboringCells: List construction failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			Coordinate coord_neighbor = ConstructCoordinate(coord.x + i, coord.y + j);
			if (IsNeighbor(coord, coord_neighbor) && IsMatrixIndex(generation, coord.x + i, coord.y + j)) {
				PushFrontList(result, coord_neighbor);
			}
		}
	}
	return result;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      List* neighbors, a List of neighbors of a coordinate
 * Output:
 *      Returns the number of neighboring cells that are Live
 
* Summary:
 *      Counts the number of Coordinates in *neighbors that
 *      correspond to live cells in *generation
 */
int LivingNeighbors(BinaryMatrix* generation, List* neighbors) 
{

	int count = 0;
	ListNode* current;
	current = neighbors->head;
	while (current != (ListNode*) NULL){
		/*Increments the count if the entry at the coordinate has
 		 *content of 1*/
		if (Live(generation, current->data)){
			count++;
		}
		current = current->next;
	}
	return count;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      FILE* fp, a file opened for writing
 * Summary:
 *      Prints the game state of *generation to *fp
 */
void PrintGeneration(BinaryMatrix* generation, FILE* fp) {
	int i, j;
	for (i = 0; i < generation->num_rows; i++) {
		for (j = 0; j < generation->num_cols; j++) {
			if (Live(generation, ConstructCoordinate(i, j))) {
				fprintf(fp, "#");
			} 
			else {
				fprintf(fp, " ");
			}
		}
		fprintf(fp, "\n");
	}
	return;
}
