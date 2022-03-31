#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

using namespace std;

int scoreCard[8][6];



struct DiceList
{
	int scoreInt;
	DiceList* next;
};

int dice[5];

DiceList* headPtr;
DiceList* lastPtr;
DiceList* currPtr;
DiceList* newNodePtr;

#endif // HEAD_H_INCLUDED
