#pragma once

#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace GameEngine
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
		nickDEATHCOUNTER=55;
		nickDEATHFLAG=1;
	}

	void GameOverState::Init()
	{
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));

		 _data->assets.LoadTexture("Nick Battle Image", NICK_IMAGE_FILEPATH);

		nickbattle = new NickBattle(_data);
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt)
	{
		if(this->nickDEATHFLAG == 1)
		{
				 if(this->nickDEATHCOUNTER > 0 && this->nickDEATHCOUNTER != 0)
				 {
							nickbattle->NickDeathAnimation(dt);

							this->nickDEATHCOUNTER = this->nickDEATHCOUNTER -1;

				//		 std::cout <<"Nick DEATH: " <<nickDEATHCOUNTER << std::endl;
				 }
				 if(this->nickDEATHCOUNTER == 0)
				 {
					 	this->nickDEATHFLAG = 0;
				 }
		}

	}



	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background );

		nickbattle-> Draw();

		this->_data->window.display();
	}
}
