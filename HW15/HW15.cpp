#include <iostream>
#include <string>
#include <algorithm>

struct Student
{
    std::string name;
    int marks[4];
};

double calculateAverageMark(const Student& student)
{
    double sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += student.marks[i];
    }
    return sum / 4.0;
}

bool compareByMarks(const Student& student1, const Student& student2)
{
    return calculateAverageMark(student1) > calculateAverageMark(student2);
}

void sorting(Student* students, int size)
{
    std::sort(students, students + size, compareByMarks);
}

Student* getTopStudent(Student* students, int size)
{
    Student* topStudent = &students[0];
    for (int i = 1; i < size; ++i)
    {
        if (calculateAverageMark(students[i]) > calculateAverageMark(*topStudent))
        {
            topStudent = &students[i];
        }
    }
    return topStudent;
}

int countAboveAverage(Student* students, int size, double N)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (calculateAverageMark(students[i]) > N)
        {
            ++count;
        }
    }
    return count;
}

void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent)
{
    unsigned numStudentsToSelect = (inSize * percent) / 100;
    for (unsigned i = 0; i < numStudentsToSelect; ++i)
    {
        Student* topStudent = &inStudents[i];
        for (unsigned j = i + 1; j < inSize; ++j)
        {
            if (calculateAverageMark(inStudents[j]) > calculateAverageMark(*topStudent))
            {
                topStudent = &inStudents[j];
            }
        }
        outStudents[i] = *topStudent;
        std::swap(inStudents[i], *topStudent);
    }
    outSize = numStudentsToSelect;
}

int main()
{
    const int size = 4;
    Student students[] =
    {
        {"Danylo", {78, 65, 92, 77}},
        {"Andrew", {44, 98, 75, 80}},
        {"Dirol", {97, 87, 84, 99}},
        {"Ivan", {78, 69, 87, 72}}
    };

    std::cout << "Average marks before sorting:" << std::endl;
    for (const auto& student : students)
    {
        double average = calculateAverageMark(student);
        std::cout << "Average marks for " << student.name << " is: " << average << std::endl;
    }

    std::cout << "\nAfter sorting by marks:" << std::endl;
    sorting(students, size);
    for (const auto& student : students)
    {
        double average = calculateAverageMark(student);
        std::cout << "Average marks for " << student.name << " is: " << average << std::endl;
    }

    Student* topStudent = getTopStudent(students, size);
    std::cout << "\nTop student is " << topStudent->name << " with average marks: " << calculateAverageMark(*topStudent) << std::endl;

    double threshold = 80.0;
    int count = countAboveAverage(students, size, threshold);
    std::cout << "\nNumber of students with average marks above " << threshold << " is: " << count << std::endl;

    unsigned percent = 50;
    Student bestStudents[size];
    unsigned bestStudentsSize;
    getBestStudents(students, size, bestStudents, bestStudentsSize, percent);

    std::cout << "\nTop " << percent << "% students:" << std::endl;
    for (unsigned i = 0; i < bestStudentsSize; ++i)
    {
        std::cout << bestStudents[i].name << " with average marks: " << calculateAverageMark(bestStudents[i]) << std::endl;
    }

    return 0;
}
