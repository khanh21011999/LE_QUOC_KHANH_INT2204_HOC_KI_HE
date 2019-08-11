
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <iostream>
#define SPEED 50;

using namespace sf;
void GameOver(RenderWindow& windows)
{

}
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
		crossBarList[i].x = rand() % 350;
		crossBarList[i].y = rand() % 550;
	}
	//tao cua so Gameover
	RectangleShape gameoverBackground(sf::Vector2f(407, 650));
	gameoverBackground.setFillColor(sf::Color::White);
	//load font
	Font font;
	font.loadFromFile("resource/font/al-seana.ttf");
	//score
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(Color::Black);
	//gameover
	Text gameoverText;
	gameoverText.setFont(font);
	gameoverText.setString("Game Over!");
	gameoverText.setCharacterSize(80);
	gameoverText.setFillColor(sf::Color::Red);
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
	//sound
	SoundBuffer buffer;
	buffer.loadFromFile("resource/sound/jump.wav");
	Sound sound;
	sound.setBuffer(buffer);
	//score 
	int score = 0;
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
	
		//std::cout << dy <<" "<<y<< "\n";

		/*if (x> 650)
			x = 0;
		if (x < 0)
			x = 650;*/
		if (y < h) {
			/*std::cout << "start" << "\n";
			//std::cout << dy << " " << y << "\n";
			//std::cout << "end " << "\n";*/ 
			//giu cho dy am
			y = h;
			for (int i = 0; i < 10; i++) {
				crossBarList[i].y = crossBarList[i].y - dy;
				if (crossBarList[i].y > 626) {
					crossBarList[i].y = 0;
					crossBarList[i].x = rand() % 407;
				}
			}
		}
		//xac dinh va cham voi crossBar

		for (int i = 0; i < 10; i++) {
			if ((x + 50 > crossBarList[i].x) && (x + 20 < crossBarList[i].x + 68)
				&& (y + 70 > crossBarList[i].y) && (y + 70 < crossBarList[i].y + 14) && (dy > 0)) {
				sound.play();
				dy = -10;
			}
		}
		//tinh diem
		//vi y==h se am nen se luon + diem
		if (y == h)
		{
			score += 1;
			scoreText.setString("Score: " + std::to_string(score));
		}
		windows.draw(background);
		windows.draw(playerSprite);
		
		playerSprite.setPosition(x, y);
		for (int i = 0; i < 10; i++)
		{
			crossBar.setPosition(crossBarList[i].x, crossBarList[i].y);
			windows.draw(crossBar);
		}
		if (y > 590)
		{
			gameoverText.setPosition(30, 200);
			scoreText.setPosition(150, 400);
			while (windows.isOpen())
			{
				sf::Event event;
				while (windows.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						windows.close();
				}
				windows.draw(gameoverBackground);
				windows.draw(gameoverText);
				windows.draw(scoreText);
				windows.display();
			}
			return 0;
		}
		windows.draw(scoreText);
		windows.display();
	}

}