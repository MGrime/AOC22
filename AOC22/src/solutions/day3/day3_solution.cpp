#include "day3_solution.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>

void day3_solution::run()
{
	const std::string input = get_input();
	std::stringstream part1(input);

	int total_prio = 0;

	std::string backpack;
	while (std::getline(part1, backpack, '\n')) {

		// Split string in half
		std::string first_half = backpack.substr(0, backpack.length() / 2);
		std::string second_half = backpack.substr(backpack.length() / 2, backpack.length() / 2);

		// Convert to their values
		std::vector<int> first_half_num;
		for (const auto part : first_half)
		{
			if (isupper(part))
			{
				first_half_num.push_back(part - 38);
			} else
			{
				first_half_num.push_back(part - 96);
			}
		}

		std::vector<int> second_half_num;
		for (const auto part : second_half)
		{
			if (isupper(part))
			{
				second_half_num.push_back(part - 38);
			}
			else
			{
				second_half_num.push_back(part - 96);
			}
		}

		// Sort
		std::ranges::sort(first_half_num);
		std::ranges::sort(second_half_num);

		// Find first of
		total_prio += *std::ranges::find_first_of(first_half_num, second_half_num);
	}

	std::cout << "Total priority of overlap items (part1) is: " << total_prio << '\n';

	std::stringstream part2(input);
	std::string elf1,elf2,elf3;

	total_prio = 0;
	while (std::getline(part2, elf1, '\n')) {
		// If we trigger loop, there will always be 2 more after
		std::getline(part2, elf2, '\n');
		std::getline(part2, elf3, '\n');

		// Now we have elf1/elf2/elf3
		// Create a map
		std::unordered_map<int, int> hash_map;

		// Start with elf1
		for (const auto item : elf1)
		{
			hash_map[item] = 1;
		}

		// Now loop and if exists set to 2
		for (const auto item : elf2)
		{
			if (hash_map.contains(item))
			{
				hash_map[item] = 2;
			}
		}

		// Now loop and if exists set to 3
		for (const auto item : elf3)
		{
			if (hash_map.contains(item))
			{
				if (hash_map[item] == 2)
				{
					hash_map[item] = 3;
					
				}
			}
		}

		// Find the element that has 3
		for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
			if (it->second == 3)
			{
				// item is it->first
				char overlapping_item = static_cast<char>(it->first);

				// Convert to prio
				int prio = 0;
				if (isupper(overlapping_item))
				{
					prio = overlapping_item - 38;
				}
				else
				{
					prio = overlapping_item - 96;
				}
				// Sum
				total_prio += prio;
			}
		}


	}
	std::cout << "Total priority of overlap items (part3) is: " << total_prio << '\n';
}
