#include "day4_solution.hpp"

#include <bitset>
#include <string>

template <typename I>
constexpr I bitwise_nor(I lhs, I rhs) noexcept { return ~(lhs | rhs); }

void day4_solution::run()
{
	const std::string input = get_input();
	std::stringstream part1(input);

	int overlapsp1 = 0;
	int overlapsp2 = 0;
	std::string pair;


	while (std::getline(part1, pair, '\n')) {

		size_t delim_pos = pair.find(',');

		std::string first_range = pair.substr(0, delim_pos);
		std::string second_range = pair.substr(delim_pos + 1, pair.length());

		// Now we need to check the range
		std::bitset<100> first_range_bits, second_range_bits;
		first_range_bits.reset();
		second_range_bits.reset();


		// Get first range and loop
		delim_pos = first_range.find('-');

		const int first_range_start = std::stoi(first_range.substr(0, delim_pos));
		const int first_range_end = std::stoi(first_range.substr(delim_pos + 1, first_range.length()));

		for (int i = first_range_start; i <= first_range_end; ++i)
		{
			first_range_bits.set(i, true);
		}

		// Get first range and loop
		delim_pos = second_range.find('-');

		const int second_range_start = std::stoi(second_range.substr(0, delim_pos));
		const int second_range_end = std::stoi(second_range.substr(delim_pos + 1, second_range.length()));

		for (int i = second_range_start; i <= second_range_end; ++i)
		{
			second_range_bits.set(i, true);
		}

		std::bitset<100> result = first_range_bits | second_range_bits;

		if ((result & ~first_range_bits).none() || (result & ~second_range_bits).none())
		{
			overlapsp1 += 1;
		}

		// Now we do part2
		std::bitset<100> p2Result = first_range_bits & second_range_bits;
		for (int i = 0; i < 100; ++i)
		{
			if (p2Result.test(i))
			{
				overlapsp2 += 1;
				break;
			}
		}

	}
	std::cout << "Overlaps (part1): " << overlapsp1 << '\n';
	std::cout << "Overlaps (part2): " << overlapsp2 << '\n';
}
