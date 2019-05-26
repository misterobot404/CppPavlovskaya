/*
Написать программу, решающую игру-головоломку «Игра в 15». Начальное размещение номеров — случайное. Предусмотреть два режима демонстрации решения:
непрерывный (с некоторой задержкой визуализации) и пошаговый (по нажатию любой клавиши). В программе использовать контейнерные классы STL.
*/
#include "game.h"

int main()
{
	mainMenu();
	return 0;
}

void mainMenu()
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
