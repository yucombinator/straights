#ifndef _GAMESTATE_
#define _GAMESTATE_
#include "Subject.h"
#include "Deck.h"
#include "Player.h"
#include "GameController.h"
#include "RoundController.h"
#include <vector>
#include <memory>
class GameController;
class RoundController;

class GameState : public Subject {
	// Class that holds the information about the game (model)
private:
	static std::shared_ptr<GameState> instance_;	// Hold the instance of the GameState

	std::vector<std::shared_ptr<Player>> players_;	// Hold the pointers to players in the game
	std::shared_ptr<Deck> deck_;					// Hold the pointers to the Deck that is used
	GameState(int _seed) : seed_(_seed) {};			// Construct the GameState
	int seed_;										// Hold the seed number
	// information about current round:
	bool firstTurn_ = true; // defaults to true - set to false after first turn
	std::shared_ptr<Player> currentPlayer_; // list of players in current round, in playing order
	std::vector<Card> playedCards_; // list of cards played by all players
	friend GameController;
	friend RoundController;
public:
	static std::shared_ptr<GameState> createInstance(int seed);	// A Facade method to create a new GameState and use pre set seed
	static std::shared_ptr<GameState> getInstance();		// Accessor -  get the unique instance of GameState
	void setSeed(int);
	int getSeed() const;

	void setFirstTurn(bool);
	int getFirstTurn() const;

	void setPlayers(std::vector<std::shared_ptr<Player>>);
	std::vector<std::shared_ptr<Player>> getPlayers() const;

	void setCurrentPlayer(std::shared_ptr<Player>);
	std::shared_ptr<Player> getCurrentPlayer() const;

	void setDeck(std::shared_ptr<Deck>);
	std::shared_ptr<Deck> getDeck() const;

	void setPlayedCards(std::vector<Card>);
	std::vector<Card> getPlayedCards() const;

	std::vector<Card> getPlayerDiscards(int);
	std::vector<Card> getPlayerHand(int);
	std::vector<Card> getPlayerLegalMoves(int);

	int getPlayerTotalScore(int);
	PlayerType getPlayerType(int);
	int getPlayerId(int);
};

#endif