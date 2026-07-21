#include <stdio.h>
#include <string.h>
#include "course.h"
#include "courseResult.h"
#include "student.h"
#include "gpa.h"

int testCreateStudent()
{
    Student s = createStudent("2021001", "Alice");
    return strcmp(s.id, "2021001") == 0 && strcmp(s.name, "Alice") == 0 && s.n_results == 0;
}

int testAddCourseResultToStudent()
{
    Student s = createStudent("2021001", "Alice");
    Course c = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    CourseResult r = createCourseResult(&c, 85, 1);

    addCourseResultToStudent(&s, r);
    return s.n_results == 1 && s.results[0].marks == 85;
}

int testSortStudentsByCGPA()
{
    Course c = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);

    Student s1 = createStudent("2021001", "Alice"); // 70 marks -> GP 3.50
    CourseResult r1 = createCourseResult(&c, 70, 1);
    addCourseResultToStudent(&s1, r1);

    Student s2 = createStudent("2021002", "Bob");   // 85 marks -> GP 4.00
    CourseResult r2 = createCourseResult(&c, 85, 1);
    addCourseResultToStudent(&s2, r2);

    Student students[] = {s1, s2};
    sortStudentsByCGPA(students, 2);

    return strcmp(students[0].name, "Bob") == 0; // Bob should be #1
}

int main()
{
    printf("Student module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCreateStudent()) passed++;
    total++;
    if (testAddCourseResultToStudent()) passed++;
    total++;
    if (testSortStudentsByCGPA()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}
