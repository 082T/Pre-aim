#pragma once


class xyz {

public:
	double x, y, z;

	xyz();
	xyz(double x, double y, double z);
};

//if "move_dir" is given by a normed vector "norm" and speed "s" , then move_dir = norm * s //

xyz pre_aim(xyz aim_from, xyz aim_to, double aim_spd, xyz move_dir);
