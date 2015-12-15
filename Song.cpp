/*
CSI-240-52
Joe Healy
Final Assignment
Song Class Definition
*/

#include "song.h"

const string Song::GENRE_NAMES[] = { "Alternative", "Blues", "Classical", "Country", "Electronic", "Hip-Hop/Rap", "Indie", "Jazz", "Pop", "R&B", "Rock" };


/*default constructor - initializes member data
PRE: none
POST: length, and year set to 0
	album, and artist set to empty string
	genre set to UNKNOWN
*/
Song::Song()
{
	this->year = 0;
	this->album = "";
	this->artist = "";
	this->genre = Genres::UNKNOWN;
}

/*value constructor - allows user to set member data on construction
PRE: n, a, al, g, and y are valid
POST: 
	name set to n
	artist set to a,
	album set to al,
	genre set to g,
	year set to y
*/
Song::Song(string n, string a, string al, Genres g,		int y)
{
	this->name = n;
	this->artist = a;
	this->genre = g;
	this->album = al;
	this->year = y;
}

/*toString - returns a strign representation of the song object
PRE: none
POST: FCTVAL is a formatted string containing details on the song object
*/
string Song::toString()
{
	string space = "             ";
	return name + "\nArtist: " + space.substr(0, space.length() - artist.length()) + artist
		+ "\nAlbum:  " + space.substr(0, space.length() - album.length()) + album
		+ "\nGenre:  " + space.substr(0, space.length() - GENRE_NAMES[genre].length()) + GENRE_NAMES[genre]
		+ "\nYear:   " + space.substr(0, space.length() - to_string(year).length()) + to_string(year);
}

bool Song::operator==(const Song &other)
{
	return (this->name == other.name && this->album == other.album && this->artist == other.artist && this->genre == other.genre && this->year == other.year);
}