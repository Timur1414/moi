#pragma once
#include "Cube.h"

class Sphere : public Cube {
private:
	std::vector<int> center;
	int r;
public:
	Sphere();
	Sphere(int, int, std::vector<int>);

	std::vector<int> r_arr();
};