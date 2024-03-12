#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H


class Game_Control{
private:
	//pre-sets til disc spaces
	//pre-sets til rod spaces
	//pre-sets til disc "modstand"/size
	//counter/ holder styr på hvor langt vi er nået med uddeling


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
