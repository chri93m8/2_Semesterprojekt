#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H
#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ncurses.h>

class Robot_control {
	private:
		ur_rtde::RTDEReceiveInterface rtde_r;
		ur_rtde::RTDEControlInterface rtde_c;
		std::string _ip;
		double _velocity = 0.25;
		double _acceleration = 0.2;
		double _blend = 0.0;
		bool _async = false;
		std::vector<double> _rotvec;
		bool _isFrameCreated; 
		
		const double pi = std::acos(-1);
		double d2r(double degree);
		void writeFrame(std::vector<double> &v);
		void insertRotvec(std::vector<double> &v);
		std::vector<double> getRotvec();
		std::vector<double> getPose();
		std::vector<double> getFrame();
		bool readFrame();	
	public:
		Robot_control(std::string ip);
		void frameMove();
		void setRotvec(std::vector<double> v);
		void createFrame();
		void gameControl(); // This will be moved into the game_control.h class at a later point
		void printFrame();
		void moveTrans();	// test bevægelse osv
		bool isFrameCreated();	
		
		//------ Game_control
		bool forceDown(int maxHeight = 10); // kører -> finde disk -> stop movement -> return
		bool move(std::vector<double> v);
		bool moveZ(double distance);
		//mangler moveZ som modtager negativ eller positiv tal størrelse
};

#endif //ROBOT_CONTROL_H
