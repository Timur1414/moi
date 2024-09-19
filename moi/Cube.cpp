#include "Cube.h"

Cube::Cube() {
	dim = 0;
	size = 0;
}

Cube::Cube(int dim) {
	this->dim = dim;
	size = pow(2, dim);
	arr.resize(size);
	for (int i = 0; i < size; i++) {
		arr[i] = to_2_ss(i);
	}
}

int Cube::get_size() {
	return size;
}

std::vector<std::vector<int>> Cube::get_arr() {
	return arr;
}

std::vector<int> Cube::to_2_ss(int n) {
	std::vector<int> res;
	while (n) {
		int ost = n % 2;
		n /= 2;
		res.push_back(ost);
	}
	while (res.size() < dim)
		res.push_back(0);
	reverse(res.begin(), res.end());
	return res;
}

int Cube::dist(const std::vector<int>& a, const std::vector<int>& b) {
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += abs(a[i] - b[i]);
	return sum;
}

std::vector<int> Cube::operator[](int index) {
	return arr[index];
}

std::pair<int, int> Cube::min_max_dist() {
	int min_dist = dim + 1;
	int max_dist = -1;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int d = dist(arr[i], arr[j]);
			min_dist = std::min(min_dist, d);
			max_dist = std::max(max_dist, d);
		}
	}
	return { min_dist, max_dist };
}

std::ostream& operator << (std::ostream& out, std::vector<int> arr) {
	for (int i : arr)
		out << i;
	return out;
}

std::ostream& operator << (std::ostream& out, Cube cube) {
	for (std::vector<int> vec : cube.arr)
		out << vec << std::endl;
	return out;
}

std::ostream& operator << (std::ostream& out, std::pair<int, int> pair) {
	out << "min: " << pair.first << "  max: " << pair.second;
	return out;
}
