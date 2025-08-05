
#include "Song.h"
#include "SongArray.h"
#include "Album.h"
#include "defs.h"

Album::Album(string artist, string title){

  this->artist = artist;
	this->title = title;

  songArray = new SongArrays();//this is how we initialize the songArray


}

Album::Album(Album& oldAlbum){
  title  = oldAlbum.title;
  artist = oldAlbum.artist;

  songArray = new SongArrays();

  for(int i=0; i<oldAlbum.songArray->size(); i++){ //NOTE: IF THIS DOES NOT WORK, TRY:"i<*(oldAlbum.songArray)->size();"
    //songArray[i]=oldAlbum.songArray[i]; //DOUBT: WE DONT NEED TO USE GETSONG() OVER HERE CORRECT?
    //bool getSong(int index, Song** theSong);

    Song* newSong;
    oldAlbum.getSong(i,&newSong);

    songArray->addSong(new Song(*newSong)); //we are using the copy constructor of the songclass, so we must dereference

  }
}

Album::~Album(){
  for(int i=0; i<songArray->size(); i++){

    /*
    Album** removedAlbum;

    bool removeResult=false;

    removeResult=theAlbumArray->removeAlbum(artist, title, removedAlbum);//return true if the song exists? I THINK THEY MEAN IF ALBUM EXISTS

    delete *removedAlbum;

    return removeResult;
    */

    //bool removeSong(string artist, string title, Song** theSong);


    Song* removedSong;

    bool removeResult=false;

    removeResult=songArray->removeSong(i, &removedSong);//return true if the song exists? I THINK THEY MEAN IF ALBUM EXISTS

    delete removedSong;



    //delete songArray[i];
  }
  delete songArray;
}

string Album::getArtist(){

  return artist;

}
string Album::getTitle(){

  return title;

}

bool Album::matches(string artist, string title){

	if((this->artist == artist) && (this->title == artist)){
		return true;
	}
	else{
		return false;
	}

}


bool Album::lessThan(Album& alb){

  if(this->artist<=alb.getArtist()){

    if(this->title<=alb.getTitle()){
      return true;
    }

  }
  else{
    return false;
  }


}

bool Album::addSong(Song* theSong){

  if(this->artist  == theSong->getArtist()){

    return songArray->addSong(theSong);

  }
   else{
     return false;
   }


}

bool Album::addSong(int index, Song* theSong){

  if(this->artist  == theSong->getArtist()){

    return songArray->addSong(index,theSong);

  }


}


bool Album::getSong(string title, Song** theSong){



  return songArray->getSong(this->artist, title, theSong);

}

bool Album::getSong(int index, Song** theSong){

  return songArray->getSong(index, theSong);

}

bool Album::removeSong(string title, Song** theSong){

  return songArray->removeSong(this->artist, title, theSong);

}

bool Album::removeSong(int index, Song** theSong){


  return songArray->removeSong(index, theSong);


}

void Album::print(){

  cout<<"Artist: "<<artist<<endl;
  cout<<"Title: "<<title<<endl;


  for(int i=0; i<songArray->size(); i++){

    //bool getSong(int index, Song** theSong);


    //songArray[i]->songPointerArray[i]->print(); //DOUBT: DOUBLE CHECK IF THIS IS HOW WE ARE SUPPOSED TO DO THE PRINTING OF THE SONGS!

    Song* currSong;

    songArray->getSong(i,&currSong);

    currSong->print();

  }


}

void Album::printShort(){

  cout<<"Artist: "<<artist<<endl;
  cout<<"Title: "<<title<<endl;

}

int Album::getAlbumSize(){
  return songArray->size();
}
