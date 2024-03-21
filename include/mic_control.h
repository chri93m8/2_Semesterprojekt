#ifndef MIC_CONTROL_H
#define MIC_CONTROL_H

// undersøg brug af https://github.com/yan9a/serial lib

class Mic_Control{
private:

	void requestData();
	// spøg MC om data fra Potmeter og motor amp 
	
public:
	
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
	 
};

#endif //MIC_CONTROL_H
