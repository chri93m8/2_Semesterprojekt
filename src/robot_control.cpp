#include "robot_control.h"
#include "kinematic.h"
#include <chrono>

Robot_control::Robot_control(std::string ip) : _ip(ip), rtde_c(ip), rtde_r(ip)  {
	_ip = ip;
	_isFrameCreated = readFrame(); 
}

bool Robot_control::isFrameCreated() {
	return _isFrameCreated;
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
	std::cout << "getPose, Press 4"<< std::endl;
	
	int input;
	std::cin >> input;
	switch(input) {
		case 1:
			//createFrame();
			break;
		case 2:
			printFrame();
			break;
		case 3: 
			moveTrans();
			break;
		case 4: 
			for ( const double d : getPose() ) {
				std::cout << d/pi*180 << ", ";
			}
			std::cout << std::endl;	
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
	char tmp;
	// mangler en måde at stoppe lortet, hvis man kommer til at trykke fejlagtigt 
	std::cout << "Save changes? y/n" << std::endl;
	std::cin >> tmp;
	if ( tmp == 'y' ) {
		Kinematic kin(init, xp, yp);
		std::vector<double> feat = kin.createFrame();
		writeFrame(feat);

		std::cout << "\n--Frame--" << std::endl;
		for (double c : feat) {
			std::cout << c << std::endl;
		}
		std::cout << "------" << std::endl;
	}
	
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

bool Robot_control::readFrame() {
	std::vector<double> a = getFrame();
	return ( a[0] == 0 && a.size() == 1 ? false : true);
}

void Robot_control::moveTrans() {
	
	if (isFrameCreated()) { 
		std::vector<double> frame = getFrame();
		//std::vector<double> frameTrans1 = rtde_c.poseTrans(frame, {.1/*-0.0767*/, /*-.0223*/.0, .0,.0/* (pi*22.3/180)*/, pi, .0});	
		//std::vector<double> frameTrans2 = rtde_c.poseTrans(frame, {.0, .1, .0, .0/* (pi*22.3/180)*/, pi, .0});	
		//std::vector<double> frameTrans3 = rtde_c.poseTrans(frame, {.0, .0, .0, .0/* (pi*22.3/180)*/, pi, .0});	
		
		std::vector<double> frameTrans1 = rtde_c.poseTrans(frame, {.1, .0, .0, (pi*148/180), -(pi*102/180), .0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		std::vector<double> frameTrans2 = rtde_c.poseTrans(frame, {.0, .1, .0, (pi*148/180), -(pi*102/180), .0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		std::vector<double> frameTrans3 = rtde_c.poseTrans(frame, {.0, .0, .0, (pi*148/180), -(pi*102/180), .0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		std::vector<double> frameTrans4 = rtde_c.poseTrans(frame, {.0, .0, .1, (pi*148/180), -(pi*102/180), .0});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		
		std::vector<double> frameTrans5 = rtde_c.poseTrans(frame, {.0, .0, .1, -(pi*90/180), .0, (pi*5/180)});//(pi*90/180), (pi*17/180), (pi*17/180)});	
		
		insertAddons(frameTrans1);
		insertAddons(frameTrans2);
		insertAddons(frameTrans3);
		insertAddons(frameTrans4);
		insertAddons(frameTrans5);
		
		//frameTrans1.insert(frameTrans1.end(), {_velocity, _acceleration, _blend});
		//frameTrans2.insert(frameTrans2.end(), {_velocity, _acceleration, _blend});
		//frameTrans3.insert(frameTrans3.end(), {_velocity, _acceleration, _blend});
		//frameTrans4.insert(frameTrans4.end(), {_velocity, _acceleration, _blend});
		//frameTrans5.insert(frameTrans5.end(), {_velocity, _acceleration, _blend});

		std::vector<std::vector<double>> path;
		//path.push_back(frameTrans3);
		path.push_back(frameTrans5);
		
		/*
		path.push_back(frameTrans1);
		path.push_back(frameTrans3);
		path.push_back(frameTrans2);
		path.push_back(frameTrans3);
		path.push_back(frameTrans4);
		path.push_back(frameTrans3);
		*/
		// Send a linear path with blending in between - (currently uses separate script)
	  	rtde_c.moveL(path);
		// Stop the RTDE control script
		rtde_c.stopScript();
		
	}
}

void Robot_control::insertAddons(std::vector<double> &v) {
	v.insert(v.end(), {_velocity, _acceleration, _blend});
}


void Robot_control::insertRotvec(std::vector<double> &v) {
	v.insert(v.end(), {getRotvec()[0], getRotvec()[1], getRotvec()[2]});
	
}

void Robot_control::setRotvec(std::vector<double> v) {
	_rotvec = v;
}


std::vector<double> Robot_control::getRotvec() {
	return _rotvec;
}

void Robot_control::move(std::vector<double> &v) {

	setRotvec({(pi*18/180), (pi*100/180), -(pi*85/180)});
	insertRotvec(v);
	
	
	std::vector<double> x = rtde_c.poseTrans(getFrame(), v);
	
	insertAddons(x);
	
	for (const double d : x ) {
		std::cout << d << " "; 
	}
	std::cout << std::endl;
	
	std::vector<std::vector<double>> path;
	path.push_back(x);
	// Send a linear path with blending in between - (currently uses separate script)
	rtde_c.moveL(path);
	// Stop the RTDE control script
	rtde_c.stopScript();
	
}


void Robot_control::home(std::vector<double> &v) {
	if (isFrameCreated()) {
		std::cout << "frame is created" << std::endl;
		
	}

}

bool Robot_control::forceDown(int maxHeight) { // kører -> finde disk -> stop movement -> return
	std::vector<double> joint_speed = {0.0, 0.0, -0.05, 0.0, 0.0, 0.0};
	double startHeight = rtde_r.getActualTCPPose()[2];
	double newHeight;
 	//double dt = 1.0/500; // 2ms
	while (rtde_r.getActualTCPForce()[2] < 21 ) {
		
    		std::chrono::steady_clock::time_point t_start = rtde_c.initPeriod();
		std::cout << "Force: " << rtde_r.getActualTCPForce()[2] << std::endl;
		newHeight = startHeight - rtde_r.getActualTCPPose()[2];
		std::cout << "newHeight: " << newHeight << std::endl;
		rtde_c.speedL(joint_speed, _acceleration);
    		//joint_speed[2] -= 0.05;
    		
    		rtde_c.waitPeriod(t_start);
		// hvis den når en distance
		if ( ( newHeight * 100 )  >= maxHeight ) {
			rtde_c.speedStop();
			rtde_c.stopScript();
			return false;
		}
		
	}
	rtde_c.speedStop();
	rtde_c.stopScript();
	return true;
	/*
	for (int i = 0; i < 10; i++) {
	  	std::cout << "\n";
  		std::cin.ignore();
		std::vector<double> a = rtde_r.getActualTCPForce();
		
		for ( const double d : a ) {
			std::cout << "force = " << d << std::endl;
		}
		std::cout << std::endl;
	}
	*/
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

