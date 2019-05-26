#include <map>
#include <vector>
#include "Note.h"
#include <algorithm>
#include <iterator>

class Notebook
{
public:
	Notebook();
	Notebook(size_t);
	~Notebook();

	void addNote();
	void eraseNote(size_t);
	void printNotebook();
	void sortAndPrintNotebookByLastName();
	void sortAndPrintNotebookByDateOfBirth();
	void searchAndPrintNoteByNumber(size_t);
	void searchAndPrintNoteByLastName(string);
	void searchAndPrintNoteByDateOfBirth(string);
	void searchAndPrintNoteByPhoneNumber(string);
	size_t getSize();

private:
	map<size_t, Note> notebook_;
};

struct NoteTempStruct
{
	size_t number_;
	string lastName_;
	string dateOfBirth_;
	string phoneNumber_;
};
class NoteTempVectorCollection
{
public:
	vector<NoteTempStruct>noteTempVector;
};

