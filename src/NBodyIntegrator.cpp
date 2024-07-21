#include "NBodyIntegrator.h"

VecList NBodyIntegrator::acceleration(const State& state, double t) {
	VecList acc_list(state.r);
	glm::dvec3 dir;
	for (int i = 0; i < acc_list.size; i++) {
		acc_list.v[i] = glm::dvec3();
		for (int j = 0; j < acc_list.size; j++) {
			if (i != j) {
				dir = state.r.v[j] - state.r.v[i];
				acc_list.v[i] += 100000.0 * dir / pow(glm::length(dir), 3.0);
			}
		}
	}
	return acc_list;
}

void NBodyIntegrator::update_RK4() {
	integrate_RK4(current_state, t, dt);
	t += dt;
}

void NBodyIntegrator::update_SemiImplicitEuler() {
	integrate_SemiImplicitEuler(current_state, t, dt);
	t += dt;
}

void NBodyIntegrator::update_ExplicitEuler() {
	integrate_ExplicitEuler(current_state, t, dt);
	t += dt;
}