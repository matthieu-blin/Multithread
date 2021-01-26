// MultiThread.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main()
{
	std::thread t([]()
	{
		for (int i = 0; i < 1000; ++i)
			std::cout << i << std::endl;
	});
}

