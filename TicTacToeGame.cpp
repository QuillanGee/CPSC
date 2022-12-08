#include <iostream>
#include <math.h>
#include <tuple>
using namespace std;
class TicTacToeGame{
public:
  TicTacToeGame();
  virtual ~TicTacToeGame();
  void play();

// private:
  void initializeGrid();
  void displayGrid();
  tuple<int,int> findFirstUnoccupiedGridSquare();
  tuple<int,int> promptForGridCoord();
  bool checkForDraw();
  bool checkForWin();
private:
  char** pp_cGrid = nullptr;
};

TicTacToeGame :: TicTacToeGame(){
  this->pp_cGrid = new char* [3]; //an array of three pointers, each pointer points to an arraylist of 3

  for(int iRow = 0;iRow<3;iRow++)
  {
    pp_cGrid[iRow] = new char[3]; //each pointer getting assigned to an arraylist of length 3
  }
  initializeGrid();
}

TicTacToeGame::~TicTacToeGame()
{
  for(int iRow = 0;iRow<3;iRow++)
  {
    delete[] pp_cGrid[iRow];
  }

  delete[] pp_cGrid;
  pp_cGrid = nullptr;
}

void TicTacToeGame::initializeGrid()
{
  for(int iRow = 0;iRow<3;iRow++)
  {
    for(int iColumn = 0; iColumn < 3; iColumn++)
    {
      this->pp_cGrid[iRow][iColumn] = '~';
    }
  }
}

void TicTacToeGame::displayGrid()
{
  for(int iRow = 0;iRow<3;iRow++)
  {
    for(int iColumn = 0; iColumn < 3; iColumn++)
    {
      cout << this->pp_cGrid[iRow][iColumn] << " ";
    }
    cout << endl;
  }
}

std::tuple<int, int> TicTacToeGame::findFirstUnoccupiedGridSquare()
{
  int iRowUnoccupied = -1;
  int iColumnUnoccupied = -1;

  bool bFound = false;

  for(int iRow = 0; (iRow < 3) && !bFound; iRow++)
  {
    for(int iColumn = 0; (iColumn < 3) && !bFound; iColumn++)
    {
      if(this->pp_cGrid[iRow][iColumn] == '~')
      {
        iRowUnoccupied = iRow;
        iColumnUnoccupied = iColumn;
        bFound = true;
      }
    }
  }
  std::tuple<int,int> tupleUnoccupiedGridSquare(iRowUnoccupied,iColumnUnoccupied);
  return tupleUnoccupiedGridSquare;
}

tuple<int,int> TicTacToeGame::promptForGridCoord()
{
  int iRow = 0;
  int iColumn = 0;

  cout << "Please enter a grid row number" << endl;
  cin >> iRow;

  cout << "Please enter a grid column number" << endl;
  cin >> iColumn;

  std::tuple<int,int> tupleCoord = std::make_tuple(iRow, iColumn);

  return tupleCoord;
}

bool TicTacToeGame::checkForDraw()
{
  bool bContinue = false;

  for(int iRow = 0; iRow <3; iRow++)
  {
    for(int iColumn = 0; iColumn < 3;iColumn++)
    {
      if(this->pp_cGrid[iRow][iColumn] != 'X' && this->pp_cGrid[iRow][iColumn] != 'O')
        bContinue = true;
    }
  }
  return !bContinue;
}

bool TicTacToeGame::checkForWin()
{
  bool bWin = false;

  for(int iRow = 0; (iRow < 3) && !bWin; iRow++)
  {
    if(this->pp_cGrid[iRow][0] != '~')
    {
      if((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) && this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][2])
      {
        bWin = true;
        cout << "WINNER: " << this->pp_cGrid[iRow][0] << "!" << endl;
      }
    }
  }
  for(int iColumn = 0; (iColumn < 3) && !bWin; iColumn++)
  {
    if(this->pp_cGrid[0][iColumn] != '~')
    {
      if((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) && this->pp_cGrid[0][iColumn] == this->pp_cGrid[2][iColumn])
      {
        bWin = true;
        cout << "WINNER: " << this->pp_cGrid[0][iColumn] << "!" << endl;
      }
    }
  }

  if(this->pp_cGrid[0][0] != '~')
  {
    if((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][0] == this->pp_cGrid[2][2]))
    {
      bWin = true;
      cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << endl;
    }
  }
  if(this->pp_cGrid[0][2] != '~')
  {
    if((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][2] == this->pp_cGrid[2][0]))
    {
      bWin = true;
      cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << endl;
    }
  }

  return bWin;
}

void TicTacToeGame::play()
{

  bool bWin = false;
  bool bDraw = false;

  displayGrid();
  while(!bWin && !bDraw)
  {
    int iRow = 0;
    int iColumn = 0;
    std::tie(iRow, iColumn) = promptForGridCoord();
    this->pp_cGrid[iRow][iColumn] = 'X';

    displayGrid();
    bWin = checkForWin();
    bDraw = checkForDraw();

    if(!bWin and !bDraw)
    {
      std::tie(iRow,iColumn) = findFirstUnoccupiedGridSquare();
      this->pp_cGrid[iRow][iColumn] = 'O';
      displayGrid();
      bWin = checkForWin();
      bDraw = checkForDraw();
    }
    if(bDraw)
    {
      cout << "Draw!" << endl;``
    }
  }

  cout << "Game over" << endl;
  return;
}

int main()
{
  TicTacToeGame *p_game = new TicTacToeGame();

  p_game->play();

  delete p_game;
}
