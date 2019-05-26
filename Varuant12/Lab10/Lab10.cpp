/*
Составить описание класса, обеспечивающего представление матрицы произвольного размера с возможностью изменения числа строк и столбцов,
вывод на экран подматрицы любого размера и всей матрицы.
Написать программу, демонстрирующую работу с этим классом.
Программа должна содержать меню, позволяющее осуществить проверку всех методов класса.
*/
#include <iostream>
using namespace std;

class Matrix // целочисленная матрица
{
private:
	int** a; // для хранения информации
	int w, h;// кол-вл строк и столбцов
public:
	Matrix(int H, int W);
	Matrix();
	~Matrix();
	void SetXY(int Y, int X, int data);		// для заполнения ячейки строки y и столбца x
	int GetXY(int Y, int X);				// возвращает значение элемента строки y и столбца x
	void Show();
	void Show(int Hbeg, int Wbeg, int Hend, int Wend); // вывод начиная со строки HBeg и заканчивая Hend, и столбца с WBeg до Wend
	void SetH(int H);
	void SetW(int W);
	int GetH() { return h; }
	int GetW() { return w; }
};
Matrix::Matrix()
{
	h = w = 0;
}
Matrix::Matrix(int H, int W)
{
	h = H;
	w = W;
	a = new int* [H];// выделение памяти под строки
	for (int i = 0; i < H; i++)
		a[i] = new int[W];// выделение памяти под каждую строку
}
Matrix::~Matrix()
{
	for (int i = 0; i < h; i++)
		delete[] a[i];
	delete[] a;
}
void Matrix::SetXY(int Y, int X, int data)
{
	if (Y < h && Y >= 0 && X < w && X >= 0)
		a[Y][X] = data;
}
int Matrix::GetXY(int Y, int X)
{
	if (Y < h && Y >= 0 && X < w && X >= 0)
		return a[Y][X];
	else
		return -1;
}
void Matrix::Show()
{
	for (int i = 0; i < h; i++, cout << endl)
		for (int j = 0; j < w; j++)
			cout << a[i][j] << "\t";
}
void Matrix::Show(int Hbeg, int Hend, int Wbeg, int Wend)
{
	if (Hend < h && Hbeg >= 0 && Wend < w && Wbeg >= 0)
	{
		for (int i = Hbeg; i <= Hend; i++, cout << endl)
			for (int j = Wbeg; j <= Wend; j++)
				cout << a[i][j] << " ";
	}
}
void Matrix::SetH(int H)
{
	int** b;// новый участок памяти
	b = new int* [H];// выделение памяти под строки
	for (int i = 0; i < H; i++)
	{
		b[i] = new int[w];// выделение памяти под каждую строку
		for (int j = 0; j < w; j++)
			b[i][j] = 0; // сразу обнуляем строки
	}

	for (int i = 0; i < H && i < h; i++)
		for (int j = 0; j < w; j++)
			b[i][j] = a[i][j]; // копируем информацию
			// устанавливаем новое кол-во строк

	for (int i = 0; i < h; i++)
		delete[] a[i]; // очистка памяти из под старой информации
	delete[] a;
	h = H;
	a = b;

}
void Matrix::SetW(int W)
{
	int** b;
	b = new int* [h];// выделение памяти под строки
	for (int i = 0; i < h; i++)
	{
		b[i] = new int[W];// выделение памяти под каждую строку
		for (int j = 0; j < W; j++)
			b[i][j] = 0; // сразу обнуляем строки
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w && j < W; j++)
			b[i][j] = a[i][j]; // копируем информацию


	for (int i = 0; i < h; i++) // очистка памяти из под старой информации
		delete[] a[i];
	delete[] a;
	w = W; // устанавливаем новое кол-во столбцов
	a = b;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Класс Matrix" << endl;
	cout << "Начальная инициализация размера матрицы" << endl;
	cout << "Высота (количество строк): ";
	int height;
	cin >> height;
	cout << "Ширина (количество столбцов): ";
	int width;
	cin >> width;
	Matrix matrix(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int value = i * 5 + j;
			matrix.SetXY(i, j, value);
		}
	}
	cout << "Матрица создана и заполнена произвольными значениями" << endl;
	system("pause");
	system("cls");

	while (true)
	{
		cout << endl;
		cout << "Класс Matrix (" << matrix.GetH() << "x" << matrix.GetW() << ")" << endl;
		cout << "1.Заполнение матрицы новыми значениями" << endl;
		cout << "2.Вывод матрицы" << endl;
		cout << "3.Установка высоты (количества строк) матрицы" << endl;
		cout << "4.Установка ширины (количества столбцов) матрицы" << endl;
		cout << "5.Вывод подматрицы" << endl;
		cout << "6.Очистка консоли" << endl;
		cout << ">";
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					cout << "Элемент [" << i+1 << "]" << "[" << j + 1 << "]: ";
					int value;
					cin >> value;
					matrix.SetXY(i, j, value);
				}
			}
		}
		break;
		case 2:
		{
			cout << endl << "Матрица:" << endl;
			matrix.Show();
		}
		break;
		case 3:
		{
			cout << "Введите новую высоту: ";
			int newH;;
			cin >> newH;
			matrix.SetH(newH);
		}
		break;
		case 4:
		{
			cout << "Введите новую ширину: ";
			int newW;;
			cin >> newW;
			matrix.SetW(newW);
		}
		break;
		case 5:
		{
			cout << "Введите начальную строку: ";
			int Hbeg;;
			cin >> Hbeg;
			cout << "Введите конечную строку: ";
			int Hend;
			cin >> Hend;
			cout << "Введите начальный столбец: ";
			int Wbeg;;
			cin >> Wbeg;
			cout << "Введите конечный столбец: ";
			int Wend;
			cin >> Wend;
			cout << endl << "Подматрица:" << endl;
			matrix.Show(Hbeg, Hend, Wbeg, Wend);
		}
		break;
		case 6:
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}