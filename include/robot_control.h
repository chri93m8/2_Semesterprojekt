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
		ur_rtde::RTDEReceiveInterface rtde_r;
		ur_rtde::RTDEControlInterface rtde_c;		
	public:
		Robot_control(std::string ip);
		void connect();
		std::string getIp();
		std::vector<double> getPose();
		void run();
		
};

#endif //ROBOT_CONTROL_H
