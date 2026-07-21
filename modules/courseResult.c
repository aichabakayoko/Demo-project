#include <stdio.h>
#include "courseResult.h"

CourseResult createCourseResult(Course *course, double marks, int is_completed)
{
    CourseResult result;
    result.course = course;
    result.marks = marks;
    result.is_completed = is_completed;
    return result;
}

void viewCourseResult(CourseResult result)
{
    printf("%s: %s\t\t [Credit: %.1f]\n",
           result.course->code, result.course->name, result.course->credit);
    if (result.is_completed)
    {
        printf("Status: Completed\tMarks: %.2f\n", result.marks);
    }
    else
    {
        printf("Status: Incomplete\n");
    }
}
