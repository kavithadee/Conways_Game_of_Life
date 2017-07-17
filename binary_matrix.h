/*
 * binary_matrix.h
 * Kavitha Dhanukodi / 912916237
 * An implementation of a Binary Matrix
 */

#ifndef _BINARY_MATRIX_H_
#define _BINARY_MATRIX_H_

typedef struct{
	int num_rows;
	int num_cols;
	int** data;
}BinaryMatrix;

/*
 * Input:
 * 	int num_rows, number of rows of the matrix
 * 	int num_cols, number of columns of the matrix
 * Output:
 * 	A Binary Matrix
 * Summary:
 * 	Dynamically allocates a new BinaryMatrix with num_rows rows
 * 	and num_cols columns and initializes each entry to 0
 */
BinaryMatrix* ConstructBinaryMatrix(int num_rows, int num_cols);

/*
 * Input:
 * 	BinaryMatrix* M, a pointer to a matrix
 * Summary:
 * 	Deallocates the memory used for *M
 */
void DeleteBinaryMatrix(BinaryMatrix* M);

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
void UpdateEntry(BinaryMatrix* M, int row, int col, int content);

/*
 * Input:
 * 	BinaryMatrix* M, a pointer to a matrix
 * 	int row, row number of entry
 * 	int col, column number of entry
 * Output:
 * 	0 for false or 1 for true
 * Summary:
 * 	Returns true if row and col are valid indices for *M and
 * 	false otherwise
 */
int IsMatrixIndex(BinaryMatrix* M, int row, int col);

/*
 * Input:
 * 	BinaryMatrix* M, a pointer to a matrix
 * Summary:
 * 	Prints the entries of *M, one row at a time
 */
void PrintMatrix(BinaryMatrix* M);


#endif /* _BINARY_MATRIX_H_ */
