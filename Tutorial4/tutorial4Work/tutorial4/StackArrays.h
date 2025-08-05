
#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "defs.h"
#include "Song.h"



class StackArrays {

	public:
		//constructor
    StackArrays();
    ~StackArrays();



		//setters


		//getters
    Song* getObjectArray();
    Song** getPointerArray();


		//other
    void addSong(Song& theSong);


	private:
		//functions


		//variables
    Song arrayOfSongs[ARR_SIZE];
    Song* songPointerArray[ARR_SIZE];
    int totalNumberOfSongs;


};
#endif
