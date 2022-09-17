#include <gtest/gtest.h>
#include "../main/Converter.h"

using namespace std;

class ConverterTest : public ::testing::Test {
	public:
		Converter converter;

		void SetUp() override {
			converter = Converter();
		}
};

TEST_F(ConverterTest, ConvertBase10_throws_exception_when_trying_to_convert_negative_number) {
	auto target_base = 10;
	auto n = - 1;

	try
	{
		converter.ConvertBase10(
			target_base = target_base,
			n = n
		);
		FAIL();
	}
	catch(const std::invalid_argument&)
	{
		SUCCEED();
	}
}

TEST_F(ConverterTest, ConvertBase10_throws_exception_when_target_base_is_smaller_than_2) {
	auto target_base = 1;
	auto n = 10;

	try
	{
		converter.ConvertBase10(
			target_base = target_base,
			n = n
		);
		FAIL();
	}
	catch(const std::invalid_argument&)
	{
		SUCCEED();
	}
}

TEST_F(ConverterTest, ConvertBase10_throws_exception_when_target_base_is_bigger_than_10) {
	auto target_base = 11;
	auto n = 10;

	try
	{
		converter.ConvertBase10(
			target_base = target_base,
			n = n
		);
		FAIL();
	}
	catch(const std::invalid_argument&)
	{
		SUCCEED();
	}
}

class ConverterBaseConversionTest : public ::testing::Test,
                                    public ::testing::WithParamInterface<tuple<int, int, vector<int>>> {

	public:
		Converter converter;

		void SetUp() override {
			converter = Converter();
		}
};

TEST_P(ConverterBaseConversionTest, ConvertBase10_returns_number_n_converted_from_base_10_to_target_base) {
	auto target_base = get<0>(GetParam());
	auto n = get<1>(GetParam());
	auto expected_result = get<2>(GetParam());

	auto result = converter.ConvertBase10(
		target_base = target_base,
		n = n
	);

	ASSERT_EQ(result, expected_result);
}

INSTANTIATE_TEST_CASE_P
(
	ConverterTest,
	ConverterBaseConversionTest,
	::testing::Values(
		std::make_tuple(2, 0, vector<int>{0}),
		std::make_tuple(2, 1, vector<int>{1}),
		std::make_tuple(2, 2, vector<int>{1, 0}),
		std::make_tuple(2, 3, vector<int>{1, 1}),
		std::make_tuple(2, 4, vector<int>{1, 0, 0}),
		std::make_tuple(2, 5, vector<int>{1, 0, 1}),
		std::make_tuple(2, 6, vector<int>{1, 1, 0}),
		std::make_tuple(2, 7, vector<int>{1, 1, 1}),
		std::make_tuple(2, 8, vector<int>{1, 0, 0, 0}),
		std::make_tuple(2, 16, vector<int>{1, 0, 0, 0, 0}),
		std::make_tuple(2, 32, vector<int>{1, 0, 0, 0, 0, 0}),
		std::make_tuple(2, 64, vector<int>{1, 0, 0, 0, 0, 0, 0}),
		std::make_tuple(2, 128, vector<int>{1, 0, 0, 0, 0, 0, 0, 0}),
		std::make_tuple(2, 256, vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0}),
		std::make_tuple(3, 0, vector<int>{0}),
		std::make_tuple(3, 1, vector<int>{1}),
		std::make_tuple(3, 2, vector<int>{2}),
		std::make_tuple(3, 3, vector<int>{1, 0}),
		std::make_tuple(3, 4, vector<int>{1, 1}),
		std::make_tuple(3, 5, vector<int>{1, 2}),
		std::make_tuple(3, 6, vector<int>{2, 0}),
		std::make_tuple(3, 7, vector<int>{2, 1}),
		std::make_tuple(3, 8, vector<int>{2, 2}),
		std::make_tuple(3, 9, vector<int>{1, 0, 0}),
		std::make_tuple(3, 12, vector<int>{1, 1, 0}),
		std::make_tuple(3, 13, vector<int>{1, 1, 1}),
		std::make_tuple(3, 14, vector<int>{1, 1, 2}),
		std::make_tuple(3, 15, vector<int>{1, 2, 0}),
		std::make_tuple(3, 16, vector<int>{1, 2, 1}),
		std::make_tuple(3, 17, vector<int>{1, 2, 2}),
		std::make_tuple(3, 18, vector<int>{2, 0, 0}),
		std::make_tuple(3, 27, vector<int>{1, 0, 0, 0}),
		std::make_tuple(10, 0, vector<int>{0}),
		std::make_tuple(10, 1, vector<int>{1}),
		std::make_tuple(10, 2, vector<int>{2}),
		std::make_tuple(10, 3, vector<int>{3}),
		std::make_tuple(10, 4, vector<int>{4}),
		std::make_tuple(10, 5, vector<int>{5}),
		std::make_tuple(10, 6, vector<int>{6}),
		std::make_tuple(10, 7, vector<int>{7}),
		std::make_tuple(10, 8, vector<int>{8}),
		std::make_tuple(10, 9, vector<int>{9}),
		std::make_tuple(10, 10,   vector<int>{1, 0}),
		std::make_tuple(10, 11,   vector<int>{1, 1}),
		std::make_tuple(10, 12,   vector<int>{1, 2}),
		std::make_tuple(10, 19,   vector<int>{1, 9}),
		std::make_tuple(10, 20,   vector<int>{2, 0}),
		std::make_tuple(10, 99,   vector<int>{9, 9}),
		std::make_tuple(10, 100,  vector<int>{1, 0, 0}),
		std::make_tuple(10, 101,  vector<int>{1, 0, 1}),
		std::make_tuple(10, 111,  vector<int>{1, 1, 1}),
		std::make_tuple(10, 119,  vector<int>{1, 1, 9}),
		std::make_tuple(10, 120,  vector<int>{1, 2, 0}),
		std::make_tuple(10, 1000, vector<int>{1, 0, 0, 0}),
		std::make_tuple(10, 100'000, vector<int>{1, 0, 0, 0, 0, 0}),
		std::make_tuple(10, 1'000'000, vector<int>{1, 0, 0, 0, 0, 0, 0})
	)
);