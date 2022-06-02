struct ChessPiece {
	short int type;          //[PAWN-0; KNIGHT-1; BISHOP-2; ROOK-3; QUEEN-4; KING-5]
	short int x_coordinate;  //[ 0-15 ]
	short int y_coordinate;  //[ 0-15 ] 
	bool color;              //[BLACK-0; WHITE-1]

	// Movement constraints
	bool straight;     //[UNABLE-0; ABLE-1]
	bool diagonal;     //[UNABLE-0; ABLE-1]
	bool knight_jump;  //[UNABLE-0; ABLE-1]
};
