#include "robot_control.h"
#include "kinematic.h"


Robot_control::Robot_control(std::string ip) : _ip(ip), rtde_c(ip), rtde_r(ip)  {
	_ip = ip;

}

void Robot_control::connect() {
	std::cout << getIp() << std::endl;
	
	try {
		//rtde(getIp());
		//ur_rtde::RTDEReceiveInterface rtde_receive(getIp());
		//std::vector<double> a = rtde_receive.getActualTCPPose();
		
		//_point = a;
		
	// mutexes
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
}

std::string Robot_control::getIp() {
	return _ip;
}


std::vector<double> Robot_control::getPose(){
	return rtde_r.getActualTCPPose();
}

void Robot_control::run() {
	double velocity = 0.5;
	double acceleration = 0.5;
	double blend = 0.0;
	
	std::vector<double> init;//= {-0.143, -0.435, 0.20, -0.001, 3.12, 0.04};
	std::vector<double> xp;// = {-0.743, -0.435, 0.20, -0.001, 3.12, 0.04};
	std::vector<double> yp;// = {-0.743, -0.235, 0.20, -0.001, 3.12, 0.04};
	
	std::cout << "Click Enter when robot is at the right init point";
	std::cin.ignore();
	
	init = getPose();
	for (double i : init) {
		std::cout << i << std::endl;
	}
	
	std::cout << "Click Enter when robot is at the right x point";
	std::cin.ignore();
	
	xp = getPose();
	for (double i : xp) {
		std::cout << i << std::endl;
	}
	
	std::cout << "Click Enter when robot is at the right y point";
	std::cin.ignore();
	yp = getPose();
	for (double i : yp) {
		std::cout << i << std::endl;
	}
	
	
	Kinematic kin(init, xp, yp);
	std::vector<double> feat = kin.getFrame();
	std::cout << "\n--Frame--" << std::endl;
	
	for (double c : feat) {
		std::cout << c << std::endl;
	}
	
	std::cout << "------" << std::endl;
	// ----------------------------------------------------------------------------------------------------
	init.insert(init.end(), {velocity, acceleration, blend});
	xp.insert(xp.end(), {velocity, acceleration, blend});
	yp.insert(yp.end(), {velocity, acceleration, blend});
	
	/*
	init.push_back(velocity);
	init.push_back(acceleration);
	init.push_back(blend);
	xp.push_back(velocity);
	xp.push_back(acceleration);
	xp.push_back(blend);
	
	yp.push_back(velocity);
	yp.push_back(acceleration);
	yp.push_back(blend);
	*/

	std::vector<std::vector<double>> path;
	path.push_back(init);
	path.push_back(xp);
	path.push_back(yp);

	// Send a linear path with blending in between - (currently uses separate script)
  	rtde_c.moveL(path);
	// Stop the RTDE control script
	rtde_c.stopScript();
}




