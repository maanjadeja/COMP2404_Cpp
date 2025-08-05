#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
// #include "SongArray.h"
#include "Array.h"
#include "Song.h"

using namespace std;

class Album {


	// template <class V>
	friend ostream& operator<<(ostream&, const Album&);

	public:
		//constructors
		Album(const string& artist, const string& albumTitle);
		// Album(const Album&); //REMOVE THE COPY CONSTRUCTOR!!!

		//destructor
		~Album();

		//getters
		const string& getTitle(){return title;}
		const string& getArtist(){return artist;}

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		// bool lessThan(const Album& givenAlbum) const;

		//add and remove
		bool addSong(Song* newSong);
		// bool addSong(int, Song*);
		bool getSong(const string& songTitle, Song** outSong) const;
		bool getSong(int givenIndex, Song** outSong) const;
		bool removeSong(const string& songTitle, Song** removedSong);
		bool removeSong(int givenIndex, Song** removedSong);

		int getSize() const;

		void printShort(ostream& ostream) const;
		void print(ostream& ostream) const;

		Song* operator[](int);



	private:
		string title;
		string artist;
		// SongArray* songs;
		Array<Song*> songs; //REPLACING SongArray WITH Array<Song*>

};




#endif
