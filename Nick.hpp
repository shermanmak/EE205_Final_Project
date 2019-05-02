#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"


namespace GameEngine
{
    class Nick
    {
        public:

            Nick( GameDataRef data );

            ~Nick();

            void Draw();

            void Animate( );

            void MoveRight( );

            void MoveLeft( );

            void MoveUp();

            void MoveDown();

            void StayonScreen();

            void CollisionRight();

            void CollisionLeft();

            void CollisionUp();

            void CollisionDown();

            const sf::Sprite &GetSprite() const;


            sf::Vector2i source;

            sf::Vector2f position  = _nickSprite.getPosition();

            void FindFruit();

            int GetFruit();

        private:
            GameDataRef _data;

            sf::Sprite _nickSprite;

            sf::Clock _clock;

            sf::Clock _movementClock;

            int fruit;

    };
}
