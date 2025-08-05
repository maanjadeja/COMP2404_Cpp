#include "Songify.h"


Songify::Songify(){

}

Songify::~Songify(){

}

bool Songify::addAlbum (const string& artist, const string& albumTitle){
	// bool MediaFactory::createAlbum(const string& title, const string& owner, Album** alb){
	Album* newAlbum;
	mediaFactory.createAlbum(albumTitle,artist, &newAlbum);

	if(albums.isFull()){
		return false;
	}
	else{
		albums.add(newAlbum);
		return true;
	}


}

bool Songify::addSong (const string& artist, const string& songTitle, const string& albumTitle){
	// bool createSong(const string& name, const string& artist, Song**);
	Song* newSong=NULL;
	bool createSongResult = mediaFactory.createSong(artist, songTitle, &newSong);
	if(albums.isFull() || createSongResult==false){
		return false;
	}
	else{
		for(int i=0; i<albums.getSize(); i++){
			if(albums[i]->getTitle() == albumTitle){
				// bool addSong(Song*);

				return albums[i]->addSong(newSong);
			}

		}
		return false;
	}

}

bool Songify::removeSong (const string& artist, const string& songTitle, const string& albumTitle){
	// bool removeSong(const string& songTitle, Song**);
	Song* removedSong;

	for(int i=0; i<albums.getSize(); i++){
		if(albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist){
			// bool removeSong(const string& songTitle, Song**);
			return albums[i]->removeSong(songTitle, &removedSong); //DOUBT: TO PASS IN AN OUTPUT PARAMETER WHERE DOES THE & SYMBOL GO? ALSO SAME ISSUE ON LINE 69


		}
	}
	return false;

}

bool Songify::removeAlbum (const string& artist , const string& albumTitle){

	int initialSize=albums.getSize();
	for(int i=0; i<albums.getSize(); i++){
		// Array<T>& Array<T>::operator-=(const T& t){
		if(albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist){
			albums-=albums[i];
		}

	}

	if(albums.getSize() < initialSize){
		return true;
	}
	else{
		return false;
	}


}

bool Songify::getAlbum(int givenIndex, Album** outputAlbum) const{
	// T& Array<T>::get(int index){
	Album* foundAlbum = NULL;
	foundAlbum = albums[givenIndex];
	if(foundAlbum == NULL){
		return false;
	}
	else{
		*outputAlbum = foundAlbum;
		return true;
	}

}

const Array<Album*>& Songify::getAlbums() const{
	return albums; //DOUBT: SHOULD RETURN A CONSTANT REFERENCE TO THE ARRAY OF ALBUMS
}

void Songify::getPlaylist(string artist, string category, Array<Song*>& playlist){

	// bool MediaFactory::createCriteria(const string& artist, const string& category, Criteria** crit){


	// Array<Song*> outputPlaylist;
	 Criteria* checker; //WE WILL PASS THIS IN THE createCriteria() FUNCTION
	// // virtual bool matches(const Song&) = 0; //This is an ABSTRACT FUNCTION, AS THE MEMORY ADDRESS = 0 HERE
	// checker.matches()
	mediaFactory.createCriteria(artist,category, &checker);

	// Array<Song*> currPlaylist;

	// // virtual void print(ostream& ost)=0;
	// cout<<endl;
	// cout<<"CHECKING THE TYPE OF CRITERIA WE HAVE: ";
	// checker->print(cout);
	// cout<<endl<<endl;


	for(int i=0; i<albums.getSize(); i++){


		for(int j=0; j<albums[i]->getSize(); j++){

			// bool getSong(int givenIndex, Song** outSong) const;
			Song* currSong=NULL;
			if(albums[i]->getSong(j, &currSong)){

				if(checker->matches(*currSong)){
					// cout<<"CHECKER MATCHES"<<endl;
					// currPlaylist.add(currSong);
					// currSong->print(cout);
					// cout<<endl;
					// currPlaylist+=currSong;
					// currPlaylist.add(currSong);
					playlist.add(currSong);

					// cout<<"currPlaylist: "<<endl;
					// cout<<currPlaylist<<endl;
					// cout<<"currPlaylist END: "<<endl;
					//
					// cout<<"currPlaylist SIZE: "<<currPlaylist.getSize()<<endl;
					//
					// cout<<"Print 0th song"<<endl<<endl;
					//
					// currPlaylist[0]->print(cout);


					// playlist.add(currSong);

				}

			}

		}

	}

	 // playlist = currPlaylist;

	// cout<<"playlist SIZE: "<<playlist.getSize()<<endl;

	//DOUBT: HOW ARE WE SUPPOSED TO CHECK THE category ??
	//WE WILL NEED TO CALL THE createCriteria FUNCTION
	//WE WILL NEED TO DO
	delete checker;

}
