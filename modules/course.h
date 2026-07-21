#ifndef COURSE_H
#define COURSE_H

typedef struct Course
{
    char code[16];
    char name[100];
    double credit;
    int semester;
} Course;

Course createCourse(char code[], char name[], double credit, int semester);
void viewCourse(Course course);

#endif
