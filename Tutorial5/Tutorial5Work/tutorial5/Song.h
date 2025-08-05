
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "defs.h"


class Song {

	public:
		//constructor
		Song(const string& artist="", const string& title="", const string& content="");
		Song(Song&);


		//setters


		//getters
		string getArtist() const; //NOTE: MAKE SURE TO USE THIS const KEYWORD IN FUNCTION THAT DONT CHANGE ANY DATA!
		string getTitle() const;


		//other
		void play() const;
		void print() const;
		bool matches(const string& artist, const string& title);


	private:
		//functions


		//variables
		string artist;
		string title;
		string content;


};
#endif
