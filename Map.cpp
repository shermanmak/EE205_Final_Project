#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

namespace GameEngine
{
    Map::Map()
    {

    }

     Map::Map( GameDataRef data ) : _data( data )
    {
        _tilemap.setTexture(this->_data->assets.GetTexture("Tile"));

    }
    void Map::Draw_1()
    {
        for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++ )
            {
			    if(TileLocation_Map1[i][j] != 0)
                {
                    _tilemap.setPosition(j*50, i*50);
                    _data ->window.draw(_tilemap);
                    //adds sprites to vector
            //        _tilevector.push_back(_tilemap);
                }
            }
        }
    }

    void Map::Draw_2()
    {
        for(int i = 0; i < 16; i++)
    {
      for(int j = 0; j < 16; j++ )
            {
          if(TileLocation_Map2[i][j] != 0)
                {
                    _tilemap.setPosition(j*50, i*50);
                    _data ->window.draw(_tilemap);
                    //adds sprites to vector
            //        _tilevector.push_back(_tilemap);
                }
            }
        }
    }

    Map::~Map()
    {

    }

    //returns vector of sprites
    const std::vector<sf::Sprite> &Map::GetSprites() const
    {

        return _tilevector;
    }


}
