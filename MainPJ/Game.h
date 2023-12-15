#pragma once
#include <random>
#include "Grid.h"
#include "brick.h"

class Game {
private:
	vector <Brick> bricks;
	Grid grid;
	Brick curBrick;
	Brick nextBrick;
	Brick ghostBrick;
	bool gameOver;
	int score;
	Sound rotateSound;
	Sound clearSound;
	Sound moveSound;
	
public:
	Game();
	Grid GetGrid();
	Brick RandomBrick();
	Brick GetCurBrick();
	void SetGameOver(bool temp);
	void Draw();
	void HandleInput();
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void MoveDownInstant();
	bool checkOutSide(Brick brick);
	void RotateBrick();
	void LockBrick();
	bool checkFit(Brick brick);
	void Reset();
	bool GetGameOver();
	void UpdateScore(int numLineCleared);
	int GetScore();
	void DrawOver();
	Music music;
	~Game();
};

