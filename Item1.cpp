#include "Item1.hpp"

namespace GameEngine
{

    Item1::Item1( GameDataRef data, int positionX, int positionY ) : _data( data )
    {
        _item1Sprite.setTexture(this->_data->assets.GetTexture("Item 1 Image"));
        _item1Sprite.setTextureRect(sf::IntRect(0*64, 0*64,64,64));
        _item1Sprite.setPosition(positionX,positionY);
    }

    Item1::~Item1()
    {


    }

    void Item1::Draw()
    {
        _data ->window.draw(_item1Sprite);

    }

     const sf::Sprite &Item1::GetSprite() const
    {
        return _item1Sprite;
    }

    void Item1::Obtained()
    {
        _item1Sprite.setPosition(1000,1000);
    }

}
