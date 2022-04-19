 /* @brief function prototypes for the student file/
  * this contains the prototypes for the student file 
  * including the first and last name with an array, the grade all within the student class 
  * it initilizes the add_grade, geberate_random_student and average functions. 
  * 
  * the typedef struct _student is used to make the code look cleaner from using struct 
  * as well as making _student a type. 
 */
typedef struct _student 
{ 
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades; 
  int num_grades; 
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
