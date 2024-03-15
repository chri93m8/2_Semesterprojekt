#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H
#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Robot_control {
	private:
		std::string _ip;
		ur_rtde::RTDEReceiveInterface rtde_r;
		ur_rtde::RTDEControlInterface rtde_c;
		double _velocity = 0.15;
		double _acceleration = 0.15;
		double _blend = 0.0;
		const double pi = std::acos(-1);
	public:
		Robot_control(std::string ip);
		void connect();
		std::string getIp();
		std::vector<double> getPose();
		void createFrame();
		std::vector<double> getFrame();
		void writeFrame(std::vector<double> &v);
		void gameControl(); // This will be moved into the game_control.h class at a later point
		void printFrame();
		void moveTrans();
		bool isFrameCreated();
		
		
};

#endif //ROBOT_CONTROL_H
