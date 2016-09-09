#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(string name, Board::Pieces piece, Board &board) :
Player(name, piece, board)
{
}

ComputerPlayer::~ComputerPlayer()
{

}

void ComputerPlayer::nextMove()
{
        for(int i = 0; i < BoardSize - 1; i++)
        {
            for(int j = 0; j < BoardSize - 1; j++)
            {
                if(board.pieceAt(i, j) == this->piece)
                {
                        if(board.pieceAt(i + 1, j) == Board::Empty)
                        {
                            board.set(i + 1, j, this->piece);
                            cout << "Computer has made a move" << endl;
                            return;
                        }
                        else if(board.pieceAt(i, j+1) == Board::Empty)
                        {
                            board.set(i, j + 1, this->piece);
                            cout << "Computer has made a move" << endl;
                            return;
                        }
                        else if(board.pieceAt(i+1, j+1) == Board::Empty)
                        {
                            board.set(i + 1, j + 1, this->piece);
                            cout << "Computer has made a move" << endl;
                            return;
                        }
                        else if(board.pieceAt(i - 1, j - 1) == Board::Empty)
                        {
                            board.set(i - 1, j - 1, this->piece);
                            cout << "Computer has made a move" << endl;
                            return;
                        }
                }
                else if(board.isEmpty(i, j) == true)
                {
                    board.set(i, j, this->piece);
                    cout << "Computer has made a move" << endl;
                    return;
                }
            }
        }
}
