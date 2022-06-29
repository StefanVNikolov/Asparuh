#include<string>
using namespace std;

#pragma once
struct ChessPiece {
	bool exists = false;     //Changes on initialization

    int type = NULL;          //[PAWN-0; KNIGHT-1; BISHOP-2; ROOK-3; QUEEN-4; KING-5]
	int x_coordinate = NULL;  //[ 0-15 ]
	int y_coordinate = NULL;  //[ 0-15 ] 
	bool color = NULL;              //[BLACK-0; WHITE-1]
	bool moved = false;

	// Movement constraints
	bool straight = false;     //[UNABLE-0; ABLE-1]
	bool diagonal = false;     //[UNABLE-0; ABLE-1]
	bool knight_jump = false;  //[UNABLE-0; ABLE-1]
};

struct PieceSpecifications {

	//Holds the lable of the corresponding index that a chess piece struct holds 
	string types[6] = { "pawn", "knight","bishop","rook", "queen", "king" };
	string colors[2] = { "black", "white" };

	string unicodeWhiteChessPieces[6] = { "wpawn.png", "wknight.png" ,"wbishop.png" ,"wrook.png" ,"wqueen.png" ,"wking.png" };
	string unicodeBlackChessPieces[6] = { "bpawn.png", "bknight.png" ,"bbishop.png" ,"brook.png" ,"bqueen.png" ,"bking.png" };
};
