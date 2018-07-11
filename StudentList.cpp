#include "StudentList.h"

#define FAILING_GPA 50
#define HONORROLL_GPA 80

using namespace std;

StudentList::StudentList(string filePath)
{
    ifstream studentFile(filePath);

    string line;
    while (!studentFile.eof())
    {
        getline(studentFile, line);

        Student s(line);
        students.push_back(s);
    }
    studentFile.close();

    sort(students.begin(), students.end(), [](Student &s1, Student &s2){ return s1.getGPA() > s2.getGPA(); });
}

Student StudentList::getValedictorian()
{
    if( students.size() == 0 || students.at(0).getGPA() < FAILING_GPA )
        throw NoValedictorianException();

    return students.at(0);
}

vector<Student> StudentList::getHonorRollStudents()
{
    vector<Student> honorStudents;

    for(Student s: students)
    {
        if( s.getGPA() >= HONORROLL_GPA )
            honorStudents.push_back(s);
        else
            break;
    }

    return honorStudents;
}

vector<Student> StudentList::getFailingStudents()
{
    vector<Student> failingStudents;

    for(vector<Student>::reverse_iterator it = students.rbegin(); it < students.rend(); it++)
    {
        if(it->getGPA() < FAILING_GPA)
            failingStudents.push_back(*it);
        else
            break;
    }

    return failingStudents;
}
