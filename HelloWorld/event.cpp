#include "event.h"
#include <pcg_random.hpp>
#include <random>

int dice_roll(int min, int max,pcg64_fast& rng)
{
	return std::uniform_int_distribution{ min,max }(rng);
}


void main_event(int& hp, int& room, pcg64_fast& rng)
{
	int dice_result{};
	dice_result = dice_roll(1,6,rng);
	room += dice_result;
	if (room % 7 == 0)
	{
		if (room == 7)
			;
		else
		{
			room = dice_roll(1, room - 1, rng);
			std::cout << "wow,a magic portal.\n back to "<< room <<'\n';
		}
	}
	else if (room % 11 == 0)
	{
		hp += 1;
		std::cout << "good luck,a recovery potion.\n";
	}
	else if (room % 13 == 0)
	{
		std::cout << "opus, a trap.\n got -2hp\n";
		hp -= 2;
		if (hp <= 0)
			return;
	}
	else if (room == 25 || room == 50 || room == 75)
	{
		hp = 10;
		std::cout << "hp -> 10";
	}
	else
		std::cout << "just empty\n oh a baby spider\n";
}