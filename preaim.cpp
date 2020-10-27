#include<iostream>
#include "preaim.h"


xyz::xyz()
{
	x = 0;
	y = 0;
	z = 0;
}

xyz::xyz(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}

xyz pre_aim(xyz aim_from, xyz aim_to, double aim_spd, xyz move_dir)
{
	
	xyz res;
	double t1, t2, t;

	// d(aim_to + t*move_dir , aim_from) = t*aim_spd , t=?
	double a, b, c;

	a = (move_dir.x * move_dir.x + move_dir.y * move_dir.y + move_dir.z * move_dir.z - aim_spd * aim_spd);
	b = (2 * (aim_to.x * move_dir.x + aim_to.y * move_dir.y + aim_to.z * move_dir.z - aim_from.x * move_dir.x - aim_from.y * move_dir.y - aim_from.z * move_dir.z));
	c = (aim_to.x * aim_to.x + aim_to.y * aim_to.y + aim_to.z * aim_to.z + aim_from.x * aim_from.x + aim_from.y * aim_from.y + aim_from.z * aim_from.z - 2 * (aim_to.x * aim_from.x + aim_to.y * aim_from.y + aim_to.z * aim_from.z));

	//std::cout << "a = " << a << std::endl;
	//std::cout << "b = " << b << std::endl;
	//std::cout << "c = " << c << std::endl;

	if ((b * b - 4 * a * c) < 0) return xyz(0, 0, 0);

	if (a == 0 && b == 0) return xyz(0, 0, 0);
	
	if (a == 0) {
		t = (-1 * c) / b;
	}
	
	else {
		t1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
		t2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);

		if (t1 < 0 && t2 < 0) return xyz(0, 0, 0);
		if (t1 < 0) t = t2;
		if (t2 < 0) t = t1;

		if (t1 >= 0 && t2 >= 0) {
			if (t1 < t2) t = t1;
			else t = t2;
		}
	}
	
	// std::cout << "t = " << t << std::endl << std::endl;

	// res = (aim_to + t * move_dir - aim_from) 

	res.x = (aim_to.x + t * move_dir.x - aim_from.x);
	res.y = (aim_to.y + t * move_dir.y - aim_from.y);
	res.z = (aim_to.z + t * move_dir.z - aim_from.z);

	double norm = sqrt(res.x * res.x + res.y * res.y + res.z * res.z);

	// final = res / ||res||

	res.x /= norm;
	res.y /= norm;
	res.z /= norm;

	return res;
}
