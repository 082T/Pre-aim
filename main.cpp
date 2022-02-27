// Math behind: https://imgur.com/a/3sraVo7

#include<iostream>
#include "preaim.h"

int main() {

	
	// call example

	xyz into(0, 0, 0);
	xyz into_speed(1, 0, 0);
	xyz from(2, 4 , 0);
	double from_speed = 2;

	
	xyz res=pre_aim(from, into, from_speed, into_speed);

	std::cout << res.x << " " << res.y << " " << res.z << std::endl;
	

	return 0;
}
