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
	out << "�������: " << rv.lastName_ << endl;
	out << "���� ��������: " << rv.dateOfBirth_ << endl;
	out << "����� ��������: " << rv.phoneNumber_ << endl;
	return out;
}
istream& operator>>(istream& in, Note& rv) {
	cout << "������� �������: ";
	in >> rv.lastName_;
	cout << "������� ���� ��������: ";
	in >> rv.dateOfBirth_;
	cout << "������� ����� ��������: ";
	in >> rv.phoneNumber_;
	return in;
}
