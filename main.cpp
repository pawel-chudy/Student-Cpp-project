#include <iostream>
#include <exception>
#include <windows.h>
#include <string>

#include "Student.h"
#include "StudentList.h"

using namespace std;

void printStudentInfo(Student st)
{
    cout << "Name: " << st.getName() << endl;
    cout << "ID: " << st.getId() << endl;
    cout << "GPA: " << st.getGPA() << endl << endl;
}

int main(int argc, const char * argv[])
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    try
    {
        StudentList stList("students.txt");

        SetConsoleTextAttribute(hConsole, 2);
        cout << "Valedictorian: " << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        printStudentInfo(stList.getValedictorian());

        SetConsoleTextAttribute(hConsole, 2);
        cout << "Honor Roll Students: " << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        for(Student s : stList.getHonorRollStudents())
            printStudentInfo(s);

        SetConsoleTextAttribute(hConsole, 2);
        cout << "Failing Students: " << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        for(Student s : stList.getFailingStudents())
            printStudentInfo(s);
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;

        return -1;
    }

    return 0;
}
