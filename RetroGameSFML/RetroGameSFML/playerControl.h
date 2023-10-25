#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
void playerControl() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		player.move(-0.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		player.move(0.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		player.move(0.0f, -0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		player.move(0.0f, 0.1f);
	}

}