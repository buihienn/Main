#include "Brick.h"
#include "Game.h"
Brick::Brick() {
	sizeOfCell = 30;
	color = { 0, 0, 0, 0 };
	rotationState = 0;
	rowOffset = 0;
	colOffset = 0;
	id = 0;
	isGhost = false;
}


void Brick::Draw(int offsetX, int offsetY) {
	vector <Position> temp = GetCellPos();
	if (isGhost) {
		for (int i = 0; i < temp.size(); i++) {
			DrawRectangleLines(temp[i].getCol() * sizeOfCell + offsetX, (temp[i].getRow()) * sizeOfCell + offsetY, sizeOfCell - 1, sizeOfCell - 1, color);
		}
	}
	else {
		for (int i = 0; i < temp.size(); i++) {
			DrawRectangle(temp[i].getCol() * sizeOfCell + offsetX, (temp[i].getRow()) * sizeOfCell + offsetY, sizeOfCell - 1, sizeOfCell - 1, color);
		}
	}

}

void Brick::SetID(int id) {
	this->id = id;
}


void Brick::Move(int row, int col) {
	rowOffset += row;
	colOffset += col;
}

vector <Position> Brick::GetCellPos() {
	vector <Position> temp = cells[rotationState];
	vector <Position> moved;
	for (int i = 0; i < temp.size(); i++) {
		Position newPos = Position(temp[i].getRow() + rowOffset, temp[i].getCol() + colOffset);
		moved.push_back(newPos);
	}
	return moved;
}

int Brick::GetID() {
	return id;
}

void Brick::Rotate() {
	rotationState++;
	if (rotationState == (int)cells.size()) {
		rotationState = 0;
	}
}

void Brick::Unrotate() {
	rotationState--;
	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}

Brick& Brick::operator=(const Brick& other) {
	if (this != &other) { 
		sizeOfCell = other.sizeOfCell;
		color = other.color;
		rotationState = other.rotationState;
		cells = other.cells;
		rowOffset = other.rowOffset;
		colOffset = other.colOffset;
		id = other.id;
	}
	return *this;
}

void Brick:: TurnToGhost() {
	isGhost = true;
}

// LBrick
LBrick::LBrick() {
	id = 1;
	color = { 47, 230, 23, 255 }; // Green
	cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
	cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
	Move(0,3);
}


// JBrick
JBrick::JBrick() {
	id = 2;
	color = { 232, 18, 18, 255 }; // Red
	cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
	cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
	Move(0, 3);
}

// LBrick
ZBrick::ZBrick() {
	id = 7;
	color = { 13, 64, 216, 255 }; // Blue
	cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
	cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
	Move(0, 3);
}

TBrick::TBrick() {
	id = 6;
	color = { 21, 204, 209, 255 }; // Cyan
	cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
	cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
	Move(0, 3);
}

SBrick::SBrick() {
	id = 5;
	color = { 166, 0, 247, 255 }; // purple
	cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
	cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
	cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
	cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
	Move(0, 3);
}

OBrick::OBrick() {
	id = 4;
	color = { 237, 234, 4, 255 }; // Yellow
	cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
	Move(0, 4);
}

IBrick::IBrick() {
	id = 3;
	color = { 226, 116, 17, 255 }; // Orange
	cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
	cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
	cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
	cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
	Move(-1, 3);
}


