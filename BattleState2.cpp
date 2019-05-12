#pragma once

#include <sstream>
#include <iostream>
#include "BattleState2.hpp"
#include "GameOverState.hpp"
#include "GameWinState.hpp"
#include "string"
#include <stdio.h>
#include <stdlib.h>

namespace GameEngine
{
     BattleState2::BattleState2(GameDataRef data) : _data(data)
     {


     }

     void BattleState2::Init()
     {
          //Background
          this->_data->assets.LoadTexture("Battle 1 Background", GAME_BATTLE_1_BACKGROUND_FILEPATH);

		      _battlebackground.setTexture(this->_data->assets.GetTexture("Battle 1 Background"));

          //characters
          _data ->assets.LoadTexture("Nick Battle Image", NICK_IMAGE_FILEPATH);
          _data ->assets.LoadTexture("Chad Battle Image", CHAD_BATTLE_IMAGE_FILEPATH);

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

          //Win notifications
          this->_data->assets.LoadTexture("Win Notification", WIN_NOTIFICATION_FILEPATH);
      		this->_notificationWin.setTexture(this->_data->assets.GetTexture("Win Notification"));
      		this->_notificationWin.setPosition((SCREEN_WIDTH / 2) - (this->_notificationWin.getGlobalBounds().width / 2),
      		(SCREEN_HEIGHT / 2) - (this->_notificationWin.getGlobalBounds().height / 2));
          win = false;

          chadbattle = new BossBattle(_data, "Chad Battle Image");
          nickbattle = new NickBattle(_data);

          //music
          if(!_song.openFromFile("Resources/music/Battle1.oga"))
          {
              std::cout << "No Music File: Main Menu" << std::endl;
          }

        //adjust song volume
        _song.play();
        _song.setLoop(true);
        _song.setVolume(20.f);

        //loading interaction sound
        if(!_clickbuffer.loadFromFile("Resources/music/MenuSelectionClick.wav"))
        {
          std::cout << "No Sound File: Menu Selection" << std::endl;
        }
        _clicksound.setBuffer(_clickbuffer);


          //Status Bar
          this-> _data->assets.LoadTexture("Current Status", STATUS_BAR_FILEPATH);
          _statusBar.setTexture(this->_data->assets.GetTexture("Current Status"));
          _statusBar.setPosition(50,200);

          this->_data->assets.LoadFont("Dialogue", DIALOG_FONT_FILEPATH);
            this->_NickHealth.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_NickHealth.setColor(sf::Color::Black);

            //sets health to start at 100 at each battle
            this->nickCurrentHealth = 100;
            std::string nickhealth = nickgetCurrentHealth_string();
            this->_NickHealth.setString(nickhealth);
            this->_NickHealth.setCharacterSize(18);
            this->_NickHealth.setPosition(155,240);

            this->_NickAttack.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_NickAttack.setColor(sf::Color::Black);
            /*if(battleswon == 0)
            {
                this->nickCurrentStrength = 20;
            }
            if(battleswon == 1)
            {
                this->nickCurrentStrength = 30;
            }
            if(battleswon == 2)
            {
                this->nickCurrentStrength = 40;
            }*/

            this->nickCurrentStrength = 25;
           // std::cout << "DEBUG: NICK CURRENT STRENGTH AT CONSTRUCT" << nickCurrentStrength << std::endl;
            std::string nickattack = nickgetCurrentStrength_string();
            this->_NickAttack.setString(nickattack);
            this->_NickAttack.setCharacterSize(18);
            this->_NickAttack.setPosition(155,260);

            this->_data->assets.LoadFont("Dialogue", DIALOG_FONT_FILEPATH);
            this->_BossHealth.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_BossHealth.setColor(sf::Color::Black);

            //sets CHAD health to start at 200 at each battle
          this->bossCurrentHealth = 200;

            std::string bosshealth = bossgetCurrentHealth_string();
            this->_BossHealth.setString(bosshealth);
            this->_BossHealth.setCharacterSize(18);
            this->_BossHealth.setPosition(165,300);

           this->bossCurrentStrength = 45;


            this->_BossAttack.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_BossAttack.setColor(sf::Color::Black);

            std::string bossattack = bossgetCurrentStrength_string();
            this->_BossAttack.setString(bossattack);
            this->_BossAttack.setCharacterSize(18);
            this->_BossAttack.setPosition(165,320);




     }

     void BattleState2::HandleInput()
     {
          sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
                    std::cout << "good-bye" << std::endl;
                    _song.stop();
			}
               //*******************************ATTACK***********************
               if (this->_data->input.IsSpriteClicked(this->_AttackButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    _clicksound.play();
                    this-> nickATTACKANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;

                    //deal damage to boss
                    bosstakeDamage(nickCurrentStrength);

                    //boss choose random spell
                    this->bosschoice = bossRandomSpell();
                    std::cout << "Boss original choice: "<<this->bosschoice << std::endl;

                    if(this->bosschoice == 1)
                    {
                      //   nicktakedamage(bossCurrentStrength);
                         this-> BossAttackFlag = 1;
                         this-> bossANIMATIONCOUNTER = 50;
                    //     std::cout << "Attack Flag: " <<this->BossAttackFlag << std::endl;
                    }
                    else if(this->bosschoice == 2)
                    {
                      //   bossHealHealth(5);
                         this-> BossHealFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Heal Flag: " <<this->BossHealFlag << std::endl;

                    }
                    else if(this->bosschoice == 3)
                    {
                     //    bossChargeStrength(2);
                         this->BossChargeFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Charge Flag: " <<this->BossChargeFlag << std::endl;
                    }
                    else if(this->bosschoice == 4)
                    {
                      //   nickgottaunted(2);
                         this->BossTauntFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Taunt Flag: " <<this->BossTauntFlag << std::endl;
                    }

               }
               //*************************HEAL************************************
              else if (this->_data->input.IsSpriteClicked(this->_HealButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{

                    _clicksound.play();
                    this-> nickHEALANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;

                    //deal damage to boss
                    nickHealHealth(10);

                    //boss choose random spell
                    this->bosschoice = bossRandomSpell();
                    std::cout << "Boss original choice: "<<this->bosschoice << std::endl;

                    if(this->bosschoice == 1)
                    {
                      //   nicktakedamage(bossCurrentStrength);
                         this-> BossAttackFlag = 1;
                         this-> bossANIMATIONCOUNTER = 50;
                    //     std::cout << "Attack Flag: " <<this->BossAttackFlag << std::endl;
                    }
                    else if(this->bosschoice == 2)
                    {
                      //   bossHealHealth(5);
                         this-> BossHealFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Heal Flag: " <<this->BossHealFlag << std::endl;

                    }
                    else if(this->bosschoice == 3)
                    {
                     //    bossChargeStrength(2);
                         this->BossChargeFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Charge Flag: " <<this->BossChargeFlag << std::endl;
                    }
                    else if(this->bosschoice == 4)
                    {
                      //   nickgottaunted(2);
                         this->BossTauntFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Taunt Flag: " <<this->BossTauntFlag << std::endl;
                    }

               }
               //********************CHARGE***************************
              else if (this->_data->input.IsSpriteClicked(this->_ChargeButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    _clicksound.play();
                    this-> nickCHARGEANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;

                    //Charge Strength
                    nickChargeStrength(5);

                    //boss choose random spell
                    this->bosschoice = bossRandomSpell();
                    std::cout << "Boss original choice: "<<this->bosschoice << std::endl;

                    if(this->bosschoice == 1)
                    {
                      //   nicktakedamage(bossCurrentStrength);
                         this-> BossAttackFlag = 1;
                         this-> bossANIMATIONCOUNTER = 50;
                    //     std::cout << "Attack Flag: " <<this->BossAttackFlag << std::endl;
                    }
                    else if(this->bosschoice == 2)
                    {
                      //   bossHealHealth(5);
                         this-> BossHealFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Heal Flag: " <<this->BossHealFlag << std::endl;

                    }
                    else if(this->bosschoice == 3)
                    {
                     //    bossChargeStrength(2);
                         this->BossChargeFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Charge Flag: " <<this->BossChargeFlag << std::endl;
                    }
                    else if(this->bosschoice == 4)
                    {
                      //   nickgottaunted(2);
                         this->BossTauntFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Taunt Flag: " <<this->BossTauntFlag << std::endl;
                    }

               }
               //*************TAUNT********************
             else if (this->_data->input.IsSpriteClicked(this->_TauntButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    _clicksound.play();
                    this-> nickTAUNTANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;

                    //taunt boss
                    bossgottaunted(5);

                    //boss choose random spell
                    this->bosschoice = bossRandomSpell();
                    std::cout << "Boss original choice: "<<this->bosschoice << std::endl;

                    if(this->bosschoice == 1)
                    {
                      //   nicktakedamage(bossCurrentStrength);
                         this-> BossAttackFlag = 1;
                         this-> bossANIMATIONCOUNTER = 50;
                    //     std::cout << "Attack Flag: " <<this->BossAttackFlag << std::endl;
                    }
                    else if(this->bosschoice == 2)
                    {
                      //   bossHealHealth(5);
                         this-> BossHealFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Heal Flag: " <<this->BossHealFlag << std::endl;

                    }
                    else if(this->bosschoice == 3)
                    {
                     //    bossChargeStrength(2);
                         this->BossChargeFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Charge Flag: " <<this->BossChargeFlag << std::endl;
                    }
                    else if(this->bosschoice == 4)
                    {
                      //   nickgottaunted(2);
                         this->BossTauntFlag = 1;
                         this-> bossANIMATIONCOUNTER = 55;
                    //     std::cout << "Taunt Flag: " <<this->BossTauntFlag << std::endl;
                    }

               }


          }

     }

     void BattleState2::Update(float dt)
     {
          //ATTACK ANIMATION
          if(this->nickATTACKANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
               {
                    nickbattle->NickAttackAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                //   std::cout <<"Nick time: " <<nickANIMATIONCOUNTER << std::endl;
               }
               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                    //     std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              chadbattle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              chadbattle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              chadbattle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              chadbattle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         chadbattle->bossResetAnimationPosition();
                         this->nickATTACKANIMATEFLAG =0;
                         if(this->BossAttackFlag == 1)
                         {
                              this->BossAttackFlag = 0;
                              nicktakedamage(bossCurrentStrength);
                         }
                         else if(this->BossHealFlag == 1)
                         {
                              this->BossHealFlag = 0;
                              bossHealHealth(5);
                         }
                         else if(this->BossChargeFlag ==1)
                         {
                              this->BossChargeFlag = 0;
                              bossChargeStrength(2);
                         }
                         else if(this->BossTauntFlag ==1)
                         {
                              this->BossTauntFlag = 0;
                              nickgottaunted(2);
                         }
                    }

               }

          }


          //HEAL ANIMATION
          if(this->nickHEALANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
               {
                    nickbattle->NickHealAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                //    std::cout <<"Nick time Heal: " <<nickANIMATIONCOUNTER << std::endl;
               }

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickHEALANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                    //     std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              chadbattle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              chadbattle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              chadbattle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              chadbattle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         chadbattle->bossResetAnimationPosition();
                         this->nickHEALANIMATEFLAG =0;
                         if(this->BossAttackFlag == 1)
                         {
                              this->BossAttackFlag = 0;
                              nicktakedamage(bossCurrentStrength);
                         }
                         else if(this->BossHealFlag == 1)
                         {
                              this->BossHealFlag = 0;
                              bossHealHealth(5);
                         }
                         else if(this->BossChargeFlag ==1)
                         {
                              this->BossChargeFlag = 0;
                              bossChargeStrength(2);
                         }
                         else if(this->BossTauntFlag ==1)
                         {
                              this->BossTauntFlag = 0;
                              nickgottaunted(2);
                         }
                    }

               }

          }




          //CHARGE ANIMATION
          if(this->nickCHARGEANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
               {
                    nickbattle->NickChargeAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                //   std::cout <<"Nick time Charge: " <<nickANIMATIONCOUNTER << std::endl;
               }
               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                        // std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              chadbattle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              chadbattle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              chadbattle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              chadbattle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         chadbattle->bossResetAnimationPosition();
                         this->nickCHARGEANIMATEFLAG =0;
                         if(this->BossAttackFlag == 1)
                         {
                              this->BossAttackFlag = 0;
                              nicktakedamage(bossCurrentStrength);
                         }
                         else if(this->BossHealFlag == 1)
                         {
                              this->BossHealFlag = 0;
                              bossHealHealth(5);
                         }
                         else if(this->BossChargeFlag ==1)
                         {
                              this->BossChargeFlag = 0;
                              bossChargeStrength(2);
                         }
                         else if(this->BossTauntFlag ==1)
                         {
                              this->BossTauntFlag = 0;
                              nickgottaunted(2);
                         }
                    }

               }

          }




          //TAUNT ANIMATION
          if(this->nickTAUNTANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
               {
                    nickbattle->NickHealAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
              //      std::cout <<"Nick time Taunt: " <<nickANIMATIONCOUNTER << std::endl;
               }

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                      //   std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              chadbattle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              chadbattle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              chadbattle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              chadbattle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         chadbattle->bossResetAnimationPosition();
                         this->nickTAUNTANIMATEFLAG =0;
                         if(this->BossAttackFlag == 1)
                         {
                              this->BossAttackFlag = 0;
                              nicktakedamage(bossCurrentStrength);
                         }
                         else if(this->BossHealFlag == 1)
                         {
                              this->BossHealFlag = 0;
                              bossHealHealth(5);
                         }
                         else if(this->BossChargeFlag ==1)
                         {
                              this->BossChargeFlag = 0;
                              bossChargeStrength(2);
                         }
                         else if(this->BossTauntFlag ==1)
                         {
                              this->BossTauntFlag = 0;
                              nickgottaunted(2);
                         }
                    }

               }

          }



          if(bossCurrentHealth <= 0)
          {

            this->win = true;
            this->bossANIMATIONCOUNTER = 0;
               //this->_data->machine.AddState(StateRef(new GameState2(this->_data)), true);
               //_song.stop();

          }
          if(nickCurrentHealth <= 0)
          {
               this->_data->machine.AddState(StateRef(new GameOverState(this->_data)), true);
               _song.stop();

          }



     }

     void BattleState2::Draw(float dt)
     {
          this->_data->window.clear(sf::Color::Red);

		      this->_data->window.draw( this->_battlebackground );

          this->_data->window.draw(this->_AttackButton);
          this->_data->window.draw(this->_HealButton);
          this->_data->window.draw(this->_TauntButton);
          this->_data->window.draw(this->_ChargeButton);
          this->_data->window.draw(this->_statusBar);

          this->_data->window.draw(_NickHealth);
          this->_data->window.draw(_NickAttack);
          this->_data->window.draw(_BossAttack);
          this->_data->window.draw(_BossHealth);
          nickbattle->Draw();
          chadbattle->Draw();

          if(this->win == true)
          {
            this->_data->window.draw(this->_notificationWin);
            if(this->_data->input.IsSpriteClicked(this->_notificationWin, sf::Mouse::Left, this->_data->window))
            {
              _clicksound.play();
              _song.stop();
              this->_data->machine.AddState(StateRef(new GameWinState(this->_data)), true);
            }
          }

		      this->_data->window.display();

     }







     void BattleState2::CheckifBattleisWon()
     {


      //    if(Nick_health < 0)
      //         std::cout<< "you lose, go to game over state" << std::endl;
      //    else if(Boss_health < 0)
      //         std::cout<< "you win, go to next map" << std::endl;

     }

     //Health  setter
    void BattleState2::nicksetHealth(int health)
    {
        this -> nickCurrentHealth = this->nickCurrentHealth+ health;
        if(this->nickCurrentHealth > 100) //hard setting max health to 100
            this->nickCurrentHealth = 100;
    }
    //Health Getter
    std::string BattleState2::nickgetCurrentHealth_string()
    {
        int Health =  this-> nickCurrentHealth;

        std::string Health_string = std::to_string(Health);

        return Health_string;

    }
    int BattleState2::nickgetCurrentHealth()
    {
        return this-> nickCurrentHealth;
    }

    //Strength setter
    void BattleState2::nicksetStrength(int strength)
    {
        this -> nickCurrentStrength = strength;
    }

    //Strength getter string
    std::string BattleState2::nickgetCurrentStrength_string()
    {
        int Strength = this-> nickCurrentStrength;

        std::string Attack_string = std::to_string(Strength);

        return Attack_string;
    }

    int BattleState2::nickgetCurrentStrength()
    {
        return this -> nickCurrentStrength;
    }

    //Health  setter
    void BattleState2::bosssetHealth(int health)
    {
        this -> bossCurrentHealth = this->bossCurrentHealth+ health;
        if(this->bossCurrentHealth > 200) //hard setting max health to 200
            this->bossCurrentHealth = 200;
    }
    //Health Getter
    int BattleState2::bossgetCurrentHealth()
    {
        return this-> bossCurrentHealth;
    }
    //Health Getter string
    std::string BattleState2::bossgetCurrentHealth_string()
    {
        int Health =  this-> bossCurrentHealth;

        std::string Health_string = std::to_string(Health);

        return Health_string;

    }

    //Strength setter
    void BattleState2::bosssetStrength(int strength)
    {
        this -> bossCurrentStrength = strength;
    }

    //Strength getter
    int BattleState2::bossgetCurrentStrength()
    {
        return this-> bossCurrentStrength;
    }
    //Strength getter string
    std::string BattleState2::bossgetCurrentStrength_string()
    {
        int Strength = this-> bossCurrentStrength;

        std::string Attack_string = std::to_string(Strength);

        return Attack_string;
    }

    void BattleState2::bosstakeDamage(int damage)
    {
        this-> bossCurrentHealth = this -> bossCurrentHealth - damage;
          if(this->bossCurrentHealth < 0)
               this->bossCurrentHealth = 0;
        std::string health = bossgetCurrentHealth_string();
        this->_BossHealth.setString(health);
        this->_BossHealth.setCharacterSize(18);
        this->_BossHealth.setPosition(165,300);

    }
    void BattleState2::bossHealHealth(int heal)
    {
        this-> bossCurrentHealth = this -> bossCurrentHealth + heal;
        std::string health = bossgetCurrentHealth_string();
        this->_BossHealth.setString(health);
        this->_BossHealth.setCharacterSize(18);
        this->_BossHealth.setPosition(165,300);
    }
    void BattleState2::bossChargeStrength(int strength)
    {
        this-> bossCurrentStrength = this -> bossCurrentStrength + strength;
        if(this->bossCurrentStrength < 0)
          this->bossCurrentStrength = 0;
        std::string attack = bossgetCurrentStrength_string();
        this->_BossAttack.setString(attack);
        this->_BossAttack.setCharacterSize(18);
        this->_BossAttack.setPosition(165,320);
    }
    void BattleState2::bossgottaunted(int strength)
    {
        this-> bossCurrentStrength = this -> bossCurrentStrength - strength;
        if(this->bossCurrentStrength < 0)
          this->bossCurrentStrength = 0;
        std::string attack = bossgetCurrentStrength_string();
        this->_BossAttack.setString(attack);
        this->_BossAttack.setCharacterSize(18);
        this->_BossAttack.setPosition(165,320);
    }
    //nick spells
     void BattleState2::nicktakedamage(int damage)
    {
        this-> nickCurrentHealth = this -> nickCurrentHealth - damage;
        std::string health = nickgetCurrentHealth_string();
        this->_NickHealth.setString(health);
        this->_NickHealth.setCharacterSize(18);
        this->_NickHealth.setPosition(155,240);

    }
    void BattleState2::nickHealHealth(int heal)
    {
        this-> nickCurrentHealth = this -> nickCurrentHealth + heal;
        std::string health = bossgetCurrentHealth_string();
        this->_NickHealth.setString(health);
        this->_NickHealth.setCharacterSize(18);
        this->_NickHealth.setPosition(155,240);
    }
    void BattleState2::nickChargeStrength(int strength)
    {
        this-> nickCurrentStrength = this -> nickCurrentStrength + strength;
        std::string attack = nickgetCurrentStrength_string();
        this->_NickAttack.setString(attack);
        this->_NickAttack.setCharacterSize(18);
        this->_NickAttack.setPosition(155,260);
    }
    void BattleState2::nickgottaunted(int strength)
    {
        this-> nickCurrentStrength = this -> nickCurrentStrength - strength;
        if(this->nickCurrentStrength < 0)
          this->nickCurrentStrength = 0;
        std::string attack = nickgetCurrentStrength_string();
        this->_NickAttack.setString(attack);
        this->_NickAttack.setCharacterSize(18);
        this->_NickAttack.setPosition(155,260);
    }

    int BattleState2::bossRandomSpell()
    {
         int spell = rand() % 4 +1;
         while(spell > 4 || spell <= 0)
         {
               int spell = rand() % 4 +1;
         }
               return spell;
    }


}
