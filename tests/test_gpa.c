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

    CourseResult r1 = createCourseResult(&c1, 80); // 4.0 * 3.0 = 12.0
    CourseResult r2 = createCourseResult(&c2, 70); // 3.5 * 1.5 = 5.25

    CourseResult results[] = {r1, r2};
    double cgpa = calculateCGPA(results, 2);

    return (cgpa > 3.83 && cgpa < 3.84); // 17.25 / 4.5 = 3.833...
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
