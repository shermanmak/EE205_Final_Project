#pragma once

#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace GameEngine
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	
        _data ->assets.LoadTexture("Nick Image", NICK_IMAGE_FILEPATH);

        nick = new Nick(_data);
    
    }

	void GameState::HandleInput()
	{
		sf::Event event;
		sf::Vector2i source(1,10);

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			//if up key is press

			//if down key is pressed

			//if left key is pressed

			//if right key is pressed
		
		}
			
	}

	void GameState::Update(float dt)
	{
		
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background );

        nick->Draw();

		this->_data->window.display();
	}
}
