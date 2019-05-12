#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "NickBattle.hpp"

namespace GameEngine
{
	class GameWinState : public State
	{
	public:
		GameWinState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		

	private:
		GameDataRef _data;
		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		NickBattle *nickbattle;
	};
}
