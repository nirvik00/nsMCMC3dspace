#include "Cell.h"



Cell::Cell(int x, int y, int z, float l, float w, float h)
{
	X = x; Y = y; Z = z;
	gridL = l; gridW = w; gridD = h;
	LEVEL = (int)(Y/gridW);

	pts.push_back(ofVec3f(X, Y, Z));
	pts.push_back(ofVec3f(X + gridL, Y, Z));
	pts.push_back(ofVec3f(X + gridL, Y, Z + gridD));
	pts.push_back(ofVec3f(X, Y, Z + gridD));
	pts.push_back(ofVec3f(X, Y + gridW, Z));
	pts.push_back(ofVec3f(X + gridL, Y + gridW, Z));
	pts.push_back(ofVec3f(X + gridL, Y + gridW, Z + gridD));
	pts.push_back(ofVec3f(X, Y + gridW, Z + gridD));


}

float Cell::cellArea() {
	return gridL*gridD;
}

void Cell::setIndices(int cellId, int i, int j, int k) {
	CellId = cellId; I = i; J = j; K = k;
}

void Cell::drawEdges() {
	ofSetColor(100,100,100); glLineWidth(1);
	ofDrawLine(pts[0], pts[1]);
	ofDrawLine(pts[1], pts[2]);
	ofDrawLine(pts[2], pts[3]);
	ofDrawLine(pts[3], pts[0]);
	ofDrawLine(pts[4], pts[5]);
	ofDrawLine(pts[5], pts[6]);
	ofDrawLine(pts[6], pts[7]);
	ofDrawLine(pts[7], pts[4]);
	ofDrawLine(pts[0], pts[4]);
	ofDrawLine(pts[1], pts[5]);
	ofDrawLine(pts[2], pts[6]);
	ofDrawLine(pts[3], pts[7]);
}

void Cell::draw() {
	ofSetColor(255, 0, 0, 50);
	ofDrawBox(X + gridL / 2, Y + gridW / 2, Z + gridD / 2, gridL, gridW, gridD);
	drawEdges();
}

void Cell::draw(bool w) {
	if (w == false) {
		ofSetColor(255, 0, 0, 50);
		ofDrawBox(X + gridL / 2, Y + gridW / 2, Z + gridD / 2, gridL, gridW, gridD);
	}
	drawEdges();
}

void Cell::draw(int t, bool w) {
	if (t == LEVEL) { 
		if (w == false) {
			ofSetColor(255, 0, 0, 50);
			ofDrawBox(X + gridL / 2, Y + gridW / 2, Z + gridD / 2, gridL, gridW, gridD);
		}
		if(w==true) { drawEdges(); }
	}
}

void Cell::draw(ofColor co, bool w) {
	if (w == false) {
		ofSetColor(co);
		ofDrawBox(X + gridL / 2, Y + gridW / 2, Z + gridD / 2, gridL, gridW, gridD);
	}
	if(w==true){ drawEdges(); }	
}

void Cell::draw(ofColor co, int t, bool w) {
	if (t == LEVEL) {
		if (w == false) {
			ofSetColor(co);
			ofDrawBox(X + gridL / 2, Y + gridW / 2, Z + gridD / 2, gridL, gridW, gridD);
		}
		if(w==true) { drawEdges(); }		
	}
	else {
		if (w == false) {
			ofSetColor(co);
			ofDrawBox(X + gridL / 2, Y + gridW / 2, Z + gridD / 2, gridL, gridW, gridD);
		}
		if (w == true) { drawEdges(); }
	}
}