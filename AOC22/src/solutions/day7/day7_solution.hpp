#pragma once
#include <ranges>
#include <unordered_map>

#include "../base/solution_base.hpp"

class day7_solution :public solution_base
{
public:
	day7_solution() : solution_base("day7"){}

	void run() override;
};

enum class filetype
{
	DIR = 0,
	FILE = 1
};

class file
{
public:
	file(filetype type, size_t size, const std::string& name): _file_type(type), _size(size), _file_name(name){}
	void set_parent(std::shared_ptr<file> parent)
	{
		_parent = parent;
	}
	void add_child(std::shared_ptr<file> child, std::shared_ptr<file> parent)
	{
		_children[child->get_name()] = child;
		_children[child->get_name()]->set_parent(parent);
	}
	unsigned long long get_size() const
	{
		size_t total = 0;
		for (const auto& val : _children | std::views::values)
		{
			total += val->get_size();
		}
		total += _size;
		return total;
	}

	const std::string& get_name() { return _file_name; }
	filetype get_type() const { return _file_type; }
	std::shared_ptr<file> get_parent() { return _parent; }
	std::shared_ptr<file> get_child(const std::string& name)
	{
		if (_children.find(name) != _children.end())
		{
			return _children.find(name)->second;
		}
		return nullptr;
	}
	const std::unordered_map<std::string, std::shared_ptr<file>>& get_children()
	{
		return _children;
	}

private:
	filetype _file_type;
	size_t _size;
	std::string _file_name;
	std::unordered_map<std::string, std::shared_ptr<file>> _children;
	std::shared_ptr<file> _parent = nullptr;
};