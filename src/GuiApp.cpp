#include "GuiApp.h"

void GuiApp::setup()
{
	parameters.setName("Controls");
	parameters.add(blank0.set(""));
	parameters.add(grids.set("GRIDS"));
	parameters.add(blank1.set(""));
	parameters.add(gridLength.set("(slider)GridLength", 10, 5, 20));
	parameters.add(gridWidth.set("(slider)GridWidth", 10, 5, 20));
	parameters.add(gridDepth.set("(slider)GridHeight", 10, 5, 20));
	parameters.add(numXGrids.set("(slider)numXGrids", 10, 1, 20));
	parameters.add(numYGrids.set("(slider)numYGrids", 10, 1, 20));
	parameters.add(numZGrids.set("(slider)numZGrids", 5, 1, 20));
	
	parameters.add(blank2.set(""));
	parameters.add(wireframe.set("(T/F) WireFrame", false));
	parameters.add(blank3.set(""));
	
	parameters.add(blank4.set(""));
	parameters.add(isolate.set("ISOLATE LEVELS"));
	parameters.add(blank5.set(""));
	parameters.add(isolateZXPlane.set("(T/F)isolate level", false));
	parameters.add(ZXToIsolate.set("(slider) ZX grid", 3, 0, 15));

	parameters.add(blank6.set(""));
	parameters.add(show.set("SHOW GRIDS"));
	parameters.add(blank7.set(""));
	parameters.add(showGrid.set("(T/F) show grids", true));
	
	parameters.add(blank8.set(""));
	parameters.add(Area.set("AGENT AREA(s) in %"));
	parameters.add(blank9.set(""));
	parameters.add(agentArea0.set("Area 0", 15, 1, 50));
	parameters.add(agentArea1.set("Area 1", 15, 1, 50));
	parameters.add(agentArea2.set("Area 2", 15, 1, 50));
	parameters.add(agentArea3.set("Area 3", 15, 1, 50));
	parameters.add(agentArea4.set("Area 4", 15, 1, 50));


	parameters.add(color0.set("color Area 0", 100, ofColor(0, 0), 255));
	parameters.add(color1.set("color Area 1", 100, ofColor(0, 0), 255));
	parameters.add(color2.set("color Area 2", 100, ofColor(0, 0), 255));
	parameters.add(color3.set("color Area 3", 100, ofColor(0, 0), 255));
	parameters.add(color4.set("color Area 4", 100, ofColor(0, 0), 255));

	parameters.add(blank10.set(""));
	parameters.add(isoAr.set("ISOLATE AREAS"));
	parameters.add(blank11.set(""));
	parameters.add(isolateArea0.set("isolate 0", true));
	parameters.add(isolateArea1.set("isolate 1", true));
	parameters.add(isolateArea2.set("isolate 2", true));
	parameters.add(isolateArea3.set("isolate 3", true));
	parameters.add(isolateArea4.set("isolate 4", true));

	gui.setup(parameters);
	gui.setBackgroundColor(0);
	gui.setBorderColor(255);
	gui.setFillColor(ofColor(255, 0, 0));

}
void GuiApp::update()
{
}
void GuiApp::draw()
{
	ofBackground(0);
	ofSetVerticalSync(false);
	gui.draw();
}

