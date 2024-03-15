#include "game_control.h"


Game_Control::Game_Control(std::string ip) : rc(ip){
	std::cout << "cunt" << std::endl;
	
}

void Game_Control::home(){

	rc.printFrame();

	//RTDEControlInterface rtde_control("192.168.1.54");

	//rtde_control.moveL(home, speed, acceleration);
}
/*
void Game_Control::findDisc(){
	//force in percent??
	
	while (rtde.getActualTCPForce() < 60 ) {
	rtde.speedL({0,0,-.005,0,0,0});
	}
}
*/
