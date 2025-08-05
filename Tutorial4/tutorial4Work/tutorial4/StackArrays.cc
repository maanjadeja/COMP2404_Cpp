
#include "StackArrays.h"
#include "Song.h"
#include "defs.h"


StackArrays::StackArrays(){

  totalNumberOfSongs=0;

}

StackArrays::~StackArrays(){
  for(int i=0; i<totalNumberOfSongs; i++){
    delete songPointerArray[i];
    //DOUBT: We dont need to delete the Song array right? without the pointers?
  }
  totalNumberOfSongs=0;
}

Song* StackArrays::getObjectArray(){

  //Song* returnSongObjectArray = &arrayOfSongs;

  return arrayOfSongs;//this should be fine

}


Song** StackArrays::getPointerArray(){

  //Song** returningSongPointerArray = &songPointerArray;

  return songPointerArray;//this should be fine as well, we dereference just like this

}


void StackArrays::addSong(Song& theSong){

  arrayOfSongs[totalNumberOfSongs]=theSong;

  Song* newSong = new Song(theSong);

  songPointerArray[totalNumberOfSongs]=newSong;

  totalNumberOfSongs++;


}
