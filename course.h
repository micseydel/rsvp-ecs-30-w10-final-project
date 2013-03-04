// Michael R Seydel

#ifndef COURSE_H
  #define COURSE_H

  #include "student.h"
  #define INITIAL_COURSES_CAPACITY 100
  #define SUBJECT_SIZE 4
  #define COURSE_SIZE 6
  #define LINE_SIZE 150
  #define FALSE 0
  #define TRUE 1

  typedef struct {
    int CRN;
    char subject[SUBJECT_SIZE];
    char course[COURSE_SIZE];
  } Course;

  void read_courses(char file[], Course *courses[], int *courses_capacity,
    int *courses_actual);
  void find_CRN(Course courses[], Student students[],
    int courses_actual, int students_actual);
  void find_subject(Course courses[], int courses_actual);
  void add_course(Course courses[], Student students[],
    int courses_actual, int students_actual);
  void remove_course(Student students[], int students_actual);

#endif

