#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Tetragon
{
protected:
	double x1, x2, y1, y2;
	size_t ID_SEQUENCE_;
	bool deleted_;
public:
	Tetragon(double a, double b, double c, double d) : x1(a), x2(b), y1(c), y2(d), ID_SEQUENCE_(rand()), deleted_(false) {};
	Tetragon() : x1(0), x2(5), y1(0), y2(5), ID_SEQUENCE_(rand()), deleted_(false) {};
	~Tetragon() { }

	virtual void Input(); // метод ввода с клавиатуры
	void Delete();
	void Result(); // метод вывода на экран
	void Move(); // перемещение
	void IsIntersect(); // пересечение 2 прямоугольников
};

class Quadrate : public Tetragon
{
public:
	void Input();
};

class Pentagon
{
protected:
	double x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
	size_t ID_SEQUENCE_;
	bool deleted_;
public:
	Pentagon() : x1(0), y1(0), x2(1), y2(-1), x3(2), y3(1), x4(2), y4(2), x5(1), y5(0), ID_SEQUENCE_(rand()), deleted_(false) {};
	~Pentagon() { }

	virtual void Input(); // метод ввода с клавиатуры
	void Delete();
	void Result(); // метод вывода на экран
	void Move(); // перемещение
	void IsIntersect(); // пересечение 2 прямоугольников

};

