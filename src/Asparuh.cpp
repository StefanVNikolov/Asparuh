//ASPARUH_0.1.1 C++ Version
//+----------------------------------------------+
//| This program generates a tree of chess games |
//| given the depth of search or a time limit    |
//+----------------------------------------------+
#include<iostream>
#include <algorithm>
#include<fstream>
#include<vector>
#include<string>
#include <iomanip>
#include "structs.cpp"
#include "ChessBoard.cpp"
#include "PositionFeeder_Text.cpp"
#include "PositionFeeder_Text.h"
#include "HTML_viewer.h"
#include "Engine.h"

using namespace std;

short int* convert_coordinates(char*);
void Clear();

int main()
{
	//Struct test
	PieceSpecifications specs;

	//Chess board
	ChessBoard chess_board = ChessBoard();
	chess_board._Init_();

	//PositionFeeder Test
	PositionFeeder_Text feeder;
	string feed_report = feeder.importInformation(chess_board);

	//Testing the move function	
	chess_board.movePiece(chess_board.board[7][1], 6, 1);
	chess_board.movePiece(chess_board.board[7][3], 4, 4);


	Engine e;

	Clear(); // Clear the console
	auto coordinates_black = e.listAvailableMovesFor_color(chess_board, 0);
	Clear(); // Clear the console
	auto record = coordinates_black.begin();
	while (record != coordinates_black.end()) 
	{
		int possition_index = record->first;
		//converting the new index to a position
		possition_index -= 1;
		int x = possition_index - ((possition_index / 8) * 8);
		int y = (possition_index - x) / 8;

		auto possitions = record->second;
		++record;

		cout << specs.colors[chess_board.board[y][x].color] << " " << specs.types[chess_board.board[y][x].type] << "___\n";
		for (auto move : possitions)
		{
			int* coordinates = new int[2];
			coordinates[0] = move[0];
			coordinates[1] = move[1];
			auto conventional_coordinates = feeder.conventionalize_coordinates(coordinates);
			char letter = conventional_coordinates[0];
			char number = conventional_coordinates[1];
			cout << "\t" << letter << number << endl;
		}
	}
	

	vector <int> indeces_h = e.highlight_indeces;
	sort(indeces_h.begin(), indeces_h.end());
	HTML_viewer viewer;
	string chess_possition = viewer.generateHTML_file(chess_board, indeces_h);
	viewer.createHTML_file(chess_possition);
		    
}



// This function takes input coordinates and converts them to 
// 2-dimentional array coordinates
short int* convert_coordinates(char* conventional_coordinates)
{
	short int coordinates[2];
	short int x_coordinate = conventional_coordinates[0] - 65;
	short int y_coordinate = 7 - (conventional_coordinates[1] - 49);

	coordinates[0] = x_coordinate;
	coordinates[1] = y_coordinate;

	return coordinates;
}

// This function is used to clear the console
void Clear()
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
	system("clear");
#endif
}