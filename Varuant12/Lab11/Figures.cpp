#include "Figures.h"
#include <list>
#include <algorithm>

struct xy {
	double x, y;
};

struct line {
	xy a;
	xy b;
};

inline int area(xy a, xy b, xy c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(int a, int b, int c, int d) {
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d);
}

bool intersect(xy a, xy b, xy c, xy d) {
	return intersect_1(a.x, b.x, c.x, d.x)
		&& intersect_1(a.y, b.y, c.y, d.y)
		&& area(a, b, c) * area(a, b, d) <= 0
		&& area(c, d, a) * area(c, d, b) <= 0;
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
void Tetragon::IsIntersect() {
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
		
		if ((y1 < y4 && y2 > y3) || (x2 < x3 && x1 > x4))
		{
			cout << "Квадраты пересекаются" << endl;
		}
		else cout << "Квадраты не пересекаются" << endl;
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
	double tempW;
	cin >> tempW;
	x2 = x1 + tempW;
	y2 = y1 + tempW;
	deleted_ = false;
}

void Pentagon::Input() {
	cout << "Введите координату точки х1: "; cin >> x1;
	cout << "Введите координату точки y1: "; cin >> y1; cout << endl;

	cout << "Введите координату точки х2: "; cin >> x2;
	cout << "Введите координату точки y2: "; cin >> y2; cout << endl;

	cout << "Введите координату точки х3: "; cin >> x3;
	cout << "Введите координату точки y3: "; cin >> y3; cout << endl;

	cout << "Введите координату точки х4: "; cin >> x4;
	cout << "Введите координату точки y4: "; cin >> y4; cout << endl;

	cout << "Введите координату точки х5: "; cin >> x5;
	cout << "Введите координату точки y5: "; cin >> y5; cout << endl;

	ID_SEQUENCE_ = rand();
	deleted_ = false;
}
void Pentagon::Delete()
{
	if (deleted_)
		cout << "Пятиугольник уже удалён!" << endl;
	else
	{
		cout << "Пятиугольник удалён" << endl;
		deleted_ = true;
	}
}
void Pentagon::Result() {
	if (!deleted_)
	{
		cout << "Идентификатор: ID" << ID_SEQUENCE_ << endl;
		cout << "Координаты:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " C:" << "(" << x3 << "," << y3 << ")" << endl;
		cout << " D:" << "(" << x4 << "," << y4 << ")" << endl;
		cout << " F:" << "(" << x5 << "," << y5 << ")" << endl;
	}
	else cout << "Сначала создайте пятиугольник" << endl;
}
void Pentagon::Move() {
	if (!deleted_)
	{
		cout << " На сколько единиц вы хотите переместить пятиугольник по оси X ?" << endl;
		double dx;
		cin >> dx;
		cout << " На сколько единиц вы хотите переместить пятиугольник по оси Y ?" << endl;
		double dy;
		cin >> dy;
		x1 += dx; x2 += dx; x3 += dx; x4 += dx; x5 += dx;
		y1 += dy; y2 += dy; y3 += dy; y4 += dy; y5 += dy;

		cout << "Пятиугольник перемещён" << endl;
		cout << "Текущие координаты:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " C:" << "(" << x3 << "," << y3 << ")" << endl;
		cout << " D:" << "(" << x4 << "," << y4 << ")" << endl;
		cout << " F:" << "(" << x5 << "," << y5 << ")" << endl;
	}
	else cout << "Сначала создайте пятиугольник" << endl;
}
void Pentagon::IsIntersect() {
	if (!deleted_)
	{
		double x11, x22, x33, x44, x55, y11, y22, y33, y44, y55;
		cout << "Координаты второго квадрата:" << endl;
		cout << "Введите координату точки х1: "; cin >> x11;
		cout << "Введите координату точки y1: "; cin >> y11; cout << endl;

		cout << "Введите координату точки х2: "; cin >> x22;
		cout << "Введите координату точки y2: "; cin >> y22; cout << endl;

		cout << "Введите координату точки х3: "; cin >> x33;
		cout << "Введите координату точки y3: "; cin >> y33; cout << endl;

		cout << "Введите координату точки х4: "; cin >> x44;
		cout << "Введите координату точки y4: "; cin >> y44; cout << endl;

		cout << "Введите координату точки х5: "; cin >> x55;
		cout << "Введите координату точки y5: "; cin >> y55; cout << endl;

		cout << endl;
		cout << "Вы ввели следующие координаты 1 пятиугольника:" << endl;
		cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
		cout << " B:" << "(" << x2 << "," << y2 << ")" << endl;
		cout << " C:" << "(" << x3 << "," << y3 << ")" << endl;
		cout << " D:" << "(" << x4 << "," << y4 << ")" << endl;
		cout << " F:" << "(" << x5 << "," << y5 << ")" << endl;
		cout << endl;
		cout << "Вы ввели следующие координаты 2 пятиугольника:" << endl;
		cout << " A:" << "(" << x11 << "," << y11 << ")" << endl;
		cout << " B:" << "(" << x22 << "," << y22 << ")" << endl;
		cout << " C:" << "(" << x33 << "," << y33 << ")" << endl;
		cout << " D:" << "(" << x44 << "," << y44 << ")" << endl;
		cout << " F:" << "(" << x55 << "," << y55 << ")" << endl;
		cout << endl;

		list<line> lines1;
		xy xy1_b; xy1_b.x = x1; xy1_b.y = y1;
		xy xy1_e; xy1_e.x = x2; xy1_e.y = y2;
		line ln1; ln1.a = xy1_b; ln1.b = xy1_e;

		xy xy2_b; xy2_b.x = x2; xy2_b.y = y2;
		xy xy2_e; xy2_e.x = x3; xy2_e.y = y3;
		line ln2; ln2.a = xy2_b; ln2.b = xy2_e;

		xy xy3_b; xy3_b.x = x3; xy3_b.y = y3;
		xy xy3_e; xy3_e.x = x4; xy3_e.y = y4;
		line ln3; ln3.a = xy3_b; ln3.b = xy3_e;

		xy xy4_b; xy4_b.x = x4; xy4_b.y = y4;
		xy xy4_e; xy4_e.x = x5; xy4_e.y = y5;
		line ln4; ln4.a = xy4_b; ln4.b = xy4_e;

		xy xy5_b; xy5_b.x = x5; xy5_b.y = y5;
		xy xy5_e; xy5_e.x = x1; xy5_e.y = y1;
		line ln5; ln5.a = xy5_b; ln5.b = xy5_e;

		lines1.push_front(ln1);
		lines1.push_front(ln2);
		lines1.push_front(ln3);
		lines1.push_front(ln4);
		lines1.push_front(ln5);

		list<line> lines2;
		xy xy11_b; xy11_b.x = x11; xy11_b.y = y11;
		xy xy11_e; xy11_e.x = x22; xy11_e.y = y22;
		line ln11; ln11.a = xy11_b; ln11.b = xy11_e;

		xy xy22_b; xy22_b.x = x22; xy22_b.y = y22;
		xy xy22_e; xy22_e.x = x33; xy22_e.y = y33;
		line ln22; ln22.a = xy22_b; ln22.b = xy22_e;

		xy xy33_b; xy33_b.x = x33; xy33_b.y = y33;
		xy xy33_e; xy33_e.x = x44; xy33_e.y = y44;
		line ln33; ln33.a = xy33_b; ln33.b = xy33_e;

		xy xy44_b; xy44_b.x = x44; xy44_b.y = y44;
		xy xy44_e; xy44_e.x = x55; xy44_e.y = y55;
		line ln44; ln44.a = xy44_b; ln44.b = xy44_e;

		xy xy55_b; xy55_b.x = x55; xy55_b.y = y55;
		xy xy55_e; xy55_e.x = x11; xy55_e.y = y11;
		line ln55; ln55.a = xy55_b; ln55.b = xy55_e;

		lines2.push_front(ln11);
		lines2.push_front(ln22);
		lines2.push_front(ln33);
		lines2.push_front(ln44);
		lines2.push_front(ln55);

		bool ex = false;
		for (auto pair : lines1)
		{
			for (auto pair2 : lines2)
			{
				if (intersect(pair.a, pair.b, pair2.a, pair2.b))
				{
					ex = true;
				}
			}
		}
		if (ex)
		{
			cout << "Пятиугольники пересекаются" << endl;
		}
		else cout << "Пятиугольники не пересекаются" << endl;
	}
	else cout << "Сначала создайте пятиугольник" << endl;
}