#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;

    printf("Enter number of courses: ");
    if (scanf("%d", &n_courses) != 1) return 1;

    for (int i = 0; i < n_courses; i++)
    {
        char code[16];
        char name[100];
        double credit;
        int semester;

        printf("\nCourse %d details:\n", i + 1);
        printf("Code: ");
        scanf("%15s", code);
        printf("Name: ");
        scanf(" %[^\n]", name);
        printf("Credit: ");
        scanf("%lf", &credit);
        printf("Semester: ");
        scanf("%d", &semester);

        courses[i] = createCourse(code, name, credit, semester);

        int is_completed;
        printf("Is completed? (1 for Yes, 0 for No): ");
        scanf("%d", &is_completed);

        double marks = 0;
        if (is_completed)
        {
            printf("Marks: ");
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
    for (int sem = 1; sem <= 8; sem++)
    {
        double sem_gpa = calculateSemesterGPA(results, n_courses, sem);
        if (sem_gpa > 0.0)
        {
            printf("Semester %d GPA: %.2f\n", sem, sem_gpa);
        }
    }

    double cgpa = calculateCGPA(results, n_courses);
    printf("\nYour Overall CGPA is: %.2f\n", cgpa);

    double target_cgpa;
    printf("\nEnter target CGPA: ");
    if (scanf("%lf", &target_cgpa) == 1)
    {
        double req_gpa = calculateRequiredGPA(results, n_courses, target_cgpa);
        if (req_gpa > 4.00)
        {
            printf("Target CGPA %.2f is mathematically impossible (Required GPA: %.2f > 4.00)\n", target_cgpa, req_gpa);
        }
        else
        {
            printf("Required GPA in remaining courses: %.2f\n", req_gpa);
        }
    }

    return 0;
}
