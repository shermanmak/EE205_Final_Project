#pragma once

#include <sstream>
#include <iostream>
#include "GameState.hpp"
#include "BattleState1.hpp"

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

		_data ->assets.LoadTexture("Boss 1 Image", BOSS_1_IMAGE_FILEPATH);

		_data->assets.LoadTexture("Tile", TILE_MAP_FILEPATH);

		_data->assets.LoadTexture("NPC 1 Image", NPC_1_IMAGE_FILEPATH);

		_data->assets.LoadTexture("Item 1 Image", ITEM_1_IMAGE_FILEPATH);

    	nick = new Nick(_data);
		map = new Map(_data);
		boss1 = new Boss1(_data);
		npc1 = new NPC1(_data);
		item1 = new Item1(_data);


    }

	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			//if up key is press
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map1(nick->GetSprite()))
				{
					nick->CollisionUp();
					nick->Animate();

				}
				else
					nick->MoveUp();
					//check for collision after movement
					if(collision.CheckWallCollision_map1(nick->GetSprite()))
						nick->CollisionUp();
					nick->Animate();
					nick->StayonScreen();
			}
			//if down key is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map1(nick->GetSprite()))
				{
					nick->CollisionDown();
					nick->Animate();

				}
				else
					nick->MoveDown();
					//check for collision after movement
					if(collision.CheckWallCollision_map1(nick->GetSprite()))
						nick->CollisionDown();
					nick->Animate();
					nick->StayonScreen();

			}
			//if left key is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map1(nick->GetSprite()))
				{
					nick->CollisionLeft();
					nick->Animate();

				}
				else
					nick->MoveLeft();
					//check for collision after movement
					if(collision.CheckWallCollision_map1(nick->GetSprite()))
						nick->CollisionLeft();
					nick->Animate();
					nick->StayonScreen();
			}
			//if right key is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map1(nick->GetSprite()))
				{
					nick->CollisionRight();
					nick->Animate();

				}
				else
					nick->MoveRight();
					//check for collision again after movement
					if(collision.CheckWallCollision_map1(nick->GetSprite()))
						nick->CollisionRight();
					nick->Animate();
					nick->StayonScreen();
			}


		}

	}


	void GameState::Update(float dt)
	{
		//if you collide with the boss go to the battle state
		if(collision.CheckSpriteCollision(nick->GetSprite(),boss1->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Go To BattleState1" << std::endl;

		  this->_data->machine.AddState(StateRef(new BattleState1(this->_data)), true);

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),npc1->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Talk to tiggle bitties" << std::endl;

		//	this->_data->machine.AddState(StateRef(new BattleState1(this->_data)), true);

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item1->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item1->Obtained();

		//	this->_data->machine.AddState(StateRef(new BattleState1(this->_data)), true);

		}


	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw( this->_background );

		nick->Draw();

		map->Draw();

		boss1->Draw();

		npc1->Draw();

		item1->Draw();

		this->_data->window.display();
	}
}
