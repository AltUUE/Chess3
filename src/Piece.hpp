#pragma once

#include <vector>
#include "Pos.h"

#define WHITE 0
#define BLACK 1

class Piece{
public:
	std::vector<Pos> possible_moves;
	std::vector<Pos> controlled_squares;
	char type;	// '#' for empty
	bool color;
	
	Piece();
	Piece(char a, bool b);
	Piece(int* n);
	
	Piece operator=(const Piece& p);
};
