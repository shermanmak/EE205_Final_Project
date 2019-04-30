#include "NPC1.hpp"

namespace GameEngine
{

    NPC1::NPC1( GameDataRef data ) : _data( data )
    {
        _npc1Sprite.setTexture(this->_data->assets.GetTexture("NPC 1 Image"));
        _npc1Sprite.setTextureRect(sf::IntRect(0*64,10*64,64,64));
        _npc1Sprite.setPosition(575,350);
    }

    NPC1::~NPC1()
    {


    }

    void NPC1::Draw()
    {
        _data ->window.draw(_npc1Sprite);

    }

     const sf::Sprite &NPC1::GetSprite() const
    {
        return _npc1Sprite;
    }


}
