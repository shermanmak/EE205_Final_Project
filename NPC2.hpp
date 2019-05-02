#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class NPC2
    {
        public:

            NPC2( GameDataRef data );

            ~NPC2();

            void Draw();

            const sf::Sprite &GetSprite() const;

            void endQuestPos(int positionX, int positionY);


        private:
            GameDataRef _data;

            sf::Sprite _npc1Sprite;



    };

}
