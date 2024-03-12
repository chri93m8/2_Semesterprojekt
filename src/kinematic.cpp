#include "kinematic.h"

Kinematic::Kinematic() {
	std::cout << "Kinematic" << std::endl;
};

void Kinematic::setStart(std::vector<double> initPoint) {
	_initPoint = initPoint;
	std::cout << "setStart: " << initPoint[0] << std::endl;
}

void Kinematic::setX(std::vector<double> xPoint) {
	_xPoint = xPoint;
	std::cout << "setX: " << xPoint[0] << std::endl;
}

void Kinematic::setY(std::vector<double> yPoint) {
	_yPoint = yPoint;
	std::cout << "setY: " << yPoint[0] << std::endl;
}

std::vector<double> Kinematic::getFrame() {
	return _frame;
}

void Kinematic::normalize(std::vector<double> &p) {
	double w = sqrt( p[0] * p[0] + p[1] * p[1] + p[2] * p[2] );
	p[0] /= w;
	p[1] /= w;
	p[2] /= w;
}
