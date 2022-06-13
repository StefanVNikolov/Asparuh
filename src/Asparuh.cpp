//ASPARUH_0.1.1 C++ Version
//+----------------------------------------------+
//| This program generates a tree of chess games |
//| given the depth of search or a time limit    |
//+----------------------------------------------+
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include "structs.cpp"
#include "ChessBoard.cpp"
#include "PositionFeeder_Text.cpp"
#include "PositionFeeder_Text.h"
#include "HTML_viewer.h"

using namespace std;

ChessPiece create_new_piece();
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

	cout << feed_report;
	//Testing the remove function	
	cout << chess_board.movePiece(chess_board.board[7][7], 4, 4);

	Clear(); // Clear the console
	HTML_viewer viewer;
	string chess_possition = viewer.generateHTML_file(chess_board);
	cout << chess_possition;
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