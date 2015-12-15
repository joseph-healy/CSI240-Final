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
	
	Song test1("bntidote", "Travis Scott", "Rodeo", Song::Genres::HIPHOP, 2015);
	
	Song test2("aaa", "me", "test", Song::Genres::HIPHOP, 1969);

	Library library;
	library.addSong(test);
	library.addSong(test1);
	library.addSong(test2);

	library.sort();

	cout << library.toString() << endl;



	system("pause");
	return 0;
}