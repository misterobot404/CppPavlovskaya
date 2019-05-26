#include "Game15Puzzle.h"

void Game::mainMenu()
{
	system("cls");
	std::cout << "\t15 P U ZZ L E"
		<< std::endl;

	std::cout << "\tEnter 1 for NEW GAME!\n"
		<< "\tEnter 2 for EXIT.\n"
		<< "\tEnter 3 for HELP.\n";
	bool y = 0;
	int choice;
	while (!y)
	{
		std::cout << ">";
		std::cin >> choice;

		if (choice < 1 || choice > 3)
			std::cout << "Incorrect input! Try again!" << std::endl;
		else
			y = 1;
	}

	switch (choice)
	{
	case 1:
		startGame();
		break;
	case 2:
		exit(0);
	case 3:
		std::cout << "\nType the number of slice you want\n"
			<< "to move. If you want to show main\n"
			<< "menu type 0. Good luck!\n"
			<< std::endl;
		system("pause");
		startGame();
		break;
	}
}
void Game::startGame()
{
	do
	{
		cleanBoard();
		fillBoard();
	} while (!checkForSolution());

	int turns = 0;
	while (!checkBoard())
	{
		showBoard();
		changeBoard();
		turns++;
	}
	std::cout << "You made it in "
		<< turns << " turns!"
		<< std::endl;
	system("pause");
}
void Game::cleanBoard()
{
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++)
			board[i][j] = 0;
}
bool Game::checkForSolution()
{
	int solution[SZ * SZ] = { 0 };
	int index = 0;
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++, index++)
			solution[index] = board[i][j];
	int inv = 0;
	for (int i = 0; i < SZ * SZ; i++)
		if (solution[i])
			for (int j = 0; j < i; j++)
				if (solution[j] > solution[i])
					++inv;
	for (int i = 0; i < SZ * SZ; i++)
		if (solution[i] == 0)
			inv += 1 + i / 4;
	return (inv & 1) ? 0 : 1;
}
bool Game::checkBoard()
{
	int count = 1;
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++, count++)
		{
			if (i == SZ - 1 && j == SZ - 1 && board[i][j] == 0) break;
			if (board[i][j] != count)
				return 0;
		}
	return 1;
}
void Game::showBoard()
{
	system("cls");
	std::cout << "15 P U ZZ L E"
		<< std::endl;

	for (int i = 0; i < SZ; i++)
	{
		std::cout << "-------------" << std::endl;
		std::cout << "|";
		for (int j = 0; j < SZ; j++)
		{
			std::cout << std::left
				<< std::setw(2)
				<< board[i][j]
				<< "|";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------" << std::endl;
}
void Game::changeBoard()
{
	bool y = 0;
	while (!y)
	{
		int turn = 0;
		do
		{
			std::cout << ">";
			std::cin >> turn;
		} while (turn < 0 || turn > 15);

		if (turn == 0)
		{
			mainMenu();
			return;
		}
		int getx = 0;
		int gety = 0;
		for (int i = 0; i < SZ; i++)
			for (int j = 0; j < SZ; j++)
				if (board[i][j] == turn)
				{
					getx = i;
					gety = j;
				}
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			int newx = getx + dx[i];
			int newy = gety + dy[i];
			if (newx < 0 || newx > SZ - 1 ||
				newy < 0 || newy > SZ - 1)
				continue;
			if (board[newx][newy] == 0)
			{
				board[newx][newy] = turn;
				board[getx][gety] = 0;
				y = 1;
				break;
			}
		}
		if (!y)
			std::cout << "Incorrect turn! Try again!" << std::endl;
	}
}
void Game::fillBoard()
{
	bool already[15] = { 0 };
	int count = 1;
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++, count++)
		{
			if (i == SZ - 1 && j == SZ - 1)
				break;
			while (true)
			{
				int randNum = rand() % 15;
				if (!already[randNum])
				{
					already[randNum] = 1;
					board[i][j] = randNum + 1;
					break;
				}
			}
		}
}

