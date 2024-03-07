#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

#include <ur_rtde/rtde_control_interface.h>
#include <iostream>

class Robot_control {
	private:
		std::string _ip;
	public:
		Robot_control(std::string ip);
		// Practical stuff
		void connect();
		std::string getIp();



		// Movement

};













#endif //ROBOT_CONTROL_H
