#pragma once

#include "SFML/Graphics.hpp"

namespace GameEngine
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		//bool IsKeyPressed(sf::Sprite object, sf::Keyboard::Key key, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}