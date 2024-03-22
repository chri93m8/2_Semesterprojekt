#include "game_control.h"


Game_control::Game_control(std::string ip) : rc(ip){
	std::cout << "cunt" << std::endl;
	//menu(); 

	
}
void Game_control::menu(){
	std::cout<<"Run program: ";
	//home(); 
	//hvad skal der overhovedet være i menuen???
	discDistribution(); 
}
void Game_control::home(){

	//rc.printFrame();
	std::cout<<"jeg er i Game_control.home"<<std::endl; 
	rc.move(homeVec);
}

void Game_control::discDistribution(){
//rodstate er ny counter
/*
		while(rodState <5){ //mens der stadig er discs tilbage
			disc = findDisc(); 
		
			if(rodState = disc.value-1){ //altså den nuværende disk er den største usorterede disk (og den derfor er usorteret)
				discSorting(disc);
			}else if(!disc.isSorted){ //hvis disc ikke 
				rc.move(discSpaces[disc]);
			}
		}
		
	
	*/
}

int Game_control::findDisc(){
/*

	rc.move(rod1);
	//open/close gripper to slide down rod
	
	bool isFound = rc.forceDown(); 
	
	if (isFound){
		
		//benytter pot-meter control
		//mic_control.Open(); // mekanisk, ikke forbindelse
		
		//rc.moveDown(discHeight/2); 
		
		//mic_control.Close();
		
		//switch ift disc presets???
		//gem disc status i enum?? eller array
		
	//	}
	
	//return disc; //enum
	*/
}

void Game_control::discSorting(int disc){ //pass by reference??
	/*

	if (mic_control.isGripping()){ //grippern har fat om en disc
		rc.move(rod3);
		rc.move({0.0 , 0.0, -0.10}) //skal afhænge af hvor langt sorteringen er nået (nedadgående bevægelse)
		//mic_control.Open(); 
		rc.move(rod3);
		rc.move(homeVec);  
	}
	
	disc.isSorted = true;
	rodState++; 
	
	//return??
	*/

}


