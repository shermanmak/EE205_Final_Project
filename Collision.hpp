#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
#include "Map.hpp"


namespace GameEngine
{
    class Collision : public Map
    {
        public:
            Collision();
            ~Collision();

            bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);

            bool CheckWallCollision_map1(sf::Sprite sprite1);

            bool CheckWallCollision_map2(sf::Sprite sprite1);

    };

}
