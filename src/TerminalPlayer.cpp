#include "TerminalPlayer.h"


TerminalPlayer::TerminalPlayer(string name, Board::Pieces piece, Board &board): Player(name, piece, board)
{
}

TerminalPlayer::~TerminalPlayer() {

}


void TerminalPlayer::nextMove()
{
    //Create temporary variables for row and col
    int row;
    int col;

	while (true)
    {

        //Prompt user
		cout << name << ", enter a move." << endl;

		// accept input
        cout << "Row: ";
        cin >> row;

        cout << "Column: ";
        cin >> col;

        //Check input, check to see if the board spot is open
        //if everything is good place the piece on the board
        if(cin.fail())
        {
            cerr << "\nInvalid input\n" << endl;
            cin.clear();
            cin.get();
        }
        else if(board.isEmpty(row, col) == false)
        {
            cout << "Spot is already taken, try again.\n" << endl;
        }
        else
        {
            board.set(row, col, this->piece);
            break;
        }
	}
}




