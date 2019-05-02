#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
		sf::Sprite _notificationFruit;
		sf::Sprite _notificationBoss1;

		sf::Music	_song;
		sf::SoundBuffer _clickbuffer;
		sf::Sound _clicksound;

		Nick *nick;
		Map *map;
		Boss1 *boss1;
		NPC1 *npc1;
	//	NPC2 *npc2;
		Item1 *item1;
		Item1 *item2;
		Item1 *item3;
		Item1 *item4;
		Item1 *item5;

		Collision collision;

		bool FruitFlag;
		bool Boss1Flag;


	};
}
