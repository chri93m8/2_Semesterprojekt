#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H
#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

class Robot_control {
	private:
		ur_rtde::RTDEReceiveInterface rtde_r;
		ur_rtde::RTDEControlInterface rtde_c;
		double _velocity = 0.25;
		double _acceleration = 0.2;
		double _blend = 0.0;
		bool _async = false;
		const double pi = std::acos(-1);
		bool _isFrameCreated; 
		double d2r(double degree);
		void insertAddons(std::vector<double> &v);
		void writeFrame(std::vector<double> &v);
		void insertRotvec(std::vector<double> &v);
		std::vector<double> _rotvec;
		std::vector<double> getRotvec();
		std::vector<double> getPose();
		std::vector<double> getFrame();
		bool readFrame();	
		void setRotvec(std::vector<double> v);
	public:
		Robot_control(std::string ip);
		void createFrame();
		void gameControl(); // This will be moved into the game_control.h class at a later point
		void printFrame();
		void moveTrans();	// test bevægelse osv
		bool isFrameCreated();	

		//------ Game_control
		bool forceDown(int maxHeight = 10); // kører -> finde disk -> stop movement -> return
		void move(std::vector<double> v);
};

#endif //ROBOT_CONTROL_H
