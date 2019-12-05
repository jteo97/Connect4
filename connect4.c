/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"
void sort(int Prizes[], int j); // declare some functions
void check(int board[MAX_SIZE][MAX_SIZE], int size, int i, int j, char **side, int **move);

/*
*** Justin Teo 711753756 ***
This is the file that you will be submitting for marking
Complete the definitions of the functions in this file
DO NOT REMOVE ANY FUNCTION DEFINITIONS - they all must be present when you submit this file
*/

int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	int Prizes[3]; // initialise a 3 element array and store the inputs into the array
	Prizes[0] = prize1;
	Prizes[1] = prize2;
	Prizes[2] = prize3;
	
	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 2; j++)
		{
			if (Prizes[j+1] >= Prizes[j]) // checks if the next element in the array is larger
			{
				sort(Prizes, j); // calls the sort function
			}
		}
	}

	return Prizes[1]; // return the 2nd element of the array which is the second place prize
}

void sort(int Prizes[], int j) // helper function that does bubble sort
{
	int temp;
	temp = Prizes[j];
	Prizes[j] = Prizes[j+1];
	Prizes[j+1] = temp;
}

int FourInARow(int values[], int length)
{
	for (int i = 0; i < (length-3); i++)
	{ // checks if the next three elements are the same as a particular element
		if ((values[i] == values[i+1]) && (values[i] == values[i+2]) && (values[i] == values[i+3]))
		{
			return i; // return index if above is true
		}
	}
	
	return -1; // otherwise return -1
}

int BinaryToDecimal(int binary)
{
	int decimal = 0, power = 1; // initialise some variables
	while (binary > 0)
	{
		if ((binary % 2) == 1) // if the remainder of the division by 2 is one perform the following
		{
			binary = (binary/2)*2; // use integer truncation to eleminate the 1 in the ones position
			decimal += power;
		}
		
		binary /= 10; // 
		power *= 2;
	}
	return decimal;
}

double MedianAbility(double abilities[], int length)
{
	int condition = 1, count = 0, countold; // initialise some variables
	double median, temp;
	
	while (condition == 1)
	{
		countold = count; // keep a memory of the counter
		for (int i = 0; i < (length - 1); i++)
		{
			if (abilities[i+1] > abilities[i]) // if the next element is larger perform bubble sort
			{
				temp = abilities[i]; // bubble sort code
				abilities[i] = abilities[i+1];
				abilities[i+1] = temp;
				count++; // add 1 to count
			}
			
		}
		
		if (countold == count)
		{
			condition = 0; // if countold equals count means all the elements are sorted from largest to smallest
		}
	}
	
	if (length % 2 == 0) // if the length of the array is even
	{
		median = (abilities[length/2 - 1] + abilities[length/2]) / 2; // average the middle two values to find median
	}
	else // otherwise if it is odd
	{
		median = abilities[length/2]; // locate the middle element of the array and assign it to median
	}
	
	return median;
}

void RemoveSpaces(char *name)
{
	int i = 0, j;
	while (name[i] != '\0') // go through entire string
	{
		if ((name[i] == ' ') && (name[i+1] == ' ')) // if the element is a space and the next element is also a space
		{
			j = i + 1;
			while (name[j] != '\0') // go through the rest of the array from position j
			{
				name[j] = name[j+1]; // shifts elements one to the left
				j++;
			}
		}
		else // only if there is one space left then loop will continue
		{
			i++;
		}
	}
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j] = 0; // fills the entire size by size board with zeros
		}
	}
	
	if (size % 2) // checks if size of the board is a odd number
	{
		board[size/2][size/2] = 3; // makes the very middle of the 2D board a three
	}
	else // otherwise if the size of the board is an even number
	{
		board[size/2 - 1][size/2 - 1] = 3; // makes a 2x2 square of threes in the centre of the board
		board[size/2 - 1][size/2] = 3;
		board[size/2][size/2 - 1] = 3;
		board[size/2][size/2] = 3;
	}
}

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	int i = -1;
	
	if (side == 'N') // if input is a N
	{
		while ((board[i+1][move] == 0) && (i < (size-1))) // as long as the next position is empty keep going
		{
			i++;
		}
		if (i != -1) // once the loop is done make the empty place the player's number
		{
			board[i][move] = player;
		}
		*lastRow = i; // update the pointer to the row number
		*lastCol = move; // update the pointer to the column number
	}
	else if (side == 'S') // if input is a S
	{
		i = size;
		while ((board[i-1][move] == 0) && (i > 0)) // as long as the next position is empty keep going
		{
			i--;
		}
		if (i != size) // once the loop is done make the empty place the player's number
		{
			board[i][move] = player;
		}
		*lastRow = i; // update the pointer to the row number
		*lastCol = move; // update the pointer to the column number
	}
	else if (side == 'W') // if input is a W
	{
		while ((board[move][i+1] == 0) && (i < (size - 1))) // as long as the next position is empty keep going
		{
			i++;
		}
		if (i != -1) // once the loop is done make the empty place the player's number
		{
			board[move][i] = player;
		}
		*lastRow = move; // update the pointer to the row number
		*lastCol = i; // update the pointer to the column number
	}
	else if (side == 'E') // if input is an E
	{
		i = size;
		while ((board[move][i-1] == 0) && (i > 0)) // as long as the next position is empty keep going
		{
			i--;
		}
		if (i != size) // once the loop is done make the empty place the player's number
		{
			board[move][i] = player;
		}
		*lastRow = move; // update the pointer to the row number
		*lastCol = i; // update the pointer to the column number
	}
	
	if ((i == -1) || (i == size)) // the above code couldn't find a place for the player to place their token, their move is invalid
		{
			*lastRow = -1; // and pointers are made -1
			*lastCol = -1; // and pointers are made -1
		}
}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	// if there is a 4 in a row horizontally going through the last placed token
	if ((board[row][col-3] == player) && (board[row][col-2] == player) && (board[row][col-1] == player) && (col-3 >= 0))
	{
		return player;
	}
	else if ((board[row][col-2] == player) && (board[row][col-1] == player) && (board[row][col+1] == player) && (col-2 >= 0) && (col+1 < size))		
	{
		return player;
	}
	else if ((board[row][col-1] == player) && (board[row][col+1] == player) && (board[row][col+2] == player) && (col-1 >= 0) && (col+2 < size))
	{
		return player;
	}
	else if ((board[row][col+1] == player) && (board[row][col+2] == player) && (board[row][col+3] == player) && (col+3 < size))
	{
		return player;
	}
	
	// if there is a 4 in a row vertically going through the last placed token
	if ((board[row-3][col] == player) && (board[row-2][col] == player) && (board[row-1][col] == player) && (row-3 >= 0))
	{
		return player;
	}
	else if ((board[row-2][col] == player) && (board[row-1][col] == player) && (board[row+1][col] == player) && (row-2 >= 0) && (row+1 < size))		
	{
		return player;
	}
	else if ((board[row-1][col] == player) && (board[row+1][col] == player) && (board[row+2][col] == player) && (row-1 >= 0) && (row+2 < size))
	{
		return player;
	}
	else if ((board[row+1][col] == player) && (board[row+2][col] == player) && (board[row+3][col] == player) && (row+3 < size))
	{
		return player;
	}
	
	// if there is a 4 in a row diagonally going down going through the last placed token
	if ((board[row-3][col-3] == player) && (board[row-2][col-2] == player) && (board[row-1][col-1] == player) && (row-3 >= 0) && (col-3 >= 0))
	{
		return player;
	}
	else if ((board[row-2][col-2] == player) && (board[row-1][col-1] == player) && (board[row+1][col+1] == player) && (row-2 >= 0) && (col-2 >= 0) && (row+1 < size) && (col+1 < size))		
	{
		return player;
	}
	else if ((board[row-1][col-1] == player) && (board[row+1][col+1] == player) && (board[row+2][col+2] == player) && (row-1 >= 0) && (col-1 >= 0) && (row+2 < size) && (col+2 < size))
	{
		return player;
	}
	else if ((board[row+1][col+1] == player) && (board[row+2][col+2] == player) && (board[row+3][col+3] == player) && (row+3 < size) && (col+3 < size))
	{
		return player;
	}
	
	// if there is a 4 in a row diagonally going up going through the last placed token
	if ((board[row+3][col-3] == player) && (board[row+2][col-2] == player) && (board[row+1][col-1] == player) && (row+3 < size) && (col-3 >= 0))
	{
		return player;
	}
	else if ((board[row+2][col-2] == player) && (board[row+1][col-1] == player) && (board[row-1][col+1] == player) && (row-1 >= 0) && (col-2 >= 0) && (row+2 < size) && (col+1 < size))		
	{
		return player;
	}
	else if ((board[row+1][col-1] == player) && (board[row-1][col+1] == player) && (board[row-2][col+2] == player) && (row-2 >= 0) && (col-1 >= 0) && (row+1 < size) && (col+2 < size))
	{
		return player;
	}
	else if ((board[row-1][col+1] == player) && (board[row-2][col+2] == player) && (board[row-3][col+3] == player) && (row-3 >= 0) && (col+3 < size))
	{
		return player;
	}
	
	for (int i = 0; i < size; i++) // if there isn't a 4 in a row anywhere on the board
	{ // checks if there are still empty spaces on the rim of the board
		if ((board[i][0] == 0) || (board[0][i] == 0) || (board[i][size-1] == 0) || (board[size-1][i] == 0))
		{
			return 0; // if there are the game continues and no-one wins
		}
	}
	return player; // if there isn't any empty spaces around the rim of the board the player who played the last token wins
}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	// the stringlength variable is set to the maximum string length for any given size of board e.g for size 4, max is 72
	int stringlength = ((size+5)*(size+4)), i = 0, x = 0; // initialise some variables
	while (i < stringlength)
	{
		boardString[i] = 45; // make all of the elements in the string a dash (ASCII code 45)
		
		if (i == ((size+4)+x*(size+5))) // whenever the loop comes across the place where a new line character needs to be placed
		{
			boardString[i] = 10; // places the new line character (ASCII code 10) in that position of the string
			x++;
		}
		i++;
	}
	
	for (int j = 0; j < (size); j++)
	{
		boardString[j+2] = 78; // places 'N' where it needs to be
		boardString[j+2+(size+5)] = 48+(char)j; // places the numbers from 0 to (size-1) where it needs to be
		boardString[j+2+(size+5)*(size+3)] = 83; // places 'S' where it needs to be
		boardString[j+2+(size+5)*(size+2)] = 48+(char)j; // places the numbers from 0 to (size-1) where it needs to be
		boardString[(size+5)*(j+2)] = 87; // places 'W' where it needs to be
		boardString[(size+5)*(j+2)+1] = 48+(char)j; // places the numbers from 0 to (size-1) where it needs to be
		boardString[(size+5)*(j+2)+size+3] = 69; // places 'E' where it needs to be
		boardString[(size+5)*(j+2)+size+2] = 48+(char)j; // places the numbers from 0 to (size-1) where it needs to be
	}
	for (int k = 0; k < size; k++)
	{
		for (int l = 0; l < size; l++)
		{
			if (board[k][l] == 0) // if it encounters a zero
			{
				boardString[(size+5)*(k+2) + (l+2)] = 46; // place a full stop (ASCII code 46) in the string
			}
			else if (board[k][l] == 3) // if it encounters a three
			{
				boardString[(k+2)*(size+5) + (l+2)] = 35; // place a hash character (ASCII code 35) in the string
			}
			else if (board[k][l] == 1) // if it encounters a one
			{
				boardString[(k+2)*(size+5) + (l+2)] = 88; // place an X (ASCII code 88) in the string to represent player 1
			}
			else if (board[k][l] == 2) // if it encounters a two
			{
				boardString[(k+2)*(size+5) + (l+2)] = 79; // place an O (ASCII code 79) in the string to represent player 2
			}
		}
	}
	
	boardString[stringlength] = '\0'; // places the null character at the very end of the string
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	for (int m = 0; m < size; m++) // scans the rim of the board for empty spaces
	{
		// assigns the pointers side and move to the empty space for the time being
		if (board[m][0] == 0)
		{
			*side = 'W';
			*move = m;
		}
		else if (board[0][m] == 0)
		{
			*side = 'N';
			*move = m;
		}
		else if (board[m][size-1] == 0)
		{
			*side = 'E';
			*move = m;
		}
		else if	(board[size-1][m] == 0)
		{
			*side = 'S';
			*move = m;
		}
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			 // if there is a 3 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i][j+1] == player) && (board[i][j+2] == player) && (j+2 < size))
			{
				if ((board[i][j-1] == 0) && (j-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i, j-1, &side, &move); // calls the check helper function
				}
				if ((board[i][j+3] == 0) && (j+3 < size)) // checks the other potential winning place
				{
					check(board, size, i, j+3, &side, &move); // calls the check helper function
				}
			}
			 // if there is a 3 in a row vertically on the board
			if ((board[i][j] == player) && (board[i+1][j] == player) && (board[i+2][j] == player) && (i+2 < size))
			{
				if ((board[i-1][j] == 0) && (i-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i-1, j, &side, &move); // calls the check helper function
				}
				if ((board[i+3][j] == 0) && (i+3 < size)) // checks the other potential winning place
				{
					check(board, size, i+3, j, &side, &move); // calls the check helper function
				}
			}
			 // if there is a 3 in a row diagonally going down on the board
			if ((board[i][j] == player) && (board[i+1][j+1] == player) && (board[i+2][j+2] == player) && (i+2 < size) && (j+2 < size))
			{
				if ((board[i-1][j-1] == 0) && (i-1 >= 0) && (j-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i-1, j-1, &side, &move); // calls the check helper function
				}
				if ((board[i+3][j+3] == 0) && (i+3 < size) && (j+3 < size)) // checks the other potential winning place
				{
					check(board, size, i+3, j+3, &side, &move); // calls the check helper function
				}
			}
			 // if there is a 3 in a row diagonally going up on the board
			if ((board[i][j] == player) && (board[i-1][j+1] == player) && (board[i-2][j+2] == player) && (j+2 < size) && (i-2 >= 0))
			{
				if ((board[i+1][j-1] == 0) && (i+1 < size) && (j-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i+1, j-1, &side, &move); // calls the check helper function
				}
				if ((board[i-3][j+3] == 0) && (i-3 >= 0) && (j+3 < size)) // checks the other potential winning place
				{
					check(board, size, i-3, j+3, &side, &move); // calls the check helper function
				}
			}
			
			 // if there is a 2 in a row, a gap, then a 1 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i][j+1] == player) && (board[i][j+3] == player) && (j+3 < size))
			{
				check(board, size, i, j+2, &side, &move); // calls the check helper function
			}
			
			 // if there is a 1 in a row, a gap, then a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i][j+2] == player) && (board[i][j+3] == player) && (j+3 < size))
			{
				check(board, size, i, j+1, &side, &move); // calls the check helper function
			}
			
			 // if there is a 2 in a row, a gap, and a 1 in a row vertically on the board
			if ((board[i][j] == player) && (board[i+1][j] == player) && (board[i+3][j] == player) && (i+3 < size))
			{
				check(board, size, i+2, j, &side, &move); // calls the check helper function
			
			}
			 // if there is a 1 in a row, a gap, and a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i+2][j] == player) && (board[i+3][j] == player) && (i+3 < size))
			{
				check(board, size, i+1, j, &side, &move); // calls the check helper function
			
			}
			 // if there is a 2 in a row, a gap, and a 1 in a row diagonally going down on the board
			if ((board[i][j] == player) && (board[i+1][j+1] == player) && (board[i+3][j+3] == player) && (j+3 < size) && (i+3 < size))
			{
				check(board, size, i+2, j+2, &side, &move); // calls the check helper function
			
			}
			 // if there is a 1 in a row, a gap, and a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i+2][j+2] == player) && (board[i+3][j+3] == player) && (i+3 < size) && (j+3 < size))
			{
				check(board, size, i+1, j+1, &side, &move); // calls the check helper function
			
			}
			 // if there is a 2 in a row, a gap, and a 1 in a row diagonally going up on the board
			if ((board[i][j] == player) && (board[i-1][j+1] == player) && (board[i-3][j+3] == player) && (j+3 < size) && (i-3 >= 0))
			{
				check(board, size, i-2, j+2, &side, &move); // calls the check helper function
			
			}
			 // if there is a 1 in a row, a gap, and a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i-2][j+2] == player) && (board[i-3][j+3] == player) && (j+3 < size) && (i-3 >= 0))
			{
				check(board, size, i-1, j+1, &side, &move); // calls the check helper function
			}
		}
	}
}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	for (int m = 0; m < size; m++) // scans the rim of the board for empty spaces
	{
		// assigns the pointers side and move to the empty space for the time being
		if (board[m][0] == 0)
		{
			*side = 'W';
			*move = m;
		}
		else if (board[0][m] == 0)
		{
			*side = 'N';
			*move = m;
		}
		else if (board[m][size-1] == 0)
		{
			*side = 'E';
			*move = m;
		}
		else if	(board[size-1][m] == 0)
		{
			*side = 'S';
			*move = m;
		}
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			 // if there is a 3 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i][j+1] == player) && (board[i][j+2] == player) && (j+2 < size))
			{
				if ((board[i][j-1] == 0) && (j-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i, j-1, &side, &move); // calls the check helper function
				}
				if ((board[i][j+3] == 0) && (j+3 < size)) // checks the other potential winning place
				{
					check(board, size, i, j+3, &side, &move); // calls the check helper function
				}
			}
			 // if there is a 3 in a row vertically on the board
			if ((board[i][j] == player) && (board[i+1][j] == player) && (board[i+2][j] == player) && (i+2 < size))
			{
				if ((board[i-1][j] == 0) && (i-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i-1, j, &side, &move); // calls the check helper function
				}
				if ((board[i+3][j] == 0) && (i+3 < size)) // checks the other potential winning place
				{
					check(board, size, i+3, j, &side, &move); // calls the check helper function
				}
			}
			 // if there is a 3 in a row diagonally going down on the board
			if ((board[i][j] == player) && (board[i+1][j+1] == player) && (board[i+2][j+2] == player) && (i+2 < size) && (j+2 < size))
			{
				if ((board[i-1][j-1] == 0) && (i-1 >= 0) && (j-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i-1, j-1, &side, &move); // calls the check helper function
				}
				if ((board[i+3][j+3] == 0) && (i+3 < size) && (j+3 < size)) // checks the other potential winning place
				{
					check(board, size, i+3, j+3, &side, &move); // calls the check helper function
				}
			}
			 // if there is a 3 in a row diagonally going up on the board
			if ((board[i][j] == player) && (board[i-1][j+1] == player) && (board[i-2][j+2] == player) && (j+2 < size) && (i-2 >= 0))
			{
				if ((board[i+1][j-1] == 0) && (i+1 < size) && (j-1 >= 0)) // checks one potential winning place
				{
					check(board, size, i+1, j-1, &side, &move); // calls the check helper function
				}
				if ((board[i-3][j+3] == 0) && (i-3 >= 0) && (j+3 < size)) // checks the other potential winning place
				{
					check(board, size, i-3, j+3, &side, &move); // calls the check helper function
				}
			}
			
			 // if there is a 2 in a row, a gap, then a 1 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i][j+1] == player) && (board[i][j+3] == player) && (j+3 < size))
			{
				check(board, size, i, j+2, &side, &move); // calls the check helper function
			}
			
			 // if there is a 1 in a row, a gap, then a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i][j+2] == player) && (board[i][j+3] == player) && (j+3 < size))
			{
				check(board, size, i, j+1, &side, &move); // calls the check helper function
			}
			
			 // if there is a 2 in a row, a gap, and a 1 in a row vertically on the board
			if ((board[i][j] == player) && (board[i+1][j] == player) && (board[i+3][j] == player) && (i+3 < size))
			{
				check(board, size, i+2, j, &side, &move); // calls the check helper function
			
			}
			 // if there is a 1 in a row, a gap, and a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i+2][j] == player) && (board[i+3][j] == player) && (i+3 < size))
			{
				check(board, size, i+1, j, &side, &move); // calls the check helper function
			
			}
			 // if there is a 2 in a row, a gap, and a 1 in a row diagonally going down on the board
			if ((board[i][j] == player) && (board[i+1][j+1] == player) && (board[i+3][j+3] == player) && (j+3 < size) && (i+3 < size))
			{
				check(board, size, i+2, j+2, &side, &move); // calls the check helper function
			
			}
			 // if there is a 1 in a row, a gap, and a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i+2][j+2] == player) && (board[i+3][j+3] == player) && (i+3 < size) && (j+3 < size))
			{
				check(board, size, i+1, j+1, &side, &move); // calls the check helper function
			
			}
			 // if there is a 2 in a row, a gap, and a 1 in a row diagonally going up on the board
			if ((board[i][j] == player) && (board[i-1][j+1] == player) && (board[i-3][j+3] == player) && (j+3 < size) && (i-3 >= 0))
			{
				check(board, size, i-2, j+2, &side, &move); // calls the check helper function
			
			}
			 // if there is a 1 in a row, a gap, and a 2 in a row horizontally on the board
			if ((board[i][j] == player) && (board[i-2][j+2] == player) && (board[i-3][j+3] == player) && (j+3 < size) && (i-3 >= 0))
			{
				check(board, size, i-1, j+1, &side, &move); // calls the check helper function
			}
		}
	}
}

void check(int board[MAX_SIZE][MAX_SIZE], int size, int i, int j, char **side, int **move)
{
	int k, count; // initialise some variables
	if ((board[i+1][j] != 0) || ((i+1) == size)) // checks if the token can stop in the desired position
	{
		count = 0;
		for (k = i;k >= 0; k--) // checks if the token has a clear path to slide
		{
			if (board[k][j] == 0)
			{
				count++;
			}
		}
		
		if (count == (i+1)) // if it does make pointers the side and column to place the token
		{
			**side = 'N';
			**move = j;
		}
	}
	
	if ((board[i-1][j] != 0) || ((i-1) == -1)) // checks if the token can stop in the desired position
	{
		count = 0;
		for (k = i;k < size; k++) // checks if the token has a clear path to slide
		{
			if (board[k][j] == 0)
			{
				count++;
			}
		}
		
		if (count == (size - i)) // if it does make pointers the side and column to place the token
		{
			**side = 'S';
			**move = j;
		}
	}
	
	if ((board[i][j-1] != 0) || ((j-1) == -1)) // checks if the token can stop in the desired position
	{
		count = 0;
		for (k = j;k < size; k++) // checks if the token has a clear path to slide
		{
			if (board[i][k] == 0)
			{
				count++;
			}
		}
		
		if (count == (size - j)) // if it does make pointers the side and column to place the token
		{
			**side = 'E';
			**move = i;
		}
	}
	
	if ((board[i][j+1] != 0) || ((j+1) == size)) // checks if the token can stop in the desired position
	{
		count = 0;
		for (k = j;k >= 0; k--) // checks if the token has a clear path to slide
		{
			if (board[i][k] == 0)
			{
				count++;
			}
		}
		
		if (count == (j+1)) // if it does make pointers the side and column to place the token
		{
			**side = 'W';
			**move = i;
		}
	}
}