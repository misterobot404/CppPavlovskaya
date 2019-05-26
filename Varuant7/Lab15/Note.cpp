#include "Note.h"

Note::Note()
{
	lastName_ = "";
	dateOfBirth_ = "";
	phoneNumber_ = "";
}
Note::Note(string SN, string D, string NM)
{
	lastName_ = SN;
	dateOfBirth_ = D;
	phoneNumber_ = NM;
}
Note::~Note()
{
}

string Note::getLastName() {
	return lastName_;
}

string Note::getDateOfBirth()
{
	return dateOfBirth_;
}

string Note::getPhoneNumber()
{
	return phoneNumber_;
}

ostream& operator<<(ostream& out, const Note& rv) {
	out << "Фамилия: " << rv.lastName_ << endl;
	out << "Дата рождения: " << rv.dateOfBirth_ << endl;
	out << "Номер телефона: " << rv.phoneNumber_ << endl;
	return out;
}
istream& operator>>(istream& in, Note& rv) {
	cout << "Введите фамилию: ";
	in >> rv.lastName_;
	cout << "Введите дату рождения: ";
	in >> rv.dateOfBirth_;
	cout << "Введите номер телефона: ";
	in >> rv.phoneNumber_;
	return in;
}
