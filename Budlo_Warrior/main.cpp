#include "Header.h"



void main()
{
	RenderWindow window(VideoMode(1280, 720), "Budlo_Warrior");
	window.setVerticalSyncEnabled(true);
	MainMenu menu;

	window.setVerticalSyncEnabled(true);
 
	while (true)
	{
		menu.Menu(window);

		if (!menu.GetIsMenu())
			break;
	}

}