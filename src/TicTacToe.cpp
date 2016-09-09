#include <iostream>
#include "Board.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

int main()
{
	//Create a board
	Board board;

    //Create 2 terminal players
    TerminalPlayer Player1("Player 1", Board::X, board);
    ComputerPlayer Player2("Player 2", Board::O, board);

    cout << "Player 1 is assigned X and goes first." << endl;
    cout << "Player 2 is assigned O and goes second.\n" << endl;

    //Output the initial board
    cout << board << endl;

    //Create a count
    int i = 0;

    while(true)
    {

        try
        {
            //Player 1 moves on odd count, while Player 2 moves on even
            if(i % 2 == 0)
            {
                Player1.nextMove();
            }
            else
            {
                Player2.nextMove();
            }
        }
        catch(exception& e)
        {
            //Error checking
            cerr << e.what() << "\n" << endl;

            //If error is thrown let the player retry
            i = i - 1;
        }

        //Output board after move
        cout << "\n" << board << endl;


        //Check for winner or draw
        if(board.winner() == Player1.getPiece())
        {
            cout << "Player 1 wins!";
            break;
        }
        else if(board.winner() == Player2.getPiece())
        {
            cout << "Player 2 wins!";
            break;
        }
        else if(board.isFull() == true)
        {
            cout << "Draw!";
            break;
        }

        //add to count
        i++;
    }

	return 0;
}
