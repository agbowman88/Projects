#include <iostream>
#include "head.h"
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
void InitialRoll ();
void InitGame(int scoreCard[][6]);
bool ValidChoice(int keepNum);
void KeepRoll(int keepNum);
bool YahtzeeChecker();
void DisplayScoreCard(int scoreCard[][6]);
void WriteScore(int numKeep, int gameRnd);
bool FullScoreBool(int scoreCard[][6], int gameRnd);
int main()
{

char rollAgain;
int rollCount;
int numKeep;
int gameRnd;
InitGame(scoreCard);
DisplayScoreCard(scoreCard);
srand(time(nullptr));

rollCount = 1;
gameRnd = 1;

do
{
while (rollCount != 3 && !YahtzeeChecker())
{
if (rollCount == 1)
    InitialRoll();
cout << "Do you want to roll again? 'Y' or 'N': ";
cin >> rollAgain;
if (rollAgain == 'Y' && rollCount != 3)
{
    cout << "What number would you like to keep? ";
    cin >> numKeep;
    if (ValidChoice(numKeep))
    {
        rollCount++;
        KeepRoll(numKeep);
    }
}
}
if (YahtzeeChecker())
    {
        numKeep = numKeep*5;
        scoreCard[gameRnd+1][numKeep+1] = numKeep;
    }
WriteScore(numKeep,gameRnd);
DisplayScoreCard(scoreCard);
rollCount = 1;
numKeep = 0;
}while (FullScoreBool(scoreCard,gameRnd));


    return 0;
}

void InitialRoll()
	{
	    cout << "Roll: ";
	    newNodePtr = new DiceList;
		headPtr = newNodePtr;
		currPtr = newNodePtr;
		currPtr->scoreInt = (rand()%6+1);
		cout << currPtr->scoreInt << " ";
		newNodePtr = new DiceList;
		currPtr->next = newNodePtr;
		currPtr = newNodePtr;
		currPtr->scoreInt = (rand()%6+1);
		cout << currPtr->scoreInt << " ";
		newNodePtr = new DiceList;
		currPtr->next = newNodePtr;
		currPtr = newNodePtr;
		currPtr->scoreInt = (rand()%6+1);
		cout << currPtr->scoreInt << " ";
		newNodePtr = new DiceList;
		currPtr->next = newNodePtr;
		currPtr = newNodePtr;
		currPtr->scoreInt = (rand()%6+1);
		cout << currPtr->scoreInt << " ";
		newNodePtr = new DiceList;
		currPtr->next = newNodePtr;
		currPtr = newNodePtr;
		currPtr->scoreInt = (rand()%6+1);
		cout << currPtr->scoreInt << " ";
		currPtr->next = nullptr;
	}
	void KeepRoll(int keepNum)
	{
		DiceList* currPtr;
		currPtr = headPtr;

		int numCount;
			numCount = 0;
			currPtr = headPtr;
			for (int x = 0; x < 5; x++)
			{
				dice[x] = currPtr->scoreInt;
				if (dice[x] == keepNum)
					numCount++;
				currPtr = currPtr->next;
			}
			//currPtr = nullptr;
			currPtr = headPtr;
			for (int x = 0; x < numCount; x++)
			{
				currPtr->scoreInt = keepNum;
				currPtr = currPtr->next;
			}
			for (int x = 0; x < (5 - numCount); x++)
			{
				currPtr->scoreInt = rand() % 6 + 1;
				currPtr = currPtr->next;
			}
			currPtr = headPtr;
			cout << "Roll: ";
			for (int y = 0; y < 5; y++)
			{
				cout << currPtr->scoreInt << ", ";
				currPtr = currPtr->next;
			}
			//currPtr = nullptr;
		}

	bool YahtzeeChecker()
	{
    if (headPtr != nullptr)
    {
		int count;
		count = 0;
		DiceList* currPtr;
		currPtr = headPtr;
		for (int x = 0; x < 5; x++)
		{
			dice[x] = currPtr->scoreInt;
			currPtr = currPtr->next;
		}
		for (int x = 0; x < 5; x++)
		{
			if (dice[0] != dice[x])
				return false;
		}
		return true;
    }
    else
        return false;
	}

	bool ValidChoice(int keepNum)
	{
		int numCount;
		DiceList* currPtr;
		currPtr = headPtr;
		numCount = 0;
		int dice[5];
		for (int x = 0; x < 5; x++)
		{
			dice[x] = currPtr->scoreInt;
			currPtr = currPtr->next;
		}

		for (int x = 0; x < 5; x++)
		{
			if (dice[x] == keepNum)
				numCount++;
		}

		if (numCount == 0)
		{
			cout << "numCount = " << numCount << ". Returning False" << endl;
			return false;
		}
		if (numCount > 0)
		{
			cout << "numCount = " << numCount << ". Returning True" << endl;
			return true;
		}
		else
			cout << "numCount = " << numCount << ".Else Return True" << endl;
			return true;
		{

		}

	}
void InitGame(int scoreCard[][6])
{
	cout << "***********************************************************************************************************************" << endl;
	cout << "                                         Yahtzee - The Simple Version                                                  " << endl;
	cout << "***********************************************************************************************************************" << endl << endl;


	for (int row = 0; row < 7; row++)
		for (int col = 0; col < 7; col++)
			scoreCard[row][col] = 0;


}

void DisplayScoreCard(int scoreCard[][6])
{
	int tempNum;
	cout << "**************************************************************************" << endl;
	cout << "                         YAHTZEE SCORECARD                                " << endl;
	cout << "**************************************************************************" << endl;
	std::cout << std::setw(15) << std::left << "Rounds";

	for (int x = 1; x < 7; x++)
		cout << setw(10) << x;
	cout << endl;
	std::cout << std::setw(15) << std::left << "Aces:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[0][col];
	cout << endl;
	std::cout << std::setw(15) << std::left << "Twos:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[1][col];
	cout << endl;
	std::cout << std::setw(15) << std::left << "Threes:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[2][col];
	cout << endl;
	std::cout << std::setw(15) << std::left << "Fours:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[3][col];
	cout << endl;
	std::cout << std::setw(15) << std::left << "Fives:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[4][col];
	cout << endl;
	std::cout << std::setw(15) << std::left << "Sixes:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[5][col];
	cout << endl;
	std::cout << std::setw(15) << std::left << "Yahtzee:";
	for (int col = 0; col < 6; col++)
		cout << setprecision(2) << setw(10) << scoreCard[6][col];
	cout << endl;
	cout << "**************************************************************************" << endl;
	std::cout << std::setw(15) << std::left << "Totals:";
	tempNum = 0;
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 7; y++)
			tempNum += scoreCard[y][x];
		std::cout << setprecision(2) << setw(10) << tempNum;
		tempNum = 0;
	}
	cout << endl << endl;
}

void WriteScore (int numKeep, int gameRnd)
{
    int keepCnt;
    int tempNum;
    keepCnt = 0;
    for(int x = 0; x < 5; x++)
    {
        currPtr = headPtr;
        tempNum = currPtr->scoreInt;
        if (tempNum = numKeep)
            keepCnt++;
    }

    numKeep = numKeep*keepCnt;
    scoreCard[numKeep/keepCnt-1][gameRnd-1] = numKeep;
}
bool FullScoreBool(int scoreCard[][6], int gameRnd)
{

	for (int row = 0; row < 7; row++)
	{
		if (scoreCard[row][gameRnd - 1] == 0)
		{
			return true;
		}

	}
	return false;
}
