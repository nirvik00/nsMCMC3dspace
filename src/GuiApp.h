#pragma once


#include "ofMain.h"
#include "ofxGui.h"

class GuiApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	
	
	ofParameterGroup parameters;

	ofParameter <string> blank0;
	ofParameter <string> grids;
	ofParameter <string> blank1;
	
	ofParameter<int>numXGrids;
	ofParameter<int>numYGrids;
	ofParameter<int>numZGrids;
	ofParameter<int>gridLength;
	ofParameter<int>gridWidth;
	ofParameter<int>gridDepth;

	ofParameter <string> blank2;
	ofParameter<bool>wireframe;
	ofParameter <string> blank3;

	ofParameter <string> blank4;
	ofParameter <string> isolate;
	ofParameter <string> blank5;
	ofParameter<bool>isolateZXPlane;
	ofParameter<int>ZXToIsolate;

	ofParameter <string> blank6;
	ofParameter <string> show;
	ofParameter<bool>showGrid;
	ofParameter <string> blank7;


	ofParameter <string> blank8;
	ofParameter <string> Area;
	ofParameter <string> blank9;
	ofParameter<float> agentArea0;
	ofParameter<float> agentArea1;
	ofParameter<float> agentArea2;
	ofParameter<float> agentArea3;
	ofParameter<float> agentArea4;

	ofParameter<ofColor> color0;
	ofParameter<ofColor> color1;
	ofParameter<ofColor> color2;
	ofParameter<ofColor> color3;
	ofParameter<ofColor> color4;
	
	ofParameter <string> blank10;
	ofParameter <string> isoAr;
	ofParameter <string> blank11;
	ofParameter<bool>isolateArea0;
	ofParameter<bool>isolateArea1;
	ofParameter<bool>isolateArea2;
	ofParameter<bool>isolateArea3;
	ofParameter<bool>isolateArea4;


	ofxPanel gui;
};

