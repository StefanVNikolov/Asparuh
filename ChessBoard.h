#include "structs.cpp"
using namespace std;

#pragma once

//Setting the size of the chess board 8x8
static const int grid_size = 8;

class ChessBoard
{
public:   
	//Creates a 2-D array of pointers to chess pieces
	ChessPiece* board[grid_size][grid_size];

	void _Init_()
	{
		//Creates a pointer to a null piece (exists value is false)
		ChessPiece null_piece;
		ChessPiece* null_piece_ptr = &null_piece;

		//Feeds the array with the pointer to the null piece
		for (int current_y = 0; current_y < grid_size; current_y++)
		{
			for (int current_x = 0; current_x < grid_size; current_x++)
			{
				//sets a [y, x] value to the pointer
				board[current_y][current_x] = null_piece_ptr;
			}
		}
	}

	bool checkIfEmpty(int x, int y)
	{
		bool occupied = false;
		//checks if the position is occupied or empty
		(board[y][x]->exists == true) ? occupied = true : occupied = false;
		return occupied;
	}

};

