// Michael R Seydel

#ifndef STUDENT_H
  #define STUDENT_H

  #define INITIAL_STUDENTS_CAPACITY 10
  #define STUDENTS_CSV_LINE_SIZE 80
  #define SID_STRLEN 12
  #define NUMBER_ALLOWED_CRNS 5

  typedef struct {
    char *first_name;
    char *last_name;
    char SID[SID_STRLEN];
    int CRNs[NUMBER_ALLOWED_CRNS];
    int number_classes;
  } Student;

  void read_students(char *file, Student *students[], int *students_capacity,
    int *students_actual);  

#endif

