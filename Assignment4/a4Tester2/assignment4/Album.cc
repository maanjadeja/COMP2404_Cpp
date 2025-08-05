#include "Album.h"


Album::Album(const string& artist, const string& albumTitle){
	this->title = albumTitle;
	this->artist = artist;
}

Album::~Album(){

	for(int i=0;i<songs.getSize();i++){
		delete songs[i];
	}
	
}

bool Album::matches(const string& artist, const string& albumTitle) const{
	if(this->artist == artist && this->title == albumTitle){
		return true;
	}
	else{
		return false;
	}
}

// bool Album::lessThan(const Album& givenAlbum) const{
// 	return this->title < givenAlbum.getTitle();
// } //DOUBT: WE DON'T NEED THIS FUNCTION


bool Album::addSong(Song* newSong){

	if(songs.isFull()){
		return false;
	}
	else{
		songs+=newSong;
		return true;
	}

}

bool Album::getSong(const string& songTitle, Song** outSong) const{
	for(int i=0; i<songs.getSize(); i++){
		if(songs[i]->getTitle() == songTitle){
			*outSong = songs[i];
			return true;
		}
	}
	return false;
}

bool Album::getSong(int givenIndex, Song** outSong) const{

	if(givenIndex>=songs.getSize() || givenIndex<0){
		return false;
	}
	else{
		*outSong = songs[givenIndex];
		return true;
	}
}

bool Album::removeSong(const string& songTitle, Song** removedSong){
	for(int i=0; i<songs.getSize(); i++){
		if(songs[i]->getTitle() == songTitle){
			*removedSong = songs[i];
			songs-=songs[i];
			return true;
		}
	}
	return false;
}

bool Album::removeSong(int givenIndex, Song** removedSong){
	if(givenIndex>=songs.getSize() || givenIndex<0){
		return false;
	}
	else{
		*removedSong = songs[givenIndex];
		songs-=songs[givenIndex];
		return true;
	}
}


int Album::getSize() const{
	return songs.getSize();
}


// T& Array<T>::operator[](int index){
Song* Album::operator[](int index){

		return songs[index];

}


void Album::printShort(ostream& ostream) const{
	// string title;
	// string artist;
	ostream<<"Title: "<<this->title<<endl;
	ostream<<"Artist: "<<this->artist<<endl;
	// return ostream; DOUBT: WE WON'T NEED TO RETURN OSTREAM OVER HERE? SINCE ITS A VOID FUNCTION AND THE SPEC SAYS TO JUST GIVE AN OSTREAM ARGUMENT;
}


void Album::print(ostream& ostream) const{

	ostream<<"Title: "<<this->title<<endl;
	ostream<<"Artist: "<<this->artist<<endl;

	//ostream<<songs<<endl; //THIS SHOULD CALL THE OSTREAM OPERATOR FUNCTION FROM THE ARRAY CLASS WE IMPLEMENTED!
	for(int i=0; i<songs.getSize(); i++){
		ostream<<*songs[i]<<endl;
	}


}

ostream& operator<<(ostream& out, const Album& album)
{

	album.printShort(out); //DOUBT: HERE DO WE HAVE TO DO PRINT OR printShort ??
	// out<<album<<endl;

	return out; //DOUBT: IS THIS HOW WE OVERLOAD THE STREAM INSERTION OPERATOR, AND IS IT SUPPOSED TO BE GLOBAL JUST LIKE ARRAY.H!!!!

}
