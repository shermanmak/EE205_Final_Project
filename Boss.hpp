#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class Boss1
    {
        public:

            Boss1( GameDataRef data, std::string ImageName );

            ~Boss1();

            void Draw();

            const sf::Sprite &GetSprite() const;


        private:
            GameDataRef _data;


            sf::Sprite _boss1Sprite;

    };

}
