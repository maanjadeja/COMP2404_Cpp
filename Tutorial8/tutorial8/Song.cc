#include "Song.h"


Song::Song(const string& artist, const string&  title, const string& category,const string& content){

  this->artist = artist;
  this->title = title;
  this->category = category;
  this->content = content;

}

const string& Song::getTitle() const{
  return this->title;
}

const string& Song::getArtist() const{
  return this->artist;
}

const string& Song::getCategory() const{
  return this->category;
}

bool Song::matches(const string& artist, const string& title) const{

  if(this-> artist == artist && this->title == title){
    return true;
  }
  else{
    return false;
  }
}

void Song::print(ostream& ost) const{

  ost<<"Artist: "<<this->artist<<endl;
  ost<<"Title: "<<this->title<<endl;
  ost<<"Category: "<<this->category<<endl;
  ost<<"Content: "<<this->content<<endl;

}

void Song::play(ostream& ost) const{

  ost<<"Artist: "<<this->artist<<endl;
  ost<<"Title: "<<this->title<<endl;
  ost<<"Category: "<<this->category<<endl;
  ost<<"Content: "<<this->content<<endl;

}

ostream& operator<<(ostream& ost, Song& song){

	song.print(ost);
  return ost;
}
