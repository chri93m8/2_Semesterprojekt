//#include <ur_rtde/rtde_control_interface.h>
//#include <ur_rtde/rtde_receive_interface.h>
//#include <thread>
//#include <chrono>
#include "robot_control.h"
#include "kinematic.h"
#include <vector>

int main(int argc, char* argv[]) {

	Robot_control rc("192.168.1.54");
	//rc.createFrame();
	//std::vector<double> a = {-1.54, -1.83, -2.28, -0.59, 1.60, 0.023};
	//rc.writeFrame(a);
	//a = rc.readFrame();
	rc.gameControl();
	//rc.moveTrans();
	/*
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	*/
	//rc.connect();	
	
	//run();

	
	
	
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
