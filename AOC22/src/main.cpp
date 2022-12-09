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
	case 2:
	{
		solution = std::make_unique<day2_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 3:
	{
		solution = std::make_unique<day3_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 4:
	{
		solution = std::make_unique<day4_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 5:
	{
		solution = std::make_unique<day5_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 6:
	{
		solution = std::make_unique<day6_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 7:
	{
		solution = std::make_unique<day7_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 8:
	{
		solution = std::make_unique<day8_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	case 9:
	{
		solution = std::make_unique<day9_solution>();
		solution->run();
		std::cin.get();
		return 0;
	}
	default:
		std::cout << "That isn't a valid day. Rerun the program to try again.";
		return -1;
	}
}