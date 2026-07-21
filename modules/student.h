#ifndef STUDENT_H
#define STUDENT_H

#include "courseResult.h"

typedef struct Student
{
    char id[16];
    char name[100];
    CourseResult results[100];
    int n_results;
} Student;

Student createStudent(char id[], char name[]);
void addCourseResultToStudent(Student *student, CourseResult result);
void viewStudent(Student student);

#endif
