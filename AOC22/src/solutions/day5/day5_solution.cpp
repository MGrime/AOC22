#include "day5_solution.hpp"

#include <bitset>
#include <string>

template <typename I>
constexpr I bitwise_nor(I lhs, I rhs) noexcept { return ~(lhs | rhs); }

void day5_solution::run()
{
	setup_stacks();

	// Now read
	const std::string input = get_input();
	std::stringstream part1(input);

	std::string instruction;


	while (std::getline(part1, instruction, '\n')) {
		int line_pos = 5;
		// First number always starts at 5
		std::string num_to_move;
		num_to_move += instruction[line_pos];
		if (instruction[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(line_pos) + 1] != ' ')
		{
			line_pos += 1;
			num_to_move += instruction[line_pos];
		}

		const int num_to_move_int = stoi(num_to_move);

		// Now move line pos past "from"
		line_pos += 7;
		
		const auto stack_from = static_cast<size_t>(instruction[line_pos] - '0');
		line_pos += 5;
		const auto stack_to = static_cast<size_t>(instruction[line_pos] - '0');

		// Now process
		for (int i = 0; i < num_to_move_int; ++i)
		{
			auto popped = stack_map[stack_from - 1]->front();
			stack_map[stack_from - 1]->pop_front();
			stack_map[stack_to - 1]->push_front(popped);
		}

	}

	std::string output;
	// Now go through each stack and get the last element
	for (int i = 0; i < 9; ++i)
	{
		output += stack_map[i]->front();
	}

	std::cout << "Top of each stack (part1) " << output;

	// Reset maps
	setup_stacks();

	std::stringstream part2(input);
	while (std::getline(part2, instruction, '\n')) {
		int line_pos = 5;
		// First number always starts at 5
		std::string num_to_move;
		num_to_move += instruction[line_pos];
		if (instruction[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(line_pos) + 1] != ' ')
		{
			line_pos += 1;
			num_to_move += instruction[line_pos];
		}

		const int num_to_move_int = stoi(num_to_move);

		// Now move line pos past "from"
		line_pos += 7;

		const auto stack_from = static_cast<size_t>(instruction[line_pos] - '0');
		line_pos += 5;
		const auto stack_to = static_cast<size_t>(instruction[line_pos] - '0');

		// Now process
		std::deque<char> temporary_stack;
		for (int i = 0; i < num_to_move_int; ++i)
		{
			auto popped = stack_map[stack_from - 1]->front();
			stack_map[stack_from - 1]->pop_front();
			temporary_stack.push_back(popped);
		}

		for (int i = 0; i < num_to_move_int; ++i)
		{
			auto popped = temporary_stack.back();
			temporary_stack.pop_back();
			stack_map[stack_to - 1]->push_front(popped);
		}
	}
	output = "";
	// Now go through each stack and get the last element
	for (int i = 0; i < 9; ++i)
	{
		output += stack_map[i]->front();
	}

	std::cout << "Top of each stack (part2) " << output;
}

void day5_solution::setup_stacks()
{
	// Empty
	for (const auto map : stack_map)
	{
		map->clear();
	}

	stack_one.push_front('F'); stack_one.push_front('D'); stack_one.push_front('B'); stack_one.push_front('Z'); stack_one.push_front('T'); stack_one.push_front('J'); stack_one.push_front('R'); stack_one.push_front('N');
	stack_two.push_front('R'); stack_two.push_front('S'); stack_two.push_front('N'); stack_two.push_front('J'); stack_two.push_front('H');
	stack_three.push_front('C'); stack_three.push_front('R'); stack_three.push_front('N'); stack_three.push_front('J'); stack_three.push_front('G'); stack_three.push_front('Z'); stack_three.push_front('F'); stack_three.push_front('Q');
	stack_four.push_front('F'); stack_four.push_front('V'); stack_four.push_front('N'); stack_four.push_front('G'); stack_four.push_front('R'); stack_four.push_front('T'); stack_four.push_front('Q');
	stack_five.push_front('L'); stack_five.push_front('T'); stack_five.push_front('Q'); stack_five.push_front('F');
	stack_six.push_front('Q'); stack_six.push_front('C'); stack_six.push_front('W'); stack_six.push_front('Z'); stack_six.push_front('B'); stack_six.push_front('R'); stack_six.push_front('G'); stack_six.push_front('N');
	stack_seven.push_front('F'); stack_seven.push_front('C'); stack_seven.push_front('L'); stack_seven.push_front('S'); stack_seven.push_front('N'); stack_seven.push_front('H'); stack_seven.push_front('M');
	stack_eight.push_front('D'); stack_eight.push_front('N'); stack_eight.push_front('Q'); stack_eight.push_front('M'); stack_eight.push_front('T'); stack_eight.push_front('J');
	stack_nine.push_front('P'); stack_nine.push_front('G'); stack_nine.push_front('S');
}
