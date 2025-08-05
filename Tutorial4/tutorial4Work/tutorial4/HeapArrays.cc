
#include "StackArrays.h"
#include "Song.h"
#include "HeapArrays.h"
#include "defs.h"

HeapArrays::HeapArrays(){

  songObjectArray = new Song[ARR_SIZE];
  songPointerArray = new Song*[ARR_SIZE];
  totalNumberOfSongs=0;
}

HeapArrays::~HeapArrays()
{
  for(int i=0; i<totalNumberOfSongs; i++){
    delete songPointerArray[i];
  }
  totalNumberOfSongs=0;
  delete [] songObjectArray;
  delete [] songPointerArray;
}

Song* HeapArrays::getObjectArray(){

  return songObjectArray;

}


Song** HeapArrays::getPointerArray(){

  return songPointerArray;

}

void HeapArrays::addSong(Song& theSong){

  songObjectArray[totalNumberOfSongs]=theSong;

  Song* newSong = new Song(theSong);

  songPointerArray[totalNumberOfSongs]=newSong;

  totalNumberOfSongs++;


}
