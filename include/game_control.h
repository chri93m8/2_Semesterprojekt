#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H


class Game_Control{
	private:
		const double pi =  std::acos(-1);

		//pre-sets til disc "modstand"/size
		//counter/ holder styr på hvor langt vi er nået med uddeling
			
		//rod presets {x, y, z, ry, rx, rz}
		std::vector<double> rod1 = {0.075, 0.0100, 0.035, 0, 0, 0} //3rd tier
		std::vector<double> rod2 = {0.0200, 0.0100, 0.035, 0, 0, 0}
		std::vector<double> rod3 = {0.0325, 0.0100, 0.035, 0 , 0, 0}

		//disc place presets {x, y, z, ry, rx, rz}
		std::vector<double> discP1 = {0.0100, 0.0275, 0.025, 0, 0, 0} //largest -- 2nd tier
		std::vector<double> discP2 = {300, 275, 25, 0, 0, 0}

		std::vector<double> discP3 = {0.075, 0.0425, 0.010, 0, 0, 0} // 1st tier
		std::vector<double> discP4 = {0.0200, 0.0425, 0.010, 0, 0, 0}
		std::vector<double> discP5 = {0.0325, 0.0425, 0.010, 0, 0, 0} //smallest


	public:
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
