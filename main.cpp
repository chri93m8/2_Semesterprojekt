//#include <ur_rtde/rtde_control_interface.h>
#include "robot_control.h"
#include "kinematic.h"
#include <thread>
#include <chrono>
#include <vector>

using namespace ur_rtde;
using namespace std::chrono; 

int main(int argc, char* argv[]) {
	std::cout << "test" << std::endl;
	Robot_control rc("192.168.1.10");
	Kinematic kin;
	//rc.connect();
	kin.setStart(std::vector<double>{12, 42,23});
	std::vector<double> p = {12,42,23};
	
	
	kin.normalize(p);
	
	int c=0;
	for (int i : p) {
		std::cout << p[c] << std::endl;
		c++;
	}
	// The constructor simply takes the IP address of the Robot
	//RTDEControlInterface rtde_control("192.168.1.10");
	//std::cout << rtde_control.getRobotStatus() << std::endl;
	//std::cout << rtde_control.isProgramRunning() << std::endl;
	//rtde_control.teachMode();
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	//rtde_control.endTeachMode();
	// First argument is the pose 6d vector followed by speed and acceleration
	//rtde_control.moveL({-0.143, -0.435, 0.20, -0.001, 3.12, 0.04}, 0.5, 0.2);

	std::cout << "test" << std::endl;
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
