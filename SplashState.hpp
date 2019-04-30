#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace GameEngine
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		// No pause() or resume() methods here as this
		// is a very simple example of a game state.

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;
		
		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}