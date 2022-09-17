#include <cstdlib>
#include <iostream>
#include <vector>
#include "Converter.h"

using namespace std;

int main(int argc, const char* argv[]) {

	int n = atoi(argv[1]);
	int target_base = atoi(argv[2]);

	Converter converter{};

	vector<int> result = converter.ConvertBase10(
		target_base = target_base,
		n = n
	);

	cout << "Result : " << endl;
	for (const auto& item: result) {
		cout << item;
	}
	cout <<endl;

	return 0;
}