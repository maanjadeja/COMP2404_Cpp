#include <iostream>
using namespace std;
#include <string>
#include <vector>


#include "Song.h"
#include "Criteria.h"



using namespace std;

void Criteria::print(ostream& ost){
}



ostream& operator<<(ostream& ost, Criteria& criteria){

	criteria.print(ost);

	return ost;

	// Criteria::print(ost);

}



A_Criteria::A_Criteria(const string& givenArtist): artist(givenArtist) {}

bool A_Criteria::matches(const Song& givenSong){ //This is an ABSTRACT FUNCTION, AS THE MEMORY ADDRESS = 0 HERE
	if(givenSong.getArtist() == this->artist){
		// cout<<"This Criteria focuses on matching the artist's of the song, in this case, the artist's name is: "<<this->artist<<endl;
		return true;
	}
	else{
		return false;
	}
}

void A_Criteria::print(ostream& ost){
	// A_Criteria()
	ost<<"This Criteria focuses on matching the artist's of the song, in this case, the artist's name is: "<<this->artist<<endl;
}



C_Criteria::C_Criteria(const string& givenCategory): category(givenCategory) {}

bool C_Criteria::matches(const Song& givenSong){ //This is an ABSTRACT FUNCTION, AS THE MEMORY ADDRESS = 0 HERE
	if(givenSong.getCategory() == this->category){
		return true;
	}
	else{
		return false;
	}
}

void C_Criteria::print(ostream& ost){
	ost<<"This Criteria focuses on matching the categories of the song, in this case, the category is: "<<this->category<<endl;
}



AorC_Criteria::AorC_Criteria(const string& givenArtist, const string& givenCategory): A_Criteria(givenArtist),C_Criteria(givenCategory){
	// A_Criteria newACriteria(givenArtist);
	// C_Criteria newCCriteria(givenCategory);
}

bool AorC_Criteria::matches(const Song& givenSong){ //This is an ABSTRACT FUNCTION, AS THE MEMORY ADDRESS = 0 HERE
	// if(givenSong.getCategory() == this->category && givenSong.getArtist() == this->artist){
	// 	return true;
	// }
	// else{
	// 	return false;
	// }

	return C_Criteria::matches(givenSong) ||  A_Criteria::matches(givenSong);
}

void AorC_Criteria::print(ostream& ost){
	A_Criteria::print(ost);
	C_Criteria::print(ost);

	// ost<<"This Criteria focuses on matching the categories and the artist's of the song, in this case, the category is: "<<this->category<<" and the artist is: "<<this->artist<<endl;
}
