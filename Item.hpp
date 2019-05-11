#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class Item
    {
        public:

            Item( GameDataRef data , int positionX, int positionY, std::string imgFile);

            ~Item();

            void Draw();

            const sf::Sprite &GetSprite() const;

            //when character obtains item
            //item will disappear/go out of bounds
            void Obtained();


        private:
            GameDataRef _data;

            sf::Sprite _itemSprite;

            int Count;

    };

}
