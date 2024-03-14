#include "robot_control.h"
#include "kinematic.h"


Robot_control::Robot_control(std::string ip) : _ip(ip), rtde_c(ip), rtde_r(ip)  {
	_ip = ip;

}

void Robot_control::connect() {
	std::cout << getIp() << std::endl;
	
	try {
		//rtde(getIp());
		//ur_rtde::RTDEReceiveInterface rtde_receive(getIp());
		//std::vector<double> a = rtde_receive.getActualTCPPose();
		
		//_point = a;
		
	// mutexes
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
}

std::string Robot_control::getIp() {
	return _ip;
}


std::vector<double> Robot_control::getPose(){
	return rtde_r.getActualTCPPose();
}

void Robot_control::gameControl() {
	std::cout << "--Menu--" << std::endl;
	std::cout << "Create new frame, Press 1" << std::endl;
	std::cout << "Print current frame, Press 2"<< std::endl;
	std::cout << "Movetrans, Press 3"<< std::endl;
	int input;
	std::cin >> input;
	switch(input) {
		case 1:
			createFrame();
			break;
		case 2:
			printFrame();
			break;
		case 3: 
			moveTrans();
			break;
		default:
			std::cout << "heste" << std::endl;
			break;
	}
}


void Robot_control::createFrame() {

	std::vector<double> init;//= {-0.143, -0.435, 0.20, -0.001, 3.12, 0.04};
	std::vector<double> xp;// = {-0.743, -0.435, 0.20, -0.001, 3.12, 0.04};
	std::vector<double> yp;// = {-0.743, -0.235, 0.20, -0.001, 3.12, 0.04};
	
	std::cout << "Click Enter when robot is at the right init point";
	std::cin.ignore();
	
	init = getPose();
	for (double i : init) {
		std::cout << i << std::endl;
	}
	
	std::cout << "Click Enter when robot is at the right x point";
	std::cin.ignore();
	
	xp = getPose();
	for (double i : xp) {
		std::cout << i << std::endl;
	}
	
	std::cout << "Click Enter when robot is at the right y point";
	std::cin.ignore();
	yp = getPose();
	for (double i : yp) {
		std::cout << i << std::endl;
	}
	
	
	Kinematic kin(init, xp, yp);
	std::vector<double> feat = kin.getFrame();
	writeFrame(feat);
	std::cout << "\n--Frame--" << std::endl;
	
	for (double c : feat) {
		std::cout << c << std::endl;
	}
	
	std::cout << "------" << std::endl;
	// ----------------------------------------------------------------------------------------------------
	/*
	init.insert(init.end(), {_velocity, _acceleration, _blend});
	xp.insert(xp.end(), {_velocity, _acceleration, _blend});
	yp.insert(yp.end(), {_velocity, _acceleration, _blend});

	std::vector<std::vector<double>> path;
	path.push_back(init);
	path.push_back(xp);
	path.push_back(yp);

	// Send a linear path with blending in between - (currently uses separate script)
  	rtde_c.moveL(path);
	// Stop the RTDE control script
	rtde_c.stopScript();
	*/
}

bool Robot_control::isFrameCreated() {
	std::vector<double> a = getFrame();
	return ( a[0] == 0 && a.size() == 1 ? false : true);
}

void Robot_control::moveTrans() {
	
	if (isFrameCreated()) { 
		std::vector<double> frame = getFrame();
		
		//std::vector<double> frameTrans1 = rtde_c.poseTrans(frame, {.1/*-0.0767*/, /*-.0223*/.0, .0,.0/* (pi*22.3/180)*/, pi, .0});	
		//std::vector<double> frameTrans2 = rtde_c.poseTrans(frame, {.0, .1, .0, .0/* (pi*22.3/180)*/, pi, .0});	
		//std::vector<double> frameTrans3 = rtde_c.poseTrans(frame, {.0, .0, .0, .0/* (pi*22.3/180)*/, pi, .0});	
		
		std::vector<double> frameTrans1 = rtde_c.poseTrans(frame, {.1, .0, .0, .0,-pi,.0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		std::vector<double> frameTrans2 = rtde_c.poseTrans(frame, {.0, .1, .0, .0,-pi,.0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		std::vector<double> frameTrans3 = rtde_c.poseTrans(frame, {.0, .0, .0, .0,-pi,.0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		
		frameTrans1.insert(frameTrans1.end(), {_velocity, _acceleration, _blend});
		frameTrans2.insert(frameTrans2.end(), {_velocity, _acceleration, _blend});
		frameTrans3.insert(frameTrans3.end(), {_velocity, _acceleration, _blend});

		std::vector<std::vector<double>> path;
		path.push_back(frameTrans3);
		path.push_back(frameTrans1);
		path.push_back(frameTrans3);
		path.push_back(frameTrans2);
		path.push_back(frameTrans3);
		
		// Send a linear path with blending in between - (currently uses separate script)
	  	rtde_c.moveL(path);
		// Stop the RTDE control script
		rtde_c.stopScript();
		
	}
}













void Robot_control::printFrame() {
	std::vector<double> a = getFrame();
	for (const double i : a ) {
			std::cout << i << ' ';
		}
	std::cout << std::endl;
}

std::vector<double> Robot_control::getFrame(){
	std::vector<double> a;
	std::ifstream _frame;
	_frame.open("frameSave.txt");
	std::string line;
	if (_frame.is_open()) {
		std::getline(_frame,line);	
		_frame.close();
		std::stringstream ss(line);
		for (double i; ss >> i;) {
			a.push_back(i); 
			if (ss.peek() == ',' || ss.peek() == ' ') {
				ss.ignore();
			}
		}
		return a;
	}
	std::cout << "Unable to open file" << std::endl; 
	return {0};
}

void Robot_control::writeFrame(std::vector<double> &v){
	std::ofstream _frame;
	_frame.open("frameSave.txt");
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			_frame << v[i]; 
		} 
		else {
			_frame << v[i] << ","; 
		}
	}
	_frame.close();
}

