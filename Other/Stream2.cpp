/*

 Определить класс с именем NOTE, содержащий следующие поля: 
 - фамилия
 - имя
 - номер телефона
 - день рождения (массив из трех чисел) 
 Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа NOTE
 Написать программу, выполняющую следующие действия: 
 - ввод с клавиатуры данных в массив, состоящий из восьми объектов типа NOTE, записи должны быть упорядочены по датам дней рождения 
 - вывод на экран информации о человеке, номер те лефона которого введен с клавиатуры, если такого нет, выдать на дисплей соответствующее сообщение 
*/
#include <iostream>
#include <string>
using namespace std;

//config
constexpr size_t numberPersons = 3;

class Note
{
private:
	struct information
	{
		int phoneNumber;
		string name;
		size_t birthday[3];
	};

	size_t noteSize;
	information *ptrInformation;

	friend istream& operator >> (istream& input, const Note& object);
	friend ostream& operator << (ostream& output, const Note& object);
public:
	Note(size_t _noteSize)
	{
		noteSize = _noteSize;
		ptrInformation = new information[noteSize];
	}	

	void sortByBirthday()
	{
		
		for (int i = noteSize - 1; i >= 0; --i)
		{
			for (int j = 0; j < i; j++)
			{
				if (ptrInformation[j].birthday[2] > ptrInformation[j + 1].birthday[2])
				{
					swapStruct(j);
				}
				else if (ptrInformation[j].birthday[2] == ptrInformation[j + 1].birthday[2])
				{
					if (ptrInformation[j].birthday[1] > ptrInformation[j + 1].birthday[1])
					{
						swapStruct(j);
					}
					else if (ptrInformation[j].birthday[0] > ptrInformation[j + 1].birthday[0])
					{
						swapStruct(j);
					}
				}
			}
		}
	}

	void swapStruct(size_t count)
	{
		information tmp;
		tmp = ptrInformation[count];
		ptrInformation[count] = ptrInformation[count + 1];
		ptrInformation[count + 1] = tmp;
	}

	void showInformationByNumber(int _phoneNumber)
	{
		size_t isFind = 0;
		for (size_t i = 0; i < noteSize; i++) {
			if (ptrInformation[i].phoneNumber == _phoneNumber) {
				cout << "Find person #" << (++isFind) << endl;
				cout << "Name: " << ptrInformation[i].name << endl;
				cout << "Birthday: ";
				for (size_t j = 0; j < 3; j++) {
					cout << ptrInformation[i].birthday[j] << ' ';
				}
				cout << endl << endl;
			}
		}
		if (!isFind)
		{
			cout << "Person not found" << endl;
		}
	}

	~Note()
	{
		delete[] ptrInformation;
		ptrInformation = nullptr;
	}
};


istream& operator >> (istream& input, const Note& object)
{
	for (size_t i = 0; i < object.noteSize; ++i) {
		if (i > 0) cin.ignore();
		cout << "Person #" << (i + 1) << ": " << endl;
		cout << "Input the name: ";
		getline(cin, object.ptrInformation[i].name);

		cout << "Input the birthday (dd.mm.yyyy): ";
		for (size_t j = 0; j < 3; j++) {
			cin >> object.ptrInformation[i].birthday[j];
		}

		cout << "Input the phone number: ";
		cin >> object.ptrInformation[i].phoneNumber;
		cout << endl;
	}
	return input;
}

ostream& operator << (ostream& output, const Note& object)
{
	for (size_t i = 0; i < object.noteSize; i++) {

		output << "Find person #" << (i + 1) << endl;
		output << "Name: " << object.ptrInformation[i].name << endl;
		output << "Birthday: ";
		for (size_t j = 0; j < 3; j++) {
			output << object.ptrInformation[i].birthday[j] << ' ';
		}
		output << "Phone number: " << object.ptrInformation[i].phoneNumber << endl;
		output << endl;
	}

	return output;
}

int readInt(istream& stream)
{
	int i;
	stream >> i;
	return i;
}

int main()
{
	system("color 0A ");
	Note myNote(numberPersons);
	cin >> myNote;

	myNote.sortByBirthday();

	cout << "All Person\n";
	cout << myNote << endl;

	cout << "Input the phone number for search\n";
	myNote.showInformationByNumber(readInt(cin));

	system("pause");
	return 0;
}