
#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "defs.h"
#include "Song.h"
#include "SongArray.h"



class Album {

	public:
		//constructor
		Album(string artist, string title);
		Album(Album&);
		~Album();




		//setters


		//getters
		string getArtist();
		string getTitle();
		//helper function
		int getAlbumSize();




		//other
		bool matches(string artist, string title);
		bool lessThan(Album& alb);
		bool addSong(Song* theSong);
		bool addSong(int index, Song* theSong);
		bool getSong(string title, Song** theSong);
		bool getSong(int index, Song** theSong);
		bool removeSong(string title, Song** theSong);
		bool removeSong(int index, Song** theSong);
		void print();
		void printShort();










	private:
		//functions


		//variables
		string artist;
		string title;
		SongArrays* songArray;


};
#endif
