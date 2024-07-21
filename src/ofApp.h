#pragma once

#include "ofMain.h"
#include "NBodyIntegrator.h"
#include "Plotter.h"
#include "Trail.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	private:
		ofEasyCam cam;
		ofIcoSpherePrimitive sphere;
		ofLight lamp1;
		ofLight lamp2;

		NBodyIntegrator nb1;
		Trail tr1;
		Trail tr2;
		Trail tr3;

		Plotter* myGraph;
};
