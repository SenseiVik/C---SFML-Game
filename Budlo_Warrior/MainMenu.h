#pragma once
#include "Header.h"

class MainMenu
{
	bool	isMenu;
	bool	player;
	int		menuNum;
	int		playerNum;
public:
	MainMenu();
	~MainMenu();

	void	Menu(RenderWindow &window);
	void	MenuDevelopers(RenderWindow &window);
	void	StartGame(RenderWindow &window, bool choosenPlayer);

	bool	GetIsMenu();
};

