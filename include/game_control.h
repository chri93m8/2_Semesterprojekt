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
		
		
		int rodState = 0; //tæller hvor langt vi er nået med sorting
		
			
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
		
		std::vector<std::vector<double>> discSpaces = {discP1, discP2, discP3, discP4, discP5};
		
		std::vector<double> homeVec = {0.10, 0.30, 0.20};
		
		
	public:
		Game_control(std::string ip);
		void menu(); 
		void settings(); 
		void home();
		void discDistribution();
		int findDisc(); 
		void discSorting(int disc);
		
};

#endif //GAME_CONTROL_H
