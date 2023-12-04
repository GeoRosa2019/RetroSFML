#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace std;

class Player
{
public:
		// Constructor
	Player()
		: position(500, 500), angle(45), array(sf::Quads, 4)
		{
			array[0].position = sf::Vector2f(0, -30);
			array[1].position = sf::Vector2f(-30, 30);
			array[2].position = sf::Vector2f(0, 15);
			array[3].position = sf::Vector2f(30, 30);

			for (size_t i = 0; i < array.getVertexCount(); i++)
			{
				array[i].color = sf::Color::White;
			}
			
		}
		// Creating a reference to the window
		void Draw(sf::RenderWindow& window)
		{
			sf::Transform transform;
			transform.translate(position).rotate(angle);
			window.draw(array, transform);
		}
	sf::Vector2f position;
	float angle;

private:
	sf::VertexArray array;
};

int main()
{
	// Create the main window Size: 1200x900
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Asteroids!!!", 
		sf::Style::Close | sf::Style::Titlebar);

	// Set framerate limit to 60fps
	sf::Clock clock;
	
	Player player;
	// Game loop  - runs every frame
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();

		player.Draw(window);
		// draw everything here...
		window.display();
	}
	return 0;
}