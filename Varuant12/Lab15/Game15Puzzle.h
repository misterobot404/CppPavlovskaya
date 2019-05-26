#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define size 4

class Game15Puzzle
{
public:
	Game15Puzzle();
	void mainMenu();
private:
	vector<vector<int>> board;

	void cleanBoard();
	bool checkForSolution();
	bool checkBoard();
	void showBoard();
	void changeBoard();
	void fillBoard();
	void startGame();
};

