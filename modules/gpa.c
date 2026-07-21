#include "gpa.h"

double marksToGradePoint(double marks)
{
    if (marks >= 80) return 4.00;
    if (marks >= 75) return 3.75;
    if (marks >= 70) return 3.50;
    if (marks >= 65) return 3.25;
    if (marks >= 60) return 3.00;
    if (marks >= 55) return 2.75;
    if (marks >= 50) return 2.50;
    if (marks >= 45) return 2.25;
    if (marks >= 40) return 2.00;
    return 0.00;
}

double calculateCGPA(CourseResult results[], int n_results)
{
    double total_grade_points = 0.0;
    double total_credits = 0.0;

    for (int i = 0; i < n_results; i++)
    {
        if (!results[i].is_completed) continue;

        double gp = marksToGradePoint(results[i].marks);
        double credit = results[i].course->credit;

        total_grade_points += gp * credit;
        total_credits += credit;
    }

    if (total_credits == 0.0) return 0.0;
    return total_grade_points / total_credits;
}

double calculateSemesterGPA(CourseResult results[], int n_results, int semester)
{
    CourseResult filtered[1000];
    int count = filterResultsBySemester(results, n_results, semester, filtered);
    return calculateCGPA(filtered, count);
}

double calculateRequiredGPA(CourseResult results[], int n_results, double target_cgpa)
{
    double completed_points = 0.0;
    double completed_credits = 0.0;
    double remaining_credits = 0.0;

    for (int i = 0; i < n_results; i++)
    {
        if (results[i].is_completed)
        {
            completed_points += marksToGradePoint(results[i].marks) * results[i].course->credit;
            completed_credits += results[i].course->credit;
        }
        else
        {
            remaining_credits += results[i].course->credit;
        }
    }

    if (remaining_credits == 0.0) return 0.0;

    double target_total_points = target_cgpa * (completed_credits + remaining_credits);
    double required_points = target_total_points - completed_points;

    return required_points / remaining_credits;
}
