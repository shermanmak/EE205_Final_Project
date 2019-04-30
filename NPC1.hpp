#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class NPC1
    {
        public:

            NPC1( GameDataRef data );

            ~NPC1();

            void Draw();

            const sf::Sprite &GetSprite() const;


        private:
            GameDataRef _data;

            sf::Sprite _npc1Sprite;

    };

}
