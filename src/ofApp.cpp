#include "ofApp.h"

void ofApp::initSys() {
	a0.setReqArea(gui->agentArea0);
	a0.setColor(gui->color0);
	a0.CELLS = CELLS;
	a0.initMove();
	
	a1.setReqArea(gui->agentArea1);
	a1.setColor(gui->color1);
	a1.CELLS = CELLS;
	a1.initMove();

	a2.setReqArea(gui->agentArea2);
	a2.setColor(gui->color2);
	a2.CELLS = CELLS;
	a2.initMove();

	a3.setReqArea(gui->agentArea3);
	a3.setColor(gui->color3);
	a3.CELLS = CELLS;
	a3.initMove();

	a4.setReqArea(gui->agentArea4);
	a4.setColor(gui->color4);
	a4.CELLS = CELLS;
	a4.initMove();
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
	ofDrawBitmapString(" Mouse Controls for 3d interface            ", 10, 20);
	ofDrawBitmapString("--------------------------------------------", 10, 40);
	ofDrawBitmapString(" Orbit: left-mouse button drag              ", 10, 60);
	ofDrawBitmapString(" (Drag down & left)                         ", 10, 80);
	ofDrawBitmapString(" (Axis : Red +X, Blue +Y, Green +Z          ", 10, 100);
	ofDrawBitmapString(" Pan: middle-mouse button drag              ", 10, 120);
	ofDrawBitmapString(" Zoom: scroll  / right-mouse drag           ", 10, 140);
	ofDrawBitmapString("Keyboard Controls                           ", 10, 180);
	ofDrawBitmapString("-----------------------------------------   ", 10, 200);
	ofDrawBitmapString("Press 'e' or 'E' to reset system            ", 10, 220);
	ofDrawBitmapString("Press 'c' or 'C' to clear cell trails       ", 10, 240);
	ofDrawBitmapString("Press 'a' or 'A' to reset init cell trail   ", 10, 260);
	ofDrawBitmapString("Press 'l' or 'L' to move left    -X   red   ", 10, 280);
	ofDrawBitmapString("Press 'r' or 'R' to move right   +X   red   ", 10, 300);
	ofDrawBitmapString("Press 'u' or 'U' to move up      -Y   green ", 10, 320);
	ofDrawBitmapString("Press 'd' or 'D' to move down    +Y   green ", 10, 340);
	ofDrawBitmapString("Press 'i' or 'I' to move in      +Z   blue  ", 10, 360);
	ofDrawBitmapString("Press 'o' or 'O' to move out     -Z   blue  ", 10, 380);
	ofDrawBitmapString("--------------------------------------------", 10, 440);
	ofDrawBitmapString("GRID: Left Window Controls                  ", 10, 460);
	ofDrawBitmapString("--------------------------------------------", 10, 480);
	ofDrawBitmapString("Sliders for various numerical parameters    ", 10, 500);
	ofDrawBitmapString("Boolean toggles for wireframe / color cells ", 10, 520);
	ofDrawBitmapString("Color picker R,G,B,A for user cell trail    ", 10, 540);
	
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
