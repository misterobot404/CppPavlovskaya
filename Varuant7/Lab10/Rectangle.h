
class Rectangle {
private:
	double x1, x2, y1, y2, dx, dy, r;
public:
	// Конструктор с 4 параметрами
	Rectangle(double a, double b, double c, double d) : x1(a), x2(b), y1(c), y2(d) {};
	// Конструктор по умолчанию
	Rectangle() : x1(2), x2(5), y1(2), y2(0) {};
	~Rectangle() { } // Деструктор

	void Input(); // метод ввода с клавиатуры
	void Result(); // метод вывода на экран
	void Peremeshenie(); // перемещение
	void Size(); // изменение размера
	void Minimal(); // построение минимального
	void Сross(); // пересечение 2 прямоугольников
};

