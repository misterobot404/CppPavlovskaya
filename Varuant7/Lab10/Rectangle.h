
class Rectangle {
private:
	double x1, x2, y1, y2, dx, dy, r;
public:
	// ����������� � 4 �����������
	Rectangle(double a, double b, double c, double d) : x1(a), x2(b), y1(c), y2(d) {};
	// ����������� �� ���������
	Rectangle() : x1(2), x2(5), y1(2), y2(0) {};
	~Rectangle() { } // ����������

	void Input(); // ����� ����� � ����������
	void Result(); // ����� ������ �� �����
	void Peremeshenie(); // �����������
	void Size(); // ��������� �������
	void Minimal(); // ���������� ������������
	void �ross(); // ����������� 2 ���������������
};

