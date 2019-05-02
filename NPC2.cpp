#include "NPC2.hpp"

namespace GameEngine
{

    NPC2::NPC2( GameDataRef data ) : _data( data )
    {
        _npc1Sprite.setTexture(this->_data->assets.GetTexture("NPC 2 Image"));
        _npc1Sprite.setTextureRect(sf::IntRect(0*64,4*64,64,64));
        _npc1Sprite.setPosition(3*50-10,6*50);
    }

    NPC2::~NPC2()
    {


    }

    void NPC2::Draw()
    {
        _data ->window.draw(_npc1Sprite);

    }

     const sf::Sprite &NPC2::GetSprite() const
    {
        return _npc1Sprite;
    }

    void NPC2::endQuestPos(int positionX, int positionY)
    {
        _npc1Sprite.setPosition(positionX, positionY);
    }

}
