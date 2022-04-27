#include "Move.h"

void Move::updateFEN(const std::string new_board){
	if(backward == nullptr) return;
	
	const FEN& prev = backward->fen;
	
	fen.board = new_board;
	
	fen.turn = !prev.turn;
	
	fen.castle[0] = prev.castle[0];
	fen.castle[1] = prev.castle[1];
	fen.castle[2] = prev.castle[2];
	fen.castle[3] = prev.castle[3];
	if(from == Pos(0,0) || to == Pos(0,0) || from == Pos(5,0))
		fen.castle[1] = 0;
	if(from == Pos(7,0) || to == Pos(7,0) || from == Pos(5,0))
		fen.castle[0] = 0;
	if(from == Pos(0,7) || to == Pos(0,7) || from == Pos(5,7))
		fen.castle[3] = 0;
	if(from == Pos(7,7) || to == Pos(7,7) || from == Pos(5,7))
		fen.castle[2] = 0;
	
	if(moved_piece.type == 'P' && (from.y - to.y == 2 || from.y - to.y == -2))
		fen.en_passant = {to.x, to.y-(fen.turn*2-1)};
	else
		fen.en_passant = {-1,0};
	
	fen.halfmoves++;
	if(moved_piece.type == 'P' || captured_piece.type != '#')
		fen.halfmoves = 0;
	
	if(!fen.turn)
		fen.fullmoves++;
}

std::string Move::toString() const{
	if(castle >= 4){
		std::string ret;
		if(castle&1)
			ret = "0-0-0";
		else
			ret = "0-0";
		if(is_check)
			ret.append("+");
		return ret;
	}
	
	char ret[10];
	int i=0;
	if(moved_piece.type != 'P'){
		ret[i++] = moved_piece.type;
	}
	if(show_file){
		ret[i++] = from.x + 'a';
	}
	if(show_rank){
		ret[i++] = from.y + '1';
	}
	if(captured_piece.type != '#'){
		ret[i++] = 'x';
	}
	ret[i++] = to.x + 'a';
	ret[i++] = to.y + '1';
	if(promoted_to.type != '#'){
		ret[i++] = '=';
		ret[i++] = promoted_to.type;
	}
	if(is_check){
		ret[i++] = '+';
	}
	ret[i] = '\0';
	
	return std::string(ret);
}
