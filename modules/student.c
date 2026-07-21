#include <stdio.h>
#include <string.h>
#include "student.h"
#include "gpa.h"

Student createStudent(char id[], char name[])
{
    Student student;
    strcpy(student.id, id);
    strcpy(student.name, name);
    student.n_results = 0;
    return student;
}

void addCourseResultToStudent(Student *student, CourseResult result)
{
    student->results[student->n_results++] = result;
}

void viewStudent(Student student)
{
    printf("Student ID: %s\t Name: %s\n", student.id, student.name);
    printf("Results (%d courses):\n", student.n_results);
    for (int i = 0; i < student.n_results; i++)
    {
        viewCourseResult(student.results[i]);
    }
}

void sortStudentsByCGPA(Student students[], int n_students)
{
    for (int i = 0; i < n_students - 1; i++)
    {
        for (int j = 0; j < n_students - i - 1; j++)
        {
            double cgpa1 = calculateCGPA(students[j].results, students[j].n_results);
            double cgpa2 = calculateCGPA(students[j + 1].results, students[j + 1].n_results);

            if (cgpa1 < cgpa2)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
