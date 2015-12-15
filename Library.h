/*
CSI-240-52
Joe Healy
Final Assignment
Library Class
*/
#ifndef __LIBRARY_
#define __LIBRARY_

#include "song.h"

using namespace std;

struct LLNode
{
	Song data;
	LLNode* prev;
	LLNode* next;
};


class Library
{
public:
	//public member functions
	
	//default constructor
	Library(); 
	
	//adds a song to the library
	void addSong(Song s); 	

	// Removes a song from the library
	void removeSong(Song s); 
	
	//removes all songs from library
	//void clearLibrary(); 
		
	//returns a string representation of the library
	string toString();

protected:

	LLNode* head;
	LLNode* current;
	LLNode* tail;

};

#endif // __LIBRARY_