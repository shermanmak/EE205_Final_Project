#include "Item.hpp"

namespace GameEngine
{

    Item::Item( GameDataRef data, int positionX, int positionY, std::string itemImg) : _data( data )
    {
        _itemSprite.setTexture(this->_data->assets.GetTexture(itemImg));
        _itemSprite.setTextureRect(sf::IntRect(0*64, 0*64,64,64));
        _itemSprite.setPosition(positionX,positionY);
        this->Count=0;
    }

    Item::~Item()
    {


    }

    void Item::Draw()
    {
        _data ->window.draw(_itemSprite);

    }

     const sf::Sprite &Item::GetSprite() const
    {
        return _itemSprite;
    }

    void Item::Obtained()
    {
        _itemSprite.setPosition(1000,1000);
    }

}
