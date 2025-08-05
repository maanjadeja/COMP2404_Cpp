
#include "MediaFactory.h"
#include <fstream>
#include <limits>


// retrieve Song data from a file and use it to create a Song object
bool MediaFactory::createSong(const string& a, const string& t, Song** song){
    ifstream mediaFile;
    mediaFile.open("media/songinfo.txt");
    string empty, title, content, category, artist, video;

    // We are assuming there is at least one record.
    // In general not a great assumption to make, but the input
    // file is fixed so we can get away with it
    while( true ){
        cout<<"Searching for songs artist: "<<endl;
        getline(mediaFile, artist);
        cout<<"artist: "<<artist<<endl;
        getline(mediaFile, title);
        cout<<"title: "<<title<<endl;
        getline(mediaFile, category);
        getline(mediaFile, content);

        // originally some songs were going to have a video element
        // (ascii art) but this part was removed to make a4 simpler
        getline(mediaFile, video);

        // if we found the right Media, make a new object and return
        if (t == title && a == artist){
            *song = new Song(artist, title, category, content);
            mediaFile.close();
            return true;
        }

        // either there is an empty line
        // and another record, or we are done
        if(!getline(mediaFile, empty))break;
    }

    mediaFile.close();
    return false;
}

bool MediaFactory::createAlbum(const string& title, const string& owner, Album** alb){

  // Album(const string& artist, const string& albumTitle);


  Album* newAlbum = new Album(owner, title);
  if(newAlbum!=NULL){
    *alb = newAlbum;
    return true;
  }
  else{
    return false;
  }



}

bool MediaFactory::createCriteria(const string& artist, const string& category, Criteria** crit){

  if(artist=="" && category==""){

    return false;
  }
  else{
    if(artist!="" && category==""){
      // A_Criteria(const string& givenArtist="");
      // A_Criteria artistCriteria(artist);
      *crit = new A_Criteria(artist); //DOUBT: IS THIS HOW WE ARE SUPPOSED TO BE USING THE DERIVED CLASSES ??
      // cout<<"HERE IN CREATE CRITERIA"<<endl;

      return true;
    }
    if(category!="" && artist==""){
      		// C_Criteria(const string& givenCategory="");
          // C_Criteria categoryCriteria(category);
          *crit = new C_Criteria(category);
          // cout<<"HERE IN CREATE CRITERIA 2"<<endl;

          return true;
    }
    else{
      // AorC_Criteria(const string& givenArtist="", const string& givenCategory="");
      // AorC_Criteria artistCategoryCriteria(artist, category);
      *crit = new AorC_Criteria(artist,category);
      // cout<<"HERE IN CREATE CRITERIA 3"<<endl;

      return true;
    }
  }

}
