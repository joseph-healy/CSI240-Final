/*
CSI-240-52
Joe Healy
Final Assignment
main source file
*/

#include <iostream>
#include "song.h"
#include "Library.h"

using namespace std;

int main()
{
	Song test("Antidote", "Travis Scott", "Rodeo", Song::Genres::HIPHOP, 2015);
	cout << test.toString() << endl;
	
	Song test1("Antidote", "Travis Scott", "Rodeo", Song::Genres::HIPHOP, 2015);
	
	if (test == test1) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;

	Library library;
	library.addSong(test);
	library.addSong(test1);

	cout << library.toString() << endl;
	cout << "==========================" << endl;
	cout << "After removal:" << endl;
	library.removeSong(test1);
	cout << library.toString();


	system("pause");
	return 0;
}