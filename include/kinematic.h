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
		//std::vector<double> _frame;
		std::vector<double> crossProduct(std::vector<double> u, std::vector<double> v);
		double normalize(std::vector<double> p);
		std::vector<double> rotmat2rotvec(std::vector<double> rotmat);
		double d2r(double degree);
		//void setStart(std::vector<double> initPoint);
		//void setX(std::vector<double> xPoint);
		//void setY(std::vector<double> yPoint);
	public:
		Kinematic(std::vector<double> init, std::vector<double> x, std::vector<double> y);
		std::vector<double> createFrame();
		//std::vector<double> getFrame();
		//std::vector<double> getInit();
		//std::vector<double> getX();
		//std::vector<double> getY();
};

#endif // KINEMATIC_H
