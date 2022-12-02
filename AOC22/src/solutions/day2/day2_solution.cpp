#include "day2_solution.hpp"
#include <string>
#include <sstream>

enum class my_moves
{
	Rock = 1,
	Paper = 2,
	Scissors = 3
};

enum class win_states
{
	Loss = 0,
	Draw = 3,
	Win = 6
};

void day2_solution::run()
{
	const std::string& input = get_input();

	std::stringstream part1(input);

	int total_score = 0;
	std::string move_pair;
	while (std::getline(part1, move_pair, '\n')) {

			// First character is my move
			const char their_move = move_pair[0];

			// Third is my move
			const char my_move = move_pair[2];

			// Rock
			if (their_move == 'A')
			{
				// rock
				if (my_move == 'X')
				{
					total_score += static_cast<int>(my_moves::Rock) + static_cast<int>(win_states::Draw);
				}
				// paper
				else if (my_move == 'Y')
				{
					total_score += static_cast<int>(my_moves::Paper) + static_cast<int>(win_states::Win);
				}
				else
				{
					total_score += static_cast<int>(my_moves::Scissors) + static_cast<int>(win_states::Loss);
				}
			}
			// Paper
			else if (their_move == 'B')
			{
				// rock
				if (my_move == 'X')
				{
					total_score += static_cast<int>(my_moves::Rock) + static_cast<int>(win_states::Loss);
				}
				// paper
				else if (my_move == 'Y')
				{
					total_score += static_cast<int>(my_moves::Paper) + static_cast<int>(win_states::Draw);
				}
				else
				{
					total_score += static_cast<int>(my_moves::Scissors) + static_cast<int>(win_states::Win);
				}
			}
			// Scissors
			else
			{
				// rock
				if (my_move == 'X')
				{
					total_score += static_cast<int>(my_moves::Rock) + static_cast<int>(win_states::Win);
				}
				// paper
				else if (my_move == 'Y')
				{
					total_score += static_cast<int>(my_moves::Paper) + static_cast<int>(win_states::Loss);
				}
				else
				{
					total_score += static_cast<int>(my_moves::Scissors) + static_cast<int>(win_states::Draw);
				}
			}

		}

	std::cout << "Total score (part1) is: " << total_score;

	std::stringstream part2(input);
	int total_score_part2 = 0;

	while (std::getline(part2, move_pair, '\n')) {

		// First character is my move
		const char their_move = move_pair[0];

		// Third is my move
		const char my_move = move_pair[2];

		// Rock
		if (their_move == 'A')
		{
			// Loss
			if (my_move == 'X')
			{
				total_score_part2 += static_cast<int>(my_moves::Scissors) + static_cast<int>(win_states::Loss);
			}
			// Draw
			else if (my_move == 'Y')
			{
				total_score_part2 += static_cast<int>(my_moves::Rock) + static_cast<int>(win_states::Draw);
			}
			// Win
			else
			{
				total_score_part2 += static_cast<int>(my_moves::Paper) + static_cast<int>(win_states::Win);
			}
		}
		// Paper
		else if (their_move == 'B')
		{
			// Loss
			if (my_move == 'X')
			{
				total_score_part2 += static_cast<int>(my_moves::Rock) + static_cast<int>(win_states::Loss);
			}
			// Draw
			else if (my_move == 'Y')
			{
				total_score_part2 += static_cast<int>(my_moves::Paper) + static_cast<int>(win_states::Draw);
			}
			// Win
			else
			{
				total_score_part2 += static_cast<int>(my_moves::Scissors) + static_cast<int>(win_states::Win);
			}
		}
		// Scissors
		else
		{
			// Loss
			if (my_move == 'X')
			{
				total_score_part2 += static_cast<int>(my_moves::Paper) + static_cast<int>(win_states::Loss);
			}
			// Draw
			else if (my_move == 'Y')
			{
				total_score_part2 += static_cast<int>(my_moves::Scissors) + static_cast<int>(win_states::Draw);
			}
			// Win
			else
			{
				total_score_part2 += static_cast<int>(my_moves::Rock) + static_cast<int>(win_states::Win);
			}
		}

	}

	std::cout << "Total score (part2) is: " << total_score_part2;

}
