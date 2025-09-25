#pragma once
#include <pcg_random.hpp>
#include <random>
namespace Random {
	inline pcg64_fast pcg{ pcg_extras::seed_seq_from<std::random_device>() };

	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{ min,max }(pcg);
	}
}
