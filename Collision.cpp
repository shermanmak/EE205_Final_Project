#include "Collision.hpp"
#include <iostream>

namespace GameEngine
{
    Collision::Collision()
    {

    }
    Collision::~Collision()
    {

    }

    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
    {
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();

        if(rect1.intersects(rect2))
        {
            std::cout << "objects are touching" << std::endl;
            return true;
        }
        else
        {
            return false;
            std::cout<<"objects are not touching" << std::endl;
        }

    }

    bool Collision::CheckWallCollision_map1(sf::Sprite sprite1)
    {

        int return_flag = 0;

        for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++ )
            {
                int bottom, top, left, right;

                    bottom = j*50 + 50;
                    top = j*50;
                    right = i*50 + 50;
                    left = i*50;
                if(TileLocation_Map1[j][i] == 1)
                {
                 //   std::cout <<"Bot = " << bottom << "Top = " << top << "Right = " << right << "Left = " << left <<std::endl;

                    if((sprite1.getGlobalBounds().left + 44 < left) //right
                        || (sprite1.getGlobalBounds().left + 20  > right) //left
                        || (sprite1.getGlobalBounds().top + 20 > bottom) //top
                        || (sprite1.getGlobalBounds().top + 64 < top)) //bottom
                        {
                            return_flag = 0;
                 //           std::cout << "Flag = 0" << std::endl;

                        }
                    else
                    {
                        return_flag = 1;
                 //       std::cout <<"FLAG = 1" << std::endl;
                        break;
                    }
                }

            }
            if(return_flag ==1)
                break;
        }

        if(return_flag == 1)
        {
            return true;

        }
        else
        {
            return false;
        }


    }

    bool Collision::CheckWallCollision_map2(sf::Sprite sprite1)
    {

        int return_flag = 0;

        for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++ )
            {
                int bottom, top, left, right;

                    bottom = j*50 + 50;
                    top = j*50;
                    right = i*50 + 50;
                    left = i*50;
                if(TileLocation_Map2[j][i] == 1)
                {
                 //   std::cout <<"Bot = " << bottom << "Top = " << top << "Right = " << right << "Left = " << left <<std::endl;

                    if((sprite1.getGlobalBounds().left + 44 < left) //right
                        || (sprite1.getGlobalBounds().left + 20  > right) //left
                        || (sprite1.getGlobalBounds().top + 20 > bottom) //top
                        || (sprite1.getGlobalBounds().top + 64 < top)) //bottom
                        {
                            return_flag = 0;
                 //           std::cout << "Flag = 0" << std::endl;

                        }
                    else
                    {
                        return_flag = 1;
                 //       std::cout <<"FLAG = 1" << std::endl;
                        break;
                    }
                }

            }
            if(return_flag ==1)
                break;
        }

        if(return_flag == 1)
        {
            return true;

        }
        else
        {
            return false;
        }


    }
}
