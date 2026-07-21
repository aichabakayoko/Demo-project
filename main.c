feature002
#include <stdio.h>
#include "course.h"
#include "courseResult.h"

#include "course.h"
 main

int main()
{
    Course courses[1000];
feature002
    CourseResult results[1000];

 main
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0);

    for (int i = 0; i < n_courses; i++)
    {
 feature002
        double marks;
        printf("Marks for %s: ", courses[i].name);
        scanf("%lf", &marks);
        results[i] = createCourseResult(&courses[i], marks);
    }

    for (int i = 0; i < n_courses; i++)
    {
        viewCourseResult(results[i]);

        viewCourse(courses[i]);
main
    }

    return 0;
}
