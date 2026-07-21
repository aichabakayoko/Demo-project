#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    for (int i = 0; i < n_courses; i++)
    {
        int is_completed;
        printf("Is %s completed? (1 for Yes, 0 for No): ", courses[i].name);
        scanf("%d", &is_completed);

        double marks = 0;
        if (is_completed)
        {
            printf("Marks for %s: ", courses[i].name);
            scanf("%lf", &marks);
        }

        results[i] = createCourseResult(&courses[i], marks, is_completed);
    }

    printf("\n--- Course Results ---\n");
    for (int i = 0; i < n_courses; i++)
    {
        viewCourseResult(results[i]);
    }

    printf("\n--- Semester GPAs ---\n");
    for (int sem = 1; sem <= 2; sem++)
    {
        double sem_gpa = calculateSemesterGPA(results, n_courses, sem);
        printf("Semester %d GPA: %.2f\n", sem, sem_gpa);
    }

    double cgpa = calculateCGPA(results, n_courses);
    printf("\nYour Overall CGPA is: %.2f\n", cgpa);

    return 0;
}
