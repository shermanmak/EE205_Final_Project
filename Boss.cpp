#include "Boss.hpp"

namespace GameEngine
{

    Boss1::Boss1( GameDataRef data, std::string ImageName ) : _data( data )
    {
        _boss1Sprite.setTexture(this->_data->assets.GetTexture(ImageName));
        _boss1Sprite.setTextureRect(sf::IntRect(0*64, 11*64,64,64));
        _boss1Sprite.setPosition(0,(800-64));
    }

    Boss1::~Boss1()
    {


    }

    void Boss1::Draw()
    {
        _data ->window.draw(_boss1Sprite);

    }

    const sf::Sprite &Boss1::GetSprite() const
    {
        return _boss1Sprite;
    }


}
