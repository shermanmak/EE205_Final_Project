#include "NickBattle.hpp"
#include <iostream>
#include "string"

namespace GameEngine
{

        NickBattle::NickBattle( GameDataRef data ) : _data( data )
        {
            _nickBattleSprite.setTexture(this->_data->assets.GetTexture("Nick Battle Image"));
            _nickBattleSprite.setTextureRect(sf::IntRect(0*200, 21*64,200,200));
            _nickBattleSprite.setScale(3,3);

            //set this position if large nick
            _nickBattleSprite.setPosition(-100,350);

            /*this->_data->assets.LoadFont("Dialogue", DIALOG_FONT_FILEPATH);
            this->_NickHealth.setFont(this->_data->assets.GetFont("Dialogue"));
            this->_NickHealth.setColor(sf::Color::Black);

            //sets health to start at 100 at each battle
            this->nickCurrentHealth = 100;
            std::string health = getCurrentHealth_string();
            this->_NickHealth.setString(health);
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
            std::cout << "DEBUG: NICK CURRENT STRENGTH AT CONSTRUCT" << nickCurrentStrength << std::endl;
            std::string attack = getCurrentStrength_string();
            this->_NickAttack.setString(attack);
            this->_NickAttack.setCharacterSize(18);
            this->_NickAttack.setPosition(155,260);*/


        }

        NickBattle::~NickBattle()
        {

        }

        void NickBattle::Draw()
        {
            _data ->window.draw(_nickBattleSprite);

            //_data->window.draw(_NickHealth);

            //_data->window.draw(_NickAttack);
        }

        void NickBattle::NickAttackAnimation(float dt)
        {
            //set position for big nick
            _nickBattleSprite.setPosition(-100,350);

            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {

                this->source_attack.y= 21;
                this->source_attack.x++;
                if(this->source_attack.x > 5)
                {
				    this->source_attack.x=0;
                }
                _nickBattleSprite.setTextureRect(sf::IntRect(source_attack.x*192, source_attack.y*64,200,200));
                _clock.restart();
            }
       }

       void NickBattle::NickHealAnimation(float dt)
        {
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_heal.y= 0;
                this->source_heal.x++;
                if(this->source_heal.x == 6)
                {
				    this->source_heal.x=0;
                }
                _nickBattleSprite.setTextureRect(sf::IntRect(source_heal.x*64, source_heal.y*64,64,64));
                _nickBattleSprite.setPosition(90,520);
                _clock.restart();
            }
       }

       void NickBattle::NickChargeAnimation(float dt)
        {
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_charge.y= 4;
                this->source_charge.x++;
                if(this->source_charge.x == 7)
                {
				    this->source_charge.x=0;
                }
                _nickBattleSprite.setTextureRect(sf::IntRect(source_charge.x*64, source_charge.y*64,64,64));
                _nickBattleSprite.setPosition(90,520);
                _clock.restart();
            }
       }

       void NickBattle::NickTauntAnimation(float dt)
        {
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_taunt.y= 12;
                this->source_taunt.x++;
                if(this->source_taunt.x == 6)
                {
				    this->source_taunt.x=0;
                }
                _nickBattleSprite.setTextureRect(sf::IntRect(source_taunt.x*64, source_taunt.y*64,64,64));
                _nickBattleSprite.setPosition(90,520);
                _clock.restart();
            }
       }

    void NickBattle::NickResetAnimationPosition()
    {
            _nickBattleSprite.setTextureRect(sf::IntRect(0*200, 21*64,200,200));
            _nickBattleSprite.setScale(3,3);
            //set this position if large nick
            _nickBattleSprite.setPosition(-100,350);

            //reset animations if not fully completely
            this->source_attack.x = 0;
            this->source_charge.x = 0;
            this->source_heal.x = 0;
            this->source_taunt.x = 0;

    }

    void NickBattle::NickDeathAnimation(float dt)
     {

       if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
       {
           this->source_taunt.y= 20;
           this->source_taunt.x++;
           if(this->source_taunt.x == 6)
           {
              this->source_taunt.x=0;
           }
           _nickBattleSprite.setTextureRect(sf::IntRect(source_taunt.x*64, source_taunt.y*64,64,64));
           _nickBattleSprite.setPosition(90,520);
           _clock.restart();
       }
    }
    /* //Health  setter
    void NickBattle::setHealth(int health)
    {
        this -> nickCurrentHealth = this->nickCurrentHealth+ health;
        if(this->nickCurrentHealth > 100) //hard setting max health to 100
            this->nickCurrentHealth = 100;
    }
    //Health Getter
    std::string NickBattle::getCurrentHealth_string()
    {
        int Health =  this-> nickCurrentHealth;

        std::string Health_string = std::to_string(Health);

        return Health_string;

    }
    int NickBattle::getCurrentHealth()
    {
        return this-> nickCurrentHealth;
    }

    //Strength setter
    void NickBattle::setStrength(int strength)
    {
        this -> nickCurrentStrength = strength;
    }

    //Strength getter string
    std::string NickBattle::getCurrentStrength_string()
    {
        int Strength = this-> nickCurrentStrength;

        std::string Attack_string = std::to_string(Strength);

        return Attack_string;
    }

    int NickBattle::getCurrentStrength()
    {
        return this -> nickCurrentStrength;
    }*/

}
