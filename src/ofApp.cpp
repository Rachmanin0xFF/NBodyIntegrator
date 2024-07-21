#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sphere.setRadius(2);
	sphere.setResolution(3);
	lamp1.setDirectional();
	lamp1.setDiffuseColor(ofFloatColor(1.0, 0.9, 0.8));
	lamp2.setDirectional();
	lamp2.setDiffuseColor(ofFloatColor(0.7, 0.8, 1.0));
	lamp2.rotateDeg(150, glm::vec3(1, 0, 0));
	myGraph = new Plotter(ofRectangle(10, 10, 300, 100));

	nb1.current_state.r = VecList(glm::dvec3(50.0, 0.0, 0.0));
	nb1.current_state.r.push_back(glm::dvec3(-50.0, 0.0, 0.0));
	nb1.current_state.r.push_back(glm::dvec3(-5.0, 20.0, 0.0));
	nb1.current_state.v = VecList(glm::dvec3(0.0, 10.0, -15.0));
	nb1.current_state.v.push_back(glm::dvec3(0.0, -10.0, -15.0));
	nb1.current_state.v.push_back(glm::dvec3(0.0, 0.0, 30.0));
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < 3000; i++) {
		nb1.update_RK4();
	}
	tr1.add_point(nb1.current_state.r.v[0]);
	tr2.add_point(nb1.current_state.r.v[1]);
	tr3.add_point(nb1.current_state.r.v[2]);
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate() << " ms: " << (1000.0 / ofGetFrameRate());
	ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
double vrot = 0.0;
void ofApp::draw(){
	ofBackground(0);
	ofEnableDepthTest();
	cam.begin();
	ofRotateY(vrot); vrot += 0.2;
	lamp1.enable();
	lamp2.enable();
	ofPushMatrix();
	
	ofSetColor(ofColor::aquamarine);
	sphere.setPosition(nb1.current_state.r.v[0]);
	sphere.draw();
	ofSetColor(ofColor::lightCoral);
	sphere.setPosition(nb1.current_state.r.v[1]);
	sphere.draw();
	ofSetColor(ofColor::springGreen);
	sphere.setPosition(nb1.current_state.r.v[2]);
	sphere.draw();
	lamp1.disable();
	lamp2.disable();

	ofSetColor(ofColor::aquamarine);
	tr1.display();
	ofSetColor(ofColor::lightCoral);
	tr2.display();
	ofSetColor(ofColor::springGreen);
	tr3.display();

	ofPopMatrix();
	cam.end();
	ofDisableDepthTest();

	myGraph->display();

}