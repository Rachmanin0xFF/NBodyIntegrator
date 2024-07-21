#pragma once
#include "ofMain.h"

class Trail {
public:
	Trail() {};
	std::vector<glm::dvec3> vecs;
	void add_point(glm::dvec3 v) {
		vecs.push_back(v);
	};
	void display() {
		if (vecs.size() < 2) return;
		for (int i = 1; i < vecs.size(); i++) {
			ofDrawLine(vecs[i - 1].x, vecs[i - 1].y, vecs[i - 1].z, vecs[i].x, vecs[i].y, vecs[i].z);
		}
	}
};