/*
 * coordinate.c
 * Kavitha Dhanukodi / 912916237
 * The program deals with Cartesian coordinates by constructing them, checking
 * if two coordinates are neighbors, and swapping the x and y value of the 
 * coordinate.
 */



#include "coordinate.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Input:
 *      int x, an x-coordinate
 *      int y, a y-coordinate
 * Output:
 *      A Coordinate
 * Summary:
 *      Initializes a Coordinate to (x,y)
 */
Coordinate ConstructCoordinate(int x, int y) {

	Coordinate coordinate;
	coordinate.x = x;
	coordinate.y = y;
	return coordinate;
}

/*
 * Input:
 * 	Coordinate C1, a coordinate
 * 	Coordinate C2, another coordinate
 * Output:
 * 	true if C2 is a neighbor of C1, false otherwise
 * Summary:
 * 	Checks if C1 and C2 are neighbors, that is, if they
 * 	are in adjacent squares (including squares that are 
 * 	diagonally adjacent) and not equal
 */
int IsNeighbor(Coordinate C1, Coordinate C2) {
	
	/*Returns false if coordinates are equal*/
	if ((C1.x == C2.x) && (C1.y == C2.y))
	{
		return 0;
	}
	/*Returns true if coordinates are vertically adjacent*/
	else if ((C1.x == C2.x) && ((C1.y == C2.y + 1) || (C1.y == C2.y - 1)))
	{
		return 1;
	}
	/*Returns true if coordinates are horizontally adjacent*/
	else if ((C1.y == C2.y) && ((C1.x == C2.x + 1) || (C1.x == C2.x - 1)))
	{
		return 1;
	}
	/*Returns true if coordinates are diagonally adjacent*/
	else if (pow((C1.x - C2.x), 2) + pow((C1.y - C2.y), 2) == 2)
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
 * 	Coordinate* C, a pointer to a Coordinate
 * Summary:
 * 	Swaps the entries of the Coordinate pointed to by C
 */
void SwapCoordinates(Coordinate* C) {

	int temp = 0;
	temp = C->x;
	C->x = C->y;
	C->y = temp;

}

