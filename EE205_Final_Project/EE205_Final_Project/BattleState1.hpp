#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "NickBattle.hpp"
#include "Boss1Battle.hpp"
#include "Boss1.hpp"

namespace GameEngine
{
    class BattleState1 : public State
    {
            public:
		        BattleState1(GameDataRef data);
                void Init();
		        void HandleInput();
		        void Update(float dt);
		        void Draw(float dt);

                void RandomAction();
                void CheckifBattleisWon();
                
                void PrintNickHealth();
                void PrintBossHealth();
                
                int bossANIMATIONCOUNTER = 0;
                int nickANIMATIONCOUNTER = 0;



            
            private:
                GameDataRef _data;	
                sf::Texture _battlebackgroundTexture;
		        sf::Sprite _battlebackground;
                
                //buttons
                sf::Sprite _AttackButton;
                sf::Sprite _HealButton;
                sf::Sprite _TauntButton;
                sf::Sprite _ChargeButton;

                Boss1Battle *boss1battle;
		        NickBattle *nickbattle;
                
                sf::Clock _clock;

                int turn;

                int nickATTACKANIMATEFLAG;
                int nickHEALANIMATEFLAG;
                int nickTAUNTANIMATEFLAG;
                int nickCHARGEANIMATEFLAG;
               // int nickANIMATIONCOUNTER;

                int bossATTACKANIMATEFLAG;
                int bossHEALANIMATEFLAG;
                int bossTAUNTANIMATEFLAG;
                int bossCHARGEANIMATEFLAG;
                bool bossturnFLAG;
              //  int bossANIMATIONCOUNTER;

		

    };
    
}
