#ifndef _Student_Student_
#define _Student_Student_

#include <string>
#include <sstream>

class Student
{
    public:
        Student(std::string studentInformation);

        std::string getFirstName();
        std::string getLastName();
        std::string getName();
        int getId();
        double getGPA();

    private:
        std::string firstName;
        std::string lastName;
        int id;
        double gpa;
};

#endif
