#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <iostream>

class solution_base
{
public:
	solution_base(const std::string& day)
	{
		read_input(day);
	}

	virtual void run() = 0;

	const std::string& get_input()
	{
		return _raw_input;
	}

	virtual ~solution_base() = default;

private:

	void read_input(const std::string& day)
	{
		// Assume input is in same folder in an input folder and is named input.txt
		std::fstream input_file;
		input_file.open("./input/" + day + ".txt");
		if (input_file.is_open())
		{
			std::stringstream buffer;
			buffer << input_file.rdbuf();

			_raw_input = buffer.str();
		}
		else
		{
			std::cout << "Cannot open file!\n";
		}
	}

	std::string _raw_input;

};

