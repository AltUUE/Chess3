#pragma once

#include <string>
#include <vector>
#include "Pos.h"
#include "Piece.h"
#include "FEN.h"

class Move{
public:
	int num;
	FEN fen;
	
	Pos from;
	Pos to;
	Piece moved_piece;
	Piece captured_piece;
	Piece promoted_to;
	char castle;
	bool en_passant;
	
	//visual	
	bool is_check;
	//Nbd2
	bool show_file;	// =1
	bool show_rank;	// =0
	
	std::vector<Move*> forward;
	Move* backward;
	
	Move(){
		backward = nullptr;
	}
	
	void updateFEN(const std::string new_board);
	std::string toString() const;
};
