#pragma once

#include <ostream>

class Pos{
public:
	int x, y;
	
	Pos(int a = -1, int b = 0) : x(a), y(b){}
	
	Pos operator+(const Pos& p) const;
	Pos operator-(const Pos& p) const;
	Pos operator=(const Pos& p);
	Pos operator+=(const Pos& p);
	Pos operator-=(const Pos& p);
	bool operator==(const Pos& p) const;
	bool operator!=(const Pos& p) const;
	bool operator<(const Pos& p) const;
	bool operator<=(const Pos& p) const;
	bool operator>(const Pos& p) const;
	bool operator>=(const Pos& p) const;
};

std::ostream& operator<<(std::ostream& os, const Pos& p);
