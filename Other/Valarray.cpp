/*������� 22. ��������� ������� 4 � 5 � �������������� ������ valarray,
������ � ����������� ��������� �����.*/

/*������� 4. ����������� ��������� ��������� ����������� ������� ������������ �������.
����������� ������� ������ ����������� ����������.
�������� ���������, � ������� ����� ��������� ��������� ������:
�	����� ����� ������������ �������� �������.
�	����� ����� ��������� �������, ������������� ����� ������ � ������ �������������� ����������.
�	������������� ������ ����� �������, ����� ������� ������������� ��� ��������, ������ ������� �� ��������� 1, � ����� � ��� ���������.
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
		//���������� ���� ����� ��� ���������
		/*for (auto it = begin(vector); it != end(vector); ++it)
		{
		for (auto qt = it; qt != end(vector); ++qt) {
		if (abs(*qt) <= 1) {
		swap(*it, *qt);
		break;
		}
		}
		}*/
		//���������� ���� ����� find
		for (auto it = begin(valarray); it != end(valarray); it++)
		{
			auto result = find(it, end(valarray), abs(*it) <= 1);
			if (result != end(valarray)) swap(*it, *result);
		}
		valarray[slice(0, 200, 2)] = 666;
		// valarray[slice(0, 200, 2)] = pow(static_cast<valarray<int> >(valarray[slice(0, 200, 2)]), 2);
		// valarray[valarray> 5 && valarray < 8] = -1;
		//����� � ������� ��������� ������
		cout << "���������������  ������\n";
		copy(begin(valarray), end(valarray), ostream_iterator<int>(cout, " "));
		//���������� ������������ ��������� � ������� ��� valarray
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
		cout << "\n�����  ���������  �������,  �������������  �����  ������  �  ������  �������������� ����������=" << sum << endl;

		auto endT = chrono::high_resolution_clock::now();
		cout << "\n��������� ����������� " << chrono::duration_cast<chrono::milliseconds>(endT - beginT).count() << " mili seconds" << endl;
	}
};

/*������� 5. ����������� ��������� ��������� ���������� �������.
�������� ���������, � ������� �������������� ����� ��������� � ���
��������, ������� �� �������� ������������� ���������. ����� �������
����� ���� ������� ��������� ����������, ������������ ������� ���������
�������.*/
class FifthTask {
public:
	FifthTask() {
		const int c = 10;
		valarray<valarray<int>> matrix;
		matrix.resize(c);
		for (int i = 0; i < matrix.size(); ++i)   matrix[i].resize(c);
		cout << "������� " << c << "x" << c << "\n";
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
		//����� ���������� � ��� ��������, ������� �� �������� ������������� ����������
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
				cout << "����� ��������� " << j << " ������� �����: " << summ << endl;
			}
			q = 0;
			summ = 0;
		}
		//������� ����� ���� ��������� ���������� ������������ ������� ���������
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
		cout << "������� ����� ���� ��������� ���������� ������������ ������� ���������: " <<
			s << endl;
	}
};

int  main()
{
	setlocale(LC_ALL, "rus");
	cout << "\n  Available tasks\n4 �������� � ���������� ��������\n5 �������� � 2-������ ��������\n";
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