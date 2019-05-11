#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Nick.hpp"
#include "Map.hpp"
#include "Collision.hpp"
//#include "BattleState2.hpp"
#include "Boss1.hpp"
#include "NPC.hpp"
#include "Item.hpp"
#include "GameOverState.hpp"

namespace GameEngine
{
	class GameState2 : public State, public Map
	{
	public:
		GameState2(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Texture _backgroundTexture;
		sf::Sprite _background;
		sf::Sprite _notificationFruit;
		sf::Sprite _notificationBoss1;

		Nick *nick;
		Map *map;
		Boss1 *boss1;
		NPC *npc1;
		NPC *npc2;
		Item *item1;
		Item *item2;
		Item *item3;
		Item *item4;
		Item *item5;
		Item *item6;

		Collision collision;

		bool FruitFlag;
		bool Boss1Flag;


	};
}
