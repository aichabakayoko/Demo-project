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
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course c2 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    Course c3 = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    CourseResult r1 = createCourseResult(&c1, 80, 1);
    CourseResult r2 = createCourseResult(&c2, 70, 1);
    CourseResult r3 = createCourseResult(&c3, 0, 0);

    CourseResult results[] = {r1, r2, r3};
    double cgpa = calculateCGPA(results, 3);

    return (cgpa > 3.83 && cgpa < 3.84);
}

int testCalculateSemesterGPA()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course c2 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    Course c3 = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    CourseResult r1 = createCourseResult(&c1, 80, 1);
    CourseResult r2 = createCourseResult(&c2, 70, 1);
    CourseResult r3 = createCourseResult(&c3, 85, 1);

    CourseResult results[] = {r1, r2, r3};
    double sem1_gpa = calculateSemesterGPA(results, 3, 1);

    return (sem1_gpa > 3.83 && sem1_gpa < 3.84);
}

int testCalculateRequiredGPA()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course c2 = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    CourseResult r1 = createCourseResult(&c1, 70, 1); // GP 3.5 * 3.0 = 10.5
    CourseResult r2 = createCourseResult(&c2, 0, 0);  // Remaining 3.0 credits

    CourseResult results[] = {r1, r2};
    // Target CGPA 3.75 for 6 total credits = 22.5 points needed -> 12 points needed in 3 credits -> Required GPA = 4.00
    double required_gpa = calculateRequiredGPA(results, 2, 3.75);

    return (required_gpa > 3.99 && required_gpa < 4.01);
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
    total++;
    if (testCalculateSemesterGPA()) passed++;
    total++;
    if (testCalculateRequiredGPA()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}
