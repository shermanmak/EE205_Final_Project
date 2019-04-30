#pragma once

#include <sstream>
#include <iostream>
#include "BattleState1.hpp"
#include "GameOverState.hpp"
//#include "GameState2.hpp"

namespace GameEngine
{
     BattleState1::BattleState1(GameDataRef data) : _data(data)
     {


     }

     void BattleState1::Init()
     {
          //Background
          this->_data->assets.LoadTexture("Battle 1 Background", GAME_BATTLE_1_BACKGROUND_FILEPATH);

		_battlebackground.setTexture(this->_data->assets.GetTexture("Battle 1 Background"));

          //characters
          _data ->assets.LoadTexture("Nick Battle Image", NICK_IMAGE_FILEPATH);
          _data ->assets.LoadTexture("Boss 1 Battle Image", BOSS_1_IMAGE_FILEPATH);

          //controls
          this->_data->assets.LoadTexture("Attack Button", ATTACK_BUTTON_FILEPATH);
          this->_AttackButton.setTexture(this->_data->assets.GetTexture("Attack Button"));
          this->_AttackButton.setPosition(400,600);
          this->_data->assets.LoadTexture("Heal Button", HEAL_BUTTON_FILEPATH);
          this->_HealButton.setTexture(this->_data->assets.GetTexture("Heal Button"));
          this->_HealButton.setPosition(600,600);
          this->_data->assets.LoadTexture("Charge Button", CHARGE_BUTTON_FILEPATH);
          this->_ChargeButton.setTexture(this->_data->assets.GetTexture("Charge Button"));
          this->_ChargeButton.setPosition(400,700);
          this->_data->assets.LoadTexture("Taunt Button", TAUNT_BUTTON_FILEPATH);
          this->_TauntButton.setTexture(this->_data->assets.GetTexture("Taunt Button"));
          this->_TauntButton.setPosition(600,700);


          boss1battle = new Boss1Battle(_data);
          nickbattle = new NickBattle(_data);

     }

     void BattleState1::HandleInput()
     {
          sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
                    std::cout << "good-bye" << std::endl;
			}
               //attack
               if (this->_data->input.IsSpriteClicked(this->_AttackButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    std::cout << "Attack button was clicked" << std::endl;

                    this-> nickATTACKANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;
                    this-> bossANIMATIONCOUNTER = 50;

               }
               //heal
               if (this->_data->input.IsSpriteClicked(this->_HealButton, sf::Mouse::Left, this->_data->window)&& this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    std::cout << "Heal button was clicked" << std::endl;

                    this-> nickHEALANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 55;
                    this-> bossANIMATIONCOUNTER = 55;


               }
               //charge
               if (this->_data->input.IsSpriteClicked(this->_ChargeButton, sf::Mouse::Left, this->_data->window)&& this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    std::cout << "Charge button was clicked" << std::endl;

                    this-> nickCHARGEANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 55;
                    this-> bossANIMATIONCOUNTER = 55;



               }
               //taunt
               if (this->_data->input.IsSpriteClicked(this->_TauntButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    std::cout << "Taunt button was clicked" << std::endl;

                    this-> nickTAUNTANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 55;
                    this-> bossANIMATIONCOUNTER = 55;

               }

          }

     }

     void BattleState1::Update(float dt)
     {
          if(this->nickATTACKANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
                    nickbattle->NickAttackAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                    std::cout <<"Nick time: " <<nickANIMATIONCOUNTER << std::endl;
               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;

                         boss1battle->bossAttackAnimation(dt);
                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
                         this->nickATTACKANIMATEFLAG =0;
                    }

               }

          }
          if(this->nickHEALANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
                    nickbattle->NickHealAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                    std::cout <<"Nick time: " <<nickANIMATIONCOUNTER << std::endl;

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         boss1battle->bossHealAnimation(dt);
                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
                         this->nickHEALANIMATEFLAG =0;
                    }

               }


          }
          if(this->nickCHARGEANIMATEFLAG == 1)
          {

               if(this->nickANIMATIONCOUNTER > 0)
                    nickbattle->NickChargeAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                    std::cout <<"Nick time: " <<nickANIMATIONCOUNTER << std::endl;

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         boss1battle->bossChargeAnimation(dt);
                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
                         this->nickCHARGEANIMATEFLAG =0;
                    }

               }

          }
          if(this->nickTAUNTANIMATEFLAG == 1)
          {

               if(this->nickANIMATIONCOUNTER > 0)
                    nickbattle->NickTauntAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                    std::cout <<"Nick time: " <<nickANIMATIONCOUNTER << std::endl;

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;

                         boss1battle->bossTauntAnimation(dt);
                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
                         this->nickTAUNTANIMATEFLAG =0;
                    }

               }

          }

     }

     void BattleState1::Draw(float dt)
     {
          this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_battlebackground );

          this->_data->window.draw(this->_AttackButton);
          this->_data->window.draw(this->_HealButton);
          this->_data->window.draw(this->_TauntButton);
          this->_data->window.draw(this->_ChargeButton);

          nickbattle->Draw();

          boss1battle->Draw();

		this->_data->window.display();

     }

     void BattleState1::CheckifBattleisWon()
     {
          int Nick_health = nickbattle ->getCurrentHealth();
          std::cout<< Nick_health<<std::endl;
          int Boss_health = boss1battle ->getCurrentHealth();
          std::cout<< Boss_health<<std::endl;

      //    if(Nick_health < 0)
      //         std::cout<< "you lose, go to game over state" << std::endl;
      //    else if(Boss_health < 0)
      //         std::cout<< "you win, go to next map" << std::endl;

     }
     void PrintNickHealth(){


     }
     void PrintBossHealth(){


     }

}
