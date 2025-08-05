
#include <istream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Song.h"
#include "Criteria.h"


using namespace std;

int testA_Criteria();
int testC_Criteria();
int testAC_Criteria();
int testPolyPrint();

bool match(Criteria*, Song&, bool);

int main(){

    int choice = 0;
    cin >> choice;
    switch(choice){
      case 0: return testA_Criteria();
      case 1: return testC_Criteria();
      case 2: return testAC_Criteria();
      case 3: return testPolyPrint();
    }

    cout<<"Bad input: "<<choice<<endl;
    return 1;

}

bool match(Criteria* crit, Song& m, bool matches){
    cout<<*crit<<m<<endl;
    cout <<"Should "<<(matches?"match":"not match")<<endl;
    bool out = crit->matches(m);
    cout << (out?"Matched":"Did not match")<<endl;
    if (out==matches){
        cout<<"Test passed"<<endl<<endl;
        return true;
    }else{
        cout<< " *****ERROR***** "<<endl;
        return false;
    }
}

int testA_Criteria(){
    int ret = 0;
    Criteria* crit1 = new A_Criteria("Nirvana");
    Criteria* crit2 = new A_Criteria("Zamphir");
    Song m("Nirvana", "You Know You're Right", "Grunge", "yayayaya");

    //if both tests pass, return 0 which means no errors occured
    if (match(crit1, m, true)&&match(crit2, m , false)) {
        cout<<"Testing artist criteria passed"<<endl<<endl;
    }else{
        cout<<"Testing artist criteria DID NOT pass"<<endl<<endl;
        ret = 1;
    }
    delete crit1, crit2;

    return ret;

}

int testC_Criteria(){
    int ret = 0;
    Criteria* crit1 = new C_Criteria("Grunge");
    Criteria* crit2 = new C_Criteria("Pop");
    Song m("Nirvana", "You Know You're Right", "Grunge", "yayayaya");

    //if both tests pass, return 0 which means no errors occured
    if (match(crit1, m, true)&&match(crit2, m , false))  {
        cout<<"Testing category criteria passed"<<endl<<endl;
    }else{
        cout<<"Testing category criteria DID NOT pass"<<endl<<endl;
        ret = 1;
    }
    delete crit1, crit2;
    return ret;
}

int testAC_Criteria(){
    Criteria* crit1 = new AorC_Criteria("Nirvana", "Grunge");
    Criteria* crit2 = new AorC_Criteria("Nirvana", "Rock");
    Criteria* crit3 = new AorC_Criteria("Justin Bieber", "Grunge");
    Criteria* crit4 = new AorC_Criteria("Justin Bieber", "Pop");

    Song m("Nirvana", "You Know You're Right", "Grunge", "yayayaya");

    //check each test for error individually
    bool pass;
    pass = match(crit1, m, true);
    pass = match(crit2, m, true)&&pass;
    pass = match(crit3, m, true)&&pass;
    pass = match(crit4, m, false)&&pass;

    delete crit1, crit2, crit3, crit4;
    if (!pass){
        cout<<"Testing artist or category criteria DID NOT pass"<<endl<<endl;
        //returning 1 indicates an error stat
        return 1;
    }

    cout<<"Testing artist or category criteria passed"<<endl<<endl;
    return 0;

}

int testPolyPrint(){
    Criteria* crit1 = new A_Criteria("Nirvana");
    Criteria* crit2 = new C_Criteria("Rock");
    Criteria* crit3 = new AorC_Criteria("Justin Bieber", "Grunge");

    stringstream ss;

    ss<<*crit1;
    cout<<*crit1<<endl;
    if (ss.str().find("Nirvana")==-1){
        cout<<"Could not find Nirvana in A_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    cout<<"'Nirvana' found in output, test passed"<<endl<<endl;

    ss.str(string());

    ss<<*crit2;
    cout<<*crit2<<endl;

    if (ss.str().find("Rock")==-1){
        cout<<"Could not find Rock in C_Criteria output"<<endl<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    cout<<"'Rock' found in output, test passed"<<endl<<endl;

    ss.str(string());

    ss<<*crit3;
    cout<<*crit3<<endl<<endl;

    if (ss.str().find("Justin Bieber")==-1){
        cout<<"Could not find 'Justin Bieber' in AorC_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    if (ss.str().find("Grunge")==-1){
        cout<<"Could not find 'Grunge' in AorC_Criteria output"<<endl;
        delete crit1, crit2, crit3;
        return 1;
    }

    cout<<"'Justin Bieber' and 'Grunge' found in output, test passed"<<endl<<endl;
    delete crit1, crit2, crit3;
    return 0;
}
