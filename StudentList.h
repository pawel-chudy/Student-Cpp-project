#ifndef _Student_StudentList_
#define _Student_StudentList_

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>


#include "Student.h"

class StudentList
{
    public:
        StudentList(std::string filePath);

        Student getValedictorian();
        std::vector<Student> getHonorRollStudents();
        std::vector<Student> getFailingStudents();

    private:
        std::vector<Student> students;
};

class NoValedictorianException : public std::exception
{
    public:
        const char *what() const throw()
        {
            return "No Valedictorian!";
        }
};

#endif
