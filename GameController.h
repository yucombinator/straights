#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_
#include<memory>
#include"GameState.h"
#include"Command.h"

// GameController is a singleton entity representing the controller for th Straights game
class GameController {
	static std::shared_ptr<GameController> instance_;
	GameState state_;
	GameController(int);
public:
	static std::shared_ptr<GameController> createInstance(int);
	static std::shared_ptr<GameController> getInstance();
	GameState getState() const;
	void playTurn(Command);
};

#endif