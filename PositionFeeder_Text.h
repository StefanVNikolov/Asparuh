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

	void extractInformation()
	{
		//Opens the text file
		ifstream Feed(fileName);

        //Check if the file exists
        if (!Feed.is_open()) //file not found
            cout << "File not found" << endl;
        else
        {
            PieceSpecifications specs;
            //Feed data per log (line)
            int type, color;
            string position;

            //read first value
            Feed >> type;
            while (!Feed.eof())
            {
                //read the rest of the line
                Feed >> color;
                Feed >> position;

                cout << specs.colors[color] << " " << specs.types[type] << " was positioned on " << position << endl;
                //read the beginning of the next data record
                Feed >> type;
            }
            Feed.close();
        }
	}

};

