#include "day6_solution.hpp"

#include <bitset>
#include <string>
#include <unordered_map>

void day6_solution::run()
{
	// Now read
	const std::string input = get_input();

	bool found = false;
	int starting_char = 0;

	while (!found)
	{
		std::unordered_map<char, int> seen_map;
		for (int i = starting_char; i < starting_char + 14; ++i)
		{
			seen_map[input[i]] += 1;
		}

		found = true;

		for (const auto& [fst, snd] : seen_map)
		{
			if (snd >= 2)
			{
				found = false;
				break;
			}
		}

		starting_char += 1;
	}

	std::cout << "Process " << starting_char + 13 << " characters";
}
