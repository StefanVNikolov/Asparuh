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
	//Clear(); // Clear the console

	//PositionFeeder Test
	PositionFeeder_Text feeder;
	string feed_report = feeder.importInformation(chess_board);

	cout << feed_report;
	cin.ignore();
	cin.get();
	Clear(); // Clear the console
	cout << chess_board.printBoard_exists();
	cin.ignore();
	cin.get();

		    
}

// This function creates a chess piece out of the user input
// Easy to follow menu 
// Accepts the index as an input
ChessPiece create_new_piece()
{
	ChessPiece piece;
	piece.exists = true;  //Chenges the exists status

	int type, color;
	char coordinates[3];

	// Take the user input for the chess piece
	cout << "Enter the following information" << endl << endl;
	cout << "Chess Piece | Piece Index" << endl;
	cout << " Pawn             0" << endl;
	cout << " Knight           1" << endl;
	cout << " Bishop           2" << endl;
	cout << " Rook             3" << endl;
	cout << " Queen            4" << endl;
	cout << " King             5" << endl;

	cout << "piece type (0-5): ";
	cin >> type; // TYPE

	cout << "\nColor | Index" << endl;
	cout << "Black     0" << endl;
	cout << "White     1" << endl;

	cout << "color (0/1):";
	cin >> color; // COLOR

	cout << "\ncoordinates (example: B2): ";
	cin >> coordinates; // CONVENTIONAL COORDINATES

	// Assign the values to the chess piece
	piece.type = type;
	piece.color = color;

	// Convert the user input to 2-dimentional array coordinates
	piece.x_coordinate = convert_coordinates(coordinates)[0];
	piece.y_coordinate = convert_coordinates(coordinates)[1];

	return piece;
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