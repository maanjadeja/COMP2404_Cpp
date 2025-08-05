
#include "Song.h"


Song::Song(const string& artist, const string& title, const string& content){

//const string& artist="", const string& title="", const string& content=""
	this->artist = artist;
	this->title = title;
	this->content = content;


}


Song::Song(Song& oldSong)
{
  title  = oldSong.title;
  artist = oldSong.artist;
	content = "RCMP";
}

void Song::print(){

	cout<<"Artist: "<<artist<<endl;
	cout<<"Title: "<<title<<endl;

}


void Song::play(){

	print();
	cout<<content<<endl;
}
