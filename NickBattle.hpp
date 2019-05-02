#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "string"

namespace GameEngine
{
    class NickBattle
    {
        public:

            NickBattle() {}

            NickBattle( GameDataRef data );

            ~NickBattle();

            void Draw();

            //Health
           // void setHealth(int health);
           // std::string getCurrentHealth_string();
           // int getCurrentHealth();

            //Strength
            //void setStrength(int strength);
            //std::string getCurrentStrength_string();
            //int getCurrentStrength();

            void NickAttackAnimation(float dt);

            void NickHealAnimation(float dt);

            void NickTauntAnimation(float dt);

            void NickChargeAnimation(float dt);

            void NickResetAnimationPosition();

            void NickDeathAnimation(float dt);

            sf::Vector2i source_attack;

            sf::Vector2i source_heal;

            sf::Vector2i source_taunt;

              sf::Vector2i source_death;

            sf::Vector2i source_charge;

            int battleswon = 0;

            //int nickCurrentHealth;

            //int nickCurrentStrength;

        private:
            GameDataRef _data;

            sf::Sprite _nickBattleSprite;

            sf::Clock _clock;


          //  sf::Text _NickHealth;
          //  sf::Text _NickAttack;

    };
}
