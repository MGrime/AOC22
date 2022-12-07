#include "day7_solution.hpp"

#include <bitset>
#include <string>
#include <unordered_map>

void day7_solution::run()
{
	// Now read
	const std::string input = get_input();

	// Create filesystem. Always starts with root
	std::shared_ptr<file> root_dir = std::make_shared<file>(filetype::DIR, 0, "/");
	std::shared_ptr<file> current_parent = root_dir;

	std::stringstream part1(input);
	std::string line;

	// Skip first line as it is just a cd / which is useless
	std::getline(part1, line, '\n');

	while (std::getline(part1, line, '\n')) {
		// If not $ its not a command
		if (line[0] != '$')
		{
			std::stringstream linestream(line);

			// Assume dir to start
			filetype type = filetype::DIR;
			size_t size = 0;
			std::string name;

			// Directory
			if (line[0] == 'd')
			{
				// >> operator moves along by word. Skip dir, second word name
				linestream >> name;
				linestream >> name;
			}
			// file
			else
			{
				type = filetype::FILE;
				linestream >> size;
				linestream >> name;
			}
			// Add to tree
			current_parent->add_child(std::make_shared<file>(type, size, name), current_parent);
		}
		else if (line[2] == 'c')
		{
			// Directory change. 5 pos skips "$ cd "
			std::string target_dir = line.substr(5);
			// . means .. command, so up one
			if (target_dir[0] == '.')
			{
				current_parent = current_parent->get_parent();
			} else
			{
				current_parent = current_parent->get_child(target_dir);
			}
		}

	}

	// Now we have file system at root
	// Part 1
	std::vector directories = { root_dir };
	size_t output = 0;
	for (size_t i = 0; i < directories.size(); ++i)
	{
		if (auto size = directories[i]->get_size(); size <= 100000)
		{
			output += size;
		}
		for (const auto& val : directories[i]->get_children() | std::views::values)
		{
			if (val->get_type() == filetype::DIR)
			{
				directories.push_back(val);
			}
		}
	}

	// PArt 2
	directories.clear();
	directories = { root_dir };

	size_t required_free = 30000000 - (70000000 - root_dir->get_size());

	size_t part2_answer = root_dir->get_size();

	for (size_t i = 0; i < directories.size(); i++) \
	{
		auto total_size = directories[i]->get_size();
		// More than we need and less than our current choice
		if (total_size >= required_free && total_size < part2_answer)
		{
			part2_answer = total_size;
		}
		for (const auto& val : directories[i]->get_children() | std::views::values) 
		{
			if (val->get_type() == filetype::DIR) 
			{
				directories.push_back(val);
			}
		}
	}

	std::cout << "Part 1. Sum of directories = " << output << '\n';
	std::cout << "Part 2. Size of smallest to delete = " << part2_answer;
}
