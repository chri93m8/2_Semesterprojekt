#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <iostream>
#include <array>
#include <vector>
#include <math.h>

class Kinematic {
	private:
		std::vector<double> _initPoint;
		std::vector<double> _xPoint;
		std::vector<double> _yPoint;
		std::vector<double> _frame;
		
	public:
		Kinematic();
		void setStart(std::vector<double> initPoint);
		void setX(std::vector<double> xPoint);
		void setY(std::vector<double> yPoint);
		std::vector<double> getDirectionVector();
		void crossProduct(std::vector<double> &d12, std::vector<double> &d13);
		void normalize(std::vector<double> &p);
		void rotmat2rotvec(std::vector<double> &rotmat);
		void createFrame(std::vector<double> &rotvec);
		void getFrame();
		
		
};

#endif // KINEMATIC_H


/*
####
# get feature plane from three points
####
##
# p1: origin
# p2: determines positive X axis (direction from p1 to p2 is X axis)
# p3: determines sign of Y axis  
## 
####
def get_feature_plane(p1, p2, p3):
	
	# Step 1. Get the direction vectors
	d12 = [ p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2] ]
	d13 = [ p3[0]-p1[0], p3[1]-p1[1], p3[2]-p1[2] ]
	
	# Step 2. Get the direction vector of Z axis by cross product of d12 and d13
	dz = cross_product(d12, d13)
	
	# Step 3. Get the X and Z unit direction vectors by normalizing d12 and dz
	temp = norm(d12)
	ux = [ d12[0]/temp, d12[1]/temp, d12[2]/temp ]
	temp = norm(dz)
	uz = [ dz[0]/temp, dz[1]/temp, dz[2]/temp ]
	
	# Step 4. Get Y unit direction vector by cross product of uz and ux
	uy = cross_product(uz, ux)
	
	# Step 5. Get the rotation matrix from the unit direction vectors
	rotmat = [ ux[0], ux[1], ux[2], uy[0], uy[1], uy[2], uz[0], uz[1], uz[2] ]
	
	# Step 6. Get the rotation vector from the rotation matrix
	rotvec = rotmat2rotvec(rotmat)
	
	# Step 7. Get the feature plane with the origin at p1 and the frame achieved at step 6
	feature_plane = [ p1[0], p1[1], p1[2], rotvec[0], rotvec[1], rotvec[2] ]
	
	return feature_plane
end
####
*/

