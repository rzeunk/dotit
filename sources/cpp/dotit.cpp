//
// Copyright (c) 2026 Rzeunk
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <dotit/dotit.hpp>
#include <stack>
#include <iostream>
#include <optional>
#include <exception>
#include <stdexcept>
#include <limits>

using stack_type = std::stack<int>;
using bad_size_type = stack_type::size_type;
using real_size_type = int;

namespace src_private_space
{
	static stack_type stack{};
}

void dotit::world::push(int x)
{
	if (
		src_private_space::stack.size()
		>=
		static_cast<bad_size_type>(
			std::numeric_limits<
				int
			>::max()
		)
	)
	{
		throw std::runtime_error{
			"stack overflow: dotit::world::push"
		};
	}
	src_private_space::stack.push(x);
}

std::optional<int> dotit::world::pop()
{
	if (src_private_space::stack.empty())
		return std::nullopt;
	int x = src_private_space::stack.top();
	src_private_space::stack.pop();
	return x;
}

std::optional<int> dotit::world::top() const
{
	if (src_private_space::stack.empty())
		return std::nullopt;
	return src_private_space::stack.top();
}

void dotit::world::snap() const
{
	stack_type copy = src_private_space::stack;
	while (! copy.empty())
	{
		std::cout << copy.top() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}

void dotit::world::clear()
{
	while (! src_private_space::stack.empty())
		src_private_space::stack.pop();
}

int dotit::world::size() const
{
	return static_cast<int>(src_private_space::stack.size());
}

bool dotit::world::empty() const
{
	return src_private_space::stack.empty();
}

