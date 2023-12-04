#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace std;

// Creating the game class.

class Game {
    public:
	Game();
	void run();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    private:
        void processEvents();
        void update();
        void render();;
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
};

// Game constructor.
Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer() {
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
}


// Process events.
void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

/*void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
		mIsMovingUp = isPressed;
	}
    else if (key == sf::Keyboard::S) {
		mIsMovingDown = isPressed;
	}
    else if (key == sf::Keyboard::A) {
		mIsMovingLeft = isPressed;
	}
    else if (key == sf::Keyboard::D) {
		mIsMovingRight = isPressed;
	}
}
*/

// Handle the player input.
// It polls all the window's events that were triggered since the last iteration of the loop.
void Game::processEvents()
{
    // Event class that holds all the different types of events.
    // Events are things that happen in the window through input from the user or the system.
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
       
        case sf::Event::Closed: // "close requested" event: we close the window
            mWindow.close();
            break;
        }
    }
}

// Updates Game logic.
void Game::update()
{
  
}

// Render the game.
void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}





void rectangleShape() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Rendering the rectangle.", sf::Style::Close | sf::Style::Titlebar);
    // Creating a clock.
    sf::Clock clock;
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
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
						rectangle.setFillColor(sf::Color::Yellow);
						break;
					}
                    if (event.mouseButton.button == sf::Mouse::Right) {
						rectangle.setFillColor(sf::Color::Magenta);
						break;
					}
					
            }

        }
        

        window.clear(sf::Color::Black);
        window.draw(rectangle); // Drawing our shape.
        window.display();
    }
}


int main()
{
    
    //Game game;
    //game.run();
    rectangleShape();
    //return 0;
}