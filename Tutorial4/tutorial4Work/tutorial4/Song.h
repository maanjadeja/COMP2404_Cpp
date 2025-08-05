
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


		//other
		void play();
		void print();


	private:
		//functions


		//variables
		string artist;
		string title;
		string content;


};
#endif
