#include "Student.h"
#include <fstream>
#include <iostream>

void writeStudents(const std::string& fileName, const std::vector<Student>& students)
{
    std::ofstream file(fileName);
    for (const auto& s : students)
    {
        file << s.surname << " " << s.name << " " << s.grade << std::endl;
    }
}

std::vector<Student> readStudents(const std::string& fileName)
{
    std::vector<Student> students;
    std::ifstream file(fileName);
    Student s;
    while (file >> s.surname >> s.name >> s.grade)
    {
        students.push_back(s);
    }
    return students;
}

void printBelowGrade(const std::vector<Student>& students, int threshold)
{
    for (const auto& s : students)
    {
        if (s.grade < threshold)
        {
            std::cout << s.surname << " " << s.name << " " << s.grade << std::endl;
        }
    }
}

double calculateAverage(const std::vector<Student>& students)
{
    if (students.empty())
    {
        return 0.0;
    }
    double sum = 0.0;
    for (const auto& s : students)
    {
        sum += s.grade;
    }
    return sum / students.size();
}
