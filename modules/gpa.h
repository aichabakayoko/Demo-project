#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

double marksToGradePoint(double marks);
double calculateCGPA(CourseResult results[], int n_results);
double calculateSemesterGPA(CourseResult results[], int n_results, int semester);
double calculateRequiredGPA(CourseResult results[], int n_results, double target_cgpa);

#endif
