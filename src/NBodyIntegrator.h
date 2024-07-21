#pragma once
#include "Integrator.h"

class NBodyIntegrator : public Integrator {
public:
	State current_state;
	double t = 0.0;
	double dt = 0.000002;
	VecList acceleration(const State& state, double t);
	void update_RK4();
	void update_SemiImplicitEuler();
	void update_ExplicitEuler();
};