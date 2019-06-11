#include "Figures.h"
#include <list>
#include <algorithm>

double SquareTriangle(double x1, double x2, double x3, double y1, double y2, double y3)
{
	double r;
	double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	double b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	double c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	double p = (a + b + c) / 2;
	r = sqrt(p * (p - a) * (p - b) * (p - c));
	return r;
}

double SquareQuadrate()
{
	return 0;
}

void Tetragon::Input() {
	cout << "Введите координату х левых точек" << endl; cin >> x1;
	cout << "Введите координату х правых точек" << endl; cin >> x2;
	cout << "Введите координату y верхних точек" << endl; cin >> y1;
	cout << "Введите координату y нижних точек" << endl; cin >> y2;
	ID_SEQUENCE_ = rand();
	deleted_ = false;
}
void Tetragon::Delete()
{
	if (deleted_)
		cout << "Квадрат уже удалён!" << endl;
	else
	{
		cout << "Квадрат удалён" << endl;
		deleted_ = true;
	}
}
void Tetragon::Result() {
	if (!deleted_)
	{
		cout << "Идентификатор: ID" << ID_SEQUENCE_ << endl;
		cout << "Координаты:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
		cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
	}
	else cout << "Сначала создайте квадрат" << endl;
}
void Tetragon::Move() {
	if (!deleted_)
	{
		cout << " На сколько единиц вы хотите переместить квадрат по оси X ?" << endl;
		double dx;
		cin >> dx;
		cout << " На сколько единиц вы хотите переместить квадрат по оси Y ?" << endl;
		double dy;
		cin >> dy;
		x1 += dx; x2 += dx;
		y1 += dy; y2 += dy;

		cout << "Квадрат перемещён" << endl;
		cout << "Текущие координаты:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
		cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
	}
	else cout << "Сначала создайте квадрат" << endl;
}

void Quadrate::Input()
{
	cout << "Введите координату х левой нижней точки квадрата" << endl;
	cin >> x1;
	cout << "Введите координату y левой нижней точки квадрата" << endl;
	cin >> y1;
	cout << "Введите ширину (и одновременно высоту) квадрата" << endl;
	cin >> wight;
	x2 = x1 + wight;
	y2 = y1 + wight;
	deleted_ = false;
}
void Quadrate::Compare() {
	if (!deleted_)
	{
		double x3, x4, y3, y4;
		cout << "Координаты второго квадрата:" << endl;
		cout << "Введите координату х левой нижней точки квадрата" << endl;
		cin >> x3;
		cout << "Введите координату y левой нижней точки квадрата" << endl;
		cin >> y3;
		cout << "Введите ширину (и одновременно высоту) квадрата" << endl;
		double tempW;
		cin >> tempW;
		x4 = x3 + tempW;
		y4 = y3 + tempW;
		cout << endl;
		cout << "Вы ввели следующие координаты 1 квадрата:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
		cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
		cout << endl;
		cout << "Вы ввели следующие координаты 2 квадрата:" << endl;
		cout << " A:" << "(" << x3 << "," << y3 << ")" << endl;
		cout << " B:" << "(" << x4 << "," << y3 << ")" << endl;
		cout << " C:" << "(" << x4 << "," << y4 << ")" << endl;
		cout << " D:" << "(" << x3 << "," << y4 << ")" << endl;
		cout << endl;

		double square1 = wight * wight;
		double square2 = tempW * tempW;

		if (square1 > square2)
		{
			cout << "Площадь первого квадрата больше второго" << endl;
		}
		else if (square1 == square2)
		{
			cout << "Площади одинаковы" << endl;
		}
		else cout << "Площадь второго квадрата больше первого" << endl;
	}
	else cout << "Сначала создайте квадрат" << endl;
}

void Triangle::Input() {
	cout << "Введите координату точки х1: "; cin >> x1;
	cout << "Введите координату точки y1: "; cin >> y1; cout << endl;

	cout << "Введите координату точки х2: "; cin >> x2;
	cout << "Введите координату точки y2: "; cin >> y2; cout << endl;

	cout << "Введите координату точки х3: "; cin >> x3;
	cout << "Введите координату точки y3: "; cin >> y3; cout << endl;

	ID_SEQUENCE_ = rand();
	deleted_ = false;
}
void Triangle::Delete()
{
	if (deleted_)
		cout << "Треугольник уже удалён!" << endl;
	else
	{
		cout << "Треугольник удалён" << endl;
		deleted_ = true;
	}
}
void Triangle::Result() {
	if (!deleted_)
	{
		cout << "Идентификатор: ID" << ID_SEQUENCE_ << endl;
		cout << "Координаты:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " C:" << "(" << x3 << "," << y3 << ")" << endl;
	}
	else cout << "Сначала создайте треугольник" << endl;
}
void Triangle::Move() {
	if (!deleted_)
	{
		cout << " На сколько единиц вы хотите переместить треугольник по оси X ?" << endl;
		double dx;
		cin >> dx;
		cout << " На сколько единиц вы хотите переместить треугольник по оси Y ?" << endl;
		double dy;
		cin >> dy;
		x1 += dx; x2 += dx; x3 += dx;
		y1 += dy; y2 += dy; y3 += dy;

		cout << "Треугольник перемещён" << endl;
		cout << "Текущие координаты:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " C:" << "(" << x3 << "," << y3 << ")" << endl;
	}
	else cout << "Сначала создайте треугольник" << endl;
}
void Triangle::Compare() {
	if (!deleted_)
	{
		double x11, x22, x33, x44, x55, y11, y22, y33;
		cout << "Координаты второго треугольника:" << endl;
		cout << "Введите координату точки х1: "; cin >> x11;
		cout << "Введите координату точки y1: "; cin >> y11; cout << endl;

		cout << "Введите координату точки х2: "; cin >> x22;
		cout << "Введите координату точки y2: "; cin >> y22; cout << endl;

		cout << "Введите координату точки х3: "; cin >> x33;
		cout << "Введите координату точки y3: "; cin >> y33; cout << endl;

		cout << endl;
		cout << "Вы ввели следующие координаты 1 треугольника:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " C:" << "(" << x3 << "," << y3 << ")" << endl;
		cout << endl;
		cout << "Вы ввели следующие координаты 2 треугольника:" << endl;
		cout << " A:" << "(" << x11 << "," << y11 << ")" << endl;
		cout << " B:" << "(" << x22 << "," << y22 << ")" << endl;
		cout << " C:" << "(" << x33 << "," << y33 << ")" << endl;
		cout << endl;

		double square1 = SquareTriangle(x1, x2, x3, y1, y2, y3);
		double square2 = SquareTriangle(x11, x22, x33, y11, y22, y33);

		if (square1 > square2)
		{
			cout << "Площадь первого треугольника больше второго" << endl;
		}
		else if (square1 == square2)
		{
			cout << "Площади одинаковы" << endl;
		}
		else cout << "Площадь второго треугольника больше первого" << endl;
	}
	else cout << "Сначала создайте треугольник" << endl;
}