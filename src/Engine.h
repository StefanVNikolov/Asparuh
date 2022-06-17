#include <iostream>
#include<string>
#include<vector>
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
		string available_coordinates;

		switch (piece_type) {
			case 0: //Pawn case
			{
				break;
			}
			case 1: //Knight case
			{
				available_coordinates += "Knight moves___\n";

				int move_indeces[8] = {-17, -15, -10, -6, 6, 10, 15, 17};
				for (int index: move_indeces)
				{
					int new_index = piece_y_coordinate * 8 + (piece_x_coordinate + 1) + index;
					if (new_index > 0 && new_index <= 64)
					{
						auto coordinates = moveWithAddition(piece_y_coordinate, piece_x_coordinate, index);
						int y = *(coordinates + 0);
						int x = *(coordinates + 1);
						if (y >= 0 && y <= 7 && x>=0 && x <= 7)
						{
							available_coordinates += "[" + to_string(y) + ", " + to_string(x) + "]\n";
						}
					}
				}
				break;
			}
			case 2: //Bishop case
			{
				break;
			}
			case 3: //Rook case
			{
				break;
			}
			case 4: //Queen case
			{
				break;
			}
			case 5: //King case
			{
				break;
			}
			default: //In process
			{
				break;
			}
		}
		return available_coordinates;
	}
	//Allows to move a piece with only one number
	//Example moveWithAddition(y, x, 19) will return the new coordinates
	int* moveWithAddition(int y, int x, int move_index)
	{
		int current_index = y * 8 + (x + 1); //converts the coordinates to a single position index (hash)
		int new_index = current_index + move_index; //creates the new position index

		//coordinates holder
		int new_y, new_x;
		int coordinates[2];

		//converting the new index to a position
		new_index -= 1;
		new_x = new_index - ((new_index / 8) * 8);
		new_y = (new_index - new_x) / 8;

		coordinates[1] = new_x;
		coordinates[0] = new_y;

		

		return coordinates;
	}

};

