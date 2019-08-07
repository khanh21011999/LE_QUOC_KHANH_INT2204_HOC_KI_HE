
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <time.h>
#include <cstdlib>
#define SPEED 50;

using namespace sf;
struct CrossBarStruct
{
	int x, y;
};
int main()
{
	srand(time(NULL));
	Vector2f v;
	sf::Clock clock;
	RenderWindow windows(VideoMode(407,650), "Jump Game");
	windows.setSize(Vector2u(407,650));
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
	int x = 100, y = 300, h = 200;
	float dx = 0, dy = 0;
	while (windows.isOpen())
	{
		while (windows.pollEvent(event))
		{
			float dt = clock.restart().asSeconds();
			if (event.type == sf::Event::Closed) windows.close();
		

		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			playerSprite.setTexture(playerRightTexture);
			x += 3;
		}
		    
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			playerSprite.setTexture(playerRightTexture);
			x -= 3;
		}

		dy += 0.2;
		y += dy;

		if (y > 590)
		{
			dy = -11;
		}
	
		windows.draw(background);
		windows.draw(playerSprite);
		playerSprite.setPosition(x,y);
		for (int i = 0; i < 10; i++)
		{
			crossBar.setPosition(crossBarList[i].x, crossBarList[i].y);
			windows.draw(crossBar);
		}

		windows.display();
	}

}