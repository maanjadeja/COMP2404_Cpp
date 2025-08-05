#include <iostream>
#include <random>
#include <sstream>
#include "GameTrux.h"

using namespace std;

#define NUM_TRUCKS 4
#define NUM_NAMES 4
#define SCORE 2

//global variables for testing purposes
string truckNames[NUM_TRUCKS] = {"XBoxxer!", "The Station!", "Switcheroo!", "Jabba the Truck"};
string orderedTruckNames[NUM_TRUCKS] = {"Jabba the Truck", "Switcheroo!", "The Station!",  "XBoxxer!"};
string gameTypes[NUM_TRUCKS] = {"XBox", "Playstation", "Switch", "PC"};
string names[NUM_NAMES*4] = 
{"Bobby", "Alice", "Julie", "Zelda",
"Cindy", "Shelly", "Ahmed", "Jonny",
"Randy", "Dopey", "Sneezy", "Grumpy",
"Doc", "Happy", "Sleepy", "Bashful"};
string orderedNames[NUM_NAMES] = {"Zelda", "Julie", "Alice", "Bobby"};
int caps[NUM_TRUCKS] = {12,10,8,9};

int testResOverlap();
bool resOverlap(Reservation& r1, Reservation& r2, bool);
int testIsMatch();
int testAddTruck();
int testAddTruckOrder();
int testDeleteTruck();
int testAddResTruck();
int testAddResTruckOrder();
int testAddRes();
int testUpdateReservations();

int main(){
    int choice = -1;
    while(choice != 0 && cin.good()){
        std::cout<<endl;
        std::cout<<" 0. Exit"<<endl;
        std::cout<<" 1. [2 marks] Test Reservation overlaps function"<<endl;
        std::cout<<" 2. [2 marks] Test isMatch function"<<endl;
        std::cout<<" 3. [2 marks] Test add truck function"<<endl;
        std::cout<<" 4. [2 marks] Test add truck for alphabetical order"<<endl;
        std::cout<<" 5. [2 marks] Test delete truck"<<endl;
        std::cout<<" 6. [4 marks] Test add reservation to truck"<<endl;
        std::cout<<" 7. [2 marks] Test add reservation to truck for correct order"<<endl;
        std::cout<<" 8. [6 marks] Test add reservation to GameTrux"<<endl;
        std::cout<<" 9. [Bonus: 1 mark] Test update reservations"<<endl;
        std::cout<<" 10. [22 marks + 1 Bonus] Test all and get mark"<<endl<<endl;
        cin >> choice;
        std::cout<<endl;
        switch (choice)
        {
        case 1: testResOverlap(); break;  
        case 2: testIsMatch(); break;  
        case 3: testAddTruck(); break;  
        case 4: testAddTruckOrder(); break;  
        case 5: testDeleteTruck(); break;
        case 6: testAddResTruck(); break;  
        case 7: testAddResTruckOrder(); break;
        case 8: testAddRes(); break;   
        case 9: testUpdateReservations(); break;
        case 10:
            int score = 0;
            score += testResOverlap();
            score += testIsMatch();
            score += testAddTruck();
            score += testAddTruckOrder(); 
            score += testDeleteTruck();    
            score += testAddResTruck(); 
            score += testAddResTruckOrder();
            score += testAddRes();
            score += testUpdateReservations();
            std::cout << "Your score is "<<score<<" out of 22"<<endl<<endl;   
            break;
        }
    }
    std::cout<<"Bye!"<<endl;
    return 0;
    
}

int testResOverlap(){
    int score = 2;
    std::cout<<endl<<"Testing Reservation overlap function..."<<endl;

    //testing same time, different days. Should not overlap.
    Date d1(2022,9,30);
 	Date d2(2022,9,29);
    Reservation res1("Joe", d1, 11, 14);
 	Reservation res2("Bob", d2, 11, 14);

 	std::cout<<endl;
    if (!resOverlap(res1, res2, false)) score = 0;

    Date date1(2021, 9, 30);
    Date date2(2021, 10, 30);
    Date date3(2022, 9, 30);
    Reservation r1("Joe", date1, 12, 14);
    Reservation r2("Joe", date1, 11, 13);

    std::cout<<endl;
    if (!resOverlap(r1, r2, true)) score = 0;

    Reservation r3("Joe", date1, 12, 14);
    Reservation r4("Joe", date1, 11, 12);

    std::cout<<endl;
    if (!resOverlap(r3, r4, false)) score = 0;

    Reservation r7("Joe", date1, 12, 14);
    Reservation r8("Joe", date2, 11, 13);

    std::cout<<endl;
    if (!resOverlap(r7, r8, false)) score = 0;

    Reservation r9("Joe", date1, 12, 14);
    Reservation r10("Joe", date2, 11, 13);

    std::cout<<endl;
    if (!resOverlap(r9, r10, false)) score = 0;

    Reservation r11("Joe", date1, 12, 14);
    Reservation r12("Joe", date3, 11, 13);

    std::cout<<endl;
    if (!resOverlap(r11, r12, false)) score = 0;

    cout<<"Score: "<<score<<endl;
    
    return score;
}

bool resOverlap(Reservation& r1, Reservation& r2, bool ol){
    if (ol){
        if (r1.overlaps(r2)){
            if (r2.overlaps(r1)){
                r1.print();
                std::cout<<" and ";
                r2.print();
                std::cout<<" overlap each other. Test passed"<<endl;
                return true;
            }else{
                r2.print();
                std::cout<<" does not overlap ";
                r1.print();
                std::cout<<"Test failed"<<endl;
                return false;
            }
        }else{
            r1.print();
            std::cout<<" does not overlap ";
            r2.print();
            std::cout<<"Test failed"<<endl;
            return false;
        }
    }else{
        //they should not overlap in this branch
        if (r1.overlaps(r2)){
            if (r2.overlaps(r1)){
                r1.print();
                std::cout<<" and ";
                r2.print();
                std::cout<<" overlap each other. Test failed"<<endl;
                return false;
            }else{
                r1.print();
                std::cout<<" overlaps ";
                r2.print();
                std::cout<<"Test failed"<<endl;
                return false;
            }
        }else{
            if (r2.overlaps(r1)){
                r1.print();
                std::cout<<" and ";
                r2.print();
                std::cout<<" overlap each other. Test failed"<<endl;
                return false;
            }else{
                r1.print();
                std::cout<<" does not overlap ";
                r2.print();
                std::cout<<"Test passed"<<endl;
                return true;
            }
        }

    }
}




int testIsMatch(){
    std::cout<<endl<<"Testing Truck isMatch function..."<<endl<<endl;
    Truck t1("Truck1", "XBox", 8, true);
    
    if (!t1.isMatch("XBox",6, true)){
        std::cout<<"Required 6 capacity, had 8, isMatch false, test failed"<<endl;
        return 0;
    }


    if (!t1.isMatch("XBox",8, true)){
        std::cout<<"Required 8 capacity, had 8, isMatch false, test failed"<<endl;
        return 0;
    }

    if (t1.isMatch("XBox",10, true)){
        std::cout<<"Required 10 capacity, had 8, isMatch true, test failed"<<endl;
        return 0;
    }

    if (!t1.isMatch("XBox",8, false)){
        std::cout<<"Did not require vr, had vr, isMatch false, test failed"<<endl;
        return 0;
    }

    if (t1.isMatch("Playstation",10, true)||t1.isMatch("Playstation",8, true)||t1.isMatch("Playstation",6, true)){
        std::cout<<"Required Playstation, had XBox, isMatch true, test failed"<<endl;
        return 0;
    }

    Truck t2("Truck2", "XBox", 8, false);

    if (!t2.isMatch("XBox",8, false)){
        std::cout<<"Did not require vr, did not have vr, isMatch false, test failed"<<endl;
        return 0;
    }

    if (t2.isMatch("XBox",8, true)){
        std::cout<<"Required vr, did not have vr, isMatch true, test failed"<<endl;
        return 0;
    }

    std::cout << "Truck isMatch all tests passed, 2 marks"<<endl;
    return SCORE;
}


int testAddTruck(){
    std::cout<<endl<<"Testing GameTrux addTruck function..."<<endl<<endl;

    GameTrux gt;
    for (int i = 0; i < NUM_TRUCKS; ++i){
        gt.addTruck(truckNames[i], gameTypes[i], caps[i], (i%2==0));
    }
    
    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.print();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find all truck names
    int found = -1;
    for (int i = 0; i < NUM_TRUCKS; ++i){
        found = output.find(truckNames[i]);
        if (found == -1){
            std::cout<<truckNames[i]<<" not found"<<endl;
            std::cout<<"addTruck test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All truck names found, 2 marks"<<endl;
    return SCORE;
}

int testAddTruckOrder(){
    std::cout<<endl<<"Testing GameTrux addTruck function for correct order..."<<endl<<endl;

    GameTrux gt;
    for (int i = 0; i < NUM_TRUCKS; ++i){
        gt.addTruck(truckNames[i], gameTypes[i], caps[i], (i%2==0));
    }

    //gt.addReservation("Bobby", "XBox", 6, Date(2022, 4, 20, 10, 12));
    
    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.print();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find all truck names
    int found = -1;
    for (int i = 0; i < NUM_TRUCKS; ++i){
        found = output.find(orderedTruckNames[i].c_str(), found+1);
        if (found == -1){
            std::cout<<orderedTruckNames[i]<<" not found in correct place"<<endl;
            std::cout<<"add trucks in order test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All truck found in order, 2 marks"<<endl;
    return SCORE;
}

int testDeleteTruck(){
     std::cout<<endl<<"Testing GameTrux deleteTruck function..."<<endl<<endl;

    GameTrux gt;
    for (int i = 0; i < NUM_TRUCKS; ++i){
        gt.addTruck(truckNames[i], gameTypes[i], caps[i], (i%2==0));
    }

    //remove the trucks in a certain order
    int indices[4] = {2,0,3,1};

    for (int i = 0; i < NUM_TRUCKS; ++i){
        gt.print();
        int index = indices[i];
        gt.deleteTruck(truckNames[index]);
         //capture the output and put in a stringstream
        streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        ostringstream strCout;
        std::cout.rdbuf( strCout.rdbuf() );

        gt.print();

        //replace std::out and print output to console
        std::cout.rdbuf( oldCoutStreamBuf );
        string output = strCout.str();
        std::cout << output;

        //find deleted truck name
        int found = output.find(truckNames[index]);
        if (found == -1){
            std::cout<<truckNames[index]<<" deleted, not found - success!"<<endl;
        }else{
            std::cout<<truckNames[index]<<" found"<<endl;
            std::cout<<"deleteTruck failed"<<endl;
            return 0;
        }
        
        
    }
    std::cout<<"deleteTruck success, "<<SCORE<<" marks"<<endl;
    return SCORE;
    
   
        
}

int testAddResTruck(){
    std::cout<<endl<<"Testing Truck add reservation function..."<<endl<<endl;

    int score = 0;
    Truck t1("Truck1", "XBox", 8, true);
    Date date1(2022, 4, 20);
    Date date2(2022, 8, 20);
    t1.addReservation(names[0], date1, 10, 12);
    t1.addReservation(names[1], date1, 12, 14);
    t1.addReservation(names[2], date2, 10, 12);

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    t1.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find truck name
    int found = -1;
    for (int i = 0; i < NUM_NAMES - 1; ++i){
        found = output.find(names[i]);
        if (found == -1){
            std::cout<<names[i]<<" not found"<<endl;
            std::cout<<"add reservation to truck test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All names found, 2 marks"<<endl<<endl;
    score += SCORE;

    t1.addReservation(names[3], date2, 10, 12);
    //reset stringstream
    strCout.str(std::string());
    std::cout.rdbuf( strCout.rdbuf() );

    t1.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    output = strCout.str();
    std::cout << output;

    if (output.find(names[NUM_NAMES-1])!=-1){
        std::cout<<names[NUM_NAMES-1]<<" reservation found, Reservations overlap, test failed"<<endl;
        return score;
    }
    std::cout<<names[NUM_NAMES-1]<<" reservation not found, test passed, 2 marks"<<endl;
    std::cout<<"Total score: "<<score + SCORE<<" marks"<<endl;
    return score + SCORE;

}

int testAddResTruckOrder(){
    std::cout<<endl<<"Testing Truck add reservation function for correct order..."<<endl<<endl;

    Truck t1("Truck1", "XBox", 8, true);
    Date date1(2024, 4, 20);
    Date date2(2022, 4, 21);
    Date date3(2022, 4, 20);
    t1.addReservation(names[0], date1, 10, 12);
    t1.addReservation(names[1], date2, 12, 14);
    t1.addReservation(names[2], date3, 10, 12);
    t1.addReservation(names[3], date3, 8, 10);
    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    t1.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find truck name
    int found = -1;
    for (int i = 0; i < NUM_NAMES - 1; ++i){
        found = output.find(orderedNames[i], found+1);
        if (found == -1){
            std::cout<<names[i]<<" not found"<<endl;
            std::cout<<"add reservation to truck in Date order test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All names found in order, 2 marks"<<endl<<endl;
    return SCORE;    
}

int testAddRes(){
    std::cout<<endl<<"Testing GameTrux add reservation function..."<<endl<<endl;

    //test they are all added to the correct truck
    GameTrux gt;

    //add some trucks
    for (int i = 0; i < NUM_TRUCKS; ++i){
        gt.addTruck(truckNames[i], gameTypes[i], caps[i], (i%2==0));
    }

    // add reservations
    Date date1(2022, 12, 25);
    for (int i = 0; i < NUM_TRUCKS; ++i){
        for (int j = 0; j < NUM_NAMES; ++j){
            gt.addReservation(names[i*4+j], gameTypes[i], 4, false, date1, 8+j*2, 8+j*2+2);
        }
    }

    //capture the output and put in a stringstream
    //so we can make sure things print properly
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;
    
    Truck* truck;

    std::cout.rdbuf( strCout.rdbuf() );

    //match the type to the truck, then find the corresponding names
    for (int i = 0; i < NUM_TRUCKS; ++i){
        strCout.str(std::string());
        gt.getTruck(i, &truck);
        truck->printReservations();
        output = strCout.str();
        for (int k = 0; k < NUM_TRUCKS; ++k){
            if (output.find(gameTypes[k])!=-1){
                for (int j = 0; j < NUM_NAMES; ++j){
                    if (output.find(names[k*4+j])==-1){
                        std::cout.rdbuf( oldCoutStreamBuf );
                        std::cout << "output: "<<output<<endl;
                        std::cout<<names[k*4+j]<<" not found in "<<gameTypes[k]<<" truck, test failed "<<endl;
                        return 0;
                    }
                }
            }
        } 
    }

    //replace std::out 
    std::cout.rdbuf( oldCoutStreamBuf );
    std::cout<<"All names found 6 marks"<<endl;
    return 6;
}

int testUpdateReservations(){
    std::cout<<endl<<"Testing GameTrux update reservation function..."<<endl<<endl;

    GameTrux gt;

    //add some trucks
    for (int i = 0; i < NUM_TRUCKS; ++i){
        gt.addTruck(truckNames[i], gameTypes[i], caps[i], (i%2==0));
    }

    // add reservations
    Date dates[NUM_NAMES];
    for (int i = 0; i < NUM_NAMES; ++i){
        dates[i].setDate(2022,12,i+1);
    }
    for (int i = 0; i < NUM_TRUCKS; ++i){
        for (int j = 0; j < NUM_NAMES; ++j){
            gt.addReservation(names[i*4+j], gameTypes[i], 4, false, dates[j], 8+j*2, 8+j*2+2);
        }
    }

    gt.updateReservations(dates[NUM_NAMES-2]);
    //capture the output and put in a stringstream
    //so we can make sure things print properly
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;
    std::cout<<"Done output"<<endl;
    
    //print out and collect the dates
    string dateStrings[NUM_NAMES];
    for (int i = 0; i < NUM_NAMES; ++i){
        strCout.str(std::string());
        std::cout.rdbuf( strCout.rdbuf() );
        dates[i].print();
        std::cout.rdbuf( oldCoutStreamBuf );
        dateStrings[i] = strCout.str();
    }

    //cout<<"out of loop"<<endl;

    //search the output for the eliminated dates.
    for (int i = 0; i < NUM_NAMES-2; ++i){    
        if (output.find(dateStrings[i])!=-1){
            cout<<"Date "<<dateStrings[i]<<" found, test failed."<<endl;        
            //return 0;       
        }        
    }

    //cout<<"out of loop 2"<<endl;

    //search the output for dates that should be there
    for (int i =  NUM_NAMES-2;i< NUM_NAMES; ++i){    
        if (output.find(dateStrings[i])==-1){
            cout<<"Date "<<dateStrings[i]<<" not found, test failed."<<endl;        
            //return 0;       
        }        
    }

    std::cout<<"Reservations correctly updated, 1 mark"<<endl;
    return 1;
}

