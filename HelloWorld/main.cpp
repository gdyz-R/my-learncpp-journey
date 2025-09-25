#include <iostream>
#include <random>
#include <pcg_random.hpp>
#include <format>
#include "event.h"
#include <cstdlib>
int main()
{
	pcg64_fast pcg{ pcg_extras::seed_seq_from<std::random_device>() };
	int currentRoom{ 1 };
	int playerHP{ 10 };
	int turnCount{ 0 };
	char main_user_input{};

	std::cout << "do you understand the game rule?\n n for exit\n";
	char user_input{ '0' };
	std::cin >> user_input;
	if (user_input == 'n')
		std::exit(0);

	while (true)
	{
		std::cout << "would you continue?\n y for yes,n for exit\n";
		std::cin >> main_user_input;
		if (main_user_input == 'n')
			std::exit(0);
		if (main_user_input == 'y')
		{
			++turnCount;
			std::cout << std::format("Turn {}: You are at room {}, HP is {}.\n", turnCount, currentRoom, playerHP);
			main_event(playerHP, currentRoom, pcg);
			if (playerHP <= 0)
			{
				std::cout << "you lose";
				break;
			}
			if (currentRoom >= 100)
			{
				std::cout << "you win";
				break;
			}
		}
	}
}