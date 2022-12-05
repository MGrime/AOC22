#pragma once
#include <array>
#include <deque>

#include "../base/solution_base.hpp"

class day5_solution :public solution_base
{
public:
	day5_solution() : solution_base("day5"){}

	void run() override;
private:
	void setup_stacks();
	// Im going to cheat because i have no idea how to handle the reading of the stacks
	std::deque<char> stack_one, stack_two, stack_three, stack_four, stack_five, stack_six, stack_seven, stack_eight, stack_nine;

	std::array<std::deque<char>*,9> stack_map{ &stack_one,&stack_two,&stack_three,&stack_four,&stack_five,&stack_six,&stack_seven,&stack_eight,&stack_nine };
};

