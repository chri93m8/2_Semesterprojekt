#include "game_control.h"


Game_control::Game_control(std::string ip) : rc(ip){
	std::cout << "Game_control constructor running... " << std::endl;
	menu(); 

	
}
void Game_control::menu(){
	int option;
	std::cout<<"MENU"<<std::endl;
	std::cout<<"1: home robot"<<std::endl;
	std::cout<<"2: run program"<<std::endl;
	std::cout<<"3: open settings"<<std::endl;
	std::cin>>option; 
	
	switch(option){
		case 1:
			home();
			break;
		case 2:
			discDistribution(); 
			break;
		case 3: 
			settings();
			break; 
	} 
}

void Game_control::settings(){

}

void Game_control::home(){

	//rc.printFrame();
	std::cout<<"jeg er i Game_control.home"<<std::endl; 
	rc.move(homeVec);
	//rc.move(rod1);
	//rc.move(rod2);
	//rc.move(rod3);
}

void Game_control::discDistribution(){

std::cout<<"jeg er i Game_control.discDistribution"<<std::endl; 
//rodstate er ny counter

		while(rodState <5){ //mens der stadig er discs tilbage
			//disc = findDisc(); 
			int disc = Disc1.value; 
		
			if(rodState = disc-1){ //altså den nuværende disk er den største usorterede disk (og den derfor er usorteret)
				discSorting(disc);
			}else if(!Disc1.isSorted){ //hvis disc ikke 
				rc.move(discSpaces[disc]);
			}
		}
		
	
	
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

void Game_control::discSorting(int disc){ 
	
	//std::cout<<rodState<<std::endl;
	bool tempisGripping = true; 
	if (tempisGripping/*mic_control.isGripping()*/){ //grippern har fat om en disc
		rc.move(rod2);
		//rc.down funktion: -0.10(10*rodState) //skal afhænge af hvor langt sorteringen er nået (nedadgående bevægelse) eller benyt forceDown??
		//mic_control.Open(); 
		//rc.move(rod3);
		//rc.move(homeVec);  
	}
	
	Disc1.isSorted = true;
	rodState++; 
	
	//return??
	

}


