/// @brief Creates a single instance of student
/// @file Student.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
class Student{
    private:
        int m_studentID;
        string m_name;
        string m_level;
        string m_major;
        double m_GPA;
        int m_FacultyID;
    public:
        Student();
        Student(int sid, string name, string level, string major, double GPA, int FacultyID);
        virtual ~Student();
        void setFacultyID(int FAID);
        int getSID();
        string getName();
        string getLevel();
        string getMajor();
        double getGPA();
        int getFacultyID();
        friend bool operator== (const Student& s1, const Student& s2);
        friend bool operator!= (const Student& s1, const Student& s2);
        friend bool operator> (const Student& s1, const Student& s2);
        friend bool operator< (const Student& s1, const Student& s2);
};

//default constructor
Student::Student(){
    m_studentID = -1;
    m_name = "";
    m_level = "";
    m_major = "";
    m_GPA = 0.0;
    m_FacultyID = -1;
}

//Overloaded constructor
Student::Student(int sid, string name, string level, string major, double GPA, int FacultyID){
    m_studentID = sid;
    m_name = name;
    m_level = level;
    m_major = major;
    m_GPA = GPA;
    m_FacultyID = FacultyID;
}

//default destructor
Student::~Student(){

}

//Sets the faculty ID
void Student::setFacultyID(int FAID){
    m_FacultyID = FAID;
}

//Returns Student ID
int Student::getSID(){
    return m_studentID;
}

//returns name
string Student::getName(){
    return m_name;
}

//returns level
string Student::getLevel(){
    return m_level;
}

//returns major
string Student::getMajor(){
    return m_major;
}

//returns GPA
double Student::getGPA(){
    return m_GPA;
}

//returns Faculty ID
int Student::getFacultyID(){
    return m_FacultyID;
}

//overides equal
bool operator== (const Student& s1, const Student& s2)
{
    return (s1.m_studentID == s2.m_studentID);
}

//overides not equal
bool operator!= (const Student& s1, const Student& s2)
{
    return (s1.m_studentID != s2.m_studentID);
}

//overides greater than
bool operator> (const Student& s1, const Student& s2)
{
    return (s1.m_studentID > s2.m_studentID);
}

//overides less than
bool operator< (const Student& s1, const Student& s2)
{
    return (s1.m_studentID < s2.m_studentID);
}