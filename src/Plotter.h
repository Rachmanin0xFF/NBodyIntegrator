#pragma once
#include "ofMain.h"
class Plotter {
public:
	std::vector<double> pts;
	ofRectangle bounds;

	Plotter(ofRectangle b) {
		bounds = b;
	};

	void display() {
		ofNoFill();
		ofSetColor(ofColor::white);
		ofDrawRectangle(bounds);
	};

	void addpt(double x) {
		pts.push_back(x);
	}
};