
#include "Song.h"


Song::Song(const string& artist, const string& title, const string& content){

	this->artist = artist;
	this->title = title;
	this->content = content;


}


Song::Song(Song& oldSong)
{
  title  = oldSong.title;
  artist = oldSong.artist;
	content =oldSong.content;
}

void Song::print() const{

	cout<<"Artist: "<<artist<<endl;
	cout<<"Title: "<<title<<endl;

}


void Song::play() const{

	print();
	cout<<"Content: "<<content<<endl;
}

string Song::getArtist() const{

	return artist;

}

string Song::getTitle() const{

	return title;

}

bool Song::matches(const string& artist, const string& title){ //DOUBT: SHOULD THIS BE A CONST?

	/*cout<<"PARAM ARTIST: "<<artist<<endl;
	cout<<"THIS->ARTIST: "<<this->artist<<endl;
	cout<<"PARAM TITLE: "<<title<<endl;
	cout<<"THIS->TITLE: "<<this->title<<endl;*/



	if((this->artist == artist) && (this->title == title)){
		//cout<<"MATCHES: TRUE"<<endl;
		return true;
	}
	else{
		//cout<<"MATCHES: FALSE"<<endl;

		return false;
	}

}
