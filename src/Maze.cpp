/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int valid_node(int *maze, int rows, int columns, int x, int y, int *visited)
{
	if (x >= 0 && x < rows&&y >= 0 && y < columns && ((*((maze + x*columns) + y)) == 1) && ((*((visited + x*columns) + y)) == 0))
		return 1;
	return 0;
}
int check_path(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int *visited)
{
	if (x1 == x2 &&y1 == y2)
		return 1;
	int res = 0;
	(*((visited + x1*columns) + y1)) = 1;
	if (valid_node(maze, rows, columns, x1, y1 + 1, visited))
		res = check_path(maze, rows, columns, x1, y1 + 1, x2, y2, visited);

	if (res == 0 && valid_node(maze, rows, columns, x1 + 1, y1, visited))
		res = check_path(maze, rows, columns, x1 + 1, y1, x2, y2, visited);

	if (res == 0 && valid_node(maze, rows, columns, x1, y1 - 1, visited))
		res = check_path(maze, rows, columns, x1, y1 - 1, x2, y2, visited);

	if (res == 0 && valid_node(maze, rows, columns, x1 - 1, y1, visited))
		res = check_path(maze, rows, columns, x1 - 1, y1, x2, y2, visited);
	return res;
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0)
		return 0;
	if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= columns || x2 < 0 || x2 >= rows || y2 < 0 || y2 >= columns)
		return 0;
	int *visited = (int *)malloc(rows * columns * sizeof(int));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			(*((visited + i*columns) + j)) = 0;
	return check_path(maze, rows, columns, x1, y1, x2, y2, visited);
}

