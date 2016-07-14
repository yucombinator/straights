#ifndef _ROUNDCONTROLLER_
#define _ROUNDCONTROLLER_

#include <vector>
#include <memory>
#include "Player.h"
#include "GameView.h"
#include "GameState.h"
#include "Deck.h"

class RoundController {
	void findStartingPlayer(); // finds player with 7S and mark as starting player
	void dealCards(); // deals 13 random cards to each player
public:
	RoundController(); // initialized blank round and deal cards
	void playAITurns(); // plays AI turns during the round until game ends or a human turn
	void handleTurn(); // handle a turn, call the associated player for move
	void playTurn(std::shared_ptr<Player>, Command); // performs the command the player chooses
};

#endif