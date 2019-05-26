#include "Notebook.h"

size_t recordNumber = 0;

Notebook::Notebook()
{
}
Notebook::Notebook(size_t count) {
	for (size_t i = 0; i < count; i++)
		addNote();
}
Notebook::~Notebook() {
}

void Notebook::addNote() {
	Note note;
	cin >> note;
	notebook_.insert(pair<size_t, Note>(++recordNumber, note));
	cout << endl;
}
void Notebook::eraseNote(size_t number)
{
	bool inp = false;
	for (auto pos = notebook_.begin(); pos != notebook_.end();)
	{
		if (pos->first == number)
		{
			pos = notebook_.erase(pos);
			inp = true;
		}
		else ++pos;
	}
	if (inp != true) cout << "Запись не найдена" << endl;
}
void Notebook::printNotebook() {
	if (notebook_.empty())
	{
		cout << "Записная книжка пуста" << endl;
		return;
	}
	for (auto note : notebook_)
	{
		cout << "Запись номер " << note.first << endl;
		cout << note.second;
		cout << endl;
	}
}
void Notebook::sortAndPrintNotebookByLastName() {
	if (getSize() != 0)
	{
		NoteTempVectorCollection noteTempVectorCollection;
		for (auto note : notebook_)
		{
			NoteTempStruct noteTempVecto;
			noteTempVecto.number_ = note.first;
			noteTempVecto.lastName_ = note.second.getLastName();
			noteTempVecto.dateOfBirth_ = note.second.getDateOfBirth();
			noteTempVecto.phoneNumber_ = note.second.getPhoneNumber();
			noteTempVectorCollection.noteTempVector.push_back(noteTempVecto);
		}
		sort(
			noteTempVectorCollection.noteTempVector.begin(),
			noteTempVectorCollection.noteTempVector.end(),
			[](NoteTempStruct& a, NoteTempStruct& b) {
			return a.lastName_ < b.lastName_;
		}
		);
		for (auto note : noteTempVectorCollection.noteTempVector)
		{
			cout << endl;
			cout << "Запись номер " << note.number_ << endl;
			cout << "Фамилия: " << note.lastName_ << endl;
			cout << "Дата рождения: " << note.dateOfBirth_ << endl;
			cout << "Номер телефона: " << note.phoneNumber_ << endl;
		}
	}
	else cout << "Записная книжка пуста" << endl;
}
void Notebook::sortAndPrintNotebookByDateOfBirth()
{
	if (getSize() != 0)
	{
		NoteTempVectorCollection noteTempVectorCollection;
		for (auto note : notebook_)
		{
			NoteTempStruct noteTempVecto;
			noteTempVecto.number_ = note.first;
			noteTempVecto.lastName_ = note.second.getLastName();
			noteTempVecto.dateOfBirth_ = note.second.getDateOfBirth();
			noteTempVecto.phoneNumber_ = note.second.getPhoneNumber();
			noteTempVectorCollection.noteTempVector.push_back(noteTempVecto);
		}
		sort(
			noteTempVectorCollection.noteTempVector.begin(),
			noteTempVectorCollection.noteTempVector.end(),
			[](NoteTempStruct& a, NoteTempStruct& b) {
			return a.dateOfBirth_ < b.dateOfBirth_;
		}
		);
		for (auto note : noteTempVectorCollection.noteTempVector)
		{
			cout << endl;
			cout << "Запись номер " << note.number_ << endl;
			cout << "Фамилия: " << note.lastName_ << endl;
			cout << "Дата рождения: " << note.dateOfBirth_ << endl;
			cout << "Номер телефона: " << note.phoneNumber_ << endl;
		}
	}
	else cout << "Записная книжка пуста" << endl;
}
void Notebook::searchAndPrintNoteByNumber(size_t number)
{
	bool inp = false;
	for (auto note : notebook_)
	{
		if (note.first == number)
		{
			cout << note.second;
			inp = true;
		}
	}
	if (inp != true) cout << "Записи не найдены" << endl;
}
void Notebook::searchAndPrintNoteByLastName(string lastName)
{
	bool inp = false;
	for (auto note : notebook_)
	{
		if (note.second.getLastName() == lastName)
		{
			cout << "Запись номер " << note.first << endl;
			cout << note.second;
			inp = true;
		}
	}
	if (inp != true) cout << "Записи не найдены" << endl;
}
void Notebook::searchAndPrintNoteByDateOfBirth(string dateOfBirth)
{
	bool inp = false;
	for (auto note : notebook_)
	{
		if (note.second.getDateOfBirth() == dateOfBirth)
		{
			cout << "Запись номер " << note.first << endl;
			cout << note.second;
			inp = true;
		}
	}
	if (inp != true) cout << "Записи не найдены" << endl;
}
void Notebook::searchAndPrintNoteByPhoneNumber(string phoneNumber)
{
	bool inp = false;
	for (auto note : notebook_)
	{
		if (note.second.getPhoneNumber() == phoneNumber)
		{
			cout << "Запись номер " << note.first << endl;
			cout << note.second;
			inp = true;
		}
	}
	if (inp != true) cout << "Записи не найдены" << endl;
}
size_t Notebook::getSize()
{
	return notebook_.size();
}
