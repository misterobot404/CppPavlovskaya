/*
��������� �������� ������, ��������������� ������������� ������� ������������� ������� � ������������ ��������� ����� ����� � ��������,
����� �� ����� ���������� ������ ������� � ���� �������.
�������� ���������, ��������������� ������ � ���� �������.
��������� ������ ��������� ����, ����������� ����������� �������� ���� ������� ������.
*/
#include <iostream>
using namespace std;

class Matrix // ������������� �������
{
private:
	int** a; // ��� �������� ����������
	int w, h;// ���-�� ����� � ��������
public:
	Matrix(int H, int W);
	Matrix();
	~Matrix();
	void SetXY(int Y, int X, int data);		// ��� ���������� ������ ������ y � ������� x
	int GetXY(int Y, int X);				// ���������� �������� �������� ������ y � ������� x
	void Show();
	void Show(int Hbeg, int Wbeg, int Hend, int Wend); // ����� ������� �� ������ HBeg � ���������� Hend, � ������� � WBeg �� Wend
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
	a = new int* [H];// ��������� ������ ��� ������
	for (int i = 0; i < H; i++)
		a[i] = new int[W];// ��������� ������ ��� ������ ������
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
	int** b;// ����� ������� ������
	b = new int* [H];// ��������� ������ ��� ������
	for (int i = 0; i < H; i++)
	{
		b[i] = new int[w];// ��������� ������ ��� ������ ������
		for (int j = 0; j < w; j++)
			b[i][j] = 0; // ����� �������� ������
	}

	for (int i = 0; i < H && i < h; i++)
		for (int j = 0; j < w; j++)
			b[i][j] = a[i][j]; // �������� ����������
			// ������������� ����� ���-�� �����

	for (int i = 0; i < h; i++)
		delete[] a[i]; // ������� ������ �� ��� ������ ����������
	delete[] a;
	h = H;
	a = b;

}
void Matrix::SetW(int W)
{
	int** b;
	b = new int* [h];// ��������� ������ ��� ������
	for (int i = 0; i < h; i++)
	{
		b[i] = new int[W];// ��������� ������ ��� ������ ������
		for (int j = 0; j < W; j++)
			b[i][j] = 0; // ����� �������� ������
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w && j < W; j++)
			b[i][j] = a[i][j]; // �������� ����������


	for (int i = 0; i < h; i++) // ������� ������ �� ��� ������ ����������
		delete[] a[i];
	delete[] a;
	w = W; // ������������� ����� ���-�� ��������
	a = b;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "����� Matrix" << endl;
	cout << "��������� ������������� ������� �������" << endl;
	cout << "������ (���������� �����): ";
	int height;
	cin >> height;
	cout << "������ (���������� ��������): ";
	int width;
	cin >> width;
	Matrix matrix(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int value = i * 5 + j;
			matrix.SetXY(i, j, value);
		}
	}
	cout << "������� ������� � ��������� ������������� ����������" << endl;
	system("pause");
	system("cls");

	while (true)
	{
		cout << endl;
		cout << "����� Matrix (" << matrix.GetH() << "x" << matrix.GetW() << ")" << endl;
		cout << "1.���������� ������� ������ ����������" << endl;
		cout << "2.����� �������" << endl;
		cout << "3.��������� ������ (���������� �����) �������" << endl;
		cout << "4.��������� ������ (���������� ��������) �������" << endl;
		cout << "5.����� ����������" << endl;
		cout << "6.������� �������" << endl;
		cout << ">";
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					cout << "������� [" << i+1 << "]" << "[" << j + 1 << "]: ";
					int value;
					cin >> value;
					matrix.SetXY(i, j, value);
				}
			}
		}
		break;
		case 2:
		{
			cout << endl << "�������:" << endl;
			matrix.Show();
		}
		break;
		case 3:
		{
			cout << "������� ����� ������: ";
			int newH;;
			cin >> newH;
			matrix.SetH(newH);
		}
		break;
		case 4:
		{
			cout << "������� ����� ������: ";
			int newW;;
			cin >> newW;
			matrix.SetW(newW);
		}
		break;
		case 5:
		{
			cout << "������� ��������� ������: ";
			int Hbeg;;
			cin >> Hbeg;
			cout << "������� �������� ������: ";
			int Hend;
			cin >> Hend;
			cout << "������� ��������� �������: ";
			int Wbeg;;
			cin >> Wbeg;
			cout << "������� �������� �������: ";
			int Wend;
			cin >> Wend;
			cout << endl << "����������:" << endl;
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