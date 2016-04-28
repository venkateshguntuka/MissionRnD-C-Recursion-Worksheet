/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void get_spiral(int rows, int columns, int k, int **input_array, int *arr, int *index)
{
	if ((rows <= 0) || (columns <= 0))
		return;

	if (rows == 1) {
		for (int j = 0; j < columns; j++)
		{
			arr[*index] = *(*(input_array + k) + k + j);
			*index += 1;
		}
		return;
	}

	if (columns == 1) {
		for (int i = 0; i < rows; i++)
		{
			arr[*index] = *(*(input_array + k + i) + k);
			*index += 1;
		}
		return;
	}
	for (int j = 0; j < columns - 1; j++)
	{
		arr[*index] = *(*(input_array + k) + k + j);
		*index += 1;
	}
	for (int i = 0; i < rows - 1; i++)
	{
		arr[*index] = *(*(input_array + k + i) + k + columns - 1);
		*index += 1;
	}
	for (int j = 0; j < columns - 1; j++)
	{
		arr[*index] = *(*(input_array + k + rows - 1) + k + columns - 1 - j);
		*index += 1;
	}
	for (int i = 0; i < rows - 1; i++)
	{
		arr[*index] = *(*(input_array + k + rows - 1 - i) + k);
		*index += 1;
	}

	get_spiral(rows - 2, columns - 2, k + 1, input_array, arr, index);
	return;
}

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *arr = (int *)malloc(rows*columns*sizeof(int));
	int index = 0;
	get_spiral(rows, columns, 0, input_array, arr, &index);
	return arr;
}


