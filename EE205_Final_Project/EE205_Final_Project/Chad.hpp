#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class Chad
    {
        public:

            Chad( GameDataRef data );
           
            ~Chad();

            void Draw();

            const sf::Sprite &GetSprite() const;


        private:
            GameDataRef _data;

            sf::Sprite _chadSprite;

    };

}