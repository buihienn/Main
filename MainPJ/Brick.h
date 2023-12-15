#pragma once
#include "Grid.h"
#include "Position.h"

class Brick {
protected:
	int sizeOfCell;
	Color color;
	int rotationState;
	map <int, vector <Position>> cells;
	int rowOffset;
	int colOffset;
	int id;
	bool isGhost;
public:
	Brick();
	void Draw(int offsetX, int offsetY);
	void Move(int row, int col);
	vector <Position> GetCellPos();
	int GetID();
	void Rotate();
	void Unrotate();
	void SetID(int id);
	Brick& operator=(const Brick& other);
	void TurnToGhost();
};

class LBrick : public Brick {
public:
	LBrick();
};

class JBrick : public Brick {
public:
	JBrick();
};

class IBrick : public Brick {
public:
	IBrick();
};

class OBrick : public Brick {
public:
	OBrick();
};
class SBrick : public Brick {
public:
	SBrick();
	
};
class TBrick : public Brick {
public:
	TBrick();
};

class ZBrick : public Brick {
public:
	ZBrick();
};
