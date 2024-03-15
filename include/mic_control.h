#ifndef MIC_CONTROL_H
#define MIC_CONTROL_H

// undersøg brug af https://github.com/yan9a/serial lib

class Mic_Control{
private:
	
public:

	void requestData();
	// spøg MC om data fra Potmeter og motor amp
	
	void Open(); 
	//Send signal til MC der åbner gribbern
	//brug requestdata() til at se hvornår den er åben (potmeter)
	
	void Close();
	//Send signal til MC der åbner gribbern
	//brug requestdata() til at se hvornår den er lukket (Motor amp) 
	
	void isGripping();
	//istedet for request data???
	

};

#endif //MIC_CONTROL_H
