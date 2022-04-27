#include "Piece.h"

Piece::Piece(){
	type = 'K';
	color = WHITE;
}

Piece::Piece(char a, bool b){
	type = a;
	color = b;
}

Piece::Piece(int* n){	//NULL goes here
	type = '#';
	color = WHITE;
}

Piece Piece::operator=(const Piece& p){
	return (possible_moves = p.possible_moves, type = p.type, color = p.color, *this);
}
