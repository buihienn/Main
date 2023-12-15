#pragma once
#include<iostream>
#include <raylib.h>
#include <vector>
#include <map>
using namespace std;

class Grid {
private:
	int numRow;
	int numCol;
	int sizeOfCell;

	vector <Color> colors;
public:
	Grid();
	int grid[20][10];
	void CreateAGrid();
	void print();
	vector <Color> GetColors();
	void DrawGrid();
	bool checkOutSide(int row, int col);
	bool checkEmpty(int row, int col); 
	bool checkRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int num);
	int ClearFullRow();
	void DrawWhite();
};


