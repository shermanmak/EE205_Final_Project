#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "NickBattle.hpp"
#include "BossBattle.hpp"
#include "Boss.hpp"

namespace GameEngine
{
    class BattleState2 : public State, public NickBattle
    {
            public:
		            BattleState2(GameDataRef data);
                void Init();
		            void HandleInput();
                void Update(float dt);
                void Draw(float dt);

                void RandomAction();
                void CheckifBattleisWon();

                void PrintNickHealth();
                void PrintNickAttack();
                void PrintBossHealth();
                void PrintBossAttack();

                int bossANIMATIONCOUNTER = 0;
                int nickANIMATIONCOUNTER = 0;
                int turn = 0;

                int nickCurrentHealth;
                int nickCurrentStrength;
                int bossCurrentHealth;
                int bossCurrentStrength;

                //Nick Health
                void nicksetHealth(int health);
                std::string nickgetCurrentHealth_string();
                int nickgetCurrentHealth();

                //Nick Strength
                void nicksetStrength(int strength);
                std::string nickgetCurrentStrength_string();
                int nickgetCurrentStrength();

                //Nick Spells/effects
                void nicktakedamage(int damage);
                void nickHealHealth(int heal);
                void nickChargeStrength(int strength);
                void nickgottaunted(int strength);

                //Health
                void bosssetHealth(int health);
                int bossgetCurrentHealth();
                std::string bossgetCurrentHealth_string();

                //Strength
                void bosssetStrength(int strength);
                int bossgetCurrentStrength();
                std::string bossgetCurrentStrength_string();

                //Boss speels/effects
                int bosschoice = 0;
                void bosstakeDamage(int damage);
                void bossHealHealth(int heal);
                void bossChargeStrength(int strength);
                void bossgottaunted(int strength);
                int bossRandomSpell();

                int BossChargeFlag;
                int BossAttackFlag;
                int BossHealFlag;
                int BossTauntFlag;


            private:
                GameDataRef _data;
                sf::Texture _battlebackgroundTexture;
		            sf::Sprite _battlebackground;

                //buttons
                sf::Sprite _AttackButton;
                sf::Sprite _HealButton;
                sf::Sprite _TauntButton;
                sf::Sprite _ChargeButton;

                sf::Sprite _notificationWin;

                BossBattle *chadbattle;
		            NickBattle *nickbattle;

                sf::Clock _clock;


                int nickATTACKANIMATEFLAG;
                int nickHEALANIMATEFLAG;
                int nickTAUNTANIMATEFLAG;
                int nickCHARGEANIMATEFLAG;

                int bossATTACKANIMATEFLAG;
                int bossHEALANIMATEFLAG;
                int bossTAUNTANIMATEFLAG;
                int bossCHARGEANIMATEFLAG;

                bool win;

                sf::Sprite _statusBar;


                sf::Text _BossHealth;
                sf::Text _BossAttack;
                sf::Text _NickHealth;
                sf::Text _NickAttack;

                sf::Music _song;
              	sf::SoundBuffer _clickbuffer;
          			sf::Sound _clicksound;



    };

}
