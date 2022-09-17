#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "Converter.h"
#include <sstream>

using namespace std;

const int MINIMUM_BASE = 2;
const int MAXIMUM_BASE = 10;

vector<int> Converter::ConvertBase10(
	int target_base,
	int n
) {
	int source_base = 10;

	if (n < 0) {
		throw invalid_argument("n must be a positive integer!");
	}
	if (target_base < MINIMUM_BASE || target_base > MAXIMUM_BASE) {
		std::stringstream ss;
		ss << "Target base must be between " << MINIMUM_BASE << " and " << MAXIMUM_BASE << endl;
		throw invalid_argument(ss.str());
	}
	if (n==0) {
		return vector<int>{0};
	}

	int max_target_base_digit_value = target_base - 1;

	int max_exp_t = floor(log_a_x(target_base, n));

	vector<int> output(max_exp_t + 1, 0);

	int number_of_bits_to_represent_n = static_cast<int>(floor(log_a_x(source_base, n))) + 1;

	string digits_temp = to_string(n);
	string digits = string(digits_temp.rbegin(), digits_temp.rend());

	for (int i = 0; i < number_of_bits_to_represent_n; ++i) {
		int remaining = static_cast<int>(digits[i] - '0')*static_cast<int>(pow(source_base, i));

		while (remaining!=0) {
			int target_exponent = floor(log_a_x(target_base, remaining));

			if (output[target_exponent]==max_target_base_digit_value) {
				int j = target_exponent;
				while (j!=output.size() - 1 && output[j]==max_target_base_digit_value) {
					output[j] = 0;
					j++;
				}
				output[j]++;
			} else {
				output[target_exponent]++;
			}

			remaining -= static_cast<int>(pow(target_base, target_exponent));
		}
	}

	reverse(output.begin(), output.end());

	return output;
}

double Converter::log_a_x(int target_base, int x) {
	return log10(x)/log10(target_base);
}
