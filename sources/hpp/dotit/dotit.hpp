//
// Copyright (c) 2026 Rzeunk
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <optional>

namespace dotit
{
	class world
	{
	public:
		void push(int x);
		std::optional<int> pop();
		std::optional<int> top() const;
		void snap() const;
		void clear();
		int size() const;
		bool empty() const;
	};
}	// namespace dotit

