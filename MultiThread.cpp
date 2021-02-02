// MultiThread.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <cassert>

using namespace std::chrono_literals;

struct V2
{
	float x;
	float y;
	std::mutex m;
	void Set(float _x, float _y) {
		m.lock();
		x = _x;
		y = _y; 
	}
	void Get(float& _x, float&  _y) {
		_x = x;
		_y = y; 
	}
};
int main()
{
	V2 v;

	std::thread t([&v]()
	{
		for (int i = 0; i < 10'000'000; ++i)
		{
			auto f = i / 1000.f;
			v.Set(f, f);
		}
	});
	std::thread t2([&v]()
	{
		float x, y;
		for (int i = 0; i < 1000; ++i)
		{
			v.Get(x, y);
			if (x != y)
				assert(false);
			printf("x:%f, y:%f\n", x, y);
		}
	});
	t.join();
	t2.join();
}

