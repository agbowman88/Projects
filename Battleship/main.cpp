// Alexander Bowman
// 08APR19
// Battleship
// Program generates a 10x10 game board with 5 ships of size
// 5,4,3,3 and 2 in random locations. User attempts to sink each ship
// by passing a row and column combination. User wins when all elements
// associated with each ship on board is inputted.

#include <iostream>
#include "battle.h"
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
char BoardArray[MAX_ROWS][MAX_COLS]; // BoardArray of char declared
Ship shipArray[MAX_SHIPS];

int main()
{
    srand(time(NULL));
    int row;
    int col;
    int sinkCount = 0;
    bool hitMiss;
    cout << "*************************************************************************" << endl;
    cout << "                              BATTLESHIP                                 " << endl;
    cout << "*************************************************************************" << endl;
    cout << "NOTES:" << endl;
    cout << "'~' = Ocean, coordinate not attacked yet. " << endl;
    cout << "'H' = Hit on part of a ship." << endl;
    cout << "'.' = Miss, previously attacked coordinate." << endl << endl;


    InitializeShips(shipArray);

    do
    {
        InitializeBoard(BoardArray);
        PlaceShip(shipArray, BoardArray);

    }while(!BoardIsValid(BoardArray));

    DisplayBoard(BoardArray);

    InitializeBoard(BoardArray);

    do
    {
        do
        {
            cout << endl << endl << "ENTER A ROW! (1-10): ";
            cin >> row;
            cout << "ENTER A COLUMN! (1-10): ";
            cin >> col;
        }while (!CoordIsValid(BoardArray, row, col));

        if (Attack(shipArray, BoardArray, row, col) == true)
        {
            cout << endl << "********HIT!********" << endl;
            SinkChecker (shipArray, sinkCount);
        }

        if (Attack(shipArray, BoardArray, row, col) == false)
        {
        cout << endl << "********MISS!********" << endl;
        }

            // DisplayBoard function call
        DisplayBoard(BoardArray);

    }while (sinkCount != 5);

cout << endl << "*************************************************************************" << endl;
cout <<         "                          YOU WIN! YOU SUNK ALL 5 SHIPS                  " << endl;
cout << "*************************************************************************" << endl;

    return 0;
}

    // Initial setup of board takes 10x10 array and fills each element with '~'
    // Precondition: 2D array is declared of type char and passed.
    // Postcondition: All 2D array elements filled with '~' character.
void InitializeBoard(/*IN/OUT*/char BoardArray[][MAX_COLS])
{
    for (int x = 0; x < MAX_ROWS; x++) // For loops through all BoardArray rows
        for (int y = 0; y < MAX_COLS; y++) // For loops through all BoardArray columns
            BoardArray[x][y] = '~'; // Makes BoardArray element equal to '~'
}
    // Prints a 2D array to the screen.
    // Precondition: 2D array is declared of type char and passed.
    // Post: All 2D array elements displayed on screen.
void DisplayBoard(/*IN*/char BoardArray[][MAX_COLS])
{
    for (int x = 0; x < MAX_ROWS; x++) // For loops through all BoardArray rows
    {
        cout << endl;
        for (int y = 0; y < MAX_COLS; y++) // For loops through all BoardArray columns
            cout << BoardArray[x][y] << " "; // Outputs BoardArray element
    }
}

void InitializeShips(Ship shipArray[MAX_SHIPS])
{

shipArray[0].shipSize = 5;
shipArray[1].shipSize = 4;
shipArray[2].shipSize = 3;
shipArray[3].shipSize = 3;
shipArray[4].shipSize = 2;
shipArray[0].shipName = "CARRIER";
shipArray[1].shipName = "BATTLESHIP";
shipArray[2].shipName = "CRUISER";
shipArray[3].shipName = "SUBMARINE";
shipArray[4].shipName = "CRUISER";
for (int z = 0; z < 5; z++)
    {
    for (int y = 0; y < 5; y++)
    {
    if (y < shipArray[z].shipSize)
        shipArray[z].status[y] = '#';
    else
        shipArray[z].status[y] = 'H';
    }
    }

for(int x = 0; x < MAX_SHIPS; x++)
    {
    if (rand()%2 == 1)
    shipArray[x].orientation = Vertical;
    else shipArray[x].orientation = Horizontal;
    }

}
void PlaceShip(Ship shipArray[MAX_SHIPS], char BoardArray[][MAX_COLS])
{
    int ranRow;
    int ranCol;
    int sinkCounter = 0;

    if (shipArray[0].orientation == Vertical)
            {
            ranRow = rand()%6;
            ranCol = rand()%10;
            for (int x = 0; x < 5; x++)
            {
                shipArray[0].position[x].row = ranRow;
                shipArray[0].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranRow++;
            }
            }
        else
            {
            ranRow = rand()%10;
            ranCol = rand()%6;
            for (int x = 0; x < 5; x++)
            {
                shipArray[0].position[x].row = ranRow;
                shipArray[0].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranCol++;
            }
            }
        if (shipArray[1].orientation == Vertical)
            {
            ranRow = rand()%7;
            ranCol = rand()%8;
            for (int x = 0; x < 4; x++)
            {
                shipArray[1].position[x].row = ranRow;
                shipArray[1].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranRow++;
            }
            shipArray[1].position[4].row = 99;
            shipArray[1].position[4].col = 99;
            }
        else
            {
            ranRow = rand()%8;
            ranCol = rand()%7;
            for (int x = 0; x < 4; x++)
            {
                shipArray[1].position[x].row = ranRow;
                shipArray[1].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranCol++;
            }
            shipArray[1].position[4].row = 99;
            shipArray[1].position[4].col = 99;
            }
        if (shipArray[2].orientation == Vertical)
            {
            ranRow = rand()%8;
            ranCol = rand()%9;
            for (int x = 0; x < 3; x++)
            {
                shipArray[2].position[x].row = ranRow;
                shipArray[2].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranRow++;
            }
            shipArray[2].position[3].row = 99;
            shipArray[2].position[3].col = 99;
            shipArray[2].position[4].row = 99;
            shipArray[2].position[4].col = 99;

            }
        else
            {
            ranRow = rand()%9;
            ranCol = rand()%8;
            for (int x = 0; x < 3; x++)
            {
                shipArray[2].position[x].row = ranRow;
                shipArray[2].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranCol++;
            }
            shipArray[2].position[3].row = 99;
            shipArray[2].position[3].col = 99;
            shipArray[2].position[4].row = 99;
            shipArray[2].position[4].col = 99;
            }
            if (shipArray[3].orientation == Vertical)
            {
            ranRow = rand()%8;
            ranCol = rand()%9;
            for (int x = 0; x < 3; x++)
            {
                shipArray[3].position[x].row = ranRow;
                shipArray[3].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranRow++;
            }
            shipArray[3].position[3].row = 99;
            shipArray[3].position[3].col = 99;
            shipArray[3].position[4].row = 99;
            shipArray[3].position[4].col = 99;
            }
        else
            {
            ranRow = rand()%9;
            ranCol = rand()%8;
            for (int x = 0; x < 3; x++)
            {
                shipArray[3].position[x].row = ranRow;
                shipArray[3].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranCol++;
            }
            shipArray[3].position[3].row = 99;
            shipArray[3].position[3].col = 99;
            shipArray[3].position[4].row = 99;
            shipArray[3].position[4].col = 99;
            }
            if (shipArray[4].orientation == Vertical)
            {
            ranRow = rand()%9;
            ranCol = rand()%10;
            for (int x = 0; x < 2; x++)
            {
                shipArray[4].position[x].row = ranRow;
                shipArray[4].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranRow++;
            }
            shipArray[4].position[2].row = 99;
            shipArray[4].position[2].col = 99;
            shipArray[4].position[3].row = 99;
            shipArray[4].position[3].col = 99;
            shipArray[4].position[4].row = 99;
            shipArray[4].position[4].col = 99;
            }
        else
            {
            ranRow = rand()%10;
            ranCol = rand()%9;
            for (int x = 0; x < 2; x++)
            {
                shipArray[4].position[x].row = ranRow;
                shipArray[4].position[x].col = ranCol;
                BoardArray[ranRow][ranCol] = '#';
                ranCol++;
            }
            shipArray[4].position[2].row = 99;
            shipArray[4].position[2].col = 99;
            shipArray[4].position[3].row = 99;
            shipArray[4].position[3].col = 99;
            shipArray[4].position[4].row = 99;
            shipArray[4].position[4].col = 99;

            }

}
bool BoardIsValid(char BoardArray[][MAX_COLS])
{
    int shipCount = 0;
    for (int x = 0; x < MAX_ROWS; x++)
        {
        for (int y = 0; y < MAX_ROWS; y++)
        {
            if(BoardArray[x][y] == '#')
                shipCount++;
        }
        }
    if (shipCount == 17)
        return true;
    else
        return false;
}
bool Attack (Ship shipArray[MAX_SHIPS], char BoardArray[][MAX_COLS], int row, int col)
{
row = row-1;
col = col-1;
bool noMatch = false;;
for (int x = 0; x < 5; x++)
{
    for (int y = 0; y < 5; y++)
        {

        if (shipArray[x].position[y].row == row && shipArray[x].position[y].col == col)
        {
            shipArray[x].status[y] = 'H';
            BoardArray[row][col] = 'H';
            noMatch = true;
            return true;
        }
        }
}
    if (noMatch == false)
    {
    BoardArray[row][col] = '.';
    return false;
    }

}
void SinkChecker (Ship shipArray[MAX_SHIPS], int& sinkCount)
{
    int hitCount;
    for (int x = 0; x < 5; x++)
    {
        hitCount = 0;
        for (int y = 0; y < 5; y++)
            {
            if (shipArray[x].status[y] == 'H')
                //cout << hitCount;
                hitCount++;
            if (hitCount == 5)
            {
                shipArray[x].status[0]= 'S';
                shipArray[x].status[1]= 'S';
                shipArray[x].status[2]= 'S';
                shipArray[x].status[3]= 'S';
                shipArray[x].status[4]= 'S';
                sinkCount++;
                cout << endl << "*****************************************************" << endl;
                cout <<         "               YOU SUNK MY " << shipArray[x].shipName << "!" << endl;
                cout << "*****************************************************" << endl;
                cout << sinkCount << " OUT OF 5 SHIPS SUNK." << endl;
            }
            }
    }

}
void ShipDisplay (Ship shipArray[MAX_SHIPS])
{
    for (int x = 0; x < 5; x++)
    {
        cout << endl;
        cout << "Ship: " << x+1;
        cout << "Size: " << shipArray[x].shipSize << "Orientation: ";
        if (shipArray[x].orientation == 0)
            cout << "Vertical. ";
        else
            cout << "Horizontal. ";
            cout << "Coordinates: ";
            cout << "Ship Name: " << shipArray[x].shipName << " ";
        for (int y = 0; y < 5; y++)
        cout << "(" << shipArray[x].position[y].row+1 << "," << shipArray[x].position[y].col+1 << ")" << " ";
        cout << "Status: ";
        for (int b = 0; b < 5; b++)
            cout << shipArray[x].status[b] << " ";
    }
    cout << endl << endl;
}

bool CoordIsValid(char BoardArray[][MAX_COLS], int row, int col)
{
    if (row < 1 || row > 10 || col < 1 || col > 10)
    {
        cout << "Row and or column out of range!" << endl;
        return false;
    }
    if (BoardArray[row-1][col-1] != '~')
    {
        cout << "Row and column combination already entered!" << endl;
        return false;
    }
    return true;
}
