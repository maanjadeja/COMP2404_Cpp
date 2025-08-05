#include "Character.h"
#include "battle.h"
#include<iostream>
#include<string>


Character::Character(const string& nameOfCharacter, int maxHealthOfCharacter, int damageOfCharacter){

  //we use this-> only when the parameters have the same name as the private attributes we are assigning the parameters to
  name = nameOfCharacter;
  currentHealth=maxHealthOfCharacter;
  damage = damageOfCharacter;

}


//setters


//getters
string Character::getCharacterName(){
  return name;
}

int Character::strike(){
  return damage;
}



//other
void Character::takeDamage(int damage){

  if((currentHealth-damage)<0){
    currentHealth=0;
  }
  else{
    currentHealth = currentHealth-damage;
  }

}

void Character::print(){
  cout<<"Character Name: "<<name<<" Current Health: "<<currentHealth<<endl;
}
