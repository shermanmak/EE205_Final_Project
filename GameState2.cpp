#pragma once

#include <sstream>
#include <iostream>
#include "GameState2.hpp"
//#include "BattleState2.hpp"
#include "NickBattle.hpp"
#include "GameOverState.hpp"

namespace GameEngine
{
	GameState2::GameState2(GameDataRef data) : _data(data)
	{

	}

	void GameState2::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

    _data ->assets.LoadTexture("Nick Image", NICK_IMAGE_FILEPATH);

		_data ->assets.LoadTexture("Boss 1 Image", BOSS_1_IMAGE_FILEPATH);

		_data->assets.LoadTexture("Tile", TILE_MAP_FILEPATH);

		_data->assets.LoadTexture("NPC 1 Image", NPC_1_IMAGE_FILEPATH);

		_data->assets.LoadTexture("Item 2 Image", ITEM_2_IMAGE_FILEPATH);

    nick = new Nick(_data);
		map = new Map(_data);
		boss1 = new Boss1(_data);
		npc1 = new NPC(_data, 12*50, 9*50-13, "NPC 1 Image", FACE_LEFT);
		item1 = new Item(_data, 100, 500, "Item 2 Image");
		item2 = new Item(_data, 150, 500, "Item 2 Image");
		item3 = new Item(_data, 200, 500, "Item 2 Image");
		item4 = new Item(_data, 250, 500, "Item 2 Image");
		item5 = new Item(_data, 300, 500, "Item 2 Image");
		item6 = new Item(_data, 350, 500, "Item 2 Image");

		this->_data->assets.LoadTexture("Find My Fruits", NPC_NOTIFICATION_1_FILEPATH);

		this->_notificationFruit.setTexture(this->_data->assets.GetTexture("Find My Fruits"));

		this->_notificationFruit.setPosition((SCREEN_WIDTH / 2) - (this->_notificationFruit.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_notificationFruit.getGlobalBounds().height / 2));

		this->_data->assets.LoadTexture("Goon 1 Notification", BOSS_NOTIFICATION_FILEPATH);

		this->_notificationBoss1.setTexture(this->_data->assets.GetTexture("Goon 1 Notification"));

		this->_notificationBoss1.setPosition((SCREEN_WIDTH / 2) - (this->_notificationBoss1.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_notificationBoss1.getGlobalBounds().height / 2));

		Boss1Flag = 0;
		FruitFlag = 0;

    }

	void GameState2::HandleInput()
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
				if(collision.CheckWallCollision_map2(nick->GetSprite()))
				{
					nick->CollisionUp();
					nick->Animate();

				}
				else
					nick->MoveUp();
					//check for collision after movement
					if(collision.CheckWallCollision_map2(nick->GetSprite()))
						nick->CollisionUp();
					nick->Animate();
					nick->StayonScreen();
			}
			//if down key is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map2(nick->GetSprite()))
				{
					nick->CollisionDown();
					nick->Animate();

				}
				else
					nick->MoveDown();
					//check for collision after movement
					if(collision.CheckWallCollision_map2(nick->GetSprite()))
						nick->CollisionDown();
					nick->Animate();
					nick->StayonScreen();

			}
			//if left key is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map2(nick->GetSprite()))
				{
					nick->CollisionLeft();
					nick->Animate();

				}
				else
					nick->MoveLeft();
					//check for collision after movement
					if(collision.CheckWallCollision_map2(nick->GetSprite()))
						nick->CollisionLeft();
					nick->Animate();
					nick->StayonScreen();
			}
			//if right key is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				//check for collision prior to movement
				if(collision.CheckWallCollision_map2(nick->GetSprite()))
				{
					nick->CollisionRight();
					nick->Animate();

				}
				else
					nick->MoveRight();
					//check for collision again after movement
					if(collision.CheckWallCollision_map2(nick->GetSprite()))
						nick->CollisionRight();
					nick->Animate();
					nick->StayonScreen();
			}


		}

	}


	void GameState2::Update(float dt)
	{
		//if you collide with the boss go to the battle state
		if(collision.CheckSpriteCollision(nick->GetSprite(),boss1->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Go To GameOver for Now" << std::endl;

			Boss1Flag = 1;

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),npc1->GetSprite()))
		{
			nick->CollisionRight();

			std::cout << "Talk to tiggle bitties" << std::endl;

			if(nick->GetFruit()==2)
			{
				npc1->endQuestPos(15*50,9*50-13);
			}

			else
			{
			FruitFlag = 1;
			}

		}

		//check item collision
		//ran into problems with implementation into item class
		//hard coded as quick fix
		if(collision.CheckSpriteCollision(nick->GetSprite(),item1->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item1->Obtained();

			nick->FindFruit();

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item2->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item2->Obtained();

			nick->FindFruit();

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item3->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item2->Obtained();

			nick->FindFruit();

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item4->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item2->Obtained();

			nick->FindFruit();

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item5->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item2->Obtained();

			nick->FindFruit();

		}


		if(collision.CheckSpriteCollision(nick->GetSprite(),item6->GetSprite()))
		{
			nick->CollisionLeft();

			std::cout << "Get item chee hoo" << std::endl;

			item2->Obtained();

			nick->FindFruit();

		}

	}

	void GameState2::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw( this->_background );

		nick->Draw();

		map->Draw_2();

		boss1->Draw();

		npc1->Draw();

		item1->Draw();

		item2->Draw();

		item3->Draw();

		item4->Draw();

		item5->Draw();

		item6->Draw();

		//collision notifications
		if(FruitFlag && nick->GetFruit() < 6)
		{
			this->_data->window.draw(this->_notificationFruit);

			if(this->_data->input.IsSpriteClicked(this->_notificationFruit, sf::Mouse::Left, this->_data->window))
			{
				FruitFlag = 0;
			}

	  }


		if(Boss1Flag)
		{
			this->_data->window.draw(this->_notificationBoss1);

			if(this->_data->input.IsSpriteClicked(this->_notificationBoss1, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameOverState(this->_data)), true);
			}

		}



		this->_data->window.display();
	}
}
