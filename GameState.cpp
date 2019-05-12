#pragma once

#include <sstream>
#include <iostream>
#include "GameState.hpp"
#include "BattleState1.hpp"
#include "NickBattle.hpp"

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

		_data->assets.LoadTexture("NPC 2 Image", NPC_2_IMAGE_FILEPATH);

		_data->assets.LoadTexture("Item 1 Image", ITEM_1_IMAGE_FILEPATH);

    nick = new Nick(_data);
		map = new Map(_data);
		boss1 = new Boss1(_data, "Boss 1 Image");
		npc1 = new NPC(_data, 12*50, 9*50-13, "NPC 1 Image", FACE_LEFT);
		npc2 = new NPC(_data, 3*50-10, 6*50, "NPC 2 Image", FACE_BACK);
		item1 = new Item(_data, 700, 0, "Item 1 Image");
		item2 = new Item(_data, 500, 75, "Item 1 Image");
		item3 = new Item(_data, 50, 500, "Item 1 Image");
		item3 = new Item(_data, 600, 300, "Item 1 Image");
		item4 = new Item(_data, 250, 450, "Item 1 Image");
		item5 = new Item(_data, 50, 75, "Item 1 Image");

		this->_data->assets.LoadTexture("Find My Fruits", NPC_NOTIFICATION_1_FILEPATH);

		this->_notificationFruit.setTexture(this->_data->assets.GetTexture("Find My Fruits"));

		this->_notificationFruit.setPosition((SCREEN_WIDTH / 2) - (this->_notificationFruit.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_notificationFruit.getGlobalBounds().height / 2));

		this->_data->assets.LoadTexture("Goon 1 Notification", BOSS_NOTIFICATION_FILEPATH);
		this->_notificationBoss1.setTexture(this->_data->assets.GetTexture("Goon 1 Notification"));
		this->_notificationBoss1.setPosition((SCREEN_WIDTH / 2) - (this->_notificationBoss1.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_notificationBoss1.getGlobalBounds().height / 2));

		this->_data->assets.LoadTexture("Thanks Notification", THANK_YOU_FILEPATH);
		this->_notificationThanks.setTexture(this->_data->assets.GetTexture("Thanks Notification"));
		this->_notificationThanks.setPosition((SCREEN_WIDTH / 2) - (this->_notificationThanks.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_notificationThanks.getGlobalBounds().height / 2));

		this->_data->assets.LoadTexture("Kind Notification", YOU_KIND_FILEPATH);
		this->_notificationYouKind.setTexture(this->_data->assets.GetTexture("Kind Notification"));
		this->_notificationYouKind.setPosition((SCREEN_WIDTH / 2) - (this->_notificationYouKind.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_notificationYouKind.getGlobalBounds().height / 2));

		this->_data->assets.LoadTexture("Question", QUESTION_1_FILEPATH);
		this->_Question.setTexture(this->_data->assets.GetTexture("Question"));
		this->_Question.setPosition((SCREEN_WIDTH / 2) - (this->_Question.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_Question.getGlobalBounds().height / 2)-150);

		this->_data->assets.LoadTexture("Answer 1", ANSWER_1_FILEPATH);
		this->_Answer1.setTexture(this->_data->assets.GetTexture("Answer 1"));
		this->_Answer1.setPosition((SCREEN_WIDTH / 2) - (this->_Answer1.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_Answer1.getGlobalBounds().height / 2));

		this->_data->assets.LoadTexture("Answer 2", ANSWER_2_FILEPATH);
		this->_Answer2.setTexture(this->_data->assets.GetTexture("Answer 2"));
		this->_Answer2.setPosition((SCREEN_WIDTH / 2) - (this->_Answer2.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_Answer2.getGlobalBounds().height / 2)+100);

		this->_data->assets.LoadTexture("Answer 3", ANSWER_3_FILEPATH);
		this->_Answer3.setTexture(this->_data->assets.GetTexture("Answer 3"));
		this->_Answer3.setPosition((SCREEN_WIDTH / 2) - (this->_Answer3.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (this->_Answer3.getGlobalBounds().height / 2)+200);


		Boss1Flag = 0;
		FruitFlag = 0;
		ThanksFlag = 0;
		KindFlag = 0;
		QuestionFlag = 0;
		AnswerCorrectFlag = 0;
		QuestionQuestFinish = 0;
		FruitQuestFinish = 0;

		//load music
		if(!_song.openFromFile("Resources/music/gamestate1song.oga"))
		{
			std::cout << "No Music File: Main Menu" << std::endl;
		}

		//adjust song volume
		_song.play();
		_song.setLoop(true);
		_song.setVolume(20.f);

		//loading interaction sound
		if(!_clickbuffer.loadFromFile("Resources/music/MenuSelectionClick.wav")){

			std::cout << "No Sound File: Menu Selection" << std::endl;

		}
		_clicksound.setBuffer(_clickbuffer);


		if(!_wrongbuffer.loadFromFile("Resources/music/wrong.wav")){

			std::cout << "No Sound File: Menu Selection" << std::endl;

		}

		_wrongsound.setBuffer(_wrongbuffer);

		if(!_correctbuffer.loadFromFile("Resources/music/correct.wav")){

			std::cout << "No Sound File: Menu Selection" << std::endl;
		}

		_correctsound.setBuffer(_correctbuffer);

}

	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
				_song.stop();
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

			Boss1Flag = 1;

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),npc1->GetSprite()))
		{
			nick->CollisionRight();

			std::cout << "Talk to Tiggle Bitties" << std::endl;

			if(nick->GetFruit()==5 && FruitQuestFinish == 0)
			{
				ThanksFlag = 1;
			}

			else
			{
				FruitFlag = 1;
			}

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),npc2->GetSprite()))
		{

			nick->CollisionDown();
			if(QuestionQuestFinish == 0)
			{
				QuestionFlag = 1;
			}
			else
				QuestionFlag = 0;
		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item1->GetSprite()))
		{

			std::cout << "Get item chee hoo" << std::endl;

			item1->Obtained();

			nick->FindFruit();

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item2->GetSprite()))
		{

			std::cout << "Get item chee hoo" << std::endl;

			item2->Obtained();

			nick->FindFruit();

		}

		if(collision.CheckSpriteCollision(nick->GetSprite(),item3->GetSprite()))
		{

			std::cout << "Get item chee hoo" << std::endl;

			item3->Obtained();

			nick->FindFruit();

		}
		if(collision.CheckSpriteCollision(nick->GetSprite(),item4->GetSprite()))
		{

			std::cout << "Get item chee hoo" << std::endl;

			item4->Obtained();

			nick->FindFruit();

		}
		if(collision.CheckSpriteCollision(nick->GetSprite(),item5->GetSprite()))
		{

			std::cout << "Get item chee hoo" << std::endl;

			item5->Obtained();

			nick->FindFruit();

		}


	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw( this->_background );

		nick->Draw();

		map->Draw_1();

		boss1->Draw();

		npc1->Draw();

		npc2->Draw();

		item1->Draw();

		item2->Draw();

		item3->Draw();

		item4->Draw();

		item5->Draw();

		//collision notifications
		if(FruitFlag && nick->GetFruit() < 5)
		{
			std::cout << FruitFlag << "Fruit notification" << std::endl;
			this->_data->window.draw(this->_notificationFruit);


			if(this->_data->input.IsSpriteClicked(this->_notificationFruit, sf::Mouse::Left, this->_data->window))
			{
				FruitFlag = 0;
				_clicksound.play();
			}

	  }

		if(QuestionFlag == 1)
		{
				this->_data->window.draw(this->_Question);
				this->_data->window.draw(this->_Answer1);
				this->_data->window.draw(this->_Answer2);
				this->_data->window.draw(this->_Answer3);
				if(this->_data->input.IsSpriteClicked(this->_Answer3, sf::Mouse::Left, this->_data->window))
				{
					QuestionFlag = 0;
					KindFlag = 1;
					//npc2->endQuestPos(5*50,5*50);
					_correctsound.play();
				}
				if(this->_data->input.IsSpriteClicked(this->_Answer1, sf::Mouse::Left, this->_data->window))
				{
					QuestionFlag = 1;
					_wrongsound.play();
				}
				if(this->_data->input.IsSpriteClicked(this->_Answer2, sf::Mouse::Left, this->_data->window))
				{
					QuestionFlag = 1;
					_wrongsound.play();
				}

		}

		if(KindFlag)
		{
			this->_data->window.draw(this->_notificationYouKind);

			if(this->_data->input.IsSpriteClicked(this->_notificationYouKind, sf::Mouse::Left, this->_data->window))
			{
				_clicksound.play();
				KindFlag = 0;
				npc2->endQuestPos(5*50,6*50-20);
				QuestionQuestFinish = 1;

			}
		}

		if(ThanksFlag)
		{
			this->_data->window.draw(this->_notificationThanks);

			if(this->_data->input.IsSpriteClicked(this->_notificationThanks, sf::Mouse::Left, this->_data->window))
			{
				_clicksound.play();
				ThanksFlag = 0;
				FruitQuestFinish = 1;
				npc1->endQuestPos(15*50,9*50-13);
				_clicksound.play();

			}
		}


		if(Boss1Flag)
		{
			this->_data->window.draw(this->_notificationBoss1);

			if(this->_data->input.IsSpriteClicked(this->_notificationBoss1, sf::Mouse::Left, this->_data->window))
			{
				_clicksound.play();
				_song.stop();
				this->_data->machine.AddState(StateRef(new BattleState1(this->_data)), true);

			}

		}



		this->_data->window.display();
	}
}
