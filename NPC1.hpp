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

            void endQuestPos(int positionX, int positionY);


        private:
            GameDataRef _data;

            sf::Sprite _npc1Sprite;



    };

}
