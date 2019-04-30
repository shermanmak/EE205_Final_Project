#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class Boss1Battle
    {
        public:
            Boss1Battle( GameDataRef data );

            ~Boss1Battle();

            void Draw();

            //Health 
            void setHealth(int health);
            int getCurrentHealth();

            //Strength
            void setStrength(int strength);
            int getCurrentStrength();



           // int RandomAnimationGenerator();

            void bossAttackAnimation(float dt);

            void bossHealAnimation(float dt);
            
            void bossTauntAnimation(float dt);
            
            void bossChargeAnimation(float dt);

            void bossResetAnimationPosition();
            
            sf::Vector2i source_attack;

            sf::Vector2i source_heal;

            sf::Vector2i source_taunt;

            sf::Vector2i source_charge;

        
        private:
            GameDataRef _data;

            sf::Sprite _boss1BattleSprite;

            sf::Clock _clock;

            int CurrentHealth;
            int CurrentStrength;


    };
}