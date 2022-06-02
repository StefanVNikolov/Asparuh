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

using namespace std;

ChessPiece create_new_piece();
void Clear();

int main()
{
	//Struct test
	ChessPiece piece;
	create_new_piece();
}

// This function creates a chess piece out of the user input
// Easy to follow menu 
// Accepts the index as an input
ChessPiece create_new_piece()
{
	ChessPiece piece;
	int type, color;
	char coordinates[3];

	cout << "Enter the following information" << endl << endl;
	cout << "Chess Piece | Piece Index" << endl;
	cout << " Pawn             0" << endl;
	cout << " Knight           1" << endl;
	cout << " Bishop           2" << endl;
	cout << " Rook             3" << endl;
	cout << " Queen            4" << endl;
	cout << " King             5" << endl;

	cout << "piece type (0-5): ";
	cin >> type;

	cout << "\nColor | Index" << endl;
	cout << "Black     0" << endl;
	cout << "White     1" << endl;

	cout << "color (0/1):";
	cin >> color;
	cout << "\ncoordinates (example: B2): ";
	cin >> coordinates;

	Clear();

	piece.type = type;
	piece.color = color;

	return piece;
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