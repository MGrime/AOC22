#include "day8_solution.hpp"
#include <array>

void day8_solution::run()
{
	const auto& input = get_input();

	std::vector<std::vector<int>> trees_grid;


	std::stringstream part1(input);
	std::string trees;

	while (std::getline(part1, trees, '\n')) {
		// Push back new tree row
		trees_grid.emplace_back();

		// Read each char
		for (auto tree : trees)
		{
			trees_grid.back().emplace_back(tree - '0');
		}
	}

	const size_t inner = trees_grid.size() - 2;
	size_t total = (trees_grid.size() * trees_grid.size()) - (inner * inner);
	int max_scenic = 0;

	// 1 -> size-1 to only look at middle entries
	for (size_t i = 1; i < trees_grid.size() - 1; ++i) // up - > down
	{
		for (size_t j = 1; j < trees_grid[i].size() - 1; ++j) // left > right
		{
			const auto& current_tree = trees_grid[i][j];
			int blocked = 0;
			// left, right, up, down
			std::array<int, 4> scenic_score = { 0,0,0,0 };

			int left = static_cast<int>(j) - 1;
			while (left >= 0)
			{
				if (current_tree <= trees_grid[i][left])
				{
					blocked += 1;
					scenic_score[0] += 1;
					break;
				}
				scenic_score[0] += 1;
				left -= 1;
			}

			size_t right = j + 1;
			while (right < trees_grid[i].size())
			{
				if (current_tree <= trees_grid[i][right])
				{
					blocked += 1;
					scenic_score[1] += 1;
					break;
				}
				scenic_score[1] += 1;
				right += 1;
			}

			int up = static_cast<int>(i) - 1;
			while (up >= 0)
			{
				if (current_tree <= trees_grid[up][j])
				{
					blocked += 1;
					scenic_score[2] += 1;
					break;
				}
				scenic_score[2] += 1;
				up -= 1;
			}

			size_t down = i + 1;
			while (down < trees_grid.size())
			{
				if (current_tree <= trees_grid[down][j])
				{
					blocked += 1;
					scenic_score[3] += 1;
					break;
				}
				scenic_score[3] += 1;
				down += 1;
			}

			if (blocked < 4)
			{
				total += 1;
			}

			const int total_scenic = scenic_score[0] * scenic_score[1] * scenic_score[2] * scenic_score[3];

			if (total_scenic > max_scenic)
			{
				max_scenic = total_scenic;
			}
			
		}
	}

	std::cout << "Part 1 " << total << " trees visible";
	std::cout << "Part 2 " << max_scenic<< " best scenic score";
}