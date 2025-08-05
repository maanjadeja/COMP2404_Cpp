
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Student.h"

using namespace std;

class Algorithms {

	public:
		//constructor
		Algorithms();

		//destructor
		~Algorithms();

		// add a new Student object to your data structure
		void addStudent(const string& number, const string& name, float);

		// v is a vector that is passed in.
		// copy or add all passing Students to v
		// passing == (gpa >= 6.0)
		void getPassingStudents(vector<Student>& v);

		// v is a vector that is passed in.
		// copy or add all Students to v in sorted order by
		// student number
		void sortByNumber(vector<Student>& v);

		// v is a vector that is passed in.
		// copy or add all Students to v in sorted order by
		// name
		void sortByName(vector<Student>& v);

		// assign the Student with the highest gpa to stuIt
		// (as an iterator)
		bool highestGpa(vector<Student>::iterator& stuIt);

		// if a Student with the name 'name' exists
		// assign that Student to stuIt (as an iterator)
		// and return true, otherwise return false
		bool findStudent(const string& name, vector<Student>::iterator& stuIt);

		static bool pass(Student& stu); //or we can delete the declaration, and create the function directly in .cc file without Algorithms::
		static bool compareNum(Student& stu1, Student& stu2);
		static bool compareName(Student& stu1, Student& stu2);

	private:
		 vector<Student> stuVect;


};
#endif
