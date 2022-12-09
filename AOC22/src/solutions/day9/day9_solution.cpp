#include "day9_solution.hpp"
#include <unordered_map>
#include <array>

struct pos
{
	int x = 0;
	int y = 0;

	[[nodiscard]] std::string get_key() const
	{
		return std::to_string(x) + ':' + std::to_string(y);
	}
};

const int KNOTS_COUNT = 10;

void day9_solution::run()
{
	const auto& input = get_input();

	std::stringstream part1(input);
	std::string movement;

	std::unordered_map<std::string, bool> visited;

	// Head is 0
	auto knots = std::array<pos, KNOTS_COUNT>();
	auto& headPos = knots[0];
	
	// Visisted start
	visited.insert({ "0:0",true });


	while (std::getline(part1, movement, '\n'))
	{
		const char direction = movement[0];
		const int amount = std::stoi(movement.substr(2));

		for (int step = 0; step < amount; ++step)
		{
			// Move head in direction
			if (direction == 'R')
			{
				headPos.x += 1;
			}
			else if (direction == 'L')
			{
				headPos.x -= 1;
			}
			else if (direction == 'U')
			{
				headPos.y += 1;
			}
			else if (direction == 'D')
			{
				headPos.y -= 1;
			}

			// Calculate pythag for knots
			for (int knot = 1; knot < KNOTS_COUNT; knot++)
			{
				int dx = knots[knot - 1].x - knots[knot].x;
				int dy = knots[knot - 1].y - knots[knot].y;

				if (std::sqrt(dx*dx + dy*dy) > 1.5)
				{
					if (dx > 0)
					{
						knots[knot].x += 1;
					}
					else if (dx < 0)
					{
						knots[knot].x -= 1;
					}
					if (dy > 0)
					{
						knots[knot].y += 1;
					}
					else if (dy < 0)
					{
						knots[knot].y -= 1;
					}

					if (knot == KNOTS_COUNT - 1)
					{
						visited.insert({ knots[knot].get_key(),true });
					}
				}
			}


		}
	}

	std::cout << "Visited points:  " << visited.size();
}
