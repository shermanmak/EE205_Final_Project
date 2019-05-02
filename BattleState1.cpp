#pragma once

#include <sstream>
#include <iostream>
#include "BattleState1.hpp"
//#include "GameOverState.hpp"
#include "GameState2.hpp"
#include "string"
#include <stdio.h>
#include <stdlib.h>

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

          //you win/lose icons


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
            if(battleswon == 0)
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
            }
           // std::cout << "DEBUG: NICK CURRENT STRENGTH AT CONSTRUCT" << nickCurrentStrength << std::endl;
            std::string nickattack = nickgetCurrentStrength_string();
            this->_NickAttack.setString(nickattack);
            this->_NickAttack.setCharacterSize(18);
            this->_NickAttack.setPosition(155,260);

            this->_data->assets.LoadFont("Dialogue", DIALOG_FONT_FILEPATH);
            this->_BossHealth.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_BossHealth.setColor(sf::Color::Black);

            //sets health to start at 100 at each battle
          this->bossCurrentHealth = 100;

            std::string bosshealth = bossgetCurrentHealth_string();
            this->_BossHealth.setString(bosshealth);
            this->_BossHealth.setCharacterSize(18);
            this->_BossHealth.setPosition(165,300);

           this->bossCurrentStrength = 20;


            this->_BossAttack.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_BossAttack.setColor(sf::Color::Black);

            std::string bossattack = bossgetCurrentStrength_string();
            this->_BossAttack.setString(bossattack);
            this->_BossAttack.setCharacterSize(18);
            this->_BossAttack.setPosition(165,320);




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
               //*******************************ATTACK***********************
               if (this->_data->input.IsSpriteClicked(this->_AttackButton, sf::Mouse::Left, this->_data->window) && this->nickANIMATIONCOUNTER <= 0
                    && this-> bossANIMATIONCOUNTER <= 0)
			{
                    std::cout << "Attack button was clicked" << std::endl;

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
                    std::cout << "Attack button was clicked" << std::endl;

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
                    std::cout << "Attack button was clicked" << std::endl;

                    this-> nickCHARGEANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;

                    //Charge Strength
                    nickChargeStrength(nickCurrentStrength);

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
                    std::cout << "Attack button was clicked" << std::endl;

                    this-> nickTAUNTANIMATEFLAG = 1;
                    this-> nickANIMATIONCOUNTER = 50;

                    //taunt boss
                    bossgottaunted(nickCurrentStrength);

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

     void BattleState1::Update(float dt)
     {
          //ATTACK ANIMATION
          if(this->nickATTACKANIMATEFLAG == 1)
          {
               if(this->nickANIMATIONCOUNTER > 0)
               {
                    nickbattle->NickAttackAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                   std::cout <<"Nick time: " <<nickANIMATIONCOUNTER << std::endl;
               }
               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              boss1battle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              boss1battle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              boss1battle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              boss1battle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
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
                    std::cout <<"Nick time Heal: " <<nickANIMATIONCOUNTER << std::endl;
               }

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickHEALANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              boss1battle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              boss1battle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              boss1battle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              boss1battle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
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
                    nickbattle->NickAttackAnimation(dt);

                    this->nickANIMATIONCOUNTER = this->nickANIMATIONCOUNTER -1;
                   std::cout <<"Nick time Charge: " <<nickANIMATIONCOUNTER << std::endl;
               }
               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              boss1battle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              boss1battle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              boss1battle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              boss1battle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
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
                    std::cout <<"Nick time Taunt: " <<nickANIMATIONCOUNTER << std::endl;
               }

               if(this->nickANIMATIONCOUNTER <= 0)
               {
                    //this->nickATTACKANIMATEFLAG = 0;
                    nickbattle->NickResetAnimationPosition();

                    if(this->bossANIMATIONCOUNTER > 0)
                    {
                         this->bossANIMATIONCOUNTER = this->bossANIMATIONCOUNTER -1;
                         std::cout << "Boss time: " <<bossANIMATIONCOUNTER << std::endl;
                         if(this->BossAttackFlag == 1)
                              boss1battle->bossAttackAnimation(dt);
                         if(this->BossHealFlag == 1)
                              boss1battle->bossHealAnimation(dt);
                         if(this->BossChargeFlag == 1)
                              boss1battle->bossChargeAnimation(dt);
                         if(this->BossTauntFlag == 1)
                              boss1battle->bossTauntAnimation(dt);

                    }
                    if(this->bossANIMATIONCOUNTER <= 0)
                    {
                         boss1battle->bossResetAnimationPosition();
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

          /*
          if(nickCurrentHealth == 0)
               std::cout << "go to game over state" << std::endl;
          if(bossCurrentHealth == 0)
               std::cout << "go to next world" << std::endl;*/

          if(bossCurrentHealth == 0)
          {
               this->_data->machine.AddState(StateRef(new GameState2(this->_data)), true);
               std::cout <<"go to game over state" <<std::endl;

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
          this->_data->window.draw(this->_statusBar);

          this->_data->window.draw(_NickHealth);
          this->_data->window.draw(_NickAttack);
          this->_data->window.draw(_BossAttack);
          this->_data->window.draw(_BossHealth);

          nickbattle->Draw();

          boss1battle->Draw();

		this->_data->window.display();

     }

     void BattleState1::CheckifBattleisWon()
     {


      //    if(Nick_health < 0)
      //         std::cout<< "you lose, go to game over state" << std::endl;
      //    else if(Boss_health < 0)
      //         std::cout<< "you win, go to next map" << std::endl;

     }

     //Health  setter
    void BattleState1::nicksetHealth(int health)
    {
        this -> nickCurrentHealth = this->nickCurrentHealth+ health;
        if(this->nickCurrentHealth > 100) //hard setting max health to 100
            this->nickCurrentHealth = 100;
    }
    //Health Getter
    std::string BattleState1::nickgetCurrentHealth_string()
    {
        int Health =  this-> nickCurrentHealth;

        std::string Health_string = std::to_string(Health);

        return Health_string;

    }
    int BattleState1::nickgetCurrentHealth()
    {
        return this-> nickCurrentHealth;
    }

    //Strength setter
    void BattleState1::nicksetStrength(int strength)
    {
        this -> nickCurrentStrength = strength;
    }

    //Strength getter string
    std::string BattleState1::nickgetCurrentStrength_string()
    {
        int Strength = this-> nickCurrentStrength;

        std::string Attack_string = std::to_string(Strength);

        return Attack_string;
    }

    int BattleState1::nickgetCurrentStrength()
    {
        return this -> nickCurrentStrength;
    }

    //Health  setter
    void BattleState1::bosssetHealth(int health)
    {
        this -> bossCurrentHealth = this->bossCurrentHealth+ health;
        if(this->bossCurrentHealth > 100) //hard setting max health to 100
            this->bossCurrentHealth = 100;
    }
    //Health Getter
    int BattleState1::bossgetCurrentHealth()
    {
        return this-> bossCurrentHealth;
    }
    //Health Getter string
    std::string BattleState1::bossgetCurrentHealth_string()
    {
        int Health =  this-> bossCurrentHealth;

        std::string Health_string = std::to_string(Health);

        return Health_string;

    }

    //Strength setter
    void BattleState1::bosssetStrength(int strength)
    {
        this -> bossCurrentStrength = strength;
    }

    //Strength getter
    int BattleState1::bossgetCurrentStrength()
    {
        return this-> bossCurrentStrength;
    }
    //Strength getter string
    std::string BattleState1::bossgetCurrentStrength_string()
    {
        int Strength = this-> bossCurrentStrength;

        std::string Attack_string = std::to_string(Strength);

        return Attack_string;
    }

    void BattleState1::bosstakeDamage(int damage)
    {
        this-> bossCurrentHealth = this -> bossCurrentHealth - damage;
          if(this->bossCurrentHealth < 0)
               this->bossCurrentHealth = 0;
        std::string health = bossgetCurrentHealth_string();
        this->_BossHealth.setString(health);
        this->_BossHealth.setCharacterSize(18);
        this->_BossHealth.setPosition(165,300);

    }
    void BattleState1::bossHealHealth(int heal)
    {
        this-> bossCurrentHealth = this -> bossCurrentHealth + heal;
        std::string health = bossgetCurrentHealth_string();
        this->_BossHealth.setString(health);
        this->_BossHealth.setCharacterSize(18);
        this->_BossHealth.setPosition(165,300);
    }
    void BattleState1::bossChargeStrength(int strength)
    {
        this-> bossCurrentStrength = this -> bossCurrentStrength + strength;
        if(this->bossCurrentStrength < 0)
          this->bossCurrentStrength = 0;
        std::string attack = bossgetCurrentStrength_string();
        this->_BossAttack.setString(attack);
        this->_BossAttack.setCharacterSize(18);
        this->_BossAttack.setPosition(165,320);
    }
    void BattleState1::bossgottaunted(int strength)
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
     void BattleState1::nicktakedamage(int damage)
    {
        this-> nickCurrentHealth = this -> nickCurrentHealth - damage;
        std::string health = nickgetCurrentHealth_string();
        this->_NickHealth.setString(health);
        this->_NickHealth.setCharacterSize(18);
        this->_NickHealth.setPosition(155,240);

    }
    void BattleState1::nickHealHealth(int heal)
    {
        this-> nickCurrentHealth = this -> nickCurrentHealth + heal;
        std::string health = bossgetCurrentHealth_string();
        this->_NickHealth.setString(health);
        this->_NickHealth.setCharacterSize(18);
        this->_NickHealth.setPosition(155,240);
    }
    void BattleState1::nickChargeStrength(int strength)
    {
        this-> nickCurrentStrength = this -> nickCurrentStrength + strength;
        std::string attack = nickgetCurrentStrength_string();
        this->_NickAttack.setString(attack);
        this->_NickAttack.setCharacterSize(18);
        this->_NickAttack.setPosition(155,260);
    }
    void BattleState1::nickgottaunted(int strength)
    {
        this-> nickCurrentStrength = this -> nickCurrentStrength - strength;
        if(this->nickCurrentStrength < 0)
          this->nickCurrentStrength = 0;
        std::string attack = nickgetCurrentStrength_string();
        this->_NickAttack.setString(attack);
        this->_NickAttack.setCharacterSize(18);
        this->_NickAttack.setPosition(155,260);
    }

    int BattleState1::bossRandomSpell()
    {
         int spell = rand() % 4 +1;
         while(spell > 4 || spell <= 0)
         {
               int spell = rand() % 4 +1;
         }
               return spell;
    }


}
