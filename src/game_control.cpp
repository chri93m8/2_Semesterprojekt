#include "game_control.h"


Game_Control::Game_Control(std::string ip) : rc(ip){
	std::cout << "cunt" << std::endl;
	
}

void Game_Control::home(){

	rc.printFrame();

	//rc.move(&homeVec, speed, acceleration);
}

void Game_Control::discDistribution(){
/* rodstate er ny counter
		while(rodstate <=5){
			disc = findDisc();
			
			if(!disc.isSorted){
				if(rodstate = disc.value-1){ //altså den nuværende disk er den største usorterede disk
					discSorting(disc);
				
				}
			}else{
				rc.move(discSpaces[disc]);
			}
		}
		
	
	*/
}

int Game_Control::findDisc(){
	//force in percent??
	//rc.move til start pos "home"
	//rc.move til rod whatever
	//open/close gripper to slide down rod
	
	//bool isFound = rc.forceDown(); 
	
	//if (isFound){
		
		//benytter pot-meter control
		//mic_control.Open(); // mekanisk, ikke forbindelse
		
		//rc.moveDown(discHeight/2); 
		
		//mic_control.Close();
		
		//switch ift disc presets???
		//gem disc status i enum?? eller array
		
	//	}
	
	//return disc; //enum
}

void Game_Control::discSorting(int disc){ //pass by reference??

	//disc.isSorted = true;
	//rodstate++; 
	
	//rc.move til home pos
	//if mic_control.isGripping() = true
	//rc.move til rod pos
	//else
	//rc.move til disc space pos
	//rc.move til rod pos
	

}


