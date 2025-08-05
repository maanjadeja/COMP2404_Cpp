
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Character {

	public:
		//constructor
		Character(const string& nameOfCharacter, int maxHealth, int damage);


		//setters


		//getters
		string getCharacterName();


		//other
		 void takeDamage(int damage);
		 int strike();
		 void print();


	private:
		//functions


		//variables
		string name;
		int maxHealth;
		int currentHealth;
		int damage;


};
#endif
