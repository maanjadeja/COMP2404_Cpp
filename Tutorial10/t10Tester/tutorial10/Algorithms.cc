#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Algorithms.h"

Algorithms::Algorithms(){
}

Algorithms::~Algorithms(){
  stuVect.clear();
}


void Algorithms::addStudent(const string& number, const string& name, float gpa){

  // Student(string="000000000", string="Hey you!",  float=0.0f);

  Student newStudent(number, name,gpa);

  stuVect.push_back(newStudent);

}

void Algorithms::getPassingStudents(vector<Student>& v){

  // cout<<"Find all passing students:"<<endl;
 // vector<Student> stuVect2(stuVect.size());

 // vector<Student>::iterator it = copy_if(stuVect.begin(), stuVect.end(), v.begin(), pass);

 for (std::vector<Student>::iterator it = stuVect.begin() ; it != stuVect.end(); ++it){
   if((*it).getGpa() >= 6.0f){
     // stuIt = it;
     v.push_back(*it);
   }
 }


 //stuVect2.resize(distance(stuVect2.begin(), it));
}

void Algorithms::sortByNumber(vector<Student>& v){

  // std::sort(vec.begin(),vec.end(), [](int &a, int &b){ return a>b; });
  // bool  Algorithms::compareNum(const string& num1, const string& num2)

  sort(stuVect.begin(), stuVect.end(), compareNum);

  for (std::vector<Student>::iterator it = stuVect.begin() ; it != stuVect.end(); ++it){
    // if((*it).getGpa() >= 6.0f){
      // stuIt = it;
      v.push_back(*it);
    }


}

void Algorithms::sortByName(vector<Student>& v){

  // v.sort(v.begin(), v.end(), [](Student& a, Student& b){ return a.getName()<b.getName();});

  sort(stuVect.begin(), stuVect.end(), compareName);

  for (std::vector<Student>::iterator it = stuVect.begin() ; it != stuVect.end(); ++it){
    // if((*it).getGpa() >= 6.0f){
      // stuIt = it;
      v.push_back(*it);
    }



}

bool Algorithms::highestGpa(vector<Student>::iterator& stuIt){

  if(stuVect.size() <= 0 ){
    return false;
  }
  else{

    stuIt = stuVect.begin();

    for (std::vector<Student>::iterator it = stuVect.begin() ; it != stuVect.end(); ++it){
      if((*stuIt).getGpa() < (*it).getGpa()){
        stuIt = it;
      }
    }

    return true;


  }

}

bool Algorithms::findStudent(const string& name, vector<Student>::iterator& stuIt){

  // stuIt = stuVect.begin();
  if(stuVect.size() <= 0 ){
    return false;
  }
  else{

    for (std::vector<Student>::iterator it = stuVect.begin() ; it != stuVect.end(); ++it){
      if((*it).getName() == name){
        stuIt = it;
        return true;
      }
    }

    return false;


  }

}



bool  Algorithms::compareNum(Student& stu1, Student& stu2){

  int stu1Num = std::stoi(stu1.getNumber());
  int stu2Num = std::stoi(stu2.getNumber());

  return stu1Num < stu2Num;


}

bool Algorithms::compareName(Student& stu1, Student& stu2){

  return stu1.getName() < stu2.getName();

}





bool Algorithms::pass(Student& stu){
  return stu.getGpa() >=6.0f;
}
