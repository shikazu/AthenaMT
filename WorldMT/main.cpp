#include <iostream>
#include "World\WorldMain.h"

int main(int argc, char **argv)
{
	World::WorldMain world_main;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}