/*
Description

Skyscraper is a logic puzzle similar to Sudoku.
You have an NxN grid that you'll fill such that every row and column contains 1...N
fx:
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
There is however a catch, since we're working with a grid of Skyscrapers we cant just place them willy nilly.
The Mayor sits in his office and demands that you can only see so many skyscrapers from different directions (only looking across columns and rows)
To solve this issue we have to abuse that each skyscraper is only as high as its number, and can hide lower skyscrapers behind it.
For example looking either from the left or right in this row:
1 4 3 2
From the left can 2 skyscrapers be seen, 1, and 4.
From the right can 3 skyscrapers be seen, 2, 3, and 4.
Input example

First we will get an N telling us how big the grid is in NxN. (10 > N > 0)
N will only be different from 4 in the bonus, so you can assume N is always 4 outside of the bonus
Secondly we get all the view demands in a single array (N >= X_i >= 0)
The array is always of length N * 4
0's mean that there are no demands for the view of the given row/column
0's means no constraint in number of buildings in view
You must be able to see EXACTLY the amount that is told, no more, no less
The array should be read as such:
Going clockwise around the grid starting at the top-left
3
0 1 0 2 1 3 2 0 1 0 2 2

- 0 1 0 -
2 ? ? ? 2
2 ? ? ? 1
0 ? ? ? 3
- 1 0 2 -
Or as displayed with indexes
-- 0 1 2 -
11 ? ? ? 3
10 ? ? ? 4
09 ? ? ? 5
-- 8 7 6 -
Where each number is looking inwards at their respective column/row
Output example

The output is the filled out city grid
For the input above we get:
1 3 2
2 1 3
3 2 1
Challenge input

Challenge 1

4
3 1 2 2 2 2 1 3 2 2 3 1 1 2 3 2
Challenge 2

4
0 0 0 0 0 2 0 0 3 0 0 0 1 3 0 3
Challenge output

Challenge 1

2 4 1 3
1 3 4 2
3 1 2 4
4 2 3 1
Challenge 2

2 1 3 4
3 4 1 2
1 2 4 3
4 3 2 1
Bonus

Make it solve for an n by n game
Some tiles may already be filled in
After the array of ints there will be an NxN 2D array of ints with some prefilled tiles
all 0 tiles are empty ones your solver need to fill out
Bonus input

Bonus 1

8
1 3 2 5 4 2 2 3 3 2 5 2 3 1 3 3 3 4 2 2 1 2 3 3 3 4 2 2 3 3 4 1
0 6 0 0 5 0 1 0
0 2 1 0 0 0 0 0
2 0 0 0 6 0 3 0
0 0 0 0 0 8 0 0
0 0 6 0 0 3 7 0
0 0 5 0 0 0 0 0
0 0 0 0 0 0 0 3
0 0 0 0 3 0 0 0
Bonus 2

6
4 3 0 3 2 2 0 0 0 3 0 0 0 2 0 2 0 0 2 3 0 0 0 0
2 0 0 0 0 0
0 0 0 0 4 0
0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
Bonus output

Bonus 1

8 6 2 3 5 7 1 4
3 2 1 5 4 6 8 7
2 7 8 4 6 5 3 1
5 4 3 1 7 8 2 6
4 8 6 2 1 3 7 5
7 3 5 6 2 1 4 8
1 5 4 7 8 2 6 3
6 1 7 8 3 4 5 2
Bonus 2

2 3 6 4 5 1
3 5 1 2 4 6
5 1 2 3 6 4
6 2 4 5 1 3
1 4 3 6 2 5
4 6 5 1 3 2*/




/*
*NOTICE: implementation not complete
*NOTICE: current recursive idea will some cells for the same value multiple times
*	Can solve this by simply olny having the orgin points call in both directons, all other instances call in only one direction
 */

#include <stdio.h>
#include <stdlib.h>

using namespace std

Class Building
{	
	private:
		int height;
		// bool north,south,east,west;	
		bool visibility[4];
	public:
		bool getVisible(int) //takes in int for direction and returns if it is visible from that direction
		void setVisible(int, bool) //takes in int for direction and sets the visible boolean for that direction to true
		int setValue(int)
		int getHeight() {return height;}
};


int cost NORTH = 0;
int cost SOUTH = 1;
int cost EAST = 2;
int cost WEST = 3;

bool getVisible(int direction)
{
	return visibility[direction];
}

bool setVisible(int direction, bool value)
{
	visibility[direction] = value;
}

/**
 * [populateSouthEast: recusivley populate all cells south and east visibility attributes]
 * @param  grid    [The gird of buildings present withing the current map]
 * @param  n       [the dimensionality of the current map]
 * @param  r       [the row of the current cell]
 * @param  c       [the column of the current cell]
 * @param  highestS [the highest building seen to the south so far]
 * @param  highestE [the highest building seen to the east so far]
 * @return         [return a grid with updated visibility for the east and south directions]
 */
Building[][] populateSouthEast(Building grid[][], int n, int r, int c, int highestS, int highestE) 
{
	if(c == n){grid = populateSouthEast().[r][c].setVisible(EAST, true);}
	if(n == 0){grid = populateSouthEast().[r][c].setVisible(SOUTH, true);}






}

/**
 * [populateSouthEast: recusivley populate all cells north and west visibility attributes]
 * @param  grid    [The gird of buildings present withing the current map]
 * @param  n       [the dimensionality of the current map]
 * @param  r       [the row of the current cell]
 * @param  c       [the column of the current cell]
 * @param  highestN [the highest building seen to the north so far]
 * @param  highestW [the highest building seen to the west so far]
 * @return         [return a grid with updated visibility for the west and north directions]
 */
Building[][] populateNorthWest(Building grid[][], int n, int r, int c, int highestN, int highestW)
{



}

Building[][] populateVisible(Building grid[][], int n)
{
	
	//recursivley populate the visibility arrays of the cells of the grid
	populateSouthEast(grid[][], n, 0, 0, 0);
	populateNorthWest( grid[][],n, n, n,0 );



}

int main(int argc, char** argv)
{

	int n; //dimensionality of the grid
	int hold = 0;

	cin >> n; // read in value for n (need to change to get from file)

	Building grid[n][n];

	for(int i = 0 ; i < n; i ++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> hold; //read in the grid input (need to change to get from file)
			 grid[i][j].setValue(hold);
		}
	}

	grid = populateVisible(grid, n);
}

