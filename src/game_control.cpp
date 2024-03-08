#include "game_control.h"

class Game_Control{
private:
	//presets til disc spaces
	//presets til rod spaces
	//presets til disc "modstand"/size


public:
	void home();
	//snakker til UR -- burde være robot_control method??
	void discDistribution();
	//counter/ holder styr på hvor langt vi er nået med uddeling
	void findDisc(); 
	//benytter force control
	//benytter pot-meter control
	
	//mic_control.Open();
	//mic_control.Close();
	
	//if(modstand == size preset) --> kør disc space preset på Disc placement metode 
	void discPlacement(int disc);
	//UR instruktioner
	//mic_control.Open();
	//mic_control.Close();
	//modtager disc
	void discSorting();
	//mic_control.Open();
	//mic_control.Close();
	
	//fast sæt af instruktioner baseret på disc space presets
	//snakker til UR
	//kør evt home når færdig??
	
}
