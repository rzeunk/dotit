//
// Copyright (c) 2026 Rzeunk
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <dotit/dotit.hpp>
#include <iostream>

int main()
try
{
	{
		dotit::world world;
		world.push(12);
		for (int i=3; i<20; ++i)
			world.push(i);
		world.snap();
		while (auto otr = world.pop())
		{
			std::cout << *otr << " ";
		}
		std::cout << std::endl;
		contract_assert(world.empty());
		std::cout << "OK\n";
	}
	{
		dotit::world world;
		world.push(2);
		world.push(3);
		contract_assert(world.size() == 2);
		contract_assert(! world.empty());
		std::cout << * world.top() << std::endl;
		std::cout << * world.pop() << std::endl;

		world.clear();

		contract_assert(world.size() == 0);
		contract_assert(world.empty());
		std::cout << "OK\n";
	}
}
catch (const std::exception & e)
{
	std::cerr << "=>\n" << e.what() << std::endl;
	return 1;
}
catch (...)
{
	std::cerr << "Unknown exception." << std::endl;
}

