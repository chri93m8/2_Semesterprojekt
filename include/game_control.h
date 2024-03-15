#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include "robot_control.h"
#include <vector>
#include<iostream>

class Game_Control{
	private:
		const double pi =  std::acos(-1);
		int speed = 0.5;
		int acceleration = 0.2; 
		Robot_control rc;
		//pre-sets til disc "modstand"/size
		
		
		//counter/ holder styr på hvor langt vi er nået med uddeling
			
		//rod presets {x, y, z, rx, ry, rz} !!!!evt fjern rotationsvektorerne
		
		std::vector<double> rod1 = {0.075, 0.0100, 0.035, 0, 0, 0}; //3rd tier
		std::vector<double> rod2 = {0.0200, 0.0100, 0.035, 0, 0, 0};
		std::vector<double> rod3 = {0.0325, 0.0100, 0.035, 0 , 0, 0};

		//disc place presets {x, y, z, rx, ry, rz}
		std::vector<double> discP1 = {0.0100, 0.0275, 0.025, 0, 0, 0}; //largest -- 2nd tier
		std::vector<double> discP2 = {0.0300, 0.0275, 0.025, 0, 0, 0};

		std::vector<double> discP3 = {0.075, 0.0425, 0.010, 0, 0, 0}; // 1st tier
		std::vector<double> discP4 = {0.0200, 0.0425, 0.010, 0, 0, 0};
		std::vector<double> discP5 = {0.0325, 0.0425, 0.010, 0, 0, 0}; //smallest
		
		//home preset?? (orientation? (22.3*pi)/180)
		std::vector<double> homeVec = {0.0, 0.0, 0.0, 0, 0, 0};


	public:
		Game_Control(std::string ip);
		void home();
		//snakker til UR -- burde være robot_control method??
		void discDistribution(); // counter funktion
		void findDisc(); 
		//benytter force control
		//benytter pot-meter control
		
		//mic_control.Open(); // mekanisk, ikke forbindelse
		//mic_control.Close();
		
		//if(modstand == size pre-set) --> kør disc space pre-set på Disc placement metode 
		void discPlacement(int disc);
		//UR instruktioner
		//modtager disc
		void discSorting();
		//mic_control.Open();
		//mic_control.Close();
		
		//fast sæt af instruktioner baseret på disc space pre-sets
		//snakker til UR
		//kør evt home når færdig??
		
};

#endif //GAME_CONTROL_H
