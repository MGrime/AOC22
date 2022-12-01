#include "day1_solution.hpp"

#include <iostream>
#include <vector>

void day1_solution::run()
{
	std::string input = get_input();

	// Split into array via /n/n
	std::vector<int> totals;
	const std::string delimiter = "\n\n";
	const std::string second_level_delimiter = "\n";

	size_t pos;
	while ((pos = input.find(delimiter)) != std::string::npos) {
		std::string set_for_elf = input.substr(0, pos);

		int per_elf = 0;
		size_t per_pos;
		while ((per_pos = set_for_elf.find(second_level_delimiter)) != std::string::npos)
		{
			per_elf += std::stoi(set_for_elf.substr(0, per_pos));
			set_for_elf.erase(0, per_pos + second_level_delimiter.length());
		}
		// Catch last one
		per_elf += std::stoi(set_for_elf);
		
		totals.push_back(per_elf);
		
		input.erase(0, pos + delimiter.length());
	}

	// Catch last one
	int per_elf = 0;
	size_t per_pos;
	while ((per_pos = input.find(second_level_delimiter)) != std::string::npos)
	{
		per_elf += std::stoi(input.substr(0, per_pos));
		input.erase(0, per_pos + second_level_delimiter.length());
	}
	// Catch last one
	per_elf += std::stoi(input);

	totals.push_back(per_elf);

	// Now find biggest
	int biggest = *std::ranges::max_element(totals);
	size_t index_of_biggest = std::distance(totals.begin(), std::ranges::max_element(totals));
	std::cout << "The elf with the most calories is at Pos: " << index_of_biggest + 1 << " and has " << biggest << " calories\n";

	// PART 2 //
	// Sort array
	std::ranges::sort(totals, std::ranges::greater());

	// Add first 3
	int total_3_biggest = totals[0] + totals[1] + totals[2];
	std::cout << "The top 3 elves carry " << total_3_biggest << " calories";

}
