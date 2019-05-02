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
#include "NPC2.hpp"
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
		sf::Sprite _notificationThanks;
		sf::Sprite _notificationYouKind;
		sf::Sprite _Question;
		sf::Sprite _Answer1;
		sf::Sprite _Answer2;
		sf::Sprite _Answer3;

		sf::Music	_song;
		sf::SoundBuffer _clickbuffer;
		sf::Sound _clicksound;
		sf::SoundBuffer _wrongbuffer;
		sf::Sound _wrongsound;
		sf::SoundBuffer _correctbuffer;
		sf::Sound _correctsound;

		Nick *nick;
		Map *map;
		Boss1 *boss1;
		NPC1 *npc1;
		NPC2 *npc2;
		Item1 *item1;
		Item1 *item2;
		Item1 *item3;
		Item1 *item4;
		Item1 *item5;

		Collision collision;

		bool QuestionQuestFinish;
		bool FruitQuestFinish;
		bool ThanksFlag;
		bool KindFlag;
		bool QuestionFlag;
		bool AnswerCorrectFlag;
		bool FruitFlag;
		bool Boss1Flag;


	};
}
