#include "Calendar.h"

Calendar::Calendar(){
    numDates = 0;
}

Calendar::~Calendar(){
    // Delete all Dates we are storing.
    // This will prevent memory leaks
    
}

bool Calendar::addDate(int y, int m, int d){
    if (numDates >= MAX_ARRAY) return false;

    Date* date = new Date(y, m, d);

    int index = 0;
    //finds the right index for date
    while (index < numDates){
        if(date->lessThan(*dates[index])){
            break;
        }
        ++index;
    }

    for (int i = numDates; i > index; --i){
        dates[i] = dates[i-1];
    }

    dates[index] = date;

    ++ numDates;
}

bool Calendar::removeDate(int y, int m, int d){
    Date date(y,m,d);

    int index = 0;
    //finds the right index for date
    while (index < numDates){
        if(date.equals(*dates[index])){
            break;
        }
        ++index;
    }

    if (index == numDates) return false;

    delete dates[index];


    while (index < numDates-1){
        dates[index] = dates[index+1];
        ++index;
    }
    --numDates;
}

bool Calendar::getDate(int index, Date** date){
    if (index < 0 || index >= numDates) return false;
    *date = dates[index];
    return true;
}

void Calendar::print(){
    cout<<endl<<"Printing all dates: "<<endl;

    for (int i =0; i < numDates; ++i){
        dates[i]->print();
    }
    
}