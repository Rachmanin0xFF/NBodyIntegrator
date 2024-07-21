#pragma once
#include "ofMain.h"
#include <iostream>


class VecList {
public:
	std::vector<glm::dvec3> v;
	int size;

	VecList(std::vector<glm::dvec3> &vecs);
	VecList(glm::dvec3 &vec);
	VecList(int &s);
	VecList();
	VecList& operator += (const VecList& a);
	VecList& operator -= (const VecList& a);
	VecList& operator *= (const double& a);
	void addTimes(const VecList& a, const double &b); // todo: use expression templates!!!
	void push_back(const glm::dvec3& v);

	void print();
};

VecList operator + (VecList a, const VecList &b);
VecList operator - (VecList a, const VecList &b);
VecList operator * (VecList a, const double &b);
VecList operator * (const double &b, const VecList &a);
VecList operator * (VecList a, const std::vector<double> &b);
VecList operator * (const std::vector<double>& b, const VecList &a);