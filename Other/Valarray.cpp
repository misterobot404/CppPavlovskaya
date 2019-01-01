/*Задание 22. Выполнить задания 4 и 5 с использованием класса valarray,
срезов и генераторов случайных чисел.*/

/*Задание 4. Разработать программу обработки одномерного массива вещественных величин.
Размерность массива задать именованной константой.
Написать программу, в которой можно выполнить следующие пункты:
•	Найти номер минимального элемента массива.
•	Найти сумму элементов массива, расположенных между первым и вторым отрицательными элементами.
•	Преобразовать массив таким образом, чтобы сначала располагались все элементы, модуль которых не превышает 1, а потом — все остальные.
*/
#include	<iostream>
#include	<vector>
#include	<chrono>
#include	<iterator>
#include	<valarray>
#include	"iomanip"
using  namespace  std;

class FourthTask
{
	static const int size = 400;
	int j = 0;
	double sum = 0, fl = 0, min = 0;
public:
	FourthTask() {
		auto beginT = chrono::high_resolution_clock::now();
		valarray <int> valarray(size);

		for (auto &i : valarray) {
			i = -50 + rand() % 100;
		}
		//самописный цикл через два итератора
		/*for (auto it = begin(vector); it != end(vector); ++it)
		{
		for (auto qt = it; qt != end(vector); ++qt) {
		if (abs(*qt) <= 1) {
		swap(*it, *qt);
		break;
		}
		}
		}*/
		//самописный цикл через find
		for (auto it = begin(valarray); it != end(valarray); it++)
		{
			auto result = find(it, end(valarray), abs(*it) <= 1);
			if (result != end(valarray)) swap(*it, *result);
		}
		valarray[slice(0, 200, 2)] = 666;
		// valarray[slice(0, 200, 2)] = pow(static_cast<valarray<int> >(valarray[slice(0, 200, 2)]), 2);
		// valarray[valarray> 5 && valarray < 8] = -1;
		//Вывод с помощью итератора вывода
		cout << "Преобразованный  массив\n";
		copy(begin(valarray), end(valarray), ostream_iterator<int>(cout, " "));
		//Нахождение минимального эллемента с помощью алг valarray
		cout << "\nMin element " << valarray.min();

		for (auto i : valarray)
		{
			if (fl)
			{
				if (i < 0)
					break;
				sum += i;
			}
			if (i < 0)
				fl = 1;
		}
		cout << "\nСумма  элементов  массива,  расположенных  между  первым  и  вторым  отрицательными элементами=" << sum << endl;

		auto endT = chrono::high_resolution_clock::now();
		cout << "\nПрограмма выполнялась " << chrono::duration_cast<chrono::milliseconds>(endT - beginT).count() << " mili seconds" << endl;
	}
};

/*Задание 5. Разработать программу обработки двумерного массива.
Написать программу, в которой рассчитывается сумма элементов в тех
столбцах, которые не содержат отрицательных элементов. Найти минимум
среди сумм модулей элементов диагоналей, параллельных главной диагонали
матрицы.*/
class FifthTask {
public:
	FifthTask() {
		const int c = 10;
		valarray<valarray<int>> matrix;
		matrix.resize(c);
		for (int i = 0; i < matrix.size(); ++i)   matrix[i].resize(c);
		cout << "Матрица " << c << "x" << c << "\n";
		for (int i = 0; i < c; i++)
		{
			cout << endl;
			for (int j = 0; j < c; j++)
			{
				matrix[i][j] = -50 + rand() % 100;
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		//сумму эллементов в тех столбцах, которые не содержат отрицательных эллементов
		for (int j(0), q(0), summ(0); j < c; j++)
		{
			for (int i = 0; i < c; i++)
			{
				if (matrix[i][j] > 0)
					q++;
			}
			if (q == c)
			{
				for (int i = 0; i < c; i++)
				{
					summ += matrix[i][j];
				}
				cout << "Сумма элементов " << j << " столбца равна: " << summ << endl;
			}
			q = 0;
			summ = 0;
		}
		//минимум среди сумм элементов диагоналей параллельных главной диагонали
		int t1, t2;
		int s = matrix[0][c - 1];
		for (int i = 1; i<c; i++)
		{
			t1 = t2 = 0;
			for (int j = 0; j < c - i; j++)
			{
				t1 += matrix[i + j][j];
				t2 += matrix[j][i + j];
			}
			if (t1<s) s = t1;
			if (t2<s) s = t2;
		}
		cout << "минимум среди сумм элементов диагоналей параллельных главной диагонали: " <<
			s << endl;
	}
};

int  main()
{
	setlocale(LC_ALL, "rus");
	cout << "\n  Available tasks\n4 Операции с одномерным массивом\n5 Операции с 2-мерным массивом\n";
	cout << "\nEnter the job number ";
	int T;
	cin >> T;
	switch (T)
	{
	case 4:
	{
		FourthTask My4;
		cout << endl;
		system("pause");
		break;
	}
	case 5:
	{
		FifthTask My5;
		cout << endl;
		system("pause");
		break;
	}
	default:
		break;
	}
}