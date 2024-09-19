#include "Sphere.h"

Sphere::Sphere() : Cube() {
	r = 0;
}

Sphere::Sphere(int dim, int r, std::vector<int> center) : Cube(dim) {
	this->r = r;
	this->center = center;
	std::vector<std::vector<int>> tmp = arr;
	arr.clear();
	for (std::vector<int> vec : tmp) {
		if (dist(center, vec) == r)
			arr.push_back(vec);
	}
	size = arr.size();
}
