OBJS = main.o Game.o SplashState.o AssetManager.o InputManager.o StateMachine.o MainMenuState.o IntroChad.o IntroState.o GameState.o Nick.o NickBattle.o Map.o Collision.o BattleState1.o Boss1.o Boss1Battle.o NPC1.o Item1.o Chad.o 
CXX = g++
CXXFLAGS = -std=c++11
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

game: $(OBJS)
	$(CXX) -o game $(OBJS) $(LDLIBS) $(LDFLAGS)

main.o: Game.hpp DEFINITIONS.hpp

Game.o: Game.hpp SplashState.hpp StateMachine.hpp AssetManager.hpp InputManager.hpp

SplashState.o: SplashState.hpp DEFINITIONS.hpp State.hpp Game.hpp

assetmanager.o: AssetManager.hpp

inputmanager.o: InputManager.hpp

statemachine.o: StateMachine.hpp State.hpp DEFINITIONS.hpp

MainMenuState.o: MainMenuState.hpp DEFINITIONS.hpp State.hpp Game.hpp

IntroState.o: IntroState.hpp GameState.hpp DEFINITIONS.hpp State.hpp Game.hpp Chad.hpp

GameState.o: GameState.hpp DEFINITIONS.hpp State.hpp Game.hpp Nick.hpp Map.hpp Collision.hpp BattleState1.hpp Boss1.hpp NPC1.hpp Item1.hpp

BattleState1.o: BattleState1.hpp DEFINITIONS.hpp State.hpp Game.hpp Nick.hpp NickBattle.hpp Boss1.hpp Boss1Battle.o

Nick.o: Nick.hpp DEFINITIONS.hpp Game.hpp

NickBattle.o: NickBattle.hpp DEFINITIONS.hpp Game.hpp Boss1Battle.hpp

Boss1.o: Boss1.hpp DEFINITIONS.hpp Game.hpp

Boss1Battle.o: Boss1Battle.hpp DEFINITIONS.hpp Game.hpp NickBattle.hpp

NPC1.o: NPC1.hpp DEFINITIONS.hpp Game.hpp

Item1.o: Item1.hpp DEFINITIONS.hpp Game.hpp

Map.o: Map.hpp DEFINITIONS.hpp Game.hpp

Collision.o: Collision.hpp

Chad.o: Chad.hpp

IntroChad.o: IntroChad.hpp DEFINITIONS.hpp Game.hpp

clean:
	$(RM) game $(OBJS)
