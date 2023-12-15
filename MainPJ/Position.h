#pragma once

class Position {
private:
	int row;
	int col;
public:
	Position(int row, int col);
	int getRow();
	int getCol();
};