#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "IntroChad.hpp"

namespace GameEngine
{
	class IntroState : public State
	{
	public:
		IntroState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _okayButton;

        sf::Sprite _background;

        sf::Font _font;

        sf::Text _text;

        sf::Clock _clock;

		//Chad *chad;

			IntroChad *introchad;

			sf::Music _introsong;
			sf::SoundBuffer _clickbuffer;
			sf::Sound _clicksound;

	};
}
