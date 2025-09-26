#include "event.h"
#include <pcg_random.hpp>
#include <random>
#include <utility>
#include <iostream>
#include <tuple>
#include <limits>

void ignore_line()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int dice_roll(int min, int max,pcg64_fast& rng)
{
	return std::uniform_int_distribution{ min,max }(rng);
}

void room_change(int& room, pcg64_fast& rng)
{
	room += dice_roll(1, 6, rng);
	std::cout << "You moved to room " << room << ".\n";
}

std::pair<int,int> room_event(int room,pcg64_fast& rng)
{
	int hp{ 0 };
	bool is_event{ false };
	if (room % 7 == 0)
	{
		is_event = true;
		if (room > 7)
		{
			room = dice_roll(1, room - 1, rng);
			std::cout << "wow,a magic portal.\n back to " << room << '\n';
		}
	}
	if (room % 11 == 0)
	{
		is_event = true;
		hp += 1;
		std::cout << "good luck,a recovery potion.\n";
	}
	if (room % 13 == 0)
	{
		is_event = true;
		std::cout << "opus, a trap.\n got -2hp\n";
		hp -= 2;
	}
	if(!is_event)
		std::cout << "nothing happened.\n";
	return { hp,room };
}

std::pair<int,int> main_event(int hp, int room, pcg64_fast& rng)
{
	int hp_change{ 0 };
	room_change(room, rng);
	std::tie(hp_change,room) = room_event(room, rng);
	switch (room)
	{
	case 25:
	case 50:
	case 75:
		hp = 10;
		std::cout << "great,full hp\n";
		break;
	default:
		hp += hp_change;
		break;
	}
	return { hp ,room };
}