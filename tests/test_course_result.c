#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int testResultCourse()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 2);
    CourseResult result = createCourseResult(&course, 77, 1);
    return result.course == &course;
}

int testResultMarks()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 2);
    CourseResult result = createCourseResult(&course, 77, 1);
    return result.marks == 77;
}

int testResultStatus()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 2);
    CourseResult result = createCourseResult(&course, 0, 0);
    return result.is_completed == 0;
}

int testFilterResultsBySemester()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course c2 = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    CourseResult r1 = createCourseResult(&c1, 80, 1);
    CourseResult r2 = createCourseResult(&c2, 75, 1);

    CourseResult results[] = {r1, r2};
    CourseResult filtered[10];

    int count = filterResultsBySemester(results, 2, 1, filtered);
    return count == 1 && filtered[0].course == &c1;
}

int main()
{
    printf("Course result module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testResultCourse()) passed++;
    total++;
    if (testResultMarks()) passed++;
    total++;
    if (testResultStatus()) passed++;
    total++;
    if (testFilterResultsBySemester()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}
