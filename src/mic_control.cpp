#include "mic_control.h"

void Mic_control::requestData() {
	std::cout << "sd" << std::endl;
	#ifdef CE_WINDOWS
		ceSerial com("\\\\.\\COM4",9600,8,'N',1); // Windows
	#else
		ceSerial com("/dev/ttyS0",9600,8,'N',1); // Linux
	#endif

	printf("Opening port %s.\n",com.GetPort().c_str());
	if (com.Open() == 0) {
		printf("OK.\n");
	}
	else {
		printf("Error.\n");
		//return 1;
	}

	bool successFlag;
	printf("Writing.\n");
	char s[]="Hello";
	successFlag=com.Write(s); // write string
	successFlag=com.WriteChar('!'); // write a character

	printf("Waiting 3 seconds.\n");
	ceSerial::Delay(3000); // delay to wait for a character

	printf("Reading.\n");
	char c=com.ReadChar(successFlag); // read a char
	if(successFlag) printf("Rx: %c\n",c);

	printf("Closing port %s.\n",com.GetPort().c_str());
	com.Close();
}





