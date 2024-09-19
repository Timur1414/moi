#include "Vector.h"

Vector::Vector() {
	dim = 0;
}

Vector::Vector(int dim) {
	this->dim = dim;
	arr = std::vector<int>(dim, 0);
}

Vector::Vector(int dim, int n) {
	this->dim = dim;
	arr = to_2_ss(n);
}

Vector::Vector(std::vector<int> arr) {
	dim = arr.size();
	this->arr = arr;
}

bool Vector::operator<=(const Vector& b) {
	for (int i = 0; i < dim; i++)
		if (arr[i] > b.arr[i])
			return false;
	return true;
}

bool Vector::operator>=(const Vector& b) {
	for (int i = 0; i < dim; i++)
		if (arr[i] < b.arr[i])
			return false;
	return true;
}

int Vector::operator[](int index) {
	return arr[index];
}

std::vector<int> Vector::get_arr() {
	return arr;
}

std::vector<int> Vector::to_2_ss(int n) {
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

int Vector::dist(const Vector& b) {
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += abs(arr[i] - b.arr[i]);
	return sum;
}

std::ostream& operator<<(std::ostream& out, Vector vector) {
	for (int i = 0; i < vector.dim; i++)
		out << vector[i];
	return out;
}
