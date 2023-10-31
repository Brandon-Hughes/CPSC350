/// @brief Creates a single instance of Faculty
/// @file Faculty.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

class Faculty{
    private:
        int m_FacultyID;
        string m_name;
        string m_level;
        string m_department;
        int* studentID;
        int m_numStudents;
    public:
        Faculty();
        Faculty(int FacultyID, string name, string level, string department);
        virtual ~Faculty();
        void addStudent(int newStudentID);
        void removeStudent(int newStudentID);
        bool hasStudent(int newStudentID);
        void printStudents();
        int getFacultyID();
        string getName();
        string getLevel();
        string getDepartment();
        friend bool operator== (const Faculty& f1, const Faculty& f2);
        friend bool operator!= (const Faculty& f1, const Faculty& f2);
        friend bool operator> (const Faculty& f1, const Faculty& f2);
        friend bool operator< (const Faculty& f1, const Faculty& f2);
};

//default constructor
Faculty::Faculty(){
    m_FacultyID = -1;
    m_name = "";
    m_level = "";
    m_department = "";
    studentID = new int[100];
    for(int i = 0; i < 100; ++i){
        studentID[i] = -1;
    }
    m_numStudents = 0;
}

//overloaded constructor
Faculty::Faculty(int FacultyID, string name, string level, string department){
    m_FacultyID = FacultyID;
    m_name = name;
    m_level = level;
    m_department = department;
    studentID = new int[100];
    for(int i = 0; i < 100; ++i){
        studentID[i] = -1;
    }
    m_numStudents = 0;
}

//defult destructor
Faculty::~Faculty(){
    
}

//returns faculty id
int Faculty::getFacultyID(){
    return m_FacultyID;
}

//returns name
string Faculty::getName(){
    return m_name;
}

//returns level
string Faculty::getLevel(){
    return m_level;
}

//returns department
string Faculty::getDepartment(){
    return m_department;
}

//adds a student to it's array
void Faculty::addStudent(int newStudentID){
    int i = 0;
    while(true){
        if(studentID[i] == -1){
            studentID[i] = newStudentID;
            break;
        }
        i++;
    }
    m_numStudents++;
}

//removes a student
void Faculty::removeStudent(int newStudentID){
    if(hasStudent(newStudentID) == false){
        return;
    } else {
        int i = 0;
        while(true){
            if(studentID[i] == newStudentID){
                studentID[i] == -1;
                break;
            }
            i++;
        }
    }
}

//checks the array to see if the faculty has it's student
bool Faculty::hasStudent(int newStudentID){
    int i = 0;
    while(true){
        if(studentID[i] == newStudentID){
            return true;
        } 
        i++;
    }
    return false;
}

//returns all students
void Faculty::printStudents(){
    for(int i = 0; i < 100; ++i){
        if(studentID[i] != -1){
            cout << studentID[i] << endl;
        }
    }
}

//overloads equal
bool operator== (const Faculty& f1, const Faculty& f2)
{
    return (f1.m_FacultyID == f2.m_FacultyID);
}

//overloads not equal
bool operator!= (const Faculty& f1, const Faculty& f2)
{
    return (f1.m_FacultyID != f2.m_FacultyID);
}

//overloads greater than
bool operator> (const Faculty& f1, const Faculty& f2)
{
    return (f1.m_FacultyID > f2.m_FacultyID);
}

//overloads less than
bool operator< (const Faculty& f1, const Faculty& f2)
{
    return (f1.m_FacultyID < f2.m_FacultyID);
}