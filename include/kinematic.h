#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <iostream>
#include <array>
#include <vector>
#include <math.h>

class Kinematic {
	private:
		const double pi = std::acos(-1);
		std::vector<double> _initPoint;
		std::vector<double> _xPoint;
		std::vector<double> _yPoint;
		double normalize(std::vector<double> p); // giver vel ikke meget mening at sende som reference, siden den skal returnere en double? 
		std::vector<double> rotmat2rotvec(std::vector<double> rotmat); //kan den ikke bare sendes som reference? 
		double d2r(double degree);
		std::vector<double> crossProduct(std::vector<double> u, std::vector<double> v); // reference?
	public:
		Kinematic(std::vector<double> init, std::vector<double> x, std::vector<double> y);
		std::vector<double> createFrame();
};
#endif // KINEMATIC_H
