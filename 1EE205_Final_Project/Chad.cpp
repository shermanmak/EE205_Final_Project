#include "Chad.hpp"

namespace GameEngine
{

    Chad::Chad( GameDataRef data ) : _data( data )
    {
        _chadSprite.setTexture(this->_data->assets.GetTexture("Chad Image"));
        //how to change the crop of picture
        _chadSprite.setTextureRect(sf::IntRect(0*64, 2*64,64,64));
        //_chadSprite.setScale(1,1);
        _chadSprite.setPosition(20,(400-64));
    }

    Chad::~Chad()
    {


    }

    void Chad::Draw()
    {
        _data ->window.draw(_chadSprite);

    }

     const sf::Sprite &Chad::GetSprite() const
    {
        return _chadSprite;
    }


}