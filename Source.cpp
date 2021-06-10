// #include "SFML-2.5.1\include\SFML\Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Game
{
private:
	sf::Vector2f playerPosition;
	bool playerMoving = false;

	sf::Texture skyTexture;
	sf::Sprite skySprite;

	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	sf::Texture heroTexture;
	sf::Sprite heroSprite;

	sf::RenderWindow &window;

	sf::Vector2f viewSize;

public:
	Game(sf::RenderWindow &_window, sf::Vector2f _viewSize)
		: window(_window),
		  viewSize(_viewSize)
	{
	}
	// Game::operator=() delete;
	~Game() {}

	void init()
	{

		if (!skyTexture.loadFromFile("Assets/graphics/sky.png"))
			return;
		cout << "Success load sky" << endl;
		skySprite.setTexture(skyTexture);

		bgTexture.loadFromFile("Assets/graphics/bg.png");
		bgSprite.setTexture(bgTexture);

		heroTexture.loadFromFile("Assets/graphics/hero.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
		heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);
	}

	void updateInput()
	{

		sf::Event event;

		// while there are pending events...
		while (window.pollEvent(event))
		{

			//printf(" polling events \n");

			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Right)
				{

					playerMoving = true;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{

				if (event.key.code == sf::Keyboard::Right)
				{

					playerMoving = false;
				}
			}

			if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update(float dt)
	{

		if (playerMoving)
		{

			heroSprite.move(50.0f * dt, 0);
		}
	}

	void draw()
	{
		window.draw(skySprite);
		window.draw(bgSprite);
		window.draw(heroSprite);
	}

	void start()
	{
		sf::Clock clock;
		init();
		while (window.isOpen())
		{
			updateInput();
			sf::Time dt = clock.restart();
			update(dt.asSeconds());
			window.clear(sf::Color::Red);
			draw();
			window.display();
		}
	}
};

int main()
{

	sf::Vector2f viewSize(1024, 768);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	sf::RenderWindow window(vm, "Hello SFML Game !!!", sf::Style::Default);

	auto game = Game(window, viewSize);
	game.start();

	return 0;
}
