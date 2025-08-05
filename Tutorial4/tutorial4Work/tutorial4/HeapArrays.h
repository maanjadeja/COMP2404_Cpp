
#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "defs.h"
#include "Song.h"
#include "StackArrays.h"



class HeapArrays {

	public:
		//constructor
		HeapArrays();
		~HeapArrays();




		//setters


		//getters
		Song* getObjectArray();
		Song** getPointerArray();



		//other
		void addSong(Song& theSong);




	private:
		//functions


		//variables

		Song* songObjectArray;
		Song** songPointerArray;
		int totalNumberOfSongs;



};
#endif
