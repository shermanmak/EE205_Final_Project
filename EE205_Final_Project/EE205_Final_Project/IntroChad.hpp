#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class IntroChad
    {
        public:

            IntroChad( GameDataRef data );
           
            ~IntroChad();

            void Draw();

            const sf::Sprite &GetSprite() const;


        private:
            GameDataRef _data;

            sf::Sprite _IntroChadSprite;

    };

}