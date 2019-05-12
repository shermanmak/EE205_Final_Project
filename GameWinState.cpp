#pragma once

#include <sstream>
#include "GameWinState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace GameEngine
{
	GameWinState::GameWinState(GameDataRef data) : _data(data)
	{

	}

	void GameWinState::Init()
	{
		this->_data->assets.LoadTexture("Game Win Background", GAME_WIN_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Win Background"));

		 _data->assets.LoadTexture("Nick Battle Image", NICK_IMAGE_FILEPATH);

		nickbattle = new NickBattle(_data);
	}

	void GameWinState::HandleInput()
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

	void GameWinState::Update(float dt)
	{

	}



	void GameWinState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background );

		//nickbattle-> Draw();

		this->_data->window.display();
	}
}
