#include "Game15Puzzle.h"

Game15Puzzle::Game15Puzzle()
{
	board.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		board[i].resize(size);
		for (size_t j = 0; j < size; ++j)
			board[i][j] = 0;
	}
}

void Game15Puzzle::mainMenu()
{
	system("cls");
	std::cout << "\nИгра в 15"
		<< std::endl;

	std::cout << "1.Новая игра\n"
		<< "2.Правила игры\n"
		<< "3.Выход\n";
	bool y = 0;
	int choice;
	while (!y)
	{
		std::cout << ">";
		std::cin >> choice;

		if (choice < 1 || choice > 3)
			std::cout << "Некорректный ввод! Попробуйте снова." << std::endl;
		else
			y = 1;
	}

	switch (choice)
	{
	case 1:
		system("cls");
		std::cout << "Подсказка: в текущей версии игры пустая клетка представлена нулём." << std::endl;
		std::cout << "Подсказка: для перемещения пустой клетки (нуля) вверх, вниз, влево или вправо\n"
			<< "требуется ввести значение соседнего элемента, который поменяется с пустой клеткой." << std::endl;
		system("pause");
		startGame();
		break;
	case 2:
		system("cls");
		std::cout << endl
			<< "Игра в 15 это популярная головоломка, придуманная в 1878 году Ноем Чепмэном.\n"
			<< "Игра представляет собой поле для игры размером 4х4 на котором случайным образом расположены числа от 1 до 15.\n"
			<< "Одна клетка остается пустой. Перемещая соседние числа, упорядочите их расположение (слева – направо и сверху – вниз).\n"
			<< "Например, первый ряд – 1, 2, 3, 4, второй – 5, 6, 7, 8 и т.д. «Вытаскивать» числа и перескакивать через числа не разрешается."
			<< std::endl;
		system("pause");
		mainMenu();
		break;
	case 3:
		exit(0);
	}
}
void Game15Puzzle::startGame()
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
	std::cout << "Вы победили за "
		<< turns << " хода!"
		<< std::endl;
	system("pause");
}
void Game15Puzzle::cleanBoard()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[i][j] = 0;
}
bool Game15Puzzle::checkForSolution()
{
	int solution[size*size] = { 0 };
	int index = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++, index++)
			solution[index] = board[i][j];
	int inv = 0;
	for (int i = 0; i < size * size; i++)
		if (solution[i])
			for (int j = 0; j < i; j++)
				if (solution[j] > solution[i])
					++inv;
	for (int i = 0; i < size * size; i++)
		if (solution[i] == 0)
			inv += 1 + i / 4;
	return (inv & 1) ? 0 : 1;
}
bool Game15Puzzle::checkBoard()
{
	int count = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++, count++)
		{
			if (i == size - 1 && j == size - 1 && board[i][j] == 0) break;
			if (board[i][j] != count)
				return 0;
		}
	return 1;
}
void Game15Puzzle::showBoard()
{
	system("cls");
	std::cout << "Игра в 15"
		<< std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "-------------" << std::endl;
		std::cout << "|";
		for (int j = 0; j < size; j++)
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
void Game15Puzzle::changeBoard()
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
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
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
			if (newx < 0 || newx > size - 1 ||
				newy < 0 || newy > size - 1)
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
			std::cout << "Введите числа находящиеся слева, справа, сверху или снизу (обращайте внимание на стены)!" << std::endl;
	}
}
void Game15Puzzle::fillBoard()
{
	bool already[15] = { 0 };
	int count = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++, count++)
		{
			if (i == size - 1 && j == size - 1)
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

