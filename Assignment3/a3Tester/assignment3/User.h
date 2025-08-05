#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class User {

    public:
      User(char idChar, int idInt, string name, int rating, Location newLocation);
      // ~User();
      string getId() const;
      string getName() const;
      int getRating() const;
      Location getLocation() const;
      void setRating(int newRating);
      void setLocation(Location newLocation);
      void setLocation(int x, int y);
      bool lessThan(User user);
      void print() const;

    protected:
      string id;
      string name;
      int rating;
      Location currLocation; //DOUBT: DOES LOCATION HAVE TO BE A Location* ?


    private:


};

#endif
