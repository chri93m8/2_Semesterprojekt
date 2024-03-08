 #include "robot_control.h"


Robot_control::Robot_control(std::string ip)  {
	_ip = ip;
}

void Robot_control::connect() {
	std::cout << getIp() << std::endl;
	//ur_rtde::DashboardClient
	
	try {
		ur_rtde::RTDEControlInterface rtde_control(getIp());
	// mutexes
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::string Robot_control::getIp() {
	return _ip;
}

