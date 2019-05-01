#pragma once

#include <sstream>
#include "IntroState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <string>

#include <iostream>

namespace GameEngine
{
	IntroState::IntroState(GameDataRef data) : _data(data)
	{

	}

	void IntroState::Init()
	{
		this->_data->assets.LoadTexture("Background", INTRO_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Okay Button", OKAY_BUTTON_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_okayButton.setTexture(this->_data->assets.GetTexture("Okay Button"));
        this->_okayButton.setPosition((SCREEN_WIDTH / 2) - (this->_okayButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT*3 / 4) - (this->_okayButton.getGlobalBounds().height / 2));

        this->_data->assets.LoadFont("Dialogue", DIALOG_FONT_FILEPATH);
        this->_text.setFont(this->_data->assets.GetFont("Dialogue"));
        this->_text.setColor(sf::Color::Black);
        this->_text.setCharacterSize(20);
        this->_text.setString("Hello... My name is Nick! \nThe girl of my dreams left me \nfor her evil ex-boyfriend due to \nhis crazy stats and MATLAB wizadry.\nI am NO match for him!!! \nI'm on a mission to raise my stats \nso hopefully I can win her back. \nI'm trying to raise my kindness, love, \nstrength, and flirt abilities.");
        this->_text.setPosition((SCREEN_WIDTH/3), (SCREEN_HEIGHT/2.5));

		//_data->assets.LoadTexture("Chad Image", CHAD_IMAGE_FILEPATH);
		_data->assets.LoadTexture("Intro Chad Image", INTRO_CHAD_IMAGE_FILEPATH);

		//chad = new Chad(_data);
		introchad = new IntroChad(_data);
		//_data->assets.LoadTexture("Princess Image", PRINCESS_IMAGE_FILEPATH);
		//princess = new Princess(_data);
	}
	void IntroState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
            
            if (this->_data->input.IsSpriteClicked(this->_okayButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Go To Game Screen" << std::endl;
				this->_data->machine.AddState(StateRef(new GameState(this->_data)), true);
			}

		}
	}

	void IntroState::Update(float dt)
	{

	}

	void IntroState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_okayButton);

        this->_data->window.draw(this-> _text);
		//chad->Draw();
		introchad->Draw();
		//princess->Draw();
		this->_data->window.display();

	}
}