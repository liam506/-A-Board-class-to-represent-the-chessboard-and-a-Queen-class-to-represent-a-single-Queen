#include <iostream>
#include <math.h>
#include<stdlib.h>
#include <vector>
using namespace std;

class Queen {
public:
  void setRow(int inRow);
  int getRow() const;

private:
  int row;
  int col;
};

int Queen::getRow() const {
     return row; }

void Queen::setRow(int inRow) {
    row =inRow; }

class Board {
public:
  static const int BOARD_SIZE = 8;
  Board();
  void doQueens();
  void display() const;

private:
  bool placeQueens(int row, int col);
  bool findNextSafeSquare(int &row, int col);
  bool isUnderAttack(int row, int col);
  vector<Queen> queens;
};

Board::Board() {
    //queens.resize(BOARD_SIZE);
    }

void Board::doQueens() {
  if (placeQueens(0, 0)) {
    display();
  } else {
    cout << "No solution found." << endl;
  }
}

bool Board::placeQueens(int row, int col) {
  // use the pseudocode above to complete this function.
  Queen queen;
for(col = 0; col< BOARD_SIZE; col++)
{
if(isUnderAttack(row, col) == false)
{
queen.setRow(col);
queens.insert(queens.begin()+row,queen);
queens[row] = queen;
if(row==BOARD_SIZE-1)
{
display();
exit(0);
}
placeQueens(row+1, col);
}
}
}


bool Board::isUnderAttack(int testRow, int testCol) {
for(int i=0; i<testRow; i++)
{
if(queens.at(i).getRow()==testCol) return true;
if(testRow-i == abs(testCol-queens.at(i).getRow())) return true;
}
return false;
}

// Sets "row" to the row of the next safe square in column col.  Important note:
// Starts with the given row and col.  In other words, the given row and col may
// be the "next safe square".
// returns true if a safe square is found, false if no safe square is found.  If
// return value is false, row is undefined.

bool Board::findNextSafeSquare(int &row, int col) {}

// Displays a visual representation of the current state of the board.  For each
// position on the board, displays "X" if a queen is located at that position,
// otherwise displays
// "_" (underscore).

void Board::display() const {
cout<<" ";
for(int rowNum =0; rowNum<BOARD_SIZE; rowNum++)
cout<<rowNum<<"  ";
cout<<endl;
for(int i=0; i<BOARD_SIZE; i++)
{
for(int j=0; j<BOARD_SIZE; j++)
{
if(queens.at(i).getRow()==j) cout<<" _ ";
else cout<<" X ";
}
cout<<endl;
}
}

int main()
  {
    Board board;
    board.doQueens();
  }
