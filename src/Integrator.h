#pragma once
#include "VecList.h"

struct State {
	VecList r;
	VecList v;
	State() {}
};

struct Derivative {
	VecList dr;
	VecList dv;
	Derivative() {};
	Derivative(int len) {
		dr = VecList(len);
		dv = VecList(len);
	}
};

class Integrator
{
public:
	int count;
	Derivative eval(const State& init, double t, double dt, const Derivative& d);
	virtual VecList acceleration(const State& state, double t) = 0;
	void Integrator::integrate_RK4(State& state, double t, double dt);
	void Integrator::integrate_SemiImplicitEuler(State& state, double t, double dt); // symplectic
	void Integrator::integrate_ExplicitEuler(State& state, double t, double dt);
};