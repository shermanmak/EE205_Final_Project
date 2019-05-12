#include "BossBattle.hpp"
//#include <stdlib.h>
#include <iostream>

namespace GameEngine
{

        BossBattle::BossBattle( GameDataRef data, std::string bossbattleImg ) : _data( data )
        {
            _bossBattleSprite.setTexture(this->_data->assets.GetTexture(bossbattleImg));
            _bossBattleSprite.setTextureRect(sf::IntRect(0*200, (21*64 + 2*192),200,200));
            _bossBattleSprite.setScale(3,3);

            //set this position if large boss
            _bossBattleSprite.setPosition(300,0);

           /* //status bar
            this->_data->assets.LoadFont("Dialogue", DIALOG_FONT_FILEPATH);
            this->_BossHealth.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_BossHealth.setColor(sf::Color::Black);

            //sets health to start at 100 at each battle
            if(this-> turncount == 0)
                this->bossCurrentHealth = 100;

            std::string health = getCurrentHealth_string();
            this->_BossHealth.setString(health);
            this->_BossHealth.setCharacterSize(18);
            this->_BossHealth.setPosition(165,300);

           this->bossCurrentStrength = 20;


            this->_BossAttack.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_BossAttack.setColor(sf::Color::Black);

            std::string attack = getCurrentStrength_string();
            this->_BossAttack.setString(attack);
            this->_BossAttack.setCharacterSize(18);
            this->_BossAttack.setPosition(165,320);

            */

        }

        BossBattle::~BossBattle()
        {

        }

        void BossBattle::Draw()
        {
            _data ->window.draw(_bossBattleSprite);
            _data ->window.draw(_BossAttack);
            _data ->window.draw(_BossHealth);
        }

        void BossBattle::bossAttackAnimation(float dt)
        {

            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {

                this->source_attack.y= (21*64 + 2*192);
                this->source_attack.x++;
                if(this->source_attack.x > 5)
                {
				    this->source_attack.x=0;
                }
                _bossBattleSprite.setTextureRect(sf::IntRect(source_attack.x*192, source_attack.y,192,192));
                _bossBattleSprite.setPosition(300,0);
                _clock.restart();
            }
       }

       void BossBattle::bossHealAnimation(float dt)
        {
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_heal.y= 2;
                this->source_heal.x++;
                if(this->source_heal.x == 6)
                {
				    this->source_heal.x=0;
                }
                _bossBattleSprite.setTextureRect(sf::IntRect(source_heal.x*64, source_heal.y*64,64,64));
                _bossBattleSprite.setPosition(500,200);
                _clock.restart();
            }
       }

       void BossBattle::bossChargeAnimation(float dt)
        {
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_charge.y= 6;
                this->source_charge.x++;
                if(this->source_charge.x == 7)
                {
				    this->source_charge.x=0;
                }
                _bossBattleSprite.setTextureRect(sf::IntRect(source_charge.x*64, source_charge.y*64,64,64));
                _bossBattleSprite.setPosition(500,200);
                _clock.restart();
            }
       }

       void BossBattle::bossTauntAnimation(float dt)
        {
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_taunt.y= 14;
                this->source_taunt.x++;
                if(this->source_taunt.x == 6)
                {
				    this->source_taunt.x=0;
                }
                _bossBattleSprite.setTextureRect(sf::IntRect(source_taunt.x*64, source_taunt.y*64,64,64));
                _bossBattleSprite.setPosition(300,0);
                _bossBattleSprite.setPosition(500,200);
                _clock.restart();
            }
       }

    void BossBattle::bossResetAnimationPosition()
    {
            _bossBattleSprite.setTextureRect(sf::IntRect(0*200, (21*64 + 2*192),200,200));
            _bossBattleSprite.setScale(3,3);
            //set this position if large nick
            _bossBattleSprite.setPosition(300,0);
            //reset animations if not fully completely
            this->source_attack.x = 0;
            this->source_charge.x = 0;
            this->source_heal.x = 0;
            this->source_taunt.x = 0;

    }

    void BossBattle::bossDeathAnimation(float dt)
     {

       if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
       {
           this->source_taunt.y= 20;
           this->source_taunt.x++;
           if(this->source_taunt.x == 6)
           {
              this->source_taunt.x=0;
           }
           _bossBattleSprite.setTextureRect(sf::IntRect(source_taunt.x*64, source_taunt.y*64,64,64));
           _bossBattleSprite.setPosition(300,0);
           _clock.restart();
       }
    }

   /* //Health  setter
    void BossBattle::setHealth(int health)
    {
        this -> bossCurrentHealth = this->bossCurrentHealth+ health;
        if(this->bossCurrentHealth > 100) //hard setting max health to 100
            this->bossCurrentHealth = 100;
    }
    //Health Getter
    int BossBattle::getCurrentHealth()
    {
        return this-> bossCurrentHealth;
    }
    //Health Getter string
    std::string BossBattle::getCurrentHealth_string()
    {
        int Health =  this-> bossCurrentHealth;

        std::string Health_string = std::to_string(Health);

        return Health_string;

    }

    //Strength setter
    void BossBattle::setStrength(int strength)
    {
        this -> bossCurrentStrength = strength;
    }

    //Strength getter
    int BossBattle::getCurrentStrength()
    {
        return this-> bossCurrentStrength;
    }
    //Strength getter string
    std::string BossBattle::getCurrentStrength_string()
    {
        int Strength = this-> bossCurrentStrength;

        std::string Attack_string = std::to_string(Strength);

        return Attack_string;
    }

    void BossBattle::takeDamage(int damage)
    {
        this-> bossCurrentHealth = this -> bossCurrentHealth - damage;
        std::cout << "DEBUG " << this->bossCurrentHealth << std::endl;
        std::string health = getCurrentHealth_string();
        this->_BossHealth.setString(health);
        this->_BossHealth.setCharacterSize(18);
        this->_BossHealth.setPosition(165,300);

    }*/

}
