#include "Player.h"

Player::Player(string name, Board::Pieces piece, Board &board) :
		name(name), piece(piece), board(board) {

}

Player::~Player() {

}

std::ostream& operator<<(ostream& out, const Player& b)
{
    switch (b.getPiece())
    {
        case Board::X:
            out << "X";
            break;
        case Board::O:
            out << "O";
            break;
        case Board::Empty:
            out << "Empty";
            break;
    }

    return out;
}
