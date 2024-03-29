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
	int option;
	std::cout<<"SETTINGS"<<std::endl;
	std::cout<<"1: adjust speed"<<std::endl;
	std::cout<<"2: adjust acceleration"<<std::endl;
	std::cout<<"3: create frame"<<std::endl;
	std::cin>>option; 
	
	switch(option){
		case 1: 
			int speed;
			std::cout<<"Type your prefered speed in..."<<std::endl;
			std::cin>>speed;
			std::cout<<"New speed: "<<speed<<std::endl; 
			//rc.speed = speed; 
			break;
		case 2:
			int acceleration;
			std::cout<<"Type your prefered acceleration in..."<<std::endl;
			std::cin>>acceleration;
			std::cout<<"New acceleration: "<<acceleration<<std::endl; 
			//rc.acceleration = acceleration; 
			break;
		//create frame, move frame
		case 3: 
			rc.createFrame();
			break; 
	}

}

void Game_control::home(){

	//rc.printFrame();
	std::cout<<"Game_control.home running..."<<std::endl; 
	
	rc.move(homeVec);
	rc.move(rod1);
	rc.move(rod2);
	rc.move(rod3);
	rc.move(discP1);
	rc.move(discP2);
	rc.move(discP3);
	rc.move(discP4);
	rc.move(discP5);
	
	/*
	
	bool a = rc.move(homeVec);
	std::cout<<a<<std::endl;
	a = rc.move(rod1);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(rod2);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(rod3);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(discP1);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(discP2);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(discP3);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(discP4);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	a =rc.move(discP5);
	a = rc.move(homeVec);
		std::cout<<a<<std::endl;
	*/
}

void Game_control::discDistribution(){

std::cout<<"Game_control.discDistribution runnning..."<<std::endl; 
std::cout<<rodState<<std::endl;

		int disc = 1;
		std::cout<<disc<<std::endl;
		while(rodState<=5){ //mens der stadig er discs tilbage
			//disc = findDisc().value; 
			//isSorted = findDisc().isSorted;
			
			//bool isSorted = false; necessary??
			if(rodState = disc-1){ //altså den nuværende disk er den største usorterede disk (og den derfor er usorteret)
				discSorting(disc);
			}
			/*
			else{ //den er ikke distrubueret; distribuer til plads
				rc.move(discSpaces[disc]);
			}
			*/
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
std::cout<<"Game_control.discSorting runnning..."<<std::endl; 
	
	//std::cout<<rodState<<std::endl;
	bool tempisGripping = true; 
	if (tempisGripping/*mic_control.isGripping()*/){ //grippern har fat om en disc
		rc.move(rod1);
		rc.move(rod2);
		rc.move(rod3);
		//rc.down funktion: -0.10(10*rodState) //skal afhænge af hvor langt sorteringen er nået (nedadgående bevægelse) eller benyt forceDown??
		//mic_control.Open(); 
		//rc.move(rod3);
		//rc.move(homeVec);  
	}
	
	//Disc1.isSorted = true;
	rodState++; 
	
	//return??
	

}


