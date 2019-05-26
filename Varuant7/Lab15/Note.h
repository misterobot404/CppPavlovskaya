#include <iostream>
using namespace std;

class Note
{
public:
	Note();
	Note(string, string, string);
	~Note();

	string getLastName();
	string getDateOfBirth();
	string getPhoneNumber();

	friend ostream& operator<<(ostream&, const Note&);
	friend istream& operator>>(istream&, Note&);

private:
	string lastName_;
	string dateOfBirth_;
	string phoneNumber_;
};

