
#include "kthSmallestNumber.hpp"
#include "Median.hpp"
#include <iostream>
#include <string>

int main() {

	std::string line;

	KthSmallestNumber<int> tenthSmallestNumber(10);
	Median<int> median;

	while (std::getline(std::cin, line)) {

		int number = stoi(line);

		tenthSmallestNumber.addNumber(number);
		std::cout << tenthSmallestNumber << std::endl;

		median.addNumber(number);
		std::cout << median << std::endl;

	}

	return 0;
}
