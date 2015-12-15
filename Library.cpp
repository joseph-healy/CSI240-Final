/*
CSI-240-52
Joe Healy
Final Assignment
Library Class
*/

#include "Library.h"

using namespace std;

/*Default constructor
PRE: none
POST: head, current and tail nodes set to null
*/
Library::Library()
{
	head = current = tail = NULL;
}

/*addSong - adds a song to the end of the library
PRE: s is a valid song object
POST: s is added to the end of the library.
if head is null, it is set to s
tail and current are set to s
*/
void Library::addSong(Song s)
{
	if (head == NULL)
	{
		head = new LLNode{ s, NULL, NULL };
	}
	else
	{
		LLNode* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new LLNode{ s, temp, NULL };
		tail = current = temp->next;
	}
}

/*removeSong - removes a specific song from the library
PRE: s is a valid song object
POST: if s matches a song in the library, that song will be removed from the library
if not, nothing happens
if s is the tail, tail is set to the previous song
if s is current, current is set to next song, if next song is null current is set to previous song
*/
void Library::removeSong(Song s)
{
	LLNode* temp = head;
	LLNode* match = new LLNode;
	while (temp->next != NULL)
	{
		if (temp->data == s)
		{
			match = temp;
		}
		temp = temp->next;
	}

	if (match != NULL)
	{
		if (match == tail)
		{
			tail = match->prev;
		}
		if (match == current)
		{
			if (match->next != NULL)
			{
				current = match->next;
			}
			else
			{
				current = match->prev;
			}
		}

		LLNode* previous = match->prev;
		LLNode* next = match->next;
		delete match;

		previous->next = next;
		next->prev = previous;
	}
}

/*sort - sorts the library alphabetically by song name
PRE: none
POST: library is sorted A-Z by songname
*/
void Library::sort()
{
	bool swapped = true;
	
	if (head == NULL)
	{
		return;
	}

	while (swapped)
	{
		current = head;
		swapped = false;
		while (current->next != NULL)
		{
			string currSong = current->data.getName();
			string nextSong = current->next->data.getName();

			//transform song titles to lowercase so that they can be compared, found this function at: https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/ 
			transform(currSong.begin(), currSong.end(), currSong.begin(), ::tolower);
			transform(nextSong.begin(), nextSong.end(), nextSong.begin(), ::tolower);

			if (currSong > nextSong)
			{
				swapNodes(current, current->next);
				swapped = true;
			}

			current = current->next;
		}
	}
	
}

/*swapNodes - swaps 2 nodes in the library
PRE: a, and b are valid
POST: node a now contains the data from node b, and vice versa
*/
void Library::swapNodes(LLNode* a, LLNode* b)
{
	Song junk = a->data;
	a->data = b->data;
	b->data = junk;
}

string Library::toString()
{
	string ret;
	LLNode* temp = head;

	while (temp != NULL)
	{
		ret.append(temp->data.toString());
		temp = temp->next;
	}
	
	return ret;
}