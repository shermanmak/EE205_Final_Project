#include "NickBattle.hpp"
#include <iostream>

namespace GameEngine
{
        NickBattle::NickBattle( GameDataRef data ) : _data( data )
        {
            _nickBattleSprite.setTexture(this->_data->assets.GetTexture("Nick Battle Image"));
            _nickBattleSprite.setTextureRect(sf::IntRect(0*200, 21*64,200,200));
            _nickBattleSprite.setScale(3,3);

            //set this position if large nick
            _nickBattleSprite.setPosition(-100,350);

    
        }

        NickBattle::~NickBattle()
        {

        }

        void NickBattle::Draw()
        {
            _data ->window.draw(_nickBattleSprite);
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
     //Health  setter
    void NickBattle::setHealth(int health)
    {
        this -> CurrentHealth = this->CurrentHealth+ health;
        if(this->CurrentHealth > 100) //hard setting max health to 100
            this->CurrentHealth = 100;
    }
    //Health Getter
    int NickBattle::getCurrentHealth()
    {
        return this-> CurrentHealth;
    }

    //Strength setter
    void NickBattle::setStrength(int strength)
    {
        this -> CurrentStrength = strength;
    }

    //Strength getter
    int NickBattle::getCurrentStrength()
    {
        return this-> CurrentStrength;
    }



}