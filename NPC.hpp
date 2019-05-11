#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GameEngine
{
    class NPC
    {
        public:

            NPC( GameDataRef data, int xPos, int yPos, std::string npcImg, int spriteDirection );

            ~NPC();

            void Draw();

            const sf::Sprite &GetSprite() const;

            void endQuestPos(int positionX, int positionY);


        private:
            GameDataRef _data;

            sf::Sprite _npcSprite;



    };

}
