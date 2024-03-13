#include "kinematic.h"

Kinematic::Kinematic(std::vector<double> init, std::vector<double> x, std::vector<double> y) : _initPoint(init), _xPoint(x), _yPoint(y) {
	_initPoint = init;
	_xPoint = x;
	_yPoint = y;
	std::cout << "Kinematic contructor" << std::endl;
};

std::vector<double> Kinematic::getFrame() {
	createFrame();
	return _frame;
}


std::vector<double> Kinematic::normalize(std::vector<double> p) {
	double w = sqrt( p[0] * p[0] + p[1] * p[1] + p[2] * p[2] );
	p[0] /= w;
	p[1] /= w;
	p[2] /= w;
	
	/*
	for (int i = 0; i < p.size(); i++) {
		std::cout << "p= " << p[i] << std::endl;
	}
	*/
	
	return p;
}

std::vector<double> Kinematic::crossProduct(std::vector<double> u, std::vector<double> v) { 
	
	double u1 = u[0];
	double u2 = u[1];
	double u3 = u[2];
	double v1 = v[0];
	double v2 = v[1];
	double v3 = v[2];
	std::vector<double> s = { (u2*v3-u3*v2), (u3*v1-u1*v3), (u1*v2-u2*v1) };
	
	std::cout << "s = " << s[0] << ' ' << s[1] << ' ' << s[2] << std::endl;
	
	return s;

}

double Kinematic::d2r(double degree) {
	return degree * pi / 180;
}

std::vector<double> Kinematic::rotmat2rotvec(std::vector<double> rotmat) {
	// array to matrix
	double r11 = rotmat[0];
	double r21 = rotmat[1];
	double r31 = rotmat[2];
	double r12 = rotmat[3];
	double r22 = rotmat[4];
	double r32 = rotmat[5];
	double r13 = rotmat[6];
	double r23 = rotmat[7];
	double r33 = rotmat[8];
	
	double ux = 0;
	double uy = 0;
	double uz = 0;

	// rotation matrix to rotation vector
	double theta = acos((r11+r22+r33-1)/2);
	
	double sth = sin(theta);
	
	std::cout << "theta= " << theta << " " << (r11+r22+r33-1)/2 << std::endl;
	
	if ( (theta > d2r(179.99)) || (theta < d2r(-179.99)) ) {
		theta = d2r(180);
		if (r21 < 0) {
			if (r31 < 0) {
				ux = sqrt((r11+1)/2);
				uy = -sqrt((r22+1)/2);
				uz = -sqrt((r33+1)/2);
			} else {
				ux = sqrt((r11+1)/2);
				uy = -sqrt((r22+1)/2);
				uz = sqrt((r33+1)/2);
			}
		} else {
			if (r31 < 0){
				ux = sqrt((r11+1)/2);
				uy = sqrt((r22+1)/2);
				uz = -sqrt((r33+1)/2);
			} else{
				ux = sqrt((r11+1)/2);
				uy = sqrt((r22+1)/2);
				uz = sqrt((r33+1)/2);
			}
		}
	}
	else {
		ux = (r32-r23)/(2*sth);
		uy = (r13-r31)/(2*sth);
		uz = (r21-r12)/(2*sth);
	}
	
	std::vector<double> rotvec = {(theta*ux),(theta*uy),(theta*uz)};

	return rotvec;

}
void Kinematic::createFrame() {

	// Step 1. Get the direction vectors
	std::vector<double> d12 = { _xPoint[0] - _initPoint[0], _xPoint[1] - _initPoint[1], _xPoint[2] - _initPoint[2] };
	std::vector<double> d13 = { _yPoint[0] - _initPoint[0], _yPoint[1] - _initPoint[1], _yPoint[2] - _initPoint[2] };
	
	for (int i = 0; i < d12.size(); i++) {
		std::cout << "d12= " << d12[i] << std::endl;
	}
	
	std::cout << "------" << std::endl;
	for (int i = 0; i < d13.size(); i++) {
		std::cout << "d13= " << d13[i] << std::endl;
	}

	// Step 2. Get the direction vector of Z axis by cross product of d12 and d13
	std::vector<double> dz = crossProduct(d12, d13);
	
	
	std::cout << "------" << std::endl;
	for (int i = 0; i < dz.size(); i++) {
		std::cout << "dz= " << dz[i] << std::endl;
	}
	
	std::cout << "------" << std::endl;
	
	// Step 3. Get the X and Z unit direction vectors by normalizing d12 and dz
	std::vector<double> temp = normalize(d12);
	
	for (int i = 0; i < temp.size(); i++) {
		std::cout << "temp= " << temp[i] << std::endl;
	}
	
	std::cout << "------" << std::endl;
	
	std::vector<double> ux = { d12[0]/temp[0], d12[1]/temp[0], d12[2]/temp[0] };
	
	for (int i = 0; i < ux.size(); i++) {
		std::cout << "ux= " << ux[i] << std::endl;
	}
	std::cout << "------" << std::endl;
	
	temp = normalize(dz);
	
	for (int i = 0; i < temp.size(); i++) {
		std::cout << "norm temp dz= " << temp[i] << std::endl;
	}
	std::cout << "------" << std::endl;
	
	std::vector<double> uz = { dz[0]/temp[2], dz[1]/temp[2], dz[2]/temp[2] };
	
	for (int i = 0; i < uz.size(); i++) {
		std::cout << "uz= " << uz[i] << std::endl;
	}
	std::cout << "------" << std::endl;
	
	
	
	
	// Step 4. Get Y unit direction vector by cross product of uz and ux
	std::vector<double> uy = crossProduct(uz, ux);

	for (int i = 0; i < uy.size(); i++) {
		std::cout << "uy= " << uy[i] << std::endl;
	}
	std::cout << "------" << std::endl;
	
	// Step 5. Get the rotation matrix from the unit direction vectors
	std::vector<double> rotmat = { ux[0], ux[1], ux[2], uy[0], uy[1], uy[2], uz[0], uz[1], uz[2] };
	
	for (int i = 0; i < rotmat.size(); i++) {
		std::cout << "rotmat= " << rotmat[i] << std::endl;
	}
	std::cout << "------" << std::endl;
	
	// Step 6. Get the rotation vector from the rotation matrix
	std::vector<double> rotvec = rotmat2rotvec(rotmat);
	
	// Step 7. Get the feature plane with the origin at p1 and the frame achieved at step 6
	_frame = {_initPoint[0], _initPoint[1], _initPoint[2], rotvec[0], rotvec[1], rotvec[2] };
}










/*
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

void Kinematic::getFrame() {
	//return _frame;
}
*/
