#pragma once
#include "Vector.h"
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>


class Function {
private:
	int number_params;
	int size;
	std::vector<Vector> data;
	Vector res;

	void generate_data();
public:
	Function();
	Function(std::vector<int>);

	Vector get_res();

	Function create_dual();

	friend int abs(Function);
	friend std::ostream& operator << (std::ostream&, Function);
	bool is_T0();
	bool is_T1();
	bool is_S();
	bool is_M();
	bool is_L();
	void show_post_classes();
	std::string show_anf();
};

int abs(Function);
std::ostream& operator << (std::ostream&, Function);

std::vector<Function> generate_all_functions(int);
std::vector<Function> generate_functions_with_post(int, bool, bool, bool, bool, bool);
