#pragma once
#include <SFML/Graphics.hpp>


#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "string"

namespace GameEngine
{
    class BossBattle
    {
        public:
           // BossBattle(){}

            BossBattle( GameDataRef data, std::string bossbattleImg );

            ~BossBattle();

            void Draw();

           /* //Health
            void bosssetHealth(int health);
            void bosstakeDamage(int damage);
            int bossgetCurrentHealth();
            std::string bossgetCurrentHealth_string();


            //Strength
            void bosssetStrength(int strength);
            int bossgetCurrentStrength();
            std::string bossgetCurrentStrength_string();*/


           // int RandomAnimationGenerator();

            void bossAttackAnimation(float dt);

            void bossHealAnimation(float dt);

            void bossTauntAnimation(float dt);

            void bossChargeAnimation(float dt);

            void bossDeathAnimation(float dt);

            void bossResetAnimationPosition();

            sf::Vector2i source_attack;

            sf::Vector2i source_heal;

            sf::Vector2i source_taunt;

            sf::Vector2i source_charge;

            int bossCurrentHealth;
            int bossCurrentStrength;
            int turncount = 0;


        private:
            GameDataRef _data;

            sf::Sprite _bossBattleSprite;

            sf::Clock _clock;

            int Level;

            sf::Text _BossHealth;
            sf::Text _BossAttack;





    };
}
