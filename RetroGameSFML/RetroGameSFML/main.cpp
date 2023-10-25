#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace std;



void rectangleShape() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Rendering the rectangle.");
    // Creating our shape.
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: // "close requested" event: we close the window
					window.close();
					break;
				case sf::Event::KeyPressed: // Key pressed.
                    if (event.key.code == sf::Keyboard::Escape) {
						window.close();
                        break;
					}
                    if (event.key.code == sf::Keyboard::Up) {
						rectangle.move(0.0f, -10.0f);
						break;
					}
                    if (event.key.code == sf::Keyboard::Down) {
						rectangle.move(0.0f, 10.0f);
						break;
					}
                    if (event.key.code == sf::Keyboard::Left) {
						rectangle.move(-10.0f, 0.0f);
						break;
					}
                    if (event.key.code == sf::Keyboard::Right) {
						rectangle.move(10.0f, 0.0f);
						break;
					}
                    if (event.key.code == sf::Keyboard::B) {
						rectangle.setFillColor(sf::Color::Blue);
						break;
					}
                    if (event.key.code == sf::Keyboard::G) {
                        rectangle.setFillColor(sf::Color::Green);
                        break;
                    }
				default:
					break;
            }

        }
        

        window.clear(sf::Color::Black);
        window.draw(rectangle); // Drawing our shape.
        window.display();
    }
}


int main()
{
    rectangleShape();
    return 0;
}