#include "MainMenu.h"



MainMenu::MainMenu()
{
	isMenu = true;
	menuNum = 0;
	playerNum = 0;
}


MainMenu::~MainMenu()
{
}

void MainMenu::Menu(RenderWindow &window)
{
	//texture
	Texture menuBackground;
	Texture menuStart;
	Texture menuExit;
	Texture menuDevelopers;
	
	Texture menuPlayer1;
	Texture menuPlayer2;
	menuBackground.loadFromFile("images\\menuBackground.png");
	menuStart.loadFromFile("images\\start.png");
	menuExit.loadFromFile("images\\exit.png");
	menuDevelopers.loadFromFile("images\\developers.png");
	
	menuPlayer1.loadFromFile("images\\blackPlayer1.png");
	menuPlayer2.loadFromFile("images\\blackPlayer2.png");

	Sprite background(menuBackground);
	Sprite start(menuStart);
	Sprite exit(menuExit);
	Sprite developers(menuDevelopers);
	Sprite player1(menuPlayer1);
	Sprite player2(menuPlayer2);
	
	//music

	Music napas;
	napas.openFromFile("music\\napas.ogg");
	napas.setVolume(50);
	napas.setLoop(true);
	napas.setVolume(5);
	napas.play();

	

	//position
	start.setPosition(490, 585);
	exit.setPosition(50, 630);
	developers.setPosition(950, 630);
	player1.setPosition(205, 225);
	player2.setPosition(620, 223);
	

	while (isMenu)
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (napas.getStatus() == Music::Stopped)
			napas.play();

		start.setColor(Color::White);
		exit.setColor(Color::White);
		developers.setColor(Color::White);

		window.clear();

		window.draw(background);

		if (IntRect(210, 225, 440, 340).contains(Mouse::getPosition(window)))
		{
			playerNum = 1;
			window.draw(player1);
		}

		if (IntRect(613, 223, 440, 340).contains(Mouse::getPosition(window)))
		{
			playerNum = 2;
			window.draw(player2);
		}

		if (IntRect(490, 585, 300, 150).contains(Mouse::getPosition(window)))
		{
			start.setColor(Color::Red);
			menuNum = 1;
		}

		if (IntRect(50, 630, 300, 50).contains(Mouse::getPosition(window)))
		{
			exit.setColor(Color::Yellow);
			menuNum = 2;
		}

		if (IntRect(950, 630, 300, 50).contains(Mouse::getPosition(window)))
		{
			developers.setColor(Color::Green);
			menuNum = 3;
		}

		if (player == 0)
			window.draw(player1);

		if (player == 1)
			window.draw(player2);

		

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				napas.stop();
				StartGame(window, player);
			}

			if (menuNum == 2)
				isMenu = false;

			if (menuNum == 3)
				MenuDevelopers(window);

			if (menuNum == 4)
				system("start https://www.instagram.com/senseyvik/?hl=ru");

			if (menuNum == 5)
				system("start https://www.instagram.com/yametesempai/?hl=ru");

			if (playerNum == 1)
				player = 0;

			if (playerNum == 2)
				player = 1;
		}

		menuNum = 0;

		window.draw(start);
		window.draw(exit);
		window.draw(developers);

		window.display();
	}



}

void MainMenu::MenuDevelopers(RenderWindow & window)
{
	//background
	Texture backgound;
	backgound.loadFromFile("images\\devBack.jpg");
	Sprite background(backgound);

	//instagram
	Texture menuInstagram;
	menuInstagram.loadFromFile("images\\instagram.png");

	Sprite instagram1(menuInstagram);
	Sprite instagram2(menuInstagram);
	Sprite instagram3(menuInstagram);

	instagram1.setPosition(100, 520);
	instagram2.setPosition(283, 520);
	instagram3.setPosition(465, 520);

	while (!Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.clear();

		instagram1.setColor(Color::White);
		instagram2.setColor(Color::White);
		instagram3.setColor(Color::White);

		window.draw(background);

		if (IntRect(100, 520, 100, 100).contains(Mouse::getPosition(window)))
		{
			instagram1.setColor(Color::Yellow);
			menuNum = 4;
		}

		if (IntRect(283, 520, 100, 100).contains(Mouse::getPosition(window)))
		{
			instagram2.setColor(Color::Yellow);
			menuNum = 5;
		}

		if (IntRect(465, 520, 100, 100).contains(Mouse::getPosition(window)))
		{
			instagram3.setColor(Color::Yellow);
			menuNum = 6;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 4)
				system("start https://www.instagram.com/senseyvik/?hl=ru");

			if (menuNum == 5)
				system("start https://www.instagram.com/yametesempai/?hl=ru");

			if (menuNum == 6)
				system("start https://www.instagram.com/di_keplin/?hl=uk");
		}

		menuNum = 0;

		window.draw(instagram1);
		window.draw(instagram2);
		window.draw(instagram3);
		window.display();
	}
}

void	MainMenu::StartGame(RenderWindow &window,bool choosenPlayer)
{
	//--------------------------------PREPARATION------------------------------------\\

	//
	int reload = 0;
	//

	View view(FloatRect(0, 0, 720, 480));

	list<GameObject*> objects;
	list<GameObject*> coins;
	GameObject	*bufferGameObj = nullptr;

	//music

	Music meme;
	meme.openFromFile("music\\meme.ogg");
	meme.setLoop(true);
	meme.stop();

	Music backMusic;
	backMusic.openFromFile("music\\backmusic.ogg");
	backMusic.setLoop(true);
	backMusic.setVolume(15);
	backMusic.play();

	Music endMusic;
	endMusic.openFromFile("music\\vika.ogg");
	endMusic.setLoop(true);

	SoundBuffer buffDamage;
	buffDamage.loadFromFile("music\\uron.ogg");
	Sound soundDamage;
	soundDamage.setBuffer(buffDamage);
	soundDamage.setVolume(40);

	SoundBuffer buffDropCoin;
	buffDropCoin.loadFromFile("music\\dropcoin.ogg");
	Sound soundDropCoin;
	soundDropCoin.setBuffer(buffDropCoin);
	soundDropCoin.setVolume(40);

	SoundBuffer buffTakeCoin;
	buffTakeCoin.loadFromFile("music\\takecoin.ogg");
	Sound soundTakeCoin;
	soundTakeCoin.setBuffer(buffTakeCoin);
	soundTakeCoin.setVolume(40);

	SoundBuffer buffRun;
	buffRun.loadFromFile("music\\run.ogg");
	Sound soundRun;
	soundRun.setBuffer(buffRun);
	soundRun.setVolume(25);

	SoundBuffer buffShoot;
	buffShoot.loadFromFile("music\\shoot.ogg");
	Sound soundShoot;
	soundShoot.setBuffer(buffShoot);
	soundShoot.setVolume(20);

	//player
	Texture playerTexture;
	
	if (choosenPlayer == 1)
		playerTexture.loadFromFile("images\\character2.png");
	else
		playerTexture.loadFromFile("images\\character.png");

	GameObject * player = nullptr;

	//shop
	Texture shopTexture;
	shopTexture.loadFromFile("images\\shop.png");
	Sprite shop;
	shop.setTexture(shopTexture);
	shop.setTextureRect(IntRect(10, 10, 81, 110));
	bool shopOpen = false;
	float shopXS = 0;
	float shopYS = 0;

	//buyList
	Texture buyListTexture;
	buyListTexture.loadFromFile("images\\pergament.png");
	Sprite buy;
	buy.setTexture(buyListTexture);
	buy.setTextureRect(IntRect(4, 4, 182, 257));

	//background
	Texture back;
	back.loadFromFile("images\\back.png");
	Sprite backGround;
	backGround.setTexture(back);

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("images\\background.jpg");

	Sprite background;
	background.setTexture(backgroundTexture);

	Texture endTexture;
	endTexture.loadFromFile("images\\end.png");
	Sprite end;
	end.setTexture(endTexture);

	// ----------------------------------------------- MAP ----------------------------------

	Texture mapTexture;
	mapTexture.loadFromFile("images\\master.png");
	
	Texture lavaTexture;
	lavaTexture.loadFromFile("images\\lava.png");

	Sprite lava;
	lava.setTexture(lavaTexture);
	lava.setTextureRect(IntRect(1104, 416, 32, 32));

	Sprite water;
	water.setTexture(lavaTexture);
	water.setTextureRect(IntRect(833, 416, 32, 32));

	Sprite sand;
	sand.setTexture(mapTexture);
	sand.setTextureRect(IntRect(2, 65, 32, 32));

	Sprite grass;
	grass.setTexture(mapTexture);
	grass.setTextureRect(IntRect(2, 129, 32, 32));

	Sprite trapGrass;
	trapGrass.setTexture(mapTexture);
	trapGrass.setTextureRect(IntRect(195, 131, 32, 32));

	Sprite ground;
	ground.setTexture(mapTexture);
	ground.setTextureRect(IntRect(2, 193, 32, 32));

	Sprite trapGround;
	trapGround.setTexture(mapTexture);
	trapGround.setTextureRect(IntRect(195, 195, 32, 32));


	//------------------------------------------------- COIN ----------------

	Texture coinTexture;
	coinTexture.loadFromFile("images\\coin.png");


	//stone
	Texture stoneTexture;
	stoneTexture.loadFromFile("images\\stone.png");

	
	//enemy
	Texture enemyTexture;
	enemyTexture.loadFromFile("images\\amazing.png");
	list<GameObject*> ENEMY;
	GameObject * bufferEnemy = nullptr;

	//boss;
	Texture bossTexture;
	bossTexture.loadFromFile("images\\boss.png");
	GameObject * BOSS = nullptr;

	Texture bubbleTexture;
	bubbleTexture.loadFromFile("images\\bubble.png");
	Sprite bubble;
	bubble.setTexture(bubbleTexture);
	bubble.setTextureRect(IntRect(0, 0, 140, 110));

	//boss attack
	Texture bossAttackTexture;
	bossAttackTexture.loadFromFile("images\\boss_shoots.png");
	list<GameObject*> bossAttack;
	GameObject * buffBossAttack = nullptr;

	for (int i = 0; i<heightMap; i++)
		for (int j = 0; j < widhtMap; j++)
		{
			if (lvl_One[i][j] == 'C')
				coins.push_back(new Coin(j * 32, i * 32, coinTexture));
			if (lvl_One[i][j] == 'P')
			{
				player = new Player(j * 32, i * 32, playerTexture);
			}
			if (lvl_One[i][j] == 'E')
				ENEMY.push_back(new Enemy(j * 32, i * 32, enemyTexture));
			if (lvl_One[i][j] == 'B')
			{
				BOSS = new Boss(j * 32, i * 32, bossTexture);
			}
			if (lvl_One[i][j] == 'H')
			{
				shop.setPosition(j * 32, i * 32 + 112);
				shopXS = j * 32;
				shopYS = i * 32;
			}
			if (lvl_One[i][j] == 'V')
			{
				objects.push_back(new Stone(j * 32, i * 32,stoneTexture,1));
			}
			
		}

	//shoot
	Texture shootTexture;
	shootTexture.loadFromFile("images\\shoot.png");

	list<GameObject*> attack;
	GameObject * bufferAttack = nullptr;

	//text
	String strCoins = "Coins: ";
	String strHealth = "Health: ";
	String strBoss = "    Java\ndeveloper\n    ";
	String strShop = "press :: F";
	String strPlate = "press :: F";

	char *buff = new char[20];

	Font font;
	font.loadFromFile("font\\12081.ttf");

	Text textCoins(strCoins, font, 20);
	Text textHealth(strHealth, font, 20);
	Text textBoss(strBoss, font, 15);
	Text textShop(strShop, font, 10);
	Text textPlate(strPlate, font, 10);

	textCoins.setFillColor(sf::Color::Green);
	textHealth.setFillColor(sf::Color::Red);
	textBoss.setFillColor(sf::Color::Black);
	textShop.setFillColor(sf::Color::Black);
	textPlate.setFillColor(sf::Color::Black);

	//---------------------

	int buffCount = 0;

	Clock clock;

	//--------------------------------RUN WINDOW------------------------------------\\

	while (window.isOpen())
	{
		view = CameraUpdate(player->GetSpawnX(), player->GetSpawnY(), view);
		background.setPosition(view.getCenter().x, view.getCenter().y);

		float time = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		time /= 800;

		reload += (time / 10);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if ((event.key.code == Keyboard::F) && (std::abs(shopXS - player->GetSpawnX()) <= 140) && (shopOpen == false))
				shopOpen = true;
			else if ((event.key.code == Keyboard::Escape) && (shopOpen == true))
				shopOpen = false;

			if ((event.key.code == Keyboard::Q) && ((Player*)player)->GetCountSalve() != 0)
			{
				player->SetHealth(player->GetHealth() + 300);
				((Player*)player)->SubmSalve();
			}
			if ((event.key.code == Keyboard::W) && ((Player*)player)->GetXRayState() == true)
			{
				if (((Player*)player)->GetFly() == false)
					((Player*)player)->SetFly(true);
				else
					((Player*)player)->SetFly(false);
			}

			if (player->GetIsAttack() && reload >= 25)
			{
				reload = 0;
				player->SetAttack(false);
				if (((Player*)player)->GetStatus() == 2)
					attack.push_back(new Shoot(player->GetSpawnX() + 70, player->GetSpawnY(), shootTexture, ((Player*)player)->GetStatus()));
				if (((Player*)player)->GetStatus() == 1)
					attack.push_back(new Shoot(player->GetSpawnX() - 70, player->GetSpawnY(), shootTexture, ((Player*)player)->GetStatus()));
			}

			if (BOSS->GetIsAttack() && bossAttack.size() < 3)
			{
				if(((Boss*)BOSS)->GetBubbleState() == false)
					bossAttack.push_back(new BossShoots(BOSS->GetSpawnX() - 80, BOSS->GetSpawnY(), bossAttackTexture, 1));
				
			}
			
		}

		if (bufferEnemy != nullptr)
		{
			ENEMY.remove(bufferEnemy);
			delete bufferEnemy;
			bufferEnemy = nullptr;
		}

		if (bufferAttack != nullptr)
		{
			attack.remove(bufferAttack);
			delete bufferAttack;
			bufferAttack = nullptr;
		}

		if (buffBossAttack != nullptr)
		{
			bossAttack.remove(buffBossAttack);
			delete buffBossAttack;
			buffBossAttack = nullptr;
		}

		//-----------------------------------------------------

		window.clear(Color::White);
		window.draw(backGround);
		
		//--------------------------------DRAW MAP------------------------------------\\

		for (int i = 0; i<heightMap; i++)
			for (int j = 0; j < widhtMap; j++)
			{
				if (lvl_One[i][j] == 'g')
				{
					ground.setPosition(j * 32, i * 32);
					window.draw(ground);
				}

				if (lvl_One[i][j] == 'G')
				{
					grass.setPosition(j * 32, i * 32);
					window.draw(grass);
				}

				if (lvl_One[i][j] == 'W')
				{
					water.setPosition(j * 32, i * 32);
					window.draw(water);
				}

				if (lvl_One[i][j] == 'L')
				{
					lava.setPosition(j * 32, i * 32);
					window.draw(lava);
				}

				if (lvl_One[i][j] == 'S')
				{
					sand.setPosition(j * 32, i * 32);
					window.draw(sand);
				}

				if (lvl_One[i][j] == 't')
				{
					trapGrass.setPosition(j * 32, i * 32);
					window.draw(trapGrass);
				}

				if (lvl_One[i][j] == 'T')
				{
					trapGround.setPosition(j * 32, i * 32);
					window.draw(trapGround);
				}
			}

		//--------------------------------DRAW & CHECK COINS------------------------------------\\

		for (list<GameObject*>::iterator it = coins.begin(); it != coins.end(); it++)
		{
			(*it)->Update(time);

			if ((*it)->GetIsAlive() == true)
				window.draw((*it)->GetSprite());
			else
			{
				bufferGameObj = *it;
				soundTakeCoin.play();
			}

		}

		if (bufferGameObj != nullptr)
		{
			coins.remove(bufferGameObj);
			delete bufferGameObj;
			bufferGameObj = nullptr;
		}


		for(auto it = coins.begin();it!=coins.end();it++)
			if ((*it)->GetRect().intersects(player->GetRect()))
			{
				((Player*)player)->AddCoin();
				(*it)->SetIsAlive(false);
			}

		//--------------------------------DRAW ATTACK------------------------------------\\

		for (list<GameObject*>::iterator it = attack.begin(); it != attack.end(); it++)
		{
			(*it)->Update(time);
			window.draw((*it)->GetSprite());
			if ((*it)->GetIsAlive() == false)
				bufferAttack = *it;
		}

		if (bufferAttack != nullptr)
		{
			attack.remove(bufferAttack);
			delete bufferAttack;
			bufferAttack = nullptr;
		}

		//--------------------------------DRAW BOSS ATTACK-----------------------------------//

		if (BOSS->GetIsAlive())
		{

			for (auto it = bossAttack.begin(); it != bossAttack.end(); it++)
			{
				(*it)->Update(time);
				window.draw((*it)->GetSprite());
				if ((*it)->GetIsAlive() == false)
					buffBossAttack = *it;
			}

			if (buffBossAttack != nullptr)
			{
				bossAttack.remove(buffBossAttack);
				delete buffBossAttack;
				buffBossAttack = nullptr;
			}

		}


		//-------------------------------DRAW SHOP-----------------------------//

		window.draw(shop);

		//shop text
		textShop.setPosition(shopXS - 50, shopYS + 120);
		window.draw(textShop);

		if (shopOpen)
		{
			buy.setPosition(player->GetSpawnX() - 300, player->GetSpawnY() - 140);
			window.draw(buy);

			if ((event.key.code == Keyboard::Z) && ((Player*)player)->GetCountCoins() >= 10)
			{
				player->SetHealth(3000);
				((Player*)player)->SetCountCoins(((Player*)player)->GetCountCoins() - 10);
			}
			if ((event.key.code == Keyboard::X) && ((Player*)player)->GetCountCoins() >= 20)
			{
				((Player*)player)->SetXRayState(true);
				((Player*)player)->SetCountCoins(((Player*)player)->GetCountCoins() - 20);
			}
			if ((event.key.code == Keyboard::C) && ((Player*)player)->GetCountCoins() >= 4)
			{
				if (((Player*)player)->GetCountSalve() < 5)
				{
					((Player*)player)->AddSalve();
					((Player*)player)->SetCountCoins(((Player*)player)->GetCountCoins() - 4);
				}
			}
		}

		//--------------------------------DRAW STONE------------------------------------\\


		for (list<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			if ((player->GetSpawnX() <= (*it)->GetSpawnX() - 300) && (player->GetSpawnY() - 150 <= (*it)->GetSpawnY()))
				(*it)->SetIsAlive(true);

			if ((*it)->GetIsAlive())
				(*it)->Update(time);

			if ((*it)->GetRect().intersects(player->GetRect()))
				player->TakeDamage((*it)->GetDamage());
		}

		for (list<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			if ((*it)->GetIsAlive())
				window.draw((*it)->GetSprite());
		}

		//--------------------------------DRAW PLAYER------------------------------------\\


		player->Update(time);
		if (player->GetIsAlive())
			window.draw(player->GetSprite());

		for(auto it = bossAttack.begin();it!=bossAttack.end();it++)
			if (player->GetRect().intersects((*it)->GetRect()))
			{
				player->TakeDamage((*it)->GetDamage());
				buffBossAttack = *it;
			}

		for (auto j = attack.begin(); j != attack.end(); j++)
			for(auto i = bossAttack.begin();i!=bossAttack.end();i++)
				if ((*i)->GetRect().intersects((*j)->GetRect()))
				{
					bufferAttack = *j;
					buffBossAttack = *i;
				}

		if (player->GetRect().intersects(BOSS->GetRect()))
			if(BOSS->GetIsAlive()==true)
				player->TakeDamage(BOSS->GetDamage());

		if (((Player*)player)->GetAnimType() == "run")
		{
			if (soundRun.getStatus() != Sound::Playing)
				soundRun.play();
		}
		else
			soundRun.stop();

		if (((Player*)player)->GetAnimType() == "shoot")
		{
			//if (soundShoot.getStatus() != Sound::Playing)
				soundShoot.play();
		}

		//---------------------------------DRAW ENEMY ---------------------------------------

		for (list<GameObject*>::iterator i = ENEMY.begin(); i != ENEMY.end(); i++)
			for (list<GameObject*>::iterator j = attack.begin(); j != attack.end(); j++)
			{
				if (std::abs((*i)->GetSpawnX() - (*j)->GetSpawnX()) <= 140)
					((Enemy*)*i)->GiveJump();

				if ((*i)->GetRect().intersects((*j)->GetRect()))
				{
					(*i)->TakeDamage((*j)->GetDamage());
					bufferAttack = (*j);
					if ((*j)->GetIsAlive() == false)
						bufferEnemy = (*j);

					soundDamage.play();
				}

			}

		for (list<GameObject*>::iterator it = ENEMY.begin(); it != ENEMY.end(); it++)
		{
			if ((*it)->GetIsAlive())
			{
				(*it)->Update(time);

				if ((player->GetSpawnX() > (*it)->GetSpawnX()) && (*it)->GetRect().intersects(FloatRect(player->GetSpawnX(), player->GetSpawnY(), player->GetWidhtRect() - 300, player->GetHeightRect())))
					((Enemy*)*it)->SetDirection(2);
				if ((player->GetSpawnX() < (*it)->GetSpawnX()) && (*it)->GetRect().intersects(FloatRect(player->GetSpawnX(), player->GetSpawnY(), player->GetWidhtRect() + 300, player->GetHeightRect())))
					((Enemy*)*it)->SetDirection(1);
				if ((*it)->GetRect().intersects(player->GetRect()))
				{
					/*if (((Player*)player)->GetOnGroundState())
					{
						(*it)->SetIsAlive(false);
						bufferEnemy = *it;
					}*/

					player->TakeDamage((*it)->GetDamage());
				}
			}
			else
			{
				bufferGameObj = *it;
				soundDropCoin.play();
			}
		}

		if (bufferGameObj != nullptr)
		{
			

			coins.push_back(new Coin(bufferGameObj->GetSpawnX(), bufferGameObj->GetSpawnY(), coinTexture));
			ENEMY.remove(bufferGameObj);
			delete bufferGameObj;
			bufferGameObj = nullptr;
		}


		for (list<GameObject*>::iterator it = ENEMY.begin(); it != ENEMY.end(); it++)
			if ((*it)->GetIsAlive())
				window.draw((*it)->GetSprite());

		//--------------------------------DRAW BOSS------------------------------------//

		if (BOSS->GetIsAlive())
		{
			BOSS->Update(time);

			for (auto it = attack.begin(); it != attack.end(); it++)
				if ((*it)->GetRect().intersects(BOSS->GetRect()))
				{
					BOSS->TakeDamage((*it)->GetDamage());
					((Boss*)BOSS)->AddCountDamage();
					bufferAttack = *it;
				}

			

			if (((Boss*)BOSS)->GetBubbleState())
			{
				bubble.setPosition(BOSS->GetSpawnX() - 20, BOSS->GetSpawnY() + 10);
				window.draw(bubble);
				if (buffCount <= 3)
				{
					ENEMY.push_back(new Enemy(8400 - (buffCount * 100), 260, enemyTexture));
					buffCount++;
				}
			}
			if (!((Boss*)BOSS)->GetBubbleState())
				buffCount = 0;

			window.draw(BOSS->GetSprite());

		}
		

		//--------------------------------DRAW TEXT------------------------------------\\
		

		//coins
		strCoins += _itoa(((Player*)player)->GetCountCoins(), buff, 10);
		textCoins.setString(strCoins);
		textCoins.setPosition(view.getCenter().x - 50, view.getCenter().y - 200);
		window.draw(textCoins);
		strCoins = "Coins: ";

		//boss
		if (BOSS->GetIsAlive())
		{
			strBoss += _itoa(((Boss*)BOSS)->GetHealth(), buff, 10);
			textBoss.setString(strBoss);
			textBoss.setPosition(BOSS->GetSpawnX(), BOSS->GetSpawnY() - 38);
			window.draw(textBoss);
			strBoss = "    Java\ndeveloper\n    ";
		}


		//health
		if (player->GetIsAlive())
			strHealth += _itoa(((Player*)player)->GetHealth(), buff, 10);
		textHealth.setString(strHealth);
		textHealth.setPosition(view.getCenter().x - 250, view.getCenter().y - 200);
		window.draw(textHealth);
		strHealth = "Health: ";

		if (!player->GetIsAlive())
		{
			background.setPosition(view.getCenter().x - 370, view.getCenter().y - 320);
			window.draw(background);
			
			backMusic.stop();

			if (meme.getStatus() == Music::Stopped)
				meme.play();


			if (Keyboard::isKeyPressed(Keyboard::Enter))
				break;
		}

		std::cout << BOSS->GetSpawnX() << std::endl;
		std::cout << BOSS->GetSpawnY() << std::endl;
		window.setView(view);

		if (!BOSS->GetIsAlive())
		{
			view.setSize(1280, 720);
			view.setCenter(640, 360);
			window.setView(view);

			end.setPosition(view.getCenter().x - 640, view.getCenter().y - 360);

			backMusic.stop();

			if (endMusic.getStatus() != Music::Playing)
				endMusic.play();

			window.draw(end);

			if (Keyboard::isKeyPressed(Keyboard::Enter))
				break;
		}

		window.display();
	}

	view.setSize(1280, 720);
	view.setCenter(640, 360);
	window.setView(view);
	window.display();
	delete[] buff;
	
	for (auto it = objects.begin(); it != objects.end(); it++)
		delete (*it);
	for (auto it = coins.begin(); it != coins.end(); it++)
		delete (*it);
	for (auto it = ENEMY.begin(); it != ENEMY.end(); it++)
		delete (*it);
	for (auto it = bossAttack.begin(); it != bossAttack.end(); it++)
		delete (*it);
	for (auto it = attack.begin(); it != attack.end(); it++)
		delete(*it);
}

bool MainMenu::GetIsMenu()
{
	return isMenu;
}
