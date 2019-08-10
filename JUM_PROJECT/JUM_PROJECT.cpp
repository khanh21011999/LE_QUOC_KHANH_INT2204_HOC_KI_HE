
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <iostream>
#define SPEED 50;

using namespace sf;
struct CrossBarStruct
{
	int x, y;
};
int main()
{
	srand(time(NULL));
	//Vector2f v;
	//sf::Clock clock;
	RenderWindow windows(VideoMode(407, 650), "Jump Game");
	windows.setSize(Vector2u(407, 650));
	windows.setVerticalSyncEnabled(true);
	Event event;
	CrossBarStruct crossBarList[10];
	for (int i = 0; i < 10; i++)
	{
		crossBarList[i].x = rand() % 363;
		crossBarList[i].y = rand() % 626;
	}
	windows.setFramerateLimit(60); //cho framerate la 60
	Texture BackGroundTexture;
	Texture playerRightTexture;
	Texture playerLeftTexture;
	Texture playerUpTexture;
	Texture crossBarTexture;
	crossBarTexture.loadFromFile("resource/image/crossbar.png");
	playerLeftTexture.loadFromFile("resource/image/left.png");
	playerRightTexture.loadFromFile("resource/image/right.png");
	BackGroundTexture.loadFromFile("resource/image/background.png");
	Sprite playerSprite(playerLeftTexture);
	Sprite background(BackGroundTexture);
	Sprite crossBar(crossBarTexture);
	//playerSprite.move(Vector2f(30,0));
	//player  124x120
	//background 407x650
	// crossBar 68x14
	int x = 100, y = 300, h = 350;
	float dx = 0, dy = 0;
	while (windows.isOpen())
	{
		while (windows.pollEvent(event))
		{
			//float dt = clock.restart().asSeconds();
			if (event.type == sf::Event::Closed) windows.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			playerSprite.setTexture(playerRightTexture);
			x += 3;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			playerSprite.setTexture(playerLeftTexture);
			x -= 3;
		}
		//set gia toc tang la 0.2
		dy += 0.2;
		y += dy;
		//neu nhan vat den vi tri
		if (y > 590)
		{
			dy = -13;
		}
		//std::cout << dy <<" "<<y<< "\n";
		if (y < h) {
			//std::cout << "start" << "\n";
			//std::cout << dy << " " << y << "\n";
			//std::cout << "end " << "\n";
			y = h; //giu cho dy am
			for (int i = 0; i < 10; i++) {
				crossBarList[i].y = crossBarList[i].y - dy;
				if (crossBarList[i].y > 626) {
					crossBarList[i].y = 0;
					crossBarList[i].x = rand() % 407;
				}
			}
		}
		windows.draw(background);
		windows.draw(playerSprite);
		playerSprite.setPosition(x, y);
		for (int i = 0; i < 10; i++)
		{
			crossBar.setPosition(crossBarList[i].x, crossBarList[i].y);
			windows.draw(crossBar);
		}

		windows.display();
	}

}