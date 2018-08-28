#include "ofApp.h"


void ofApp::initSys() {
	MSG = "";
	sysOccupiedCELLS.clear(); 
	float totalArea = (numXGrids*numYGrids*numZGrids*gridLength*gridDepth);
	MSG += "\ntotal Area = " + to_string(totalArea);
	MSG += "\ntotal Number of Cells = " + to_string(CELLS.size());
	MSG += "\ntotal Occupied  Cells = " + to_string(sysOccupiedCELLS.size());

	a0.clearTrail();
	float a0Area = totalArea*(gui->agentArea0) / 100;
	a0.setReqArea(a0Area);
	a0.setColor(gui->color0);
	a0.CELLS = CELLS;
	a0.initMove();
	float a0Deficit = a0Area - a0.gotArea(); totalDeficit = a0Deficit;
	sysOccupiedCELLS = a0.getSysOccCells();

	MSG += "\n\nRequired Area  #0= " + to_string(a0Area);
	MSG += "\nAchieved Area  #0= " + to_string(a0.gotArea());
	MSG += "\nDeficit Area   #0= " + to_string(a0Deficit);
	MSG += "\nCells occupied #0= " + to_string(a0.cellTrail.size());
	
	

	a1.clearTrail();
	float a1Area = totalArea*(gui->agentArea1) / 100;
	a1.setReqArea(a1Area);
	a1.setColor(gui->color1);
	a1.CELLS = CELLS;
	a1.setSysOccCells(sysOccupiedCELLS);
	a1.initMove();
	float a1Deficit = a1Area - a1.gotArea(); totalDeficit += a1Deficit;
	sysOccupiedCELLS.clear();
	sysOccupiedCELLS = a1.getSysOccCells();

	MSG += "\n\nRequired Area  #1= " + to_string(a1Area);
	MSG += "\nAchieved Area  #1= " + to_string(a1.gotArea());
	MSG += "\nDeficit Area   #1= " + to_string(a1Deficit);
	MSG += "\nCells occupied #1= " + to_string(a1.cellTrail.size());
	


	a2.clearTrail();
	float a2Area = totalArea*(gui->agentArea2) / 100;
	a2.setReqArea(a2Area);
	a2.setColor(gui->color2);
	a2.CELLS = CELLS;
	a2.setSysOccCells(sysOccupiedCELLS);
	a2.initMove();
	float a2Deficit = a2Area - a2.gotArea(); totalDeficit += a2Deficit;
	sysOccupiedCELLS.clear();
	sysOccupiedCELLS = a2.getSysOccCells();

	MSG += "\n\nRequired Area  #2= " + to_string(a2Area);
	MSG += "\nAchieved Area  #2= " + to_string(a2.gotArea());
	MSG += "\nDeficit Area   #2= " + to_string(a2Deficit);
	MSG += "\nCells occupied #2= " + to_string(a2.cellTrail.size());
	

	a3.clearTrail();
	float a3Area = totalArea*(gui->agentArea3) / 100;
	a3.setReqArea(a3Area);
	a3.setColor(gui->color3);
	a3.CELLS = CELLS;
	a3.setSysOccCells(sysOccupiedCELLS);
	a3.initMove();
	float a3Deficit = a3Area - a3.gotArea(); totalDeficit += a3Deficit;
	sysOccupiedCELLS.clear();
	sysOccupiedCELLS = a3.getSysOccCells();

	MSG += "\n\nRequired Area  #3= " + to_string(a3Area);
	MSG += "\nAchieved Area  #3= " + to_string(a3.gotArea());
	MSG += "\nDeficit Area   #3= " + to_string(a3Deficit);
	MSG += "\nCells occupied #3=  " + to_string(a3.cellTrail.size());
	


	a4.clearTrail();
	float a4Area = totalArea*(gui->agentArea4) / 100;
	a4.setReqArea(a4Area);
	a4.setColor(gui->color4);
	a4.CELLS = CELLS;
	a4.setSysOccCells(sysOccupiedCELLS);
	a4.initMove();
	float a4Deficit = a4Area - a4.gotArea(); totalDeficit += a4Deficit;
	sysOccupiedCELLS.clear();
	sysOccupiedCELLS = a4.getSysOccCells();
	
	MSG += "\n\nRequired Area  #4= " + to_string(a4Area);
	MSG += "\nAchieved Area  #4= " + to_string(a4.gotArea());
	MSG += "\nDeficit Area   #4= " + to_string(a4Deficit);
	MSG += "\nCells occupied #4= " + to_string(a4.cellTrail.size());

	MSG += "\n\n\nTotal deficit= " + to_string(totalDeficit);
	MSG += "\ntotal Occupied  Cells = " + to_string(sysOccupiedCELLS.size());
	MSG += "\n\n\nPress 'n' 'N' to run iterations ";
}

void ofApp::resetSys() {
	CELLS.clear();	
	int m = 0;
	int x = 0; 
	for (int i = 0; i < numXGrids; i++) {
		int y = 0;
		for (int j = 0; j < numYGrids; j++) {
			int z = 0;
			for (int k = 0; k < numZGrids; k++) {
				Cell cell(x, y, z, gridLength, gridWidth, gridDepth);
				cell.setIndices(m, i, j, k);
				CELLS.push_back(cell);
				z += gridDepth;
				m++;
			}
			y += gridWidth;
		}
		x += gridLength;
	}
}

void ofApp::setup(){
	srand(unsigned(std::time(0)));
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	cam.setDistance(400);
	gridLength = gui->gridLength;
	gridWidth = gui->gridWidth;
	gridDepth = gui->gridDepth;
	numXGrids = gui->numXGrids;
	numYGrids = gui->numYGrids;
	numZGrids = gui->numZGrids;
	isolateZXPlane = gui->isolateZXPlane;
	ZXToIsolate = gui -> ZXToIsolate;
	MSG = "\npress 'a' 'A' to start ";
	resetSys();
}

void ofApp::update(){
	gridLength = gui->gridLength;
	gridWidth = gui->gridWidth;
	gridDepth = gui->gridDepth;
	numXGrids = gui->numXGrids;
	numYGrids = gui->numYGrids;
	numZGrids = gui->numZGrids;
	ZXToIsolate = gui->ZXToIsolate;
	isolateZXPlane = gui->isolateZXPlane;
	

	resetSys();
}

void ofApp::draw(){
	ofBackground(0); 

	cam.begin();
	if (gui->showGrid == true) {
		for (int i = 0; i < CELLS.size(); i++) {
			if (isolateZXPlane == true) { CELLS[i].draw(ZXToIsolate, gui->wireframe); }
			else { CELLS[i].draw(gui->wireframe); }
		}
	}

	for (int i = 0; i < a0.cellTrail.size(); i++) {
		ofColor co = gui->color0; ofFill();
		a0.cellTrail[i].draw(co, false);
	}


	for (int i = 0; i < a1.cellTrail.size(); i++) {
		ofColor co = gui->color1; ofFill();
		a1.cellTrail[i].draw(co, false);
	}


	for (int i = 0; i < a2.cellTrail.size(); i++) {
		ofColor co = gui->color2; ofFill();
		a2.cellTrail[i].draw(co, false);
	}


	for (int i = 0; i < a3.cellTrail.size(); i++) {
		ofColor co = gui->color3; ofFill();
		a3.cellTrail[i].draw(co, false);
	}


	for (int i = 0; i < a4.cellTrail.size(); i++) {
		ofColor co = gui->color4; ofFill();
		a4.cellTrail[i].draw(co, false);
	}

	int axisDim = gridLength*numXGrids*1.5;
	ofDrawAxis(axisDim);
	cam.end();

	ofDisableDepthTest();
	ofSetColor(255, 255, 255); ofFill();
	ofDrawBitmapString(" Mouse Controls for 3d interface    ", 10, 20);
	ofDrawBitmapString("------------------------------------", 10, 40);
	ofDrawBitmapString(" Orbit: left-mouse button drag      ", 10, 60);
	ofDrawBitmapString(" (Drag down & left)                 ", 10, 80);
	ofDrawBitmapString(" (Axis : Red +X, Blue +Y, Green +Z  ", 10, 100);
	ofDrawBitmapString(" Pan: middle-mouse button drag      ", 10, 120);
	ofDrawBitmapString(" Zoom: scroll  / right-mouse drag   ", 10, 140);
	ofDrawBitmapString("Keyboard Controls                   ", 10, 180);
	ofDrawBitmapString("------------------------------------", 10, 200);
	ofDrawBitmapString("Press 'e' or 'E' to reset system    ", 10, 220);
	ofDrawBitmapString("Press 'a' or 'A' to occupy cells    ", 10, 260);
	ofDrawBitmapString("------------------------------------", 10, 300);
	ofDrawBitmapString("GRID: Left Window Controls          ", 10, 320);
	ofDrawBitmapString("------------------------------------", 10, 340);
	ofDrawBitmapString("Sliders for numerical parameters    ", 10, 360);
	ofDrawBitmapString("Boolean toggles for wireframe       ", 10, 380);
	ofDrawBitmapString("Color picker R,G,B,A                ", 10, 400);
	
	ofSetColor(255,0,0); ofFill(); ofDrawBitmapString(MSG,1000,40);
}

void ofApp::keyPressed(int key){
	if (key == 'e' || key == 'E') { resetSys(); }
	if (key == 'a' || key == 'A') { initSys(); }
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
