#pragma once

#include "ofMain.h"
#include "GuiApp.h"

#include "Cell.h"
#include "Agent.h"

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		/* IMPORTANT POSITION OF SHARED POINTER */
		shared_ptr<GuiApp> gui;


		/*	MY METHODS	*/
		void resetSys();
		void initSys();

		int numXGrids, numYGrids, numZGrids;
		float gridLength, gridWidth, gridDepth;
		bool isolateXYPlane, isolateYZPlane, isolateZXPlane;
		int XYToIsolate, YZToIsolate, ZXToIsolate;

		ofEasyCam cam;

		vector<Cell> CELLS;
		Agent a0, a1, a2, a3, a4;
		string MSG="";
};