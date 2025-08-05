
#ifndef SONGARRAYS_H
#define SONGARRAYS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "defs.h"
#include "Song.h"



class SongArrays {

	public:
		//constructor
		SongArrays();
		~SongArrays();




		//setters


		//getters
		Song** getPointerArray();
		int size();



		//other
		bool addSong(Song* theSong);
		bool addSong(int index, Song* theSong);
		bool getSong(string artist, string title, Song** theSong);
		bool getSong(int index, Song** theSong);
		bool removeSong(string artist, string title, Song** theSong);
		bool removeSong(int index, Song** theSong);
		bool isFull();
		void print();




	private:
		//functions


		//variables

		Song** songPointerArray;
		int totalNumberOfSongs;



};
#endif
