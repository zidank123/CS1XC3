#include "student.h"
#include <stdbool.h>

/* #brief creating a type _course within all the files 
 * initilazing all the variables 

 * This code uses typedef struct to create a type called, 
 * "_course" in this program. This means we don't need to write
 * struct throughout our code. It makes the code look much cleaner as well. 
 * 
 * Initialize top_student in the Student class with function class 
 * Initiliaze passing in the Student class with function course and total_passing 
 * 
*/
 
typedef struct _course 
{
  char name[100];
  char code[10];
  Student *students;
  int total_students;
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


