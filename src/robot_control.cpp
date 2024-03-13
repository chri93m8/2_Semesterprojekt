#include "robot_control.h"


Robot_control::Robot_control(std::string ip)  {
	_ip = ip;

}

void Robot_control::connect() {
	std::cout << getIp() << std::endl;
	
	try {
		
		//ur_rtde::RTDEControlInterface ur = ur_rtde::RTDEControlInterface rtde_control(getIp());
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
/*
	ur_rtde::RTDEControlInterface rtde_control(getIp());
	ur_rtde::RTDEReceiveInterface rtde_receive(getIp());
	std::vector<double> a = rtde_receive.getActualTCPPose();
		
	_point = a;
	*/
	return _point;
}





