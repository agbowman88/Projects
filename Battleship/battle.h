#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED
#include <string>
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
const int MAX_SHIPSIZE = 5;
const int MAX_SHIPS = 5;

//typedef char BoardArray[MAX_ROWS][MAX_COLS];

// Ships can be placed vertically or horizontally, or not yet placed
enum Orientation {Vertical, Horizontal, None};

// Hold x and y coordinates in a single structure
struct PositionType
{
    int row;
    int col;
};

struct Ship
{
    std::string shipName;
    int shipSize;
    char status[5];   // Number of spots on a ship
                                // Entry for each spot, hit or not hit
    PositionType position[MAX_SHIPSIZE];      // Coordinates of ship on the board
    Orientation orientation;    // Vertical or horizontal placement
};


// Initial setup of board takes 10x10 array and fills each element with '~'
// Precondition: 2D array is declared of type char and passed.
// Postcondition: All 2D array elements filled with '~' character.
void InitializeBoard(/*IN/OUT*/char BoardArray[][MAX_COLS]);

// Prints a 2D array to the screen.
// Precondition: 2D array is declared of type char and passed.
// Post: All 2D array elements displayed on screen.
void DisplayBoard(/*IN*/char BoardArray[][MAX_COLS]);

// Set initial configuration for the array of all 5? ships
// Pre: ...
// Post: ...
void InitializeShips(Ship shipArray[MAX_SHIPS]);

// Called by InitializeShip function to setup each ship
// Pre: ...
// Post: ...
void PlaceShip(Ship shipArray[MAX_SHIPS], char BoardArray[][MAX_COLS]);

// For a given board, ship, and position, tests to see if the given position is valid for
// that particular ship, on that particular board
// Pre: board, ship, and position must be initialized with valid values for their types
// Post: Returns true if the given ship has no conflicts at that specified position,
//       otherwise returns false.
bool CoordIsValid(char BoardArray[][MAX_COLS], int row, int col);

bool BoardIsValid(char BoardArray[][MAX_COLS]);

bool Attack (Ship shipArray[MAX_SHIPS], char BoardArray[][MAX_COLS], int row, int col);

void SinkChecker (Ship shipArray[MAX_SHIPS], int& sinkCount);

void ShipDisplay (Ship shipArray[MAX_SHIPS]);



#endif // BATTLE_H_INCLUDED
