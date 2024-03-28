#ifndef MIC_CONTROL_H
#define MIC_CONTROL_H

#include <stdio.h>
//#define CE_SERIAL_IMPLEMENTATION
#include "ceSerial.h"
#include <iostream>

// undersøg brug af https://github.com/yan9a/serial lib

class Mic_control{
private:
public:

	void requestData();
	// spøg MC om data fra Potmeter og motor amp 
	
	
	void Open(); 
	//Send signal til MC der åbner gribbern
	//brug requestdata() til at se hvornår den er åben (potmeter)
	//returen 1 when done
	
	void Close();
	//Send signal til MC der lukker gribbern
	//brug requestdata() til at se hvornår den er lukket (Motor amp)
	//returen 1 when done 
	
	void gripperData();
	//Behandeler data fra requestData() og sender det vider i programmet
	//Returne et aray med gripperSate(0=clost 1=open) Returne diskSize(1-5)
	
	bool isGripping(); 
	
	 
};

#endif //MIC_CONTROL_H
