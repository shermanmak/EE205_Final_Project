#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class Item1
    {
        public:

            Item1( GameDataRef data );

            ~Item1();

            void Draw();

            const sf::Sprite &GetSprite() const;

            //when character obtains item
            //item will disappear/go out of bounds
            void Obtained();


        private:
            GameDataRef _data;

            sf::Sprite _item1Sprite;

            int possess;

    };

}
