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
};

class Quadrate : public Tetragon
{
public:
	double wight;
	void Input();
	void Compare();
};

class Triangle
{
protected:
	double x1, x2, x3, y1, y2, y3;
	size_t ID_SEQUENCE_;
	bool deleted_;
public:
	Triangle() : x1(0), y1(0), x2(1), y2(1), x3(0), y3(2), ID_SEQUENCE_(rand()), deleted_(false) {};
	~Triangle() { }

	virtual void Input(); // метод ввода с клавиатуры
	void Delete();
	void Result(); // метод вывода на экран
	void Move(); // перемещение
	void Compare(); // сравнение площади

};

