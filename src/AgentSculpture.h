#pragma once

#include "ofMain.h"
#include "Cell.h"
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

class AgentSculpture
{
public:
	float reqArea;
	ofColor COL;
	vector<Cell> cellTrail;
	vector<Cell> CELLS;
	vector <Cell> sysOccupiedCells;
	
	AgentSculpture() {};

	void setReqArea(float ar) { reqArea = ar; }
	void setSysOccCells(vector <Cell>);
	vector<Cell> getSysOccCells() { return sysOccupiedCells; }
	void setColor(ofColor co) { COL = co; }
	float gotArea();
	
	void clearTrail();
	void initMove();
	
	void genMoves(int);

	int findCellByIndex(int, int, int);
	int checkOccupancy(int);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void moveIn();
	void moveOut();

};

