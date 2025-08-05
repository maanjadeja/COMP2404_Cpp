#include <iostream>
#include <string>
#include "Character.h"
#include "battle.h"
using namespace std;


int main(){

    cout<<"Please input name, max health and damage for your fighter character"<<endl;

    string theName;
    int theMaxHealth;
    int theDamage;

    cout<<"Name of Fighter: ";
    cin>>theName;

    cout<<"Max Health of Fighter: ";
    cin>>theMaxHealth;

    cout<<"Damage of Fighter: ";
    cin>>theDamage;


    Character fighter = Character(theName, theMaxHealth, theDamage);

    //to call the functions use fighter. ____

    cout<<endl;
    cout<<"Please input name, max health and damage for your orc character"<<endl;


    string theName2;
    int theMaxHealth2;
    int theDamage2;

    cout<<"Name of Orc Character: ";
    cin>>theName2;

    cout<<"Max Health of Orc Character: ";
    cin>>theMaxHealth2;

    cout<<"Damage of Orc Character: ";
    cin>>theDamage2;

    Character orcCharacter = Character(theName2, theMaxHealth2, theDamage2);

    cout<<endl;

    fighter.print();
    orcCharacter.print();

    cout<<endl;


    Gondor::fight(fighter, orcCharacter);

    cout<<endl;

    fighter.print();
    orcCharacter.print();

    cout<<endl;

    Mordar::fight(fighter, orcCharacter);

    cout<<endl;

    fighter.print();
    orcCharacter.print();

    cout<<endl;







}
