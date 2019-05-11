#include "Nick.hpp"
#include <iostream>

namespace GameEngine
{

    Nick::Nick( GameDataRef data ) : _data( data )
    {
        _nickSprite.setTexture(this->_data->assets.GetTexture("Nick Image"));
        _nickSprite.setTextureRect(sf::IntRect(1*64, 10*64,64,64));
        this->fruit=0;
    }

    void Nick::Draw()
    {
        _data ->window.draw(_nickSprite);
    }
    Nick::~Nick()
    {

    }

    void Nick::MoveDown()
    {

        this->source.y = WALK_DOWN;
		    _nickSprite.move(0,7);
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));
       // std::cout << "moved down" << std::endl;
       // std::cout << "X =" << _nickSprite.getPosition().x << " Y = " << _nickSprite.getPosition().y << std::endl;



    }

    void Nick::MoveLeft()
    {

        this->source.y = WALK_LEFT;
		_nickSprite.move(-7,0);
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));
       // std::cout << "moved left" << std::endl;
       // std::cout << "X =" << _nickSprite.getPosition().x << " Y = " << _nickSprite.getPosition().y << std::endl;



    }

    void Nick::MoveRight()
    {

        this->source.y = WALK_RIGHT;
		_nickSprite.move(7,0);
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));
        //std::cout << "moved right" << std::endl;
        //std::cout << "X =" << _nickSprite.getPosition().x << " Y = " << _nickSprite.getPosition().y << std::endl;



    }

    void Nick::MoveUp()
    {

        this->source.y = WALK_UP;
		_nickSprite.move(0,-7);
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));
        //std::cout << "moved up" << std::endl;
        //std::cout << "X =" << _nickSprite.getPosition().x << " Y = " << _nickSprite.getPosition().y << std::endl;


    }


    void Nick::CollisionRight()
    {
        this->source.y = WALK_RIGHT;
		_nickSprite.move(-7,0);
       // std::cout << "Collision Right" << std::endl;
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));


    }

    void Nick::CollisionLeft()
    {
         this->source.y = WALK_LEFT;
		_nickSprite.move(7,0);
       // std::cout << "Collision Left" << std::endl;
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));

    }

    void Nick::CollisionUp()
    {
        this->source.y = WALK_UP;
		    _nickSprite.move(0,7);
       // std::cout << "Collision Up" << std::endl;
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));

    }

    void Nick::CollisionDown()
    {
        this->source.y = WALK_DOWN;
		_nickSprite.move(0,-7);
        //std::cout << "Collision Down" << std::endl;
        _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));

    }

    void Nick::StayonScreen()
    {
        //adapt the position of the Nick if going off the screen
			sf::Vector2f position = _nickSprite.getPosition();
            if(position.x > SCREEN_WIDTH - 64)
                position.x = SCREEN_WIDTH - 64;
            if(position.x < 0)
                position.x = 0;
            if(position.y > SCREEN_HEIGHT - 64)
                position.y = SCREEN_HEIGHT - 64;
            if(position.y < 0)
                position.y = 0;
			_nickSprite.setPosition(position);

    }

    const sf::Sprite &Nick::GetSprite() const
    {
        return _nickSprite;
    }

    void Nick::FindFruit()
    {
      this->fruit++;
    }

    int Nick::GetFruit()
    {
      return fruit;
    }

    void Nick::Animate( )
    {
       if (_clock.getElapsedTime().asSeconds() > NICK_ANIMATION_DURATION / 9) //Using 9 because there are 9 animation images
		{
				this->source.x++;
				if(this->source.x *64 >= 576)
				this->source.x=0;
                _nickSprite.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));

                _clock.restart();


        }
    }

}
