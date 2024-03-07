#include "robot_control.h"

Robot_control::Robot_control(std::string ip)  {
	_ip = ip;
}

void Robot_control::connect() {
	std::cout << getIp() << std::endl;
}

std::string Robot_control::getIp() {
	return _ip;
}

