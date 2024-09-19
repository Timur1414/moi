#include "Function.h"

void Function::generate_data() {
	for (size_t i = size / 2; i > 0; i /= 2) {
		std::vector<int> tmp(size, 0);
		bool flag = true;
		for (size_t j = 0; j < size; j++) {
			if (j % i == 0)
				flag = !flag;
			tmp[j] = (int)flag;
		}
		data.push_back(Vector(tmp));
	}
}

Function::Function() {
	number_params = 0;
	size = 0;
	data = std::vector<Vector>(0);
	res = Vector(0);
}

Function::Function(std::vector<int> res) {
	this->res = res;
	size = res.size();
	number_params = log2(size);
	generate_data();
}

Vector Function::get_res() {
	return res;
}

Function Function::create_dual() {
	auto cur_res = this->res.get_arr();
	std::vector<int> new_res(cur_res.size());
	for (size_t i = 0; i < new_res.size(); i++)
		new_res[i] = cur_res[i] ^ 1;
	std::reverse(new_res.begin(), new_res.end());
	return Function(new_res);
}

bool Function::is_T0() {
	return (res[0] == 0);
}

bool Function::is_T1() {
	return (res[size - 1] == 1);
}

bool Function::is_S() {
	for (size_t i = 0; i < size / 2; i++) {
		if (res[i] == res[size - 1 - i])
			return false;
	}
	return true;
}

bool Function::is_M() {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i + 1; j < size; j++) {
			Vector a(number_params, i);
			Vector b(number_params, j);
			if (a <= b)
				if (res[j] < res[i])
					return false;
		}
	}
	return true;
}

bool Function::is_L() {
	std::map<std::string, int> map;
	map["0"] = res[0];
	for (size_t i = 1; i < size; i++) {
		Vector kit(number_params, i);
		std::string key;
		for (size_t j = 0; j < number_params; j++)
			if (kit[j])
				key += '0' + (j + 1);
		int value = res[i];
		value ^= map.at("0");
		std::for_each(map.begin(), map.end(), [key, &value](std::pair<std::string, int> item) {
			if (std::all_of(item.first.begin(), item.first.end(), [key](char c) {
				return key.find(c) != std::string::npos;
				})) {
				value ^= item.second;
			}
		});
		map[key] = value;
	}
	// значения в map - коэффициенты анф функции
	for (std::pair<std::string, int> item : map)
		if (item.second == 1 && item.first.length() != 1)
			return false;
	return true;
}

void Function::show_post_classes() {
	std::cout << "T0 T1 S L M\n";
	std::cout << this->is_T0() << "  " << this->is_T1() << "  " << this->is_S() << " " << this->is_L() << " " << this->is_M() << std::endl;
}

std::string Function::show_anf() {
	std::map<std::string, int> map;
	map["0"] = res[0];
	for (size_t i = 1; i < size; i++) {
		std::cout << i << "/" << size << std::endl;
		Vector kit(number_params, i);
		std::string key;
		for (size_t j = 0; j < number_params; j++)
			if (kit[j])
				key += '0' + (j + 1);
		int value = res[i];
		value ^= map.at("0");
		std::for_each(map.begin(), map.end(), [key, &value](std::pair<std::string, int> item) {
			if (std::all_of(item.first.begin(), item.first.end(), [key](char c) {
				return key.find(c) != std::string::npos;
				})) {
				value ^= item.second;
			}
			});
		map[key] = value;
	}
	std::string res = "";
	for (auto item : map) {
		if (item.second) {
			std::cout << item.first << "  +  ";
			res += item.first + "  +  ";
		}
	}
	return res;
}

int abs(Function f) {
	int sum = 0;
	auto vec = f.res.get_arr();
	for_each(vec.begin(), vec.end(), [&sum](int item) {
		sum += item;
		});
	return sum;
}

std::ostream& operator<<(std::ostream& out, Function f) {
	for (size_t i = 0; i < f.size; i++) {
		for (size_t j = 0; j < f.number_params; j++)
			out << f.data[j][i] << " ";
		out << "| ";
		out << f.res[i] << std::endl;
	}
	return out;
}

std::vector<Function> generate_all_functions(int n) {
	std::vector<Function> res;
	int len = pow(2, n);
	int size = pow(2, len);
	for (size_t i = 0; i < size; i++) {
		Vector tmp(len, i);
		res.push_back(Function(tmp.get_arr()));
	}
	return res;
}

std::vector<Function> generate_functions_with_post(int n, bool T0, bool T1, bool S, bool L, bool M) {
	std::vector<Function> res;
	int len = pow(2, n);
	int size = pow(2, len);
	for (size_t i = 0; i < size; i++) {
		Vector tmp(len, i);
		Function f(tmp.get_arr());
		if (f.is_T0() == T0 && f.is_T1() == T1 && f.is_S() == S && f.is_L() == L && f.is_M() == M)
			res.push_back(f);
	}
	return res;
}
