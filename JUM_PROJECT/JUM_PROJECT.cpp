
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define SPEED 50;

using namespace sf;
int main()
{
	sf::Clock clock;
	RenderWindow windows(VideoMode(532, 850), "Jump Game");
	windows.setSize(Vector2u(532, 850));
	Event event;

	windows.setFramerateLimit(60);
	Vector2f moveRight(20,0);
	Vector2f moveLeft(-20, 0);
	Texture BackGroundTexture;
	Texture playerRightTexture;
	Texture playerLeftTexture;
	playerLeftTexture.loadFromFile("resource/image/leftx2.png");
	playerRightTexture.loadFromFile("resource/image/right2x.png");
	BackGroundTexture.loadFromFile("resource/image/background.png");
	Sprite playerSprite(playerLeftTexture);
	Sprite background(BackGroundTexture);
	playerSprite.setPosition(250,730);

	//playerSprite.move(Vector2f(30,0));
	while (windows.isOpen())
	{
		while (windows.pollEvent(event))
		{
			float dt = clock.restart().asSeconds();
			if (event.type == sf::Event::Closed) windows.close();
			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code) {
				case Keyboard::Left: 
					playerSprite.setTexture(playerLeftTexture);
					playerSprite.move(moveLeft); break;
				case Keyboard::Right: 
					playerSprite.setTexture(playerRightTexture);
					playerSprite.move(moveRight);
					break;
				}
			}

		}
		windows.clear();
		windows.draw(background);
		windows.draw(playerSprite);
		windows.display();
	}

}