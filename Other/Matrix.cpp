#include <iostream>
using namespace std;

class Matrix
{
	private: int N, M, **matr1i;
	public:
		Matrix(int Nm, int Mm)
		{
			N = Nm; 
			M = Mm;

			 matr1i = new int*[N];

			for (int i(0); i < N; i++)
			{
				*(matr1i + i) = new int[M];
			}


			for (int i(0); i < N; i++)
			{
				for (int j(0); j < M; j++)
				{
					cout << "Введите matr1[" << i << "][" << j << "] ";
					cin >> *(*(matr1i + i) + j);
					cout << endl;
				}
			}

			/*for (int i(0); i < N; i++)
			{
				for (int j(0); j < M; j++)
				{
					cout << *(*(matr1i + i) + j) << " ";
				}
				cout << endl;
			}*/
		}
		void  Print()
		{
			for (int i(0); i < N; i++)
			{
				for (int j(0); j < M; j++)
				{
					cout << *(*(matr1i + i) + j) << " ";
	 	  		}
			}
			cout << endl;
		}
};

void main()
{
	setlocale(LC_ALL, "rus");
	int N,M;
	cout << "Матрицу сколько на сколько вы хотите создать";
	cin >> M >> N;
	Matrix Mat(N, M);
	Mat.Print();
	system("pause");
}