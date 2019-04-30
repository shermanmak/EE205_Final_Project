#include "IntroChad.hpp"

namespace GameEngine
{

    IntroChad::IntroChad( GameDataRef data ) : _data( data )
    {
        _IntroChadSprite.setTexture(this->_data->assets.GetTexture("Intro Chad Image"));
        //how to change the crop of picture
        //_IntroChadSprite.setTextureRect(sf::IntRect(0*64, 2*64,64,64));
        _IntroChadSprite.setScale(1,1);
        _IntroChadSprite.setPosition(-35,(0));
    }

    IntroChad::~IntroChad()
    {


    }

    void IntroChad::Draw()
    {
        _data ->window.draw(_IntroChadSprite);

    }

     const sf::Sprite &IntroChad::GetSprite() const
    {
        return _IntroChadSprite;
    }


}