#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>

using namespace std;

class Criteria {

  friend ostream& operator<<(ostream&, Criteria&);
	public:
		virtual bool matches(const Song&) = 0; //This is an ABSTRACT FUNCTION, AS THE MEMORY ADDRESS = 0 HERE
		virtual void print(ostream& ost)=0;


	private:


};

class A_Criteria : virtual public Criteria
{
  public:
		A_Criteria(const string& givenArtist="");
		virtual bool matches(const Song& givenSong);
		virtual void print(ostream& ost);



	private:   //KEEP ATTRIBUTES PRIVATE, AND THEN JUST USE THE matches(const Song& givenSong) FUNCTION
		string artist;

};

class C_Criteria : virtual public Criteria
{
  public:
		C_Criteria(const string& givenCategory="");
		virtual bool matches(const Song& givenSong);
		virtual void print(ostream& ost);


	private:
		string category;

};

class AorC_Criteria : public A_Criteria, public C_Criteria
{
  public:
		AorC_Criteria(const string& givenArtist="", const string& givenCategory="");
		virtual bool matches(const Song& givenSong);
		virtual void print(ostream& ost);

	private:



};

#endif
