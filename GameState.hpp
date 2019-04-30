#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Nick.hpp"
#include "Map.hpp"
#include "Collision.hpp"
#include "BattleState1.hpp"
#include "Boss1.hpp"
#include "NPC1.hpp"
#include "Item1.hpp"

namespace GameEngine
{
	class GameState : public State, public Map
	{
	public:
		GameState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		Nick *nick;
		Map *map;
		Boss1 *boss1;
		NPC1 *npc1;
		Item1 *item1;

		Collision collision;
		bool DownCollision;


	};
}
