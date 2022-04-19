
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/* @brief this is the main file
 * that finds the course class, code, number of students (using a generator),
 * top student in the class, and number of passing students
 * 
 * srand is used to ensure that generating a number of students 
 * is not one set value
 * strcpy return the copied string including NULL.
 * from the "course.c" file we use the enroll_student function, 
 * print_course function, print_student, total_passing functions.
 * 
 * @param student, total_passing, passing_students
 * @return 0

*/

int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}