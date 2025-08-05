
#include "Song.h"
#include "SongArray.h"
#include "defs.h"

SongArrays::SongArrays(){

  songPointerArray = new Song*[MAX_ARRAY];
  totalNumberOfSongs=0;
}


SongArrays::~SongArrays()
{
  for(int i=0; i<totalNumberOfSongs; i++){
    delete songPointerArray[i];
  }
  totalNumberOfSongs=0;
  delete [] songPointerArray;
}



Song** SongArrays::getPointerArray(){

  return songPointerArray;

}

bool SongArrays::addSong(Song* theSong){

  cout<<"theSong title: "<<theSong->getTitle()<<endl;

  if(totalNumberOfSongs<MAX_ARRAY){

    //Song* newSong = new Song(*theSong);

    songPointerArray[totalNumberOfSongs]=theSong;

    totalNumberOfSongs++;

    cout<<"SUCCESFULLY ADDED"<<endl;


    return true;

  }
  else{
    cout<<"FAILED ADDITION"<<endl;
    return false;

  }

}

bool SongArrays::addSong(int index, Song* theSong){ //THIS ADD FUNCTION IS FINE!

  if(totalNumberOfSongs<MAX_ARRAY){

    //check index
    if(0<=index && index<=totalNumberOfSongs){

      for(int j=totalNumberOfSongs; j>index-1; j--){
        if(index<j){

             songPointerArray[j] = songPointerArray[j-1];

        }
        else{
            break;
        }


    }

    //Song* newSong = new Song(*theSong);

    songPointerArray[index]=theSong;

    totalNumberOfSongs++;
    return true;

     //songPointerArray[index] = theSong; DOUBT: INITIALLY WE HAD THIS PIECE OF CODE BUT I LOOKED AT THE PREVIOUS ADDSONG FUNCTION AND HOW WE WERE ADDING THE SONG

  }
  else{
    return false;
  }

  }
  else{
    return false;
  }

}

bool SongArrays::getSong(string artist, string title, Song** theSong){


  for(int i=0; i<totalNumberOfSongs; i++){

    if((songPointerArray[i]->matches(artist,title))){


      *theSong = songPointerArray[i];
      /*cout<<"Title of found song: "<<title<<endl;

      cout<<"PARAM Artist: "<<artist<<endl;
      cout<<"Found song Artist: "<<(**theSong).getArtist()<<endl;

      cout<<"PARAM Title: "<<title<<endl;
      cout<<"Found song Title: "<<(**theSong).getTitle()<<endl;*/


      return true;
    }


  }
  //cout<<"NONE"<<endl;
  return false;


}

bool SongArrays::getSong(int index, Song** theSong){

  if(0<=index && index<totalNumberOfSongs){

    *theSong = songPointerArray[index];

    return true;

  }
  else{
    return false;
  }


}

bool SongArrays::removeSong(string artist, string title, Song** theSong){

  int indexOfSongToRemove=0;

  for(int i=0; i<totalNumberOfSongs; i++){

    if((songPointerArray[i]->matches(artist,title))){

      indexOfSongToRemove=i;
      *theSong = songPointerArray[i];

    }
    else{

      return false;

    }

  }

  for(int j=indexOfSongToRemove; j<totalNumberOfSongs; j++){



    songPointerArray[j] = songPointerArray[j+1];


  }

  totalNumberOfSongs--;

  return true;



}

bool SongArrays::removeSong(int index, Song** theSong){


  if(0<=index && index<totalNumberOfSongs){

    *theSong = songPointerArray[index];

    for(int i=index; i<totalNumberOfSongs; i++){

      songPointerArray[i] = songPointerArray[i+1];



    }
    totalNumberOfSongs--;

    return true;

  }
  else{
    return false;
  }

}

int SongArrays::size(){
  return totalNumberOfSongs;
}


bool SongArrays::isFull(){

  if(totalNumberOfSongs==MAX_ARRAY){

    return true;

  }
  else{
    return false;
  }


}

void SongArrays::print(){

  for(int i=0; i<totalNumberOfSongs; i++){

    songPointerArray[i]->print();

  }


}
