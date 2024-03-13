//#include <ur_rtde/rtde_control_interface.h>
#include "robot_control.h"
#include "kinematic.h"
#include <thread>
#include <chrono>
#include <vector>

#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>

using namespace ur_rtde;
using namespace std::chrono; 

int main(int argc, char* argv[]) {
	std::cout << "test" << std::endl;
	//Robot_control rc("192.168.1.54");
	//rc.connect();	
	
	ur_rtde::RTDEControlInterface rtde_control("192.168.1.54");
	ur_rtde::RTDEReceiveInterface rtde_receive("192.168.1.54");
	
	
	std::vector<double> cc = rtde_receive.getActualTCPPose();
	//rtde_control.moveL(cc, 0.5, 0.2); 
	for (double i : cc) {
		std::cout << i << std::endl;
	}
	
	/*
	// Parameters
	double acceleration = 0.5;
	double dt = 1.0/500; // 2ms
	std::vector<double> joint_q = {-1.54, -1.83, -2.28, -0.59, 1.60, 0.023};
  	std::vector<double> joint_speed = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	
	// Move to initial joint position with a regular moveJ
	rtde_control.moveJ(joint_q);

/*
	// Execute 500Hz control loop for 2 seconds, each cycle is ~2ms
	for (unsigned int i=0; i<1000; i++) {
		steady_clock::time_point t_start = rtde_control.initPeriod();
		rtde_control.speedJ(joint_speed, acceleration, dt);
		joint_speed[0] += 0.0005;
		joint_speed[1] += 0.0005;
		rtde_control.waitPeriod(t_start);
	}
	rtde_control.speedStop();
	rtde_control.stopScript();
*/




	
	//std::vector<double> a = rtde_receive.getActualTCPPose();
	//kin.setStart(std::vector<double>{12, 42,23});
	std::vector<double> init;//= {-0.143, -0.435, 0.20, -0.001, 3.12, 0.04};
	std::vector<double> xp;// = {-0.743, -0.435, 0.20, -0.001, 3.12, 0.04};
	std::vector<double> yp;// = {-0.743, -0.235, 0.20, -0.001, 3.12, 0.04};
	
	std::cout << "Click Enter when robot is at the right init point";
	std::cin.ignore();
	//init = rc.getPose();
	init = rtde_receive.getActualTCPPose();
	
	for (double i : init) {
		std::cout << i << std::endl;
	}
	
	std::cout << "Click Enter when robot is at the right x point";
	std::cin.ignore();
	//xp = rc.getPose();
	xp = rtde_receive.getActualTCPPose();
	
	for (double i : xp) {
		std::cout << i << std::endl;
	}
	
	std::cout << "Click Enter when robot is at the right y point";
	std::cin.ignore();
	//yp = rc.getPose();
	yp = rtde_receive.getActualTCPPose();
	
	for (double i : yp) {
		std::cout << i << std::endl;
	}
	
	
	Kinematic kin(init, xp, yp);
	std::vector<double> feat = kin.getFrame();
	std::cout << "\n--Frame--" << std::endl;
	
	int i = 0;
	for (int c : feat) {
		std::cout << feat[i] << std::endl;
		i++;
	}
	
	std::cout << "------" << std::endl;
	//kin.normalize(p);
	
	// The constructor simply takes the IP address of the Robot
	//RTDEControlInterface rtde_control("192.168.1.10");
	//std::cout << rtde_control.getRobotStatus() << std::endl;
	//std::cout << rtde_control.isProgramRunning() << std::endl;
	//rtde_control.teachMode();
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	//rtde_control.endTeachMode();
	// First argument is the pose 6d vector followed by speed and acceleration
	//rtde_control.moveL({-0.143, -0.435, 0.20, -0.001, 3.12, 0.04}, 0.5, 0.2);

	double velocity = 0.5;
	double acceleration = 0.5;
	double blend_1 = 0.0;
	double blend_2 = 0.02;
	double blend_3 = 0.0;
	std::vector<double> path_pose1 = {-0.143, -0.435, 0.20, -0.001, 3.12, 0.04, velocity, acceleration, blend_1};
	std::vector<double> path_pose2 = {-0.143, -0.51, 0.21, -0.001, 3.12, 0.04, velocity, acceleration, blend_2};
	std::vector<double> path_pose3 = {-0.32, -0.61, 0.31, -0.001, 3.12, 0.04, velocity, acceleration, blend_3};


	std::vector<double> init_p = init;//= {-0.143, -0.435, 0.20, -0.001, 3.12, 0.04};
	init_p.push_back(velocity);
	init_p.push_back(acceleration);
	init_p.push_back(blend_1);
	for (double d : init_p) {
		std::cout << "asd: " << d << std::endl;
	}
	std::vector<double> xp_p = xp;// = {-0.743, -0.435, 0.20, -0.001, 3.12, 0.04};
	xp_p.push_back(velocity);
	xp_p.push_back(acceleration);
	xp_p.push_back(blend_2);
	std::vector<double> yp_p = yp;// = {-0.743, -0.235, 0.20, -0.001, 3.12, 0.04};
	yp_p.push_back(velocity);
	yp_p.push_back(acceleration);
	yp_p.push_back(blend_3);

	std::vector<std::vector<double>> path;
	path.push_back(init_p);
	path.push_back(xp_p);
	path.push_back(yp_p);

	// Send a linear path with blending in between - (currently uses separate script)
  	rtde_control.moveL(path);
	// Stop the RTDE control script
	rtde_control.stopScript();
	
	
	return 0;
}

/*

Cpp:

Boost ( /beast(?) )


	Interface/GUI:
		-Terminal.. ig?


	Classes:
		-ur_rtde ( MEN DER ER ALLEREDE CLASS API )
			-Connect
			-Disconnect
			-Status ( threading ) (isConnected(), isProgramRunning(), getRobotStatus(), isPoseWithinSafetyLimits(),  )
			-Settings ( setTCP, )
			---- force control ----
			-Feature ( manuelt på robot? )			
			-Movement ( force control )
			- TBC...
			
			
			
			
			
			
		-Microcontroller communication (ATMega644PU ( nok bare ATMega )
			-GripperControl
			
		-webinterface? Næppe..	
		-SQL ( eventlogger )
		-Controller


Microcontroller:

	Communication:
		-FreeMODBUS(?) https://www.embedded-experts.at/en/freemodbus/ports-ascii-rtu/avr-atmega8-16-32-128-168-169/
		-https://github.com/dipakgmx/ATMega_TWI
		
	



*/
