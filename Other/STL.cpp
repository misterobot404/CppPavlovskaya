/*������ 1. ��������� ������� 4 � �������������� ���������� ������������ ������� � ���������� ����������.
���������� ����������� (�� ����� �������� ���������) ����������� � ������� ����������� ��������� �����.
������� 4. ����������� ��������� ��������� ����������� ������� ������������ �������.
����������� ������� ������ ����������� ����������.
�������� ���������, � ������� ����� ��������� ��������� ������:
�	����� ����� ������������ �������� �������.
�	����� ����� ��������� �������, ������������� ����� ������ � ������ �������������� ����������.
�	������������� ������ ����� �������, ����� ������� ������������� ��� ��������, ������ ������� �� ��������� 1, � ����� � ��� ���������.*/
#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>
#include	<chrono>
#include	<iterator>
using  namespace  std;

class FourthTask
{
	static const int size = 100000;
	int j = 0;
	double sum = 0, fl = 0, min = 0;
public:
	FourthTask() {
		auto beginT = chrono::high_resolution_clock::now();
		vector <int> vector(size);
		//foreach
		for (auto &i : vector) {
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
		for (auto it = begin(vector); it != end(vector); it++)
		{
			auto result = find(it, end(vector), abs(*it) <= 1);
			if (result != vector.end()) swap(*it, *result);
		}
		//����� � ������� ��������� ������
		cout << "���������������  ������\n";
		copy(begin(vector), end(vector), ostream_iterator<int>(cout, " "));
		//���������� ��������� ������������ ��������� � ������� ��� STL
		cout << "\nMin element " << *min_element(begin(vector), end(vector));

		for (auto i : vector)
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


/*������ 2. �������� ����� ��������� � ������� ������� ����������� ���������� (������������ ���� <chrono>). ��������
���������� ��������� � ����������� ������ ����������� ������� (������� 4), ���������� ��� ���������� ������� 10.
������� 10. ��� �������� ������ � ��������� ������� ��������� � ������ TABLET, ���������� ��������� ����: �����, ������������ �������, ��������, ���������� ������, ��������� ������, ����, ������� ������ ������� �����, ������� ����������, ����������� ������, ���������� ������.
�������� ������� ������ � �������� ���� ������ � �������� �� ����������� ���������. ��������� �����: � ������ ���� ������ ����������� ���������� ��������� � ���� �������; ����� ��� ��������� ����������� ������ � ��������.
�������� �������, ����������� ������ � �������� �� ����� � ���������, ���������� ���� �� ��������� ������������ �������������.
�������� ������ ���������, ��������� ���� � ������� � ��������� (������ �������� � ����������) � ��������� �� ����� ����������� ������.
*/


/*������ 3. ��������� ������� 7 � �������������� ���������� ������������ ������� � ���������� ����������. �����������
� ������������������ ��� �������������� ������� (���������) ����������� ��������� �������� ������������ ����������.
������� 7	������� ��������� � ������ AEROFLOT, ���������� ��������� ����:
-�������� ������ ���������� �����;
-����� �����
-��� ��������
�������� ���������, ����������� ��������� ��������:
-���� � ���������� ������ � ������, ��������� �� ���� ��������� ���� AEROFLOT
-������ ������ ���� ��������� � ���������� ������� �� ��������� ������� ����������
-����� �� ����� ������� ���������� � ������� ������, ������������� ���������, ��� �������� ������ � ����������
-���� ����� ������ ���, ������ �� ������� ��������������� ���������*/

class SeventhTask
{
	struct AEROFLOT
	{
		string namereice;
		int �somoleta;
		string tipsomoleta;
	};
public:
	SeventhTask() {
		cout << " AEROFLOT\n������� ��������� ���� AEROFLOT ����� � ����? ";
		int T;
		cin >> T;
		database�reation(T);
		task(T);
	}
	vector <AEROFLOT> DateBase;
	AEROFLOT AirStruct;
	void database�reation(int count) {
		for (; count != 0; count--)
		{
			cout << "������� ����� ���������� ";
			cin >> AirStruct.namereice;
			cout << "������� ��� �������� ";
			cin >> AirStruct.tipsomoleta;
			cout << "������� ����� �������� ";
			cin >> AirStruct.�somoleta;
			DateBase.push_back(AirStruct);
			cout << "\n";
		}
	};
	int task(int count) {
		while (true)
		{
			cout << "\n  Available tasks\n1 ������ ������� ���������� ������ ������������ �� ��������\n2 ������ �������� ��������������� �� ������� ������\n3 ����� �� ���� �������\n";
			cout << "\nEnter the job number, or -1 to exit ";
			int T;
			cin >> T;
			cout << "\n";
			switch (T)
			{
			case 1: {
				sort(DateBase.begin(), DateBase.end(), [](const AEROFLOT& lhs, const AEROFLOT& rhs) {
					return (lhs.namereice < rhs.namereice);
				});
				for (auto it = DateBase.begin(); it != DateBase.end(); ++it)
				{
					cout << "\n����� ���������� > " << it->namereice << "\n��� ������� > " << it->tipsomoleta << "\n����� ����� > " << it->�somoleta;
				}
				break;
			}
			case 2: {
				sort(DateBase.begin(), DateBase.end(), [](const AEROFLOT& lhs, const AEROFLOT& rhs) {
					return (lhs.�somoleta < rhs.�somoleta);
				});
				cout << "\n������ �������� ��������������� �� ������� ������:\n";
				for (auto it = DateBase.begin(); it != DateBase.end(); ++it)
				{
					cout << "\n����� ���������� > " << it->namereice << "\n��� ������� > " << it->tipsomoleta << "\n����� ����� > " << it->�somoleta;
				}
				break;
			}
			case 3: {
				cout << "\n\n������� ��� ������� ";
				string typeaircraft;
				cin >> typeaircraft;
				bool ret = false;
				for (auto it = DateBase.begin(); it != DateBase.end(); ++it)
				{
					if (it->tipsomoleta == typeaircraft)
					{
						cout << "\n����� ���������� " << it->namereice;
						cout << "\n����� ����� " << it->�somoleta << "\n";
						ret = true;
					}
				}
				if (!ret) printf("����� ������ ���");
				break;
			}
			case -1: return 1;
			default:
				break;
			}
		}
	}
};

int  main()
{
	setlocale(LC_ALL, "rus");
	cout << "\n  Available tasks\n4 �������� � ���������� ��������\n0 ����� ������� ��������� �������\n7 ��������� AEROFLOT\n";
	cout << "\nEnter the job number ";
	int T;
	cin >> T;
	cout << "\n";
	switch (T)
	{
	case 4:
	{
		FourthTask My4;
		cout << endl;
		system("pause");
		break;
	}
	case 0:
	{
		break;
	}
	case 7:
	{
		SeventhTask My7;
		cout << endl;
		system("pause");
		break;
	}
	default:
		break;
	}
}