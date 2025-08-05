#include <istream>
#include <string>

#include "HeapArrays.h"
#include "StackArrays.h"
#include "defs.h"

//network data

const string artists[3] ={"Irene", "Bob", "Alice"};


bool testStackObjectArray();
bool testStackPointerArray();
bool testHeapObjectArray();
bool testHeapPointerArray();

int main(){

    int choice = 0;
    cin >> choice;
    bool flag = true;
    switch(choice){
      case 0: flag = testStackObjectArray(); break;
      case 1: flag = testStackPointerArray(); break;
      case 2: flag = testHeapObjectArray(); break;
      case 3: flag = testHeapPointerArray(); break;
    }
    
    
    if (flag){
      return 0;
    }else{
      return 1;
    }
  
}

bool testHeapObjectArray(){
  HeapArrays ha;
  string title;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      Song song(title, artists[i], "Lyrics");
      ha.addSong(song);
  }
  Song* song = ha.getObjectArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    song[i].play();
  }
  return true;
}

bool testHeapPointerArray(){
  HeapArrays ha;
  string title;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      Song song(title, artists[i], "Lyrics");
      ha.addSong(song);
  }
  Song** song = ha.getPointerArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    (*song[i]).play();
  }
  return true;
}

bool testStackObjectArray(){
  StackArrays sa;
  string title;
  for (int i = 0; i < ARR_SIZE; ++i){
      cin >> title;
      Song song(title, artists[i], "Lyrics");
      sa.addSong(song);
  }
  Song* song = sa.getObjectArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    song[i].play();
  }
  return true;
}

bool testStackPointerArray(){
  StackArrays sa;
  string title;
  for (int i = 0; i < ARR_SIZE; ++i){
      cin >> title;
      Song song(title, artists[i], "Lyrics");
      sa.addSong(song);
  }
  Song** song = sa.getPointerArray();
  for (int i = 0; i < ARR_SIZE; ++i){
    (*song[i]).play();
  }
  return true;
}

