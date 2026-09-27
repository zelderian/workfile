#include "Student.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Student> students = {
        { "Petrenko", "Ivan", 85 },
        { "Kovalenko", "Olena", 62 },
        { "Sydorenko", "Mykola", 74 },
        { "Bondarenko", "Anna", 55 },
        { "Shevchenko", "Taras", 90 }
    };

    writeStudents("students.txt", students);

    std::vector<Student> loaded = readStudents("students.txt");

    int threshold;
    std::cout << "Введіть прохідний бал: ";
    std::cin >> threshold;

    std::cout << "Студенти з балом нижче " << threshold << ":" << std::endl;
    printBelowGrade(loaded, threshold);

    std::cout << "Середній бал по групі: " << calculateAverage(loaded) << std::endl;

    return 0;
}
