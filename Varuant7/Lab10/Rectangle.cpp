#include "Rectangle.h"
#include <iostream>
using namespace std;

void Rectangle::Input() {
	cout << "������� ���������� � ����� �����" << endl; cin >> x1;
	cout << "������� ���������� � ������ �����" << endl; cin >> x2;
	cout << "������� ���������� y ������� �����" << endl; cin >> y1;
	cout << "������� ���������� y ������ �����" << endl; cin >> y2;
}
void Rectangle::Result() {
	cout << "�� ����� ��������� ���������� ��������������:" << endl;
	cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
	cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
	cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
}
void Rectangle::Peremeshenie() {
	cout << " �� ������� ������ �� ������ ����������� ������������� �� ��� X ?" << endl;
	cin >> dx;
	cout << " �� ������� ������ �� ������ ����������� ������������� �� ��� Y ?" << endl;
	cin >> dy;
	cout << "���������� ��������� ���������� ��������������:" << endl;
	cout << " A:" << "(" << x1 + dx << "," << y1 + dy << ")" << endl;
	cout << " B:" << "(" << x2 + dx << "," << y1 + dy << ")" << endl;
	cout << " C:" << "(" << x2 + dx << "," << y2 + dy << ")" << endl;
	cout << " D:" << "(" << x1 + dx << "," << y2 + dy << ")" << endl;
}
void Rectangle::Size() {
	cout << " �� ������� ��� �������� ������ �������������� ?" << endl;
	cin >> r;
	cout << "���������� ��������� ���������� ��������������:" << endl;
	cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << " B:" << "(" << x2 * r << "," << y1 << ")" << endl;
	cout << " C:" << "(" << x2 * r << "," << y2 << ")" << endl;
	cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;

}
void Rectangle::Minimal() {
	double x3, x4, y3, y4, x_min = x1, x_max = x1, y_min = y1, y_max = y1;
	cout << " 2 �������������:" << endl;
	cout << "������� ���������� � ����� �����" << endl; cin >> x3;
	cout << "������� ���������� y ������� �����" << endl; cin >> y3;
	cout << "������� ���������� � ������ �����" << endl; cin >> x4;
	cout << "������� ���������� y ������ �����" << endl; cin >> y4;
	cout << endl << "�� ����� ��������� ���������� 1 ��������������:" << endl;
	cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
	cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
	cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
	cout << endl;
	cout << "�� ����� ��������� ���������� 2 ��������������:" << endl;
	cout << " A:" << "(" << x3 << "," << y3 << ")" << endl;
	cout << " B:" << "(" << x4 << "," << y3 << ")" << endl;
	cout << " C:" << "(" << x4 << "," << y4 << ")" << endl;
	cout << " D:" << "(" << x3 << "," << y4 << ")" << endl;
	cout << endl;
	double A[4] = { x1,x2,x3,x4 }, B[4] = { y1,y2,y3,y4 };
	for (int i = 0; i < 4; i++)
	{
		if (x_max < A[i])
		{
			x_max = A[i];
		}
		if (y_max < B[i])
		{
			y_max = B[i];
		}
		if (x_min > A[i])
		{
			x_min = A[i];
		}
		if (y_min > B[i])
		{
			y_min = B[i];
		}
	}
	cout << " ���������� ������������� ���������� ��� ���������� ����� ��������� ����������: " << endl;
	cout << " A:" << "(" << x_min << "," << y_max << ")" << endl;
	cout << " B:" << "(" << x_max << "," << y_max << ")" << endl;
	cout << " C:" << "(" << x_max << "," << y_min << ")" << endl;
	cout << " D:" << "(" << x_min << "," << y_min << ")" << endl;
}
void Rectangle::�ross() {
	double x3, x4, y3, y4, x_min = x1, x_max = x1, y_min = y1, y_max = y1, x1_sred, x2_sred, y1_sred, y2_sred;
	cout << " 2 �������������:" << endl;
	cout << "������� ���������� � ����� �����" << endl; cin >> x3;
	cout << "������� ���������� y ������� �����" << endl; cin >> y3;
	cout << "������� ���������� � ������ �����" << endl;    cin >> x4;
	cout << "������� ���������� y ������ �����" << endl;    cin >> y4;
	cout << endl;
	cout << "�� ����� ��������� ���������� 1 ��������������:" << endl;
	cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
	cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
	cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
	cout << endl;
	cout << "�� ����� ��������� ���������� 2 ��������������:" << endl;
	cout << " A:" << "(" << x3 << "," << y3 << ")" << endl;
	cout << " B:" << "(" << x4 << "," << y3 << ")" << endl;
	cout << " C:" << "(" << x4 << "," << y4 << ")" << endl;
	cout << " D:" << "(" << x3 << "," << y4 << ")" << endl;
	cout << endl;
	double A[4] = { x1,x2,x3,x4 }, B[4] = { y1,y2,y3,y4 };
	for (int i = 0; i < 4; i++)
	{
		if (x_max < A[i])
		{
			x_max = A[i];
		}
		if (y_max < B[i])
		{
			y_max = B[i];
		}
		if (x_min > A[i])
		{
			x_min = A[i];
		}
		if (y_min > B[i])
		{
			y_min = B[i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((A[i] != x_max) && (A[i] != x_min))
		{
			x1_sred = A[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((A[i] != x_max) && (A[i] != x_min) && (A[i] != x1_sred))
		{
			x2_sred = A[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((B[i] != y_max) && (B[i] != y_min))
		{
			y1_sred = B[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((B[i] != y_max) && (B[i] != y_min) && (B[i] != y1_sred))
		{
			y2_sred = B[i];
			break;
		}
	}
	cout << " ������������� �� ����������� ���� ���������� ����� �������� ����������: " << endl;
	cout << " A:" << "(" << x1_sred << "," << y2_sred << ")" << endl;
	cout << " B:" << "(" << x2_sred << "," << y2_sred << ")" << endl;
	cout << " C:" << "(" << x2_sred << "," << y1_sred << ")" << endl;
	cout << " D:" << "(" << x1_sred << "," << y1_sred << ")" << endl;
}
