#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include "robot_control.h"
#include <vector>
#include <iostream>

class Game_control{
	private:
		const double pi =  std::acos(-1);
		int speed = 0.5;
		int acceleration = 0.2; 
		Robot_control rc;
		int rodState; 
		
		//enum Board
			//50x40
		
		struct { 
			int discHeight; //universal??
			int value;
			int size; // afhængig af modstand ??
			bool isSorted = false;
			
		
		}Disc1, Disc2, Disc3, Disc4, Disc5;
		
		
		/*
		Disc1.value = 1;
		Disc1.size = 0.08;
		
		Disc2.value = 2;
		Disc2.size = 0.08;
		
		Disc3.value = 3;
		Disc3.size = 0.08;
		
		Disc4.value = 4;
		Disc4.size = 0.08;
		
		Disc5.value = 5;
		Disc5.size = 0.08;
		*/
		
		
		//int rodstate = 0; //tæller hvor langt vi er nået med sorting
		
			
		//rod presets {x, y, z} 
		
		std::vector<double> rod1 = {0.075, 0.425, 0.35}; //3rd tier
		std::vector<double> rod2 = {0.200, 0.425, 0.35};
		std::vector<double> rod3 = {0.325, 0.425, 0.35}; //sorted rod??
		
		//disc presets {x, y, z} 
		std::vector<double> discP1 = {0.100, 0.275, 0.25}; //largest -- 2nd tier
		std::vector<double> discP2 = {0.300, 0.275, 0.25};
		
		std::vector<double> discP3 = {0.075, 0.100, 0.10}; // 1st tier
		std::vector<double> discP4 = {0.200, 0.100, 0.10};
		std::vector<double> discP5 = {0.325, 0.100, 0.10}; //smallest	
		
		//std::vector<vector<double>> discSpaces = {discP1, discP2, discP3, discP4, discP5};
		
		std::vector<double> homeVec = {0.10, 0.30, 0.20};
		
	public:
		Game_control(std::string ip);
		void menu(); 
		void settings(); 
		
		void home();
		//robot_control.move(homing pos)
		//snakker til UR -- burde være robot_control method?
		
		void discDistribution(); // counter funktion
		int findDisc(); 
		//benytter force control
		//benytter pot-meter control
		
		//mic_control.Open(); // mekanisk, ikke forbindelse
		//mic_control.Close();
		
		//if(modstand == size pre-set) --> kør disc space pre-set på Disc placement metode 
		//return disc
		
		//void discPlacement(int disc);
		//UR instruktioner
		//modtager disc
		void discSorting(int disc);
		//mic_control.Open();
		//mic_control.Close();
		
		//fast sæt af instruktioner baseret på disc space pre-sets
		//snakker til UR
		//kør evt home når færdig??
		
};

#endif //GAME_CONTROL_H
