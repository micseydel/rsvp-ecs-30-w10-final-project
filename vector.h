// Michael R Seydel

#ifndef VECTOR_H
  #define VECTOR_H

  #include "student.h"
  #include "course.h"

  void init_courses(Course *courses[]);
  void init_students(Student *students[]);

  void resize_courses(Course *courses[], int *courses_capacity);
  void resize_students(Student *students[], int *students_capacity);

  void deallocate_courses(Course courses[]);
  void deallocate_students(Student students[], int *students_actual);

#endif

