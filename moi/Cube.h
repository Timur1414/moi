#pragma once
#include <vector>
#include <iostream>

class Cube {
protected:
	int dim;
	std::vector<std::vector<int>> arr;
	int size;
public:
	Cube();
	Cube(int);

	int get_size();
	std::vector<std::vector<int>> get_arr();

	std::vector<int> to_2_ss(int);
	int dist(const std::vector<int>&, const std::vector<int>&);
	friend std::ostream& operator << (std::ostream&, Cube);
	std::vector<int> operator [] (int);
	std::pair<int, int> min_max_dist();
};


std::ostream& operator << (std::ostream&, std::vector<int>);

std::ostream& operator << (std::ostream&, Cube);

std::ostream& operator << (std::ostream&, std::pair<int, int>);
