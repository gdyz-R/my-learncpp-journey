#include <iostream>
#include <random>
#include <pcg_random.hpp>
#include <format>
#include "event.h"
#include <cstdlib>
#include <tuple>
#include <utility>

void is_understand();
bool is_finish(int,int);
void ask_continue();


int main()
{
	bool is_loop{ true };
	pcg64_fast pcg{ pcg_extras::seed_seq_from<std::random_device>() };
	int currentRoom{ 1 };
	int playerHP{ 10 };
	int turnCount{ 0 };

	is_understand();// explain the game rule

	while (is_loop)
	{		
		ask_continue();
		++turnCount;
		std::cout << std::format("Turn {}: You are at room {}, HP is {}.\n", 
			turnCount, currentRoom, playerHP);
		std::tie(playerHP,currentRoom) = main_event(playerHP, currentRoom, pcg);
		is_loop = is_finish(playerHP, currentRoom);
	}
	return 0;
}

void is_understand()
{
	std::cout << "Game Rule:\n";
	std::cout << "1. You start at room 1, with 10 HP.\n";
	std::cout << "2. Each turn, you can choose to continue or exit the game.\n";
	std::cout << "3. If you continue, you will roll a dice to move forward 1-6 rooms.\n";
	std::cout << "4. Special events:\n";
	std::cout << "   - If you land on a room number that is a multiple of 7 (except room 7),\n";
	std::cout << "     you will be teleported back to a random previous room.\n";
	std::cout << "   - If you land on a room number that is a multiple of 11,\n";
	std::cout << "     you will find a recovery potion and gain 1 HP.\n";
	std::cout << "   - If you land on a room number that is a multiple of 13,\n";
	std::cout << "     you will trigger a trap and lose 2 HP.\n";
	std::cout << "   - If you land on rooms 25, 50, or 75, your HP will be restored to 10.\n";
	std::cout << "5. The game ends if your HP drops to 0 or below (you lose),\n";
	std::cout << "   or if you reach or exceed room 100 (you win).\n";
	std::cout << "Good luck!\n";
	bool is_valid_input{ false };
	while (!is_valid_input)
	{
	std::cout << "do you understand the game rule? (y/n)\n";
	char user_input{ '0' };
	std::cin >> user_input;
	ignore_line();
	if (user_input == 'y')
		is_valid_input = true;
	if (user_input == 'n')
		std::exit(0);
	}
}

bool is_finish(int playerHP,int currentRoom)
{
	if (playerHP <= 0)
	{
		std::cout << "you lose";
		return false;
	}
	if (currentRoom >= 100)
	{
		std::cout << "you win";
		return false;
	}
	return true;
}

void ask_continue()
{
	char user_input{ '0' };
	bool is_valid_input{ false };
	while (!is_valid_input)
	{
		std::cout << "would you continue? (y/n)\n";
		std::cin >> user_input;
		ignore_line();
		if (user_input == 'y')
			is_valid_input = true;
		if (user_input == 'n')
			std::exit(0);
	}
}
