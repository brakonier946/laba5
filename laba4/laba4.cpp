#include <iostream>

#include <vector>
#include "Spisok.h"

using namespace std;

int main()
{
	Spisok<univer> s;

	s.add(univer::createFromConsole());
	s.add(univer::createFromConsole());
	s.add(univer::createFromConsole());
	s.add(univer::createFromConsole());

	cout << endl << "print: " << endl;
	s.print();

	cout << endl << "print reverse: " << endl;
	s.printReverse();

	s.sort();
	cout << endl << "print sorted data: " << endl;
	s.print();

	return 0;
}
