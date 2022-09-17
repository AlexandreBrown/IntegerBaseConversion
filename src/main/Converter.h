#ifndef IntegerBaseConversion_MYCLASS_H
#define IntegerBaseConversion_MYCLASS_H

#include <vector>
#include <string>

class Converter {
	public:

		std::vector<int> ConvertBase10(
			int target_base,
			int n
		) ;

	private:

		static double log_a_x(int a, int x) ;
};

#endif
