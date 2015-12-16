/* 
CSI-240-52
Joe Healy
Final Assignment
Song Class
*/

#ifndef __SONG_
#define __SONG_

#include <string>

using namespace std;

class Song
{
public:

	// enum used to keep track of genre
	static enum Genres
	{
		UNKNOWN = -1,
		ALTERNATIVE, // 0
		BLUES, // 1
		CLASSICAL, // 2 
		COUNTRY, // 3
		ELECTRONIC, // 4
		HIPHOP, // 5
		INDIE, // 6
		JAZZ, // 7
		POP, // 8
		RnB, // 9
		ROCK, // 10
	};

	static const string GENRE_NAMES[]; // = {"Alternative", "Blues", "Classical", "Country", "Electronic", "Hip-Hop/Rap", "Indie", "Jazz", "Pop", "R&B", "Rock"}

	//public member functions
	
	//Constructors

	//default constructor
	Song();
	
	//value constructor, allows user to pass in a name, artist, album, genre, length and year
	Song(string n, string a, string al, Genres g, int y);
	
	//copy constructor
	Song(const Song &other);


	//toString - returns a string representation of the Song object
	string toString();

	//getters
	string getName(){ return name; };
	string getArtist(){ return artist; };
	Genres getGenre(){ return genre; };
	string getAlbum(){ return album; };
	int getYear(){ return year; };

	//setters
	void setArtist(string a);
	void setGenre(Genres g);
	void setAlbum(string a);
	void setYear(int y);

	//operators
	bool operator==(const Song &other);

private:
	//private member data

	string name;
	string artist;
	Genres genre;
	string album;
	int year;
};

#endif //__SONG_