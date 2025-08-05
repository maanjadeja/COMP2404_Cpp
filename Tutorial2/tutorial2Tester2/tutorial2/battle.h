
#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Character.h"

using namespace std;

namespace Gondor{

  void fight(Character& fighter, Character& orc);

}

//Gondor::fight(.....)

namespace Mordar{

  void fight(Character& fighter, Character& orc);

}

//Mordar::fight(.....)

//prevents a name conflict and still be functional
#endif
