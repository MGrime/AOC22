#include <iostream>
#include <memory>
#include "solutions/solutions.hpp"

int main() {
	std::cout << "Welcome to AOC 2022\n";
	std::cout << "Enter a number between (inclusive) 1 and 25 to run solution for that day:\n";

	const int selection = std::cin.get() - '0';

	std::unique_ptr<solution_base> solution;

	switch (selection)
	{
	case 1:
	{
		solution = std::make_unique<day1_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	default:
		std::cout << "That isn't a valid day. Rerun the program to try again.";
		return -1;
	}
}