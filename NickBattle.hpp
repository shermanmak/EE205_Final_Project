#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class NickBattle
    {
        public:
            NickBattle( GameDataRef data );

            ~NickBattle();

            void Draw();

            //Health 
            void setHealth(int health);
            int getCurrentHealth();

            //Strength
            void setStrength(int strength);
            int getCurrentStrength();

            void NickAttackAnimation(float dt);

            void NickHealAnimation(float dt);
            
            void NickTauntAnimation(float dt);
            
            void NickChargeAnimation(float dt);

            void NickResetAnimationPosition();
            
            sf::Vector2i source_attack;

            sf::Vector2i source_heal;

            sf::Vector2i source_taunt;

            sf::Vector2i source_charge;

        
        private:
             GameDataRef _data;

            sf::Sprite _nickBattleSprite;

            sf::Clock _clock;
            int CurrentHealth;
            int CurrentStrength;

    };
}