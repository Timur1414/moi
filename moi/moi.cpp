#include <iostream>
#include "Function.h"
#include <fstream>


using namespace std;


int main() {
	Vector v(std::pow(2, 25), 0);
	std::vector<int> arr = v.get_arr();
	int index = std::pow(2, 25 - 1) + 1;
	arr[index] = 1;
	Function f(arr);
	std::string s = f.show_anf();
	cout << s;
	ofstream fout("res.txt");
	fout << s;
	fout.close();


	return 0;
}
