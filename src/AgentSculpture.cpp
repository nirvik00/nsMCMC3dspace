#include "AgentSculpture.h"

void AgentSculpture::setSysOccCells(vector <Cell> t) {
	for (int i = 0; i < t.size(); i++) {
		sysOccupiedCells.push_back(t[i]);
	}
}

int AgentSculpture::findCellByIndex(int u, int v, int w) {
	int idx = -1;
	for (int t = 0; t < CELLS.size(); t++) {
		int i = CELLS[t].I;
		int j = CELLS[t].J;
		int k = CELLS[t].K;
		if (u == i && v == j && k == w) {
			idx = t;
			break;
		}
	}
	return idx;
}

int AgentSculpture::checkOccupancy(int u) {
	int sum = 0;
	for (int t = 0; t < cellTrail.size(); t++) {
		if (CELLS[u].CellId == cellTrail[t].CellId) { sum++; break; }
	}
	for (int i = 0; i < sysOccupiedCells.size(); i++) {
		if (CELLS[u].CellId == sysOccupiedCells[i].CellId) { sum++; break; }
	}
	if (sum == 0) return 0;
	else return 1;
}

float AgentSculpture::gotArea() {
	float sum = 0;
	for (int i = 0; i < cellTrail.size(); i++) {
		sum += cellTrail[i].cellArea();
	}
	return sum;
}

void AgentSculpture::clearTrail() {
	cellTrail.clear();
	sysOccupiedCells.clear();
}

void AgentSculpture::initMove() {
	cellTrail.clear();
	random_shuffle(CELLS.begin(), CELLS.end());
	Cell a = CELLS[0];
	cellTrail.push_back(a);
	if (gotArea() < reqArea) { genMoves(0); }
	
	setSysOccCells(cellTrail);
}

void AgentSculpture::genMoves(int rec)
{
	vector<int> opts = { 0, 1, 2, 3, 4, 5 };
	random_shuffle(opts.begin(), opts.end());

	int x = opts[0];
	if (x == 0) { moveLeft(); }
	else if (x == 1) { moveRight(); }
	else if (x == 2) { moveUp(); }
	else if (x == 3) { moveDown(); }
	else if (x == 4) { moveIn(); }
	else { moveOut(); }
	
	if (gotArea() < reqArea && rec<100) { rec++; genMoves(rec); }
	
}

void AgentSculpture::moveLeft() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(--I, J, K);
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
	}
}

void AgentSculpture::moveRight() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(++I, J, K);
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
	}
}

void AgentSculpture::moveUp() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, ++J, K);
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
	}
	else {
	}
}

void AgentSculpture::moveDown() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, --J, K);
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
	}
	else {
	}
}

void AgentSculpture::moveIn() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, J, --K);
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
	}
	else {
	}
}

void AgentSculpture::moveOut() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, J, ++K);
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
	}
	else {
	}
}
