/// @brief Starts the program to create a student and faculty index
/// @file main.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "DblList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


BST<int>* studentIDTree = new BST<int>();
BST<int>* facultyIDTree = new BST<int>();
DblList<Student*>* studentsList = new DblList<Student*>();
DblList<Faculty*>* facultyList = new DblList<Faculty*>();
int numStudents = 1;
int numFaculty = 1;

int getStudentPosition(int x);
int getFacultyPosition(int x);
void printAllStudents();
void printAllFaculty();
void displayStudentInformation(int studentID);
void displayFacultyInformation(int facultyID);
void addStudent(int ID, string n, string l, string m, double GPA, int FID);
void deleteStudent(int ID);
void addFaculty(int FID, string n, string l, string d);
void deleteFaculty(int FID);
void changeStudentFaculty(int SID, int FID);
void removeStudentFaculty(int FID, int SID);

int main(){
  int inputNum;
  bool hold = true;
  while(hold){
      cout << "Please select an option; " << endl;
      cout << "1. Print all students in sorted order by ID number" << endl;
      cout << "2. Print all faculty in sorted order by ID number" << endl;
      cout << "3. Display a students information by ID number" << endl;
      cout << "4. Display a facultys information by ID number" << endl;
      cout << "5. Create a new student" << endl;
      cout << "6. Delete a existing student" << endl;
      cout << "7. Create a new faculty member" << endl;
      cout << "8. Delete a existing faculty member" << endl;
      cout << "9. Change a student's advisor (faculty member)" << endl;
      cout << "10. Remove a advisee from a faculty member" << endl; 
      cout << "11. Exit from the program" << endl;
      cout << "Please only enter an integer" << endl;
      cin >> inputNum;
      while(cin.fail()){
        cin.clear();
        cin.ignore();
      }
      switch(inputNum){
        case 1:
          {
            printAllStudents();
            break;
          }
        case 2:
          {printAllFaculty();
          break;}
        case 3:
          {cout << "Please input a student ID number that exists" << endl;
          int studentIDInput;
          cin >> studentIDInput;
          displayStudentInformation(studentIDInput);
          break;}
        case 4:
          {cout << "Please input a faculty ID number that exists" << endl;
          int facultyIDInput;
          cin >> facultyIDInput;
          displayFacultyInformation(facultyIDInput);
          break;}
        case 5:
         {
          string i_name;
          string i_level;
          string i_major;
          double i_GPA;
          int i_faculty;
          cout << "Please insert information as asked" << endl;
          cout << "Student Name: ";
          cin.ignore();
          getline(cin,i_name);
          cout << "Students Level: ";
          getline(cin,i_level);
          cout << "Students Major: "; 
          getline(cin,i_major);
          cout << "Students GPA: (must be entered as a decimal)";
          cin >> i_GPA;
          cout << "Existing Faculty Member's ID: ";
          cin >> i_faculty;
          if(!facultyIDTree->contains(i_faculty)){
            cout << "Faculty member does not exist. Exiting" << endl;
            break;
          }
          addStudent(numStudents, i_name, i_level, i_major, i_GPA, i_faculty);
          break;
         }
        case 6:
          {int i_studentID;  
          cout << "Please insert student ID to be deleted: " << endl;
          cin >> i_studentID;
          deleteStudent(i_studentID);
          break;}
        case 7:
          {
          string i_name;
          string i_level;
          string i_department;
          cout << "Please insert information as asked" << endl;
          cout << "Faculty Name: ";
          cin.ignore();
          getline(cin,i_name);
          cout << "Faculty Level: ";
          getline(cin,i_level);
          cout << "Faculty Department: "; 
          getline(cin,i_department);
          addFaculty(numFaculty, i_name, i_level, i_department);
          break;
          }
        case 8:
          {int i_FacultyID;  
          cout << "Please insert faculty ID to be deleted: " << endl;
          cin >> i_FacultyID;
          deleteFaculty(i_FacultyID);
          break;}
        case 9:
          {int i_FacultyID;
          int i_studentID; 
          cout << "Please insert information as asked" << endl;
          cout << "Student ID to change ";
          cin >> i_studentID;
          cout << "Faculty ID to change it to ";
          cin >> i_FacultyID;
          changeStudentFaculty(i_studentID, i_FacultyID);
          break;}
        case 10:
          {int i_FacultyID;
          int i_studentID; 
          cout << "Please insert information as asked" << endl;
          cout << "Faculty ID to remove a student from ";
          cin >> i_FacultyID;
          cout << "Student ID to remove ";
          cin >> i_studentID;
          removeStudentFaculty(i_FacultyID, i_studentID);
          break;}
        case 11:
          {hold = false;
          break;}
        default:
          cout << "Invalid reponse please try again" << endl;

      }
  }
  ofstream writefile("runLog.txt");
  writefile << "All Students: " << endl;

  for(int i = 1; i < numStudents; ++i){
    writefile << "ID Number: " << i << ", ";
    if(!(studentIDTree->contains(i))){
  } else {
    int j = getStudentPosition(i);
    writefile << "Name: " << studentsList->get(j)->getName() << ", Level: " << studentsList->get(j)->getLevel() 
        << ", Major: " << studentsList->get(j)->getMajor() << ", GPA: " << to_string(studentsList->get(j)->getGPA())
        << ", Faculty Advisor: " << studentsList->get(j)->getFacultyID() << endl;
  }
  }
  writefile << "All Faculty: " << endl;
  for(int i = 1; i < numFaculty; ++i){
    writefile << "ID Number: " << i << ", ";
    if(!(facultyIDTree->contains(i))){
  } else {
    int j = getFacultyPosition(i);
    writefile << "Name: " << facultyList->get(j)->getName() << ", Level: " << facultyList->get(j)->getLevel() 
        << ", Department: " << facultyList->get(j)->getDepartment() << endl;
  }
  }
  writefile.close();
  

  //print students by id
  //print faculty by id
  //display student information by id
  //display faculty information by id
  //adds a new student
  //delete a student
  //add a new faculty
  //delete a faculty
  //changes a student advisor given id and faculty
  //remove an advisee from a faculty member
  //exit

  delete studentIDTree;
  delete facultyIDTree;
  delete studentsList;
  delete facultyList;

  return 0;
}

int getStudentPosition(int x){
  int pos = 0;
    while(true){
      if(studentsList->get(pos)->getSID() == x){
        break;
      }
      ++pos;
    }
  return pos;
}
int getFacultyPosition(int x){
  int pos = 0;
    while(true){
      if(facultyList->get(pos)->getFacultyID() == x){
        break;
      }
      ++pos;
    }
  return pos;
}

void printAllStudents(){
  for(int i = 1; i < numStudents; ++i){
    cout << "ID Number: " << i << ", ";
    displayStudentInformation(i);
  }
}
void printAllFaculty(){
  for(int i = 1; i < numFaculty; ++i){
    cout << "ID Number: " << i << ", ";
    displayFacultyInformation(i);
  }
}

void displayStudentInformation(int studentID){
  if(!(studentIDTree->contains(studentID))){
    cout << "Student does not exist" << endl;
  } else {
    int i = getStudentPosition(studentID);
    cout << "Name: " << studentsList->get(i)->getName() << ", Level: " << studentsList->get(i)->getLevel() 
        << ", Major: " << studentsList->get(i)->getMajor() << ", GPA: " << to_string(studentsList->get(i)->getGPA())
        << ", Faculty Advisor: " << studentsList->get(i)->getFacultyID() << endl;
  }
}
void displayFacultyInformation(int facultyID){
  if(!(facultyIDTree->contains(facultyID))){
    cout << "Faculty member does not exist" << endl;
  } else {
    int i = getFacultyPosition(facultyID);
    cout << "Name: " << facultyList->get(i)->getName() << ", Level: " << facultyList->get(i)->getLevel() 
        << ", Department: " << facultyList->get(i)->getDepartment() << endl;
  }
}

void addStudent(int ID, string n, string l, string m, double GPA, int FID){
  if(facultyIDTree->contains(FID) && !(studentIDTree->contains(ID))){
    Student* s1 = new Student(ID, n, l, m, GPA, FID);
    studentIDTree->insert(ID);
    studentsList->addBack(s1);
    int i = getFacultyPosition(FID);
    facultyList->get(i)->addStudent(ID);
    cout << "Student has been added with ID: " << numStudents << endl;
    ++numStudents;
  } else {
    cout << "Invalid Input" << endl;
  }
}
void deleteStudent(int ID){
  if(!(studentIDTree->contains(ID))){
    cout << "Student does not exist" << endl;
  } else {
    int i = getStudentPosition(ID);
    int j = getFacultyPosition(studentsList->get(i)->getFacultyID());
    studentIDTree->remove(ID);
    studentsList->remove(i);
    facultyList->get(i)->removeStudent(ID);
    cout << "Student has been removed" << endl;
  }
}

void addFaculty(int FID, string n, string l, string d){
  if(!(facultyIDTree->contains(FID))){
    Faculty* f1 = new Faculty(FID, n, l, d);
    facultyIDTree->insert(FID);
    facultyList->addBack(f1);
    cout << "Faculty has been added with ID: " << numFaculty << endl;
    ++numFaculty;
  } else {
    cout << "Another Faculty member has that ID number" << endl;
  }
}
void deleteFaculty(int FID){
  bool canRemove = true;
  if(!(facultyIDTree->contains(FID))){
    cout << "Faculty does not exist" << endl;
    canRemove = false;
  }
  for(int i = 0; i < studentsList->getSize(); ++i){
    if(studentsList->get(i)->getFacultyID() == FID){
      cout << "Student with ID: " << studentsList->get(i)->getSID() << " currently has them as an advisor so can not remove" << endl;
      canRemove = false;
    }
  }
  if(canRemove){
    int j = getFacultyPosition(FID);
    facultyIDTree->remove(FID);
    facultyList->remove(j);
    cout << "Faculty member has been remove" << endl;
  }
}

void changeStudentFaculty(int SID, int FID){
  if(!(studentIDTree->contains(SID))){
    cout << "Student does not exist" << endl;
  } else {
    int j = getStudentPosition(SID);
    while(true){
      if(facultyIDTree->contains(FID)){
        studentsList->get(j)->setFacultyID(FID);
        break;
      } else {
        cout << "Faculty member does not exist" << endl;
      }
    }
  }
  
}
void removeStudentFaculty(int FID, int SID){
  if(!(facultyIDTree->contains(FID))){
    cout << "Faculty does not exist" << endl;
  } else {
    int i = getFacultyPosition(FID);
    if(facultyList->get(i)->hasStudent(SID)){
      facultyList->get(i)->removeStudent(SID);
      int newFID;
      while(true){
        cout << "The student needs a new advisor. Please insert the new advisor ID: " << endl;
        cin >> newFID;
        if(facultyIDTree->contains(newFID)){
          changeStudentFaculty(SID, newFID);
          break;
        }
        cout << "Invalid Facutly ID" << endl;
      }
      
    } else {
      cout << "This faculty member doesn't have this student" << endl;
    }
  }
}