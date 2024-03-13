#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <ur_rtde/dashboard_client.h>
#include <iostream>
#include <vector>

class Robot_control {
	private:
		std::string _ip;
		std::vector<double> _point;
		
	public:
		Robot_control(std::string ip);
		// Practical stuff
		void connect();
		std::string getIp();
		std::vector<double> getPose();


		// Movement
		
};

#endif //ROBOT_CONTROL_H
