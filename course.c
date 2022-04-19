#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/* @file course.h
 * Function for enroll_student
 * 
 * This file contains the 
 * prototype for enroll_student
 * including, total_student, course, 
 * print_course, top_student and other variables
 * 
 * @author Kareem Zidan
 * @author CS1XC3 INSTRUCTOR 
 * @bug No known bugs.
*/

/* @brief promps user for Course and Student. 
 * Allocates the course into the course variable 
 * Allocates the student into the student variable 
 * Sets course to a value. Course can only be given a specific value
 * Its value is given by the total number of students (total_students)
 * Using the calloc function to allocate a specified amount of memory.
 * This function returns a void pointer to this memory of
 * sizeof(students), which is a compile-time unary operator used to 
 * compute the size of its operand. 
 * sizeof returns the size of the variable, being students. Or, how
 * many stuents memory, in this data type. 
 * 
 * If the total_students equals to 1, then take the data type of Student 
 * using sizeof to allocate its memory or size. 
 * 
 * else course realloc  the course of students and course of total_students
 * using the memory of students using sizeof. 
 * 
 * @return void
 *
*/
 
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/* @brief Prints the course name and code, with "\n" 
 * new line after each prompt. 
 * Prints total students and sets that to course. 
 * 
 * using a for loop, if the course size (total number of students)
 * is greater then the initialized 0, print the sudents course and students
 * at the array of i in the loop.
 * 
 * @return void
*/
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}
/* @brief finds the top student of the course of total students 
 * if the number of total students equals to 0, then return NULL 
 * as there is no student to find the top one. 
 * double variable, find the average of the student initiliazed at 0. 
 * find the max average of all the students using the average function
 * 
 * As long as there is more then 1 student, there will be a max average to find
 * using a for loop, if there is more then 1 students in course, 
 * find the average of each student. 
 * if the student average is greater then the maz average 
 * then the maz average equals to the student average 
 * and student equals to the course of the student at inialized of loop.
 * 
 * @param total_student
 * @param max_average 
 * @param student_average 
 * @return student 
 * @return NULL
*/

Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/* @brief finding all the studens who passed the course. 
 * using a counter in a for loop, go through every student
 * in the course and check if they pass the course. 
 * The counter increases by 1 everytime 1 students, average 
 * is abover 50. 
 * using calloc because there are some parts of the data that is unitialized 
 * to allocate the memory of students that are passing and not passing. 
 * find the total passing in the course equal to the counter 
 * which was increasing by 1 as each student thats average was above 50. 
 * 
 * @param total_passing
 * @param course->total_students
 * @return passing
*/

Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}