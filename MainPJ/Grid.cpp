#include "Grid.h"

Grid::Grid() {
	numRow = 20;
	numCol = 10;
	sizeOfCell = 30;
	CreateAGrid();
	colors = GetColors();
}

void Grid::CreateAGrid() {
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			grid[i][j] = 0;
		}
	}
}

void Grid::print() {
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

vector <Color> Grid::GetColors() {
	const Color darkGrey = { 26, 31, 40, 255 };
	const Color green = { 47, 230, 23, 255 };
	const Color red = { 232, 18, 18, 255 };
	const Color orange = { 226, 116, 17, 255 };
	const Color yellow = { 237, 234, 4, 255 };
	const Color purple = { 166, 0, 247, 255 };
	const Color cyan = { 21, 204, 209, 255 };
	const Color blue = { 13, 64, 216, 255 };
	const Color lightBlue = { 59, 85, 162, 255 };
	const Color darkBlue = { 44, 44, 127, 255 };
	
	return {darkGrey, green, red, orange, yellow, purple, cyan, blue };
}

//void Grid::DrawGrid() {
//	for (int i = 0; i < numRow; i++) {
//		for (int j = 0; j < numCol; j++) {
//			int cellValue = grid[i][j];
//			DrawRectangle(j * sizeOfCell + 1, (i - 3) * sizeOfCell + 1, sizeOfCell - 1, sizeOfCell - 1, colors[grid[i][j]]);
//		}
//	}
//}

void Grid::DrawGrid() {
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			int cellValue = grid[i][j];
			DrawRectangle(j * sizeOfCell + 11, i * sizeOfCell + 11, sizeOfCell - 1, sizeOfCell - 1, colors[grid[i][j]]);
		}
	}
}

bool Grid::checkOutSide(int row, int col) {
	if (row >= 0 && row < numRow && col >= 0 && col < numCol) {
		return false;
	}
	return true;
}

bool Grid::checkEmpty(int row, int col) {
	if (grid[row][col] == 0) {
		return true;
	}
	return false;
}

bool Grid::checkRowFull(int row) {
	for (int i = 0; i < numCol; i++) {
		if (grid[row][i] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row) {
	for (int i = 0; i < numCol; i++) {
		grid[row][i] = 0;
	}
}

void Grid::MoveRowDown(int row, int num) {
	for (int i = 0; i < numCol; i++) {
		grid[row + num][i] = grid[row][i];
		grid[row][i] = 0;
	}
}

int Grid::ClearFullRow() {
	int numRowClear = 0;
	for (int i = numRow - 1; i >= 0; i--) {
		if (checkRowFull(i)) {
			ClearRow(i);
			numRowClear++;
		}
		else if (numRowClear > 0) {
			MoveRowDown(i, numRowClear);
		}
	}
	return numRowClear;
}

void Grid::DrawWhite() {
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			if (grid[i][j] != 0) {
				DrawRectangle(j * sizeOfCell + 11, i * sizeOfCell + 11, sizeOfCell - 1, sizeOfCell - 1, WHITE);
			}
		}
	}
}