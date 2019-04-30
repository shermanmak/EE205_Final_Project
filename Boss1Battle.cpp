#include "Boss1Battle.hpp"
//#include <stdlib.h>
#include <iostream>

namespace GameEngine
{
        Boss1Battle::Boss1Battle( GameDataRef data ) : _data( data )
        {
            _boss1BattleSprite.setTexture(this->_data->assets.GetTexture("Boss 1 Battle Image"));
            _boss1BattleSprite.setTextureRect(sf::IntRect(0*200, (21*64 + 2*192),200,200));
            _boss1BattleSprite.setScale(3,3);

            //set this position if large boss
            _boss1BattleSprite.setPosition(300,0);
            

    
        }

        Boss1Battle::~Boss1Battle()
        {

        }

        void Boss1Battle::Draw()
        {
            _data ->window.draw(_boss1BattleSprite);
        }

        void Boss1Battle::bossAttackAnimation(float dt)
        {            
            
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {

                this->source_attack.y= (21*64 + 2*192);
                this->source_attack.x++;
                if(this->source_attack.x > 5)
                {
				    this->source_attack.x=0;
                }
                _boss1BattleSprite.setTextureRect(sf::IntRect(source_attack.x*192, source_attack.y,192,192));
                _boss1BattleSprite.setPosition(300,0);
                _clock.restart();
            } 
       }

       void Boss1Battle::bossHealAnimation(float dt)
        {            
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_heal.y= 2;
                this->source_heal.x++;
                if(this->source_heal.x == 6)
                {
				    this->source_heal.x=0;
                }
                _boss1BattleSprite.setTextureRect(sf::IntRect(source_heal.x*64, source_heal.y*64,64,64));
                _boss1BattleSprite.setPosition(500,200);
                _clock.restart();
            } 
       }

       void Boss1Battle::bossChargeAnimation(float dt)
        {            
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_charge.y= 6;
                this->source_charge.x++;
                if(this->source_charge.x == 7)
                {
				    this->source_charge.x=0;
                }
                _boss1BattleSprite.setTextureRect(sf::IntRect(source_charge.x*64, source_charge.y*64,64,64));
                _boss1BattleSprite.setPosition(500,200);
                _clock.restart();
            } 
       }

       void Boss1Battle::bossTauntAnimation(float dt)
        {            
            if (_clock.getElapsedTime().asSeconds() > ( .7 / 5))
            {
                this->source_taunt.y= 14;
                this->source_taunt.x++;
                if(this->source_taunt.x == 6)
                {
				    this->source_taunt.x=0;
                }
                _boss1BattleSprite.setTextureRect(sf::IntRect(source_taunt.x*64, source_taunt.y*64,64,64));
                _boss1BattleSprite.setPosition(300,0);
                _boss1BattleSprite.setPosition(500,200);
                _clock.restart();
            } 
       }
        
    void Boss1Battle::bossResetAnimationPosition()
    {
            _boss1BattleSprite.setTextureRect(sf::IntRect(0*200, (21*64 + 2*192),200,200));
            _boss1BattleSprite.setScale(3,3);
            //set this position if large nick
            _boss1BattleSprite.setPosition(300,0);
            //reset animations if not fully completely
            this->source_attack.x = 0;
            this->source_charge.x = 0;
            this->source_heal.x = 0;
            this->source_taunt.x = 0;

    }

    //Health  setter
    void Boss1Battle::setHealth(int health)
    {
        this -> CurrentHealth = this->CurrentHealth+ health;
        if(this->CurrentHealth > 100) //hard setting max health to 100
            this->CurrentHealth = 100;
    }
    //Health Getter
    int Boss1Battle::getCurrentHealth()
    {
        return this-> CurrentHealth;
    }

    //Strength setter
    void Boss1Battle::setStrength(int strength)
    {
        this -> CurrentStrength = strength;
    }

    //Strength getter
    int Boss1Battle::getCurrentStrength()
    {
        return this-> CurrentStrength;
    }


}