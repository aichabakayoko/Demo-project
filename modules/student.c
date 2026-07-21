#include <stdio.h>
#include <string.h>
#include "student.h"

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
