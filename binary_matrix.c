/*
 * binary_matrix.c
 * Kavitha Dhanukodi / 912916237
 * An implementation of a Binary Matrix
 */


#include "binary_matrix.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Input:
 * 	int num_rows, number of rows of the matrix
 * 	int num_cols, number of columns of the matrix
 * Output:
 * 	A Binary Matrix
 * Summary:
 * 	Dynamically allocates a new BinaryMatrix with num_rows rows
 *	and num_cols columns and initializes each entry to 0
 */
BinaryMatrix* ConstructBinaryMatrix(int num_rows, int num_cols) 
{
	/*Makes sure the number of rows and columns are not negative*/
	if ((num_rows <= 0) || (num_cols <= 0))
	{
		printf("Error in CreateMatrix: number of rows and columns must be positive\n");
		exit(0);
	}
	
	BinaryMatrix* matrix;
	/*Dynamically allocates memory for the entire data type*/
	matrix = (BinaryMatrix*) malloc(sizeof(BinaryMatrix));
	/*Initialises the number of rows of the matrix*/
	matrix->num_rows = num_rows;
	/*Initialises the number of columns of the matrix*/
	matrix->num_cols = num_cols;
	int i;
	/*Allocates memory for and initialises an array of pointers*/
	matrix->data = calloc(sizeof(int*), num_rows);
	for (i = 0; i < num_rows; i++)
	{
		matrix->data[i] = calloc(sizeof(int), num_cols);
	}
	return matrix;
}

/*
 * Input:
 * 	BinaryMatrix* M, a pointer to a matrix
 * 	int row, an x-coordinate or row number of entry
 * 	int col, a y-coordinste or column number of entry
 * 	int content, content entry is updated to
 * Summary:
 * 	Updates the entry with the coordinate (row,col) with
 * 	content
 */
void DeleteBinaryMatrix(BinaryMatrix* M) 
{
	/*Frees memory of each row first*/
	for(int i = 0; i < M->num_rows; i++)
	{
		free(M->data[i]);
	}
	/*Frees memory of array of pointers next*/
	free(M->data);
	/*Lastly, frees memory of entire matrix*/
	free(M); 
}

/*
 * Input:
 * 	BinaryMatrix* M, a pointer to a matrix
 * 	int row, an x-coordinate or row number of entry
 * 	int col, a y-coordinate or column number of entry
 * 	int content, content entry is updated to
 * Summary:
 * 	Updates the entry with the coordinate (row,col) with
 * 	content
 */
void UpdateEntry(BinaryMatrix* M, int row, int col, int content) 
{
	/*Checks that row and column numbers are in the matrix*/
	if((row >= M->num_rows) || (col >=  M->num_cols)){
		printf("Error in UpdateEntry: index out of bounds\n");
		exit(0);
	}
	/*Checks that content is either 0 or 1*/
	if((content != 0) && (content != 1))
	{
		printf("Error in UpdateEntry: content must be 0 or 1\n");
		exit(0);
	}
	M->data[row][col] = content;
		
}
/*
 * Input:
 *      BinaryMatrix* M, a pointer to a matrix
 *      int row, row number of entry
 *      int col, column number of entry
 * Output:
 *      0 for false or 1 for true
 * Summary:
 *      Returns true if row and col are valid indices for *M and
 *      false otherwise
 */
int IsMatrixIndex(BinaryMatrix* M, int row, int col) 
{

	/*Checks to make sure matrix has valid memory*/
	if(M == NULL)
	{
		printf("IsMatrixIndex Error: NULL parameter passed\n");
		exit(0);
	}
	/*Checks that row and col are positive and in the matrix*/
	if(((row >= 0) && (col >= 0)) && ((row < M->num_rows) && (col <  M->num_cols))){
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Input:
 * 	BinaryMatrix* M, a pointer to a matrix
 * Summary:
 * 	Prints the entries of *M, one row at a time
 */
void PrintMatrix(BinaryMatrix* M) 
{

	for (int i = 0; i < M->num_rows; i++)
	{
		for(int j = 0; j < M->num_cols; j++)
		{
			printf("%d", M->data[i][j]);
		}
		printf("\n");
	}
}
