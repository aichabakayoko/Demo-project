#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"
#include "student.h"

int main()
{
    Course courses[1000];
    Student students[1000];
    int n_courses = 0;
    int n_students = 0;

    printf("Enter number of courses: ");
    if (scanf("%d", &n_courses) != 1) return 1;

    for (int i = 0; i < n_courses; i++)
    {
        char code[16], name[100];
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
    }

    printf("\nEnter number of students: ");
    if (scanf("%d", &n_students) != 1) return 1;

    for (int i = 0; i < n_students; i++)
    {
        char id[16], name[100];
        printf("\nStudent %d ID: ", i + 1);
        scanf("%15s", id);
        printf("Student %d Name: ", i + 1);
        scanf(" %[^\n]", name);

        students[i] = createStudent(id, name);

        for (int j = 0; j < n_courses; j++)
        {
            int is_completed;
            printf("Is %s completed for %s? (1 for Yes, 0 for No): ", courses[j].name, students[i].name);
            scanf("%d", &is_completed);

            double marks = 0;
            if (is_completed)
            {
                printf("Marks: ");
                scanf("%lf", &marks);
            }

            CourseResult res = createCourseResult(&courses[j], marks, is_completed);
            addCourseResultToStudent(&students[i], res);
        }
    }

    printf("\n=== ALL STUDENTS SUMMARY ===\n");
    for (int i = 0; i < n_students; i++)
    {
        printf("\n----------------------------------------\n");
        viewStudent(students[i]);
        double cgpa = calculateCGPA(students[i].results, students[i].n_results);
        printf("Overall CGPA: %.2f\n", cgpa);
    }

    return 0;
}
