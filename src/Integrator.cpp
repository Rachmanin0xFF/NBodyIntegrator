#include "Integrator.h"

Derivative Integrator::eval(const State& init, double t, double dt, const Derivative& d) {
	State next(init);
	next.r.addTimes(d.dr, dt);
	next.v.addTimes(d.dv, dt);

	Derivative out(d);
	out.dr = next.v;
	out.dv = acceleration(next, t + dt);

	return out;
}

// TODO: allow arbitrary butcher tableau, general ERK
void Integrator::integrate_RK4(State& state, double t, double dt) {
	Derivative a, b, c, d;
	a = Integrator::eval(state, t, 0.0, Derivative(state.r.size));
	b = Integrator::eval(state, t, dt * 0.5, a);
	c = Integrator::eval(state, t, dt * 0.5, b);
	d = Integrator::eval(state, t, dt, c);

	VecList dxdt = VecList(b.dr);
	dxdt += c.dr; dxdt *= 2.0; dxdt += a.dr; dxdt += d.dr; dxdt *= 1.0 / 6.0;
	VecList dvdt = VecList(b.dv);
	dvdt += c.dv; dvdt *= 2.0; dvdt += a.dv; dvdt += d.dv; dvdt *= 1.0 / 6.0;
	state.r.addTimes(dxdt, dt);
	state.v.addTimes(dvdt, dt);
}

void Integrator::integrate_SemiImplicitEuler(State& state, double t, double dt) {
	state.v.addTimes(acceleration(state, t), dt);
	state.r.addTimes(state.v, dt);
}

void Integrator::integrate_ExplicitEuler(State& state, double t, double dt) {
	VecList& acc = acceleration(state, t);
	state.r.addTimes(state.v, dt);
	state.v.addTimes(acc, dt);
}