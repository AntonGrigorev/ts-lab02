#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
#include <ctime>
#include <vector>

double f(double x) {
	return -cos(0.5 * x) - 1;
}

double g(double x) {
	return sin(5*x)*f(x);
}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int main() {
	srand(time(0));
	const double a = -2;
	const double b = 4;
	double x = 0;
	double N = 0;
	double P1 = 0;
	double Pn = 0;
	std::array<double, 10> P;
	std::array<double, 20> q;
	std::vector<double> func_v;
	P[0] = 0.9;
	q[0] = 0.005;
	for (int i = 1; i < 10; i++) {
		P[i] = P[i - 1] + 0.01;
	}
	for (int i = 1; i < 20; i++) {
		q[i] = q[i - 1] + 0.005;
	}
	std::cout << "f(x)" << std::endl;  //f(x) = -cos(0.5x) - 1
	for (int i = 0; i < 10; i++) {
		std::cout << "P = " << P[i] << std::endl;
		for (int j = 0; j < 20; j++) {
			N = ceil(log(1 - P[i]) / log(1 - q[j]));
			P1 = 1 - q[j];
			Pn = pow(P1, N);
			std::cout <<"  P1 = " << P1 << "    Pn = " << Pn << std::endl;
			std::cout << "   q = "<< q[j] << "     N = " << N;
			for (int k = 1; k <= N; k++) {
				x = fRand(a, b);
				func_v.push_back(f(x));	
			}
			auto result = std::min_element(func_v.begin(), func_v.end());
			std::cout << "   Fmin = " << *result << std::endl;
			func_v.clear();
		}
	}

	std::cout << "f(x) * sin5x" << std::endl;     //g(x) = f(x)*sin(5x)
	for (int i = 0; i < 10; i++) {
		std::cout << "P = " << P[i] << std::endl;
		for (int j = 0; j < 20; j++) {
			N = ceil(log(1 - P[i]) / log(1 - q[j]));
			P1 = 1 - q[j];
			Pn = pow(P1, N);
			std::cout << "  P1 = " << P1 << "    Pn = " << Pn << std::endl;
			std::cout << "   q = " << q[j] << "     N = " << N;
			for (int k = 1; k <= N; k++) {
				x = fRand(a, b);
				func_v.push_back(g(x));
			}
			auto result = std::min_element(func_v.begin(), func_v.end());
			std::cout << "   Fmin = " << *result << std::endl;
			func_v.clear();
		}
	}
}
