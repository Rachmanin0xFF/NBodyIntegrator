#include "VecList.h"

VecList::VecList(std::vector<glm::dvec3> &vecs) {
	v = vecs;
	for (glm::dvec3& r : vecs) {
		r = glm::dvec3(r);
	}
	size = v.size();
}
VecList::VecList(glm::dvec3 &vec) {
	v = std::vector<glm::dvec3>();
	v.push_back(vec);
	size = 1;
}
VecList::VecList(int &s) {
	v = std::vector<glm::dvec3>(s);
	for (int i = 0; i < s; i++) {
		v[i] = glm::dvec3();
	}
	size = s;
}
VecList::VecList() {
	size = -1;
}
void VecList::push_back(const glm::dvec3& a) {
	v.push_back(a);
	size++;
}

void VecList::print() {
	std::cout << "size: " << size << std::endl;
	for (glm::dvec3& r : v) {
		std::cout << "\t" << r.x << " " << r.y << " " << r.z << " " << std::endl;
	}
}
VecList& VecList::operator += (const VecList& a) {
	for (int i = 0; i < size; i++) {
		v[i] += a.v[i];
	}
	return *this;
}
VecList& VecList::operator -= (const VecList& a) {
	for (int i = 0; i < size; i++) {
		v[i] -= a.v[i];
	}
	return *this;
}
VecList& VecList::operator *= (const double& a) {
	for (int i = 0; i < size; i++) {
		v[i] *= a;
	}
	return *this;
}
void VecList::addTimes(const VecList& a, const double &b) {
	for (int i = 0; i < size; i++) {
		v[i] += a.v[i]*b;
	}
}

VecList operator + (VecList a, const VecList& b) {
	for (int i = 0; i < a.size; i++) a.v[i] += b.v[i];
	return a;
}
VecList operator - (VecList a, const VecList& b) {
	for (int i = 0; i < a.size; i++) a.v[i] -= b.v[i];
	return a;
}



VecList operator * (VecList a, const double& b) {
	for (int i = 0; i < a.size; i++) a.v[i] *= b;
	return a;
}
VecList operator * (const double& b, const VecList &a) {
	return a * b;
}
VecList operator * (VecList a, const std::vector<double>& b) {
	for (int i = 0; i < a.size; i++) a.v[i] *= b[i];
	return a;
}
VecList operator * (const std::vector<double>& b, const VecList &a) {
	return a * b;
}