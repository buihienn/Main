#include "Position.h"

Position::Position(int row, int col) {
	this->row = row;
	this->col = col;
}

int Position::getRow() {
	return row;
}
int Position::getCol() {
	return col;
}