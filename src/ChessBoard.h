#include "structs.cpp"
#include <iostream>
using namespace std;

#pragma once

//Setting the size of the chess board 8x8
static const int grid_size = 8;

//The names of the piece attributes
static const PieceSpecifications specs;

class ChessBoard
{
public:   
	//Creates a 2-D array of chess pieces
	ChessPiece board[grid_size][grid_size];

	void _Init_()
	{
		//Creates a null piece (exists value is false)
		ChessPiece null_piece;

		//Feeds the array with the null piece
		for (int current_y = 0; current_y < grid_size; current_y++)
		{
			for (int current_x = 0; current_x < grid_size; current_x++)
			{
				board[current_y][current_x] = null_piece;
			}
		}
	}

	//Rewrites the information of an existing piece
	string placePiece(ChessPiece* piece_ptr)
	{
		//Creating a log holder for the function
		string log;

		//Initializing values to unpointerize the piece
		int x = piece_ptr->x_coordinate;
		int y = piece_ptr->y_coordinate;
		int ptr_type = piece_ptr->type;
		int ptr_color = piece_ptr->color;

		//Assigning the values to the board
		board[y][x].exists = true;
		board[y][x].type = ptr_type;
		board[y][x].color = ptr_color;

		//Adding information about the created piece to the log
		string address = "[" + to_string(x) + ", " + to_string(y) + "]";
		log += specs.colors[board[y][x].color] + " " + specs.types[board[y][x].type] + " on " + address + "\n";

		return log;
	}

	bool checkIfEmpty(int x, int y)
	{
		bool occupied = false;
		//checks if the position is occupied or empty
		(board[y][x].exists == true) ? occupied = true : occupied = false;
		return occupied;
	}

	//3 PRINT TEST FUNCTIONS BECAUSE I AM LAZY
	string printBoard_type()
	{
		string matrix;
		for (int current_column = 0; current_column < grid_size; current_column++)
		{
			for (int current_row = 0; current_row < grid_size; current_row++)
			{
				matrix += to_string(board[current_column][current_row].type) + " ";
			}
			matrix += "\n";
		}
		return matrix;
	}

	string printBoard_color()
	{
		string matrix;
		for (int current_column = 0; current_column < grid_size; current_column++)
		{
			for (int current_row = 0; current_row < grid_size; current_row++)
			{
				matrix += to_string(board[current_column][current_row].color) + " ";
			}
			matrix += "\n";
		}
		return matrix;
	}

	string printBoard_exists()
	{
		string matrix;
		for (int current_column = 0; current_column < grid_size; current_column++)
		{
			for (int current_row = 0; current_row < grid_size; current_row++)
			{
				matrix += to_string(board[current_column][current_row].exists) + " ";
			}
			matrix += "\n";
		}
		return matrix;
	}

};

