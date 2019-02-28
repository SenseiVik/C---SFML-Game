#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;



namespace
{
	View CameraUpdate(float x, float y, View view)
	{
		if (x < 390)
			x = 390;
		if (x > 8375)
			x = 8375;
		if (y < 240)
			y = 240;
		if (y > 1100)
			y = 1100;

		view.setCenter(x, y);

		return view;
	}
}