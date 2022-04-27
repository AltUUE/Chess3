#pragma once

#include "Pos.h"
#include "Piece.h"

class Move{
public:
	int num;
	
	Pos from;
	Pos to;
	Piece moved_piece;
	Piece captured_piece;
	Piece promoted_to;
	char castle;
	bool en_passant;
	
	//visual	
	//Nbd2+
	bool is_check;	// =1
	bool show_file;	// =1
	bool show_rank;	// =0
};
