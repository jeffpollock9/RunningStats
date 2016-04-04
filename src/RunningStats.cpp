#include "kthSmallestNumber.hpp"
#include "Median.hpp"
#include <iostream>
#include <string>

#include <gtest/gtest.h>
TEST(MathTest, TwoPlusTwoEqualsFour) {
	EXPECT_EQ(2 + 2, 4);
}
// a change in a branch again...
// try another commit...
// a change in master
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//int main() {
//
//	std::string line;
//
//	KthSmallestNumber<int> tenthSmallestNumber(10);
//	Median<int> median;
//
//	while (std::getline(std::cin, line)) {
//
//		int number = stoi(line);
//
//		tenthSmallestNumber.addNumber(number);
//		std::cout << tenthSmallestNumber << std::endl;
//
//		median.addNumber(number);
//		std::cout << median << std::endl;
//
//	}
//
//	return 0;
//}
