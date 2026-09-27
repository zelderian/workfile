#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student
{
    std::string surname;
    std::string name;
    int grade;
};

void writeStudents(const std::string& fileName, const std::vector<Student>& students);
std::vector<Student> readStudents(const std::string& fileName);
void printBelowGrade(const std::vector<Student>& students, int threshold);
double calculateAverage(const std::vector<Student>& students);

#endif
