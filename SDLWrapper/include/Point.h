#pragma once
namespace SDLlib
{
	struct Point
	{
		Point() = delete;
		Point(int x, int y) : x(x), y(y)
		{
		}

		int x;
		int y;
	};
}

