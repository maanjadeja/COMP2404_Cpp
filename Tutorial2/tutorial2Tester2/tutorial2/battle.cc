#include "battle.h"
#include "Character.h"
#include<iostream>
#include<string>

void Gondor::fight(Character& fighter, Character& orc){

  int finalFighterStrike = fighter.strike()+1;
  int finalOrcStrike = orc.strike()-1;
  //fighter.damage+=1;
  //orc.damage-=1;

  orc.takeDamage(finalFighterStrike);

  cout<<orc.getCharacterName()<<" takes "<<finalFighterStrike<<" damage!"<<endl;


  //int orcStrike1 = orc.strike();
  fighter.takeDamage(finalOrcStrike);

  cout<<fighter.getCharacterName()<<" takes "<<finalOrcStrike<<" damage!"<<endl;


}

void Mordar::fight(Character& fighter, Character& orc){

  int orcFinalStrike = orc.strike()+1;
  int figherFinalStrike = fighter.strike()-1;

  orc.takeDamage(figherFinalStrike);

  cout<<orc.getCharacterName()<<" takes "<<figherFinalStrike<<" damage!"<<endl;

  fighter.takeDamage(orcFinalStrike);

  cout<<fighter.getCharacterName()<<" takes "<<orcFinalStrike<<" damage!"<<endl;



}
