#include <iostream>
#include<string>
#include "structs.cpp"
#include "ChessBoard.h"
using namespace std;

#pragma once

class Engine
{
public:
	//Checks for legal moves for a given chess piece
	string checkAvailableMovesFor(ChessBoard board, int piece_y_coordinate, int piece_x_coordinate)
	{
		int piece_type = board.board[piece_y_coordinate][piece_x_coordinate].type;
		string log;

		switch (piece_type) {
			case 0: //Pawn case
			{
				log += "Pawn legal moves---\n";
				break;
			}
			case 1: //Knight case
			{
				log += "Knight legal moves---\n";

				break;
			}
			case 2: //Knight case
			{
				log += "Bishop legal moves---\n";
				break;
			}
			case 3: //Knight case
			{
				log += "Rook legal moves---\n";
				break;
			}
			case 4: //Knight case
			{
				log += "Queen legal moves---\n";
				break;
			}
			case 5: //Knight case
			{
				log += "King legal moves---\n";
				break;
			}
			default: //In process
			{
				break;
			}
		}
		return log;
	}
	//Allows to move a piece with only one number
	//Example moveWithAddition(y, x, 19) will return the new coordinates
	int* moveWithAddition(int y, int x, int move_index)
	{
		int current_index = y * 8 + (x + 1); //converts the coordinates to a single position index (hash)
		int new_index = current_index + move_index; //creates the new position index

		//coordinates holder
		int new_y, new_x;
		new_x = 7;
		int coordinates[2];

		//converting the new index to a position
		if (new_index % 8 != 0)
		{
			new_x = (new_index % 8) - 1;
			coordinates[1] = new_x;
		}
		new_y = (new_index - new_x) / 8;
		coordinates[0] = new_y;

		

		return coordinates;
	}

};

