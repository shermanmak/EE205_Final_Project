#include "NPC.hpp"

namespace GameEngine
{

    NPC::NPC( GameDataRef data, int xPos, int yPos, std::string npcImg, int spriteDirection ) : _data( data )
    {
        _npcSprite.setTexture(this->_data->assets.GetTexture(npcImg));
        _npcSprite.setTextureRect(sf::IntRect(0*64,spriteDirection*64,64,64));
        _npcSprite.setPosition(xPos, yPos);
    }

    NPC::~NPC()
    {


    }

    void NPC::Draw()
    {
        _data ->window.draw(_npcSprite);

    }

     const sf::Sprite &NPC::GetSprite() const
    {
        return _npcSprite;
    }

    void NPC::endQuestPos(int positionX, int positionY)
    {
        _npcSprite.setPosition(positionX, positionY);
    }

}
