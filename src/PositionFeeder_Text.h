#include<iostream>
#include<fstream>
#include<string>
#include "structs.cpp"

using namespace std;
#pragma once

//Name of the file containing the information
const string fileName = "chessFeed.txt";

//This class reads from a .txt file
//Parses the information to ChessPieces
//Feeds a chess board with all pieces at once
class PositionFeeder_Text
{
public:

    //This function reads a file containing the start position
    //Loads the start position on a chess board board
    //Returns a log with the created pieces (+ spec-info)
	string importInformation(ChessBoard &board)
	{
        //Creates a log holder;
        string log;

		//Opens the text file
		ifstream Feed(fileName);

        //Check if the file exists
        if (!Feed.is_open()) //file not found
            cout << "File not found" << endl;
        else
        {
            //Feed data per log (line)
            int type, color;
            char position[3];

            //read first value
            Feed >> type;
            while (!Feed.eof())
            {
                //read the rest of the line
                Feed >> color;
                Feed >> position;

                //Create a new piece
                ChessPiece current_chess_piece;
                current_chess_piece.exists = true;
                current_chess_piece.type = type;
                current_chess_piece.color = color;
                current_chess_piece.x_coordinate = convert_coordinates(position)[0];
                current_chess_piece.y_coordinate = convert_coordinates(position)[1];

                string current_log = board.placePiece(&current_chess_piece); //Using the chessboard place function (actual positioning)
                log += current_log;                                          //Adding the placement log to the main log
                
                //read the beginning of the next data record
                Feed >> type;
            }
            //Closing the feed file after the last line
            Feed.close();
        }
        return log;
	}
    // This function takes input coordinates and converts them to 
    // 2-dimentional array coordinates
    short int* convert_coordinates(char* conventional_coordinates)
    {
        //int coordinates holder
        short int coordinates[2];
        //Converting the ASCII char index to the actual 2D array coordinate
        short int x_coordinate = conventional_coordinates[0] - 65;
        short int y_coordinate = 7 - (conventional_coordinates[1] - 49);

        coordinates[0] = x_coordinate;
        coordinates[1] = y_coordinate;

        return coordinates;
    }

};

