#include "robot_control.h"
#include "game_control.h"
#include "kinematic.h"
#include <vector>

int main(int argc, char* argv[]) {
//cunt

	//Robot_control rc("192.168.1.54");
	Game_control gc("192.168.1.54");
	/ 
	
	
		//rc.createFrame();
	//std::vector<double> a = {-1.54, -1.83, -2.28, -0.59, 1.60, 0.023};
	//rc.writeFrame(a);
	//a = rc.readFrame();
	//rc.gameControl();
	//std::vector<double> a = {.0,.0,.3};
	//std::vector<double> b = {.0,-.1,.4};
	/*
	std::vector<double> frameTrans1 = {.1, .0, .3};	
	std::vector<double> frameTrans2 = {.0, .1, .3};
	std::vector<double> frameTrans3 = {.0, .0, .3};
	std::vector<double> frameTrans4 = {.0, .0, .4};
	std::vector<double> frameTrans5 = {.0, .0, .3};
	*/
	//rc.createFrame();
	//rc.frameMove();
	
	/*
	
	std::vector<double> rod1 = {0.075, 0.425, 0.35}; //3rd tier
	std::vector<double> rod2 = {0.200, 0.425, 0.35};
	std::vector<double> rod3 = {0.325, 0.425, 0.35};
	std::vector<double> discP1 = {0.100, 0.275, 0.25}; //largest -- 2nd tier
	std::vector<double> discP2 = {0.300, 0.275, 0.25};
	std::vector<double> discP3 = {0.075, 0.100, 0.10}; // 1st tier
	std::vector<double> discP4 = {0.200, 0.100, 0.10};
	std::vector<double> discP5 = {0.325, 0.100, 0.10}; //smallest
	
	std::vector<double> homeVec = {0.10, 0.30, 0.20};
	
	
	bool a = true;
	while (a) {
		//a = rc.move(homeVec);
		//std::cout<<"homeVec"; 
		
		a = rc.move(homeVec);
		a = rc.move(rod2);
		a = rc.move(rod3);
		/*
		a = rc.move(discP1);
		a = rc.move(discP2);
		a = rc.move(discP3);
		a = rc.move(discP4);
		a = rc.move(discP5);
		*/
			
	
	/*
		a = rc.move({.1, .1, .15});
		a = rc.move({.2, .1, .15});
		a = rc.move({.2, .2, .15});
		a = rc.move({.1, .2, .15});
		a = rc.move(frameTrans3);
		a = rc.move(frameTrans1);
		a = rc.move(frameTrans3);
		a = rc.move(frameTrans2);
		a = rc.move(frameTrans3);
		a = rc.move(frameTrans4);
	*/
	/*
		
	}
	

	*/

	/*
		rc.moveTrans();
		
		rc.move(a);
		rc.move(b);
		
		rc.move({.0,.0,.5});
	rc.move({.0,.0,.3});
	rc.move({.0,.0,.4});
	*/
	//rc.forceDown();
	//std::vector<double> a = {.20, -.10, .20};
	//rc.move(a);

	//std::vector<double> ainit= {-0.143, -0.435, 0.20, -0.001, 3.12, 0.04};
	//std::vector<double> axp = {-0.743, -0.435, 0.20, -0.001, 3.12, 0.04};
	//std::vector<double> ayp = {-0.743, -0.235, 0.20, -0.001, 3.12, 0.04};
	//Kinematic kin(ainit, axp, ayp);
	//std::vector<double> t = kin.createFrame();
	
	/*
	while (rtde.getActualTCPForce() < 60 ) {
	rtde.speedL({0,0,-.005,0,0,0});
	}
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
