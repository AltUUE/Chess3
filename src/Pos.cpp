#include "Pos.h"

Pos Pos::operator+(const Pos& p) const {
	return {x + p.x, y + p.y};
}

Pos Pos::operator-(const Pos& p) const {
	return {x - p.x, y - p.y};
}

Pos Pos::operator=(const Pos& p){
	return (x = p.x, y = p.y, *this);
}

Pos Pos::operator+=(const Pos& p){
	return (x = x+p.x, y = y+p.y, *this);
}

Pos Pos::operator-=(const Pos& p){
	return (x = x-p.x, y = y-p.y, *this);
}

bool Pos::operator==(const Pos& p) const {
	return (x == p.x && y == p.y);
}

bool Pos::operator!=(const Pos& p) const {
	return (x != p.x || y != p.y);
}

bool Pos::operator<(const Pos& p) const {
	return (x < p.x && y < p.y);
}

bool Pos::operator<=(const Pos& p) const {
	return (x <= p.x && y <= p.y);
}

bool Pos::operator>(const Pos& p) const {
	return (x > p.x && y > p.y);
}

bool Pos::operator>=(const Pos& p) const {
	return (x >= p.x && y >= p.y);
}

std::ostream& operator<<(std::ostream& os, const Pos& p){
	os << '(' << p.x << ',' << ' ' << p.y << ')';
	return os;
}
