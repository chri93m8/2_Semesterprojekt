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
		bool _isFrameCreated; 
		std::vector<double> _rotvec;


		void insertAddons(std::vector<double> &v);
	public:
		Robot_control(std::string ip);
		bool isFrameCreated();
		std::string getIp();
		std::vector<double> getPose();
		void createFrame();
		std::vector<double> getFrame();
		void writeFrame(std::vector<double> &v);
		void gameControl(); // This will be moved into the game_control.h class at a later point
		void printFrame();
		void moveTrans();
		bool readFrame();
		

		//------ Game_control
		void home(std::vector<double> &v); // skal være cirke {-15, 20, 20}
		bool forceDown(int maxHeight); // kører -> finde disk -> stop movement -> return
		//void move(std:vector<double> &d); // {x,y,z} ( {RX,RY,RZ} skal gives på et tidspunkt ( eventuelt i contructor'en som arguement ), af game_control	
		//void moveDown(double height); // bevæg sig ned med en given højde. Lav check på om det er i millimeter
		void move(std::vector<double> &v);
		
		void insertRotvec(std::vector<double> &v);
		void setRotvec(std::vector<double> v);
		std::vector<double> getRotvec();
};

#endif //ROBOT_CONTROL_H
