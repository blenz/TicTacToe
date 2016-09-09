#include "Board.h"

using namespace std;

Board::Board()
{
	clear();
}

//Destructor
Board::~Board()
{
}

/**
 * Return true if the board position is empty
 */
bool Board::isEmpty(int row, int col) const
{
	if (row >= BoardSize or col >= BoardSize)
	{
	   throw out_of_range("Not in range, can only get pieces from positions 0 to 2. Retry.");
	}

    if(Board::board[row][col] == Empty)
        return true;
    else
        return false;
}

/**
 * Return true if the piece is Empty
 */
bool Board::isEmpty(Pieces value) const
{
    if (value == Empty)
        return true;
    else
        return false;
}

/**
 * Return the piece at the board position
 */
Board::Pieces Board::pieceAt(int row, int col) const
{
	if (row >= BoardSize or col >= BoardSize)
	{
	    throw out_of_range("Not in range. Can only get pieces from positions 0 to 2.");
	}

    return Board::board[row][col];
}


/**
 * Return the piece that is the winner, else return Empty
 */
Board::Pieces Board::winner() const
{
    //Check for horizontal match
    for(int i = 0; i < BoardSize; i++)
    {
        if(board[i][0] == board[i][1] and board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    //Check for vertical match
    for(int i = 0; i < BoardSize; i++)
    {
        if (board[0][i] == board[1][i] and board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //Check for diagonal match
    for(int i = 0; i == 0; i++)
    {
        if (board[i][i] == board[i+1][i+1] and board[i+1][i+1] == board[i+2][i+2])
        {
            return board[i][i];
        }
        else if (board[i][i+2] == board[i+1][i+1] and board[i+1][i+1] == board[i+2][i])
        {
            return board[i+1][i+1];
        }
    }

    return Empty;
}

/**
 * Return the row/column size
 */
int Board::getBoardSize() const
{
    return BoardSize;
}

/**
 * Clear the board
 */
void Board::clear()
{
    for(int i = 0; i < BoardSize; i++)
    {
        for(int j = 0; j < BoardSize; j++)
        {
            Board::board[i][j] = Empty;
        }
    }
}

/**
 * Return true if the board is full
 */
bool Board::isFull() const
{

    for(int i = 0; i < BoardSize; i++)
    {
        for(int j = 0; j < BoardSize; j++)
        {
            if(Board::board[i][j] == Empty)
                return false;
        }
    }
    return true;
}

/**
 * Set a board position with a piece
 */
void Board::set(int row, int col, Pieces p)
{
	 if (row >= BoardSize or col >= BoardSize)
	 {
	     throw out_of_range("Not in range. Can only places pieces to positions 0 to 2.");
	 }

    Board::board[row][col] = p;
}

/**
 * Output board to an output stream
 */
std::ostream& operator<<(ostream& out, const Board& b)
{
    for(int i=0; i<3; i++)    //This loops on the rows.
	{
		for(int j=0; j<3; j++) //This loops on the columns
		{
			switch (b.board[i][j])
			 {
				case Board::X:
					out << "X" << "  ";
					break;
				case Board::O:
					out << "O" << "  ";
					break;
				case Board::Empty:
					out << "-" << "  ";
					break;
			 }
		}
		cout << endl;
	}


    return out;
}














