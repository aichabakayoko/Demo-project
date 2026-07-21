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
    printf("%s: %s\t\t [Credit: %.1f] [Semester: %d]\n",
           result.course->code, result.course->name, result.course->credit, result.course->semester);
    if (result.is_completed)
    {
        printf("Status: Completed\tMarks: %.2f\n", result.marks);
    }
    else
    {
        printf("Status: Incomplete\n");
    }
}

int filterResultsBySemester(CourseResult results[], int n_results, int semester, CourseResult filtered[])
{
    int count = 0;
    for (int i = 0; i < n_results; i++)
    {
        if (results[i].course->semester == semester)
        {
            filtered[count++] = results[i];
        }
    }
    return count;
}
