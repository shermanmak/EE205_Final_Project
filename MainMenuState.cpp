#pragma once

#include <sstream>
#include "MainMenuState.hpp"
#include "IntroState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace GameEngine
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));

		if(!_mainmenusong.openFromFile("Resources/music/MainMenuMusic.oga")){

			std::cout << "No Music File: Main Menu" << std::endl;

		}


		//adjust song volume
		_mainmenusong.play();
		_mainmenusong.setLoop(true);
		_mainmenusong.setVolume(20.f);

		//loading interaction sound
		if(!_clickbuffer.loadFromFile("Resources/music/MenuSelectionClick.wav")){

			std::cout << "No Sound File: Menu Selection" << std::endl;

		}

		_clicksound.setBuffer(_clickbuffer);

	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
				_mainmenusong.stop();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				_clicksound.play();
				std::cout << "Go To Intro Screen" << std::endl;
				this->_data->machine.AddState(StateRef(new IntroState(this->_data)), true);
				_mainmenusong.stop();
			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}
