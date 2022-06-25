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
	//Move highlighter holder
	vector <int> highlight_indeces;

	//Checks for legal moves for a given chess piece
	string checkAvailableMovesFor(ChessBoard board, int piece_y_coordinate, int piece_x_coordinate)
	{
		//Taking piece stats
		int piece_type = board.board[piece_y_coordinate][piece_x_coordinate].type;
		int piece_color = board.board[piece_y_coordinate][piece_x_coordinate].color;

		string available_coordinates;

		switch (piece_type) {
		case 0: //Pawn case
		{
			break;
		}
		case 1: //Knight case
		{
			available_coordinates += "Knight moves___\n";

			int move_destinations[8][2] = {
				{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
				{-1, -2}, {-1, 2}, {1, -2}, {1, 2} };

			for (auto destination : move_destinations)
			{
				int distance = calculateDistance(piece_y_coordinate, piece_x_coordinate,
					destination[0], destination[1]);


				if (distance != 0)
				{
					int new_index = piece_y_coordinate * 8 + (piece_x_coordinate + 1) + distance;
					if (new_index > 0 && new_index <= 64)
					{
						auto coordinates = moveWithAddition(piece_y_coordinate, piece_x_coordinate, distance);
						int y = *(coordinates + 0);
						int x = *(coordinates + 1);
						if (y >= 0 && y <= 7 && x >= 0 && x <= 7)
						{
							//Taking the cell information
							bool occupancy_status = board.board[y][x].exists;
							int occupancy_color = board.board[y][x].color;

							if (occupancy_status == false || (occupancy_status == true && occupancy_color != piece_color))
							{
								//Pushing the coordinates to highlight in the HTML file
								int coordinates_h[2]{};
								coordinates_h[0] = y;
								coordinates_h[1] = x;
								highlight_indeces.push_back(new_index);
							}


							//Adding information to the return log
							available_coordinates += "[" + to_string(y) + ", " + to_string(x) + "]\n";
						}
					}
				}
			}
			break;
		}
		case 2: //Bishop case
		{
			available_coordinates += "Bishop moves___\n";

			int move_destinations[4][2] = {
				{-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

			for (auto destination : move_destinations)
			{
				//Multiples the length of the direction 
				for (int distance_increase = 1; distance_increase <= 7; distance_increase++)
				{
					int distance = calculateDistance(piece_y_coordinate, piece_x_coordinate,
						destination[0] * distance_increase, destination[1] * distance_increase);


					if (distance != 0)
					{
						int new_index = piece_y_coordinate * 8 + (piece_x_coordinate + 1) + distance;
						if (new_index > 0 && new_index <= 64)
						{
							auto coordinates = moveWithAddition(piece_y_coordinate, piece_x_coordinate, distance);
							int y = *(coordinates + 0);
							int x = *(coordinates + 1);
							if (y >= 0 && y <= 7 && x >= 0 && x <= 7)
							{
								//Taking the cell information
								bool occupancy_status = board.board[y][x].exists;
								int occupancy_color = board.board[y][x].color;

								if (occupancy_status == false)
								{
									//Pushing the coordinates to highlight in the HTML file
									int coordinates_h[2]{};
									coordinates_h[0] = y;
									coordinates_h[1] = x;
									highlight_indeces.push_back(new_index);
								}
								else if(occupancy_status == true && occupancy_color != piece_color)
								{
									//Pushing the coordinates to highlight in the HTML file
									int coordinates_h[2]{};
									coordinates_h[0] = y;
									coordinates_h[1] = x;
									highlight_indeces.push_back(new_index);
									break;
								}
								else {
									break;
								}


								//Adding information to the return log
								available_coordinates += "[" + to_string(y) + ", " + to_string(x) + "]\n";
							}
						}
					}
				}
			}

			break;
		}
		case 3: //Rook case
		{
			available_coordinates += "Rook moves___\n";

			int move_destinations[4][2] = {
				{-1, 0}, {1, 0}, {0, -1}, {0, 1} };

			for (auto destination : move_destinations)
			{
				//Multiples the length of the direction 
				for (int distance_increase = 1; distance_increase <= 7; distance_increase++)
				{
					int distance = calculateDistance(piece_y_coordinate, piece_x_coordinate,
						destination[0] * distance_increase, destination[1] * distance_increase);


					if (distance != 0)
					{
						int new_index = piece_y_coordinate * 8 + (piece_x_coordinate + 1) + distance;
						if (new_index > 0 && new_index <= 64)
						{
							auto coordinates = moveWithAddition(piece_y_coordinate, piece_x_coordinate, distance);
							int y = *(coordinates + 0);
							int x = *(coordinates + 1);
							if (y >= 0 && y <= 7 && x >= 0 && x <= 7)
							{
								//Taking the cell information
								bool occupancy_status = board.board[y][x].exists;
								int occupancy_color = board.board[y][x].color;

								if (occupancy_status == false)
								{
									//Pushing the coordinates to highlight in the HTML file
									int coordinates_h[2]{};
									coordinates_h[0] = y;
									coordinates_h[1] = x;
									highlight_indeces.push_back(new_index);
								}
								else if (occupancy_status == true && occupancy_color != piece_color)
								{
									//Pushing the coordinates to highlight in the HTML file
									int coordinates_h[2]{};
									coordinates_h[0] = y;
									coordinates_h[1] = x;
									highlight_indeces.push_back(new_index);
									break;
								}
								else {
									break;
								}


								//Adding information to the return log
								available_coordinates += "[" + to_string(y) + ", " + to_string(x) + "]\n";
							}
						}
					}
				}
			}

			break;
		}
		case 4: //Queen case
		{
			available_coordinates += "Queen moves___\n";

			int move_destinations[8][2] = {
				{-1, -1}, {-1, 1}, {1, -1}, {1, 1},
				{-1, 0}, {1, 0}, {0, -1}, {0, 1} };

			for (auto destination : move_destinations)
			{
				//Multiples the length of the direction 
				for (int distance_increase = 1; distance_increase <= 7; distance_increase++)
				{
					int distance = calculateDistance(piece_y_coordinate, piece_x_coordinate,
						destination[0] * distance_increase, destination[1] * distance_increase);


					if (distance != 0)
					{
						int new_index = piece_y_coordinate * 8 + (piece_x_coordinate + 1) + distance;
						if (new_index > 0 && new_index <= 64)
						{
							auto coordinates = moveWithAddition(piece_y_coordinate, piece_x_coordinate, distance);
							int y = *(coordinates + 0);
							int x = *(coordinates + 1);
							if (y >= 0 && y <= 7 && x >= 0 && x <= 7)
							{
								//Taking the cell information
								bool occupancy_status = board.board[y][x].exists;
								int occupancy_color = board.board[y][x].color;

								if (occupancy_status == false)
								{
									//Pushing the coordinates to highlight in the HTML file
									int coordinates_h[2]{};
									coordinates_h[0] = y;
									coordinates_h[1] = x;
									highlight_indeces.push_back(new_index);
								}
								else if (occupancy_status == true && occupancy_color != piece_color)
								{
									//Pushing the coordinates to highlight in the HTML file
									int coordinates_h[2]{};
									coordinates_h[0] = y;
									coordinates_h[1] = x;
									highlight_indeces.push_back(new_index);
									break;
								}
								else {
									break;
								}


								//Adding information to the return log
								available_coordinates += "[" + to_string(y) + ", " + to_string(x) + "]\n";
							}
						}
					}
				}
			}
			break;
		}
		case 5: //King case
		{

			available_coordinates += "King moves___\n";

			int move_destinations[8][2] = { 
				{-1, -1}, {-1, 1}, {1, -1}, {1, 1},     
				{-1, 0}, {1, 0}, {0, -1}, {0, 1} };

			for (auto destination : move_destinations)
			{
				int distance = calculateDistance(piece_y_coordinate, piece_x_coordinate,
					destination[0], destination[1]);


				if (distance != 0)
				{
					int new_index = piece_y_coordinate * 8 + (piece_x_coordinate + 1) + distance;
					if (new_index > 0 && new_index <= 64)
					{
						auto coordinates = moveWithAddition(piece_y_coordinate, piece_x_coordinate, distance);
						int y = *(coordinates + 0);
						int x = *(coordinates + 1);
						if (y >= 0 && y <= 7 && x >= 0 && x <= 7)
						{
							//Taking the cell information
							bool occupancy_status = board.board[y][x].exists;
							int occupancy_color = board.board[y][x].color;

							if (occupancy_status == false || (occupancy_status == true && occupancy_color != piece_color))
							{
								//Pushing the coordinates to highlight in the HTML file
								int coordinates_h[2]{};
								coordinates_h[0] = y;
								coordinates_h[1] = x;
								highlight_indeces.push_back(new_index);
							}


							//Adding information to the return log
							available_coordinates += "[" + to_string(y) + ", " + to_string(x) + "]\n";
						}
					}
				}
			}
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

	//Calculates the distance between 2 points
	int calculateDistance(int y_from, int x_from, int y_additive, int x_additive)
	{
		int y_to = y_from + y_additive;
		int x_to = x_from + x_additive;

		int index_from = y_from * 8 + (x_from + 1);
		int index_to = y_to * 8 + (x_to + 1);
		int distance = index_to - index_from;

		if (y_to < 0 || y_to > 7 || x_to < 0 || x_to > 7)
		{
			return 0;
		}

		return distance;
	}

};

