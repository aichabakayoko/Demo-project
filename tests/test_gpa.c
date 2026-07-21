#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int testMarksToGradePoint()
{
    return marksToGradePoint(82) == 4.00 &&
           marksToGradePoint(77) == 3.75 &&
           marksToGradePoint(38) == 0.00;
}

int testCalculateCGPA()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0);
    Course c2 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);
    Course c3 = createCourse("CSE 4203", "Discrete Mathematics", 3.0);

    CourseResult r1 = createCourseResult(&c1, 80, 1);
    CourseResult r2 = createCourseResult(&c2, 70, 1);
    CourseResult r3 = createCourseResult(&c3, 0, 0); // Incomplete

    CourseResult results[] = {r1, r2, r3};
    double cgpa = calculateCGPA(results, 3);

    return (cgpa > 3.83 && cgpa < 3.84);
}

int main()
{
    printf("GPA module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testMarksToGradePoint()) passed++;
    total++;
    if (testCalculateCGPA()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}
