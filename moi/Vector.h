#pragma once
#include <vector>
#include <iostream>

class Vector {
private:
	int dim;
	std::vector<int> arr;
public:
	Vector();
	Vector(int);
	Vector(int, int);
	Vector(std::vector<int>);
	
	bool operator <= (const Vector&);
	bool operator >= (const Vector&);
	int operator[] (int);

	std::vector<int> get_arr();

	std::vector<int> to_2_ss(int);
	int dist(const Vector&);

	friend std::ostream& operator << (std::ostream&, Vector);
};

std::ostream& operator << (std::ostream&, Vector);
