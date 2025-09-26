#ifndef EVENT_H
#define	EVENT_H
#include<pcg_random.hpp>
#include<utility>
std::pair<int, int> main_event(int hp, int room, pcg64_fast& rng);
void ignore_line();
#endif  EVENT_H