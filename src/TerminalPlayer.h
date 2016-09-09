#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

#include "Player.h"

class TerminalPlayer: public Player
{
public:
	TerminalPlayer(string name, Board::Pieces piece, Board &board);
	virtual ~TerminalPlayer();

	void nextMove();

};

#endif /* TERMINALPLAYER_H_ */
