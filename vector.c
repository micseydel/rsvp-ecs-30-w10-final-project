// Michael R Seydel

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "course.h"
#include "student.h"


void init_courses(Course *courses[])
{
  *courses = malloc(INITIAL_COURSES_CAPACITY * sizeof(Course));
} // init_courses()


void init_students(Student *students[])
{
  int i, j;

  *students = malloc(INITIAL_STUDENTS_CAPACITY * sizeof(Student));

  for (i = 0; i < INITIAL_STUDENTS_CAPACITY; i++)
    for (j = 0; j < NUMBER_ALLOWED_CRNS; j++)
      (*students)[i].CRNs[j] = 0;
} // init_students()


void resize_courses(Course *courses[], int *courses_capacity)
{
  int i;
  Course *temp;

  temp = malloc(*courses_capacity * 2 * sizeof(Course));
  if (!temp) return;

  for (i = 0; i < *courses_capacity; i++)
    temp[i] = (*courses)[i];

  *courses_capacity *= 2;

  free(*courses);
  *courses = temp;
} // resize_courses()


void resize_students(Student *students[], int *students_capacity)
{
  int i, j;
  Student *temp;

  temp = malloc(*students_capacity * 2 * sizeof(Student));

  for (i = 0; i < *students_capacity; i++)
    temp[i] = (*students)[i];

  *students_capacity *= 2;

  for (; i < *students_capacity; i++)
    for (j = 0; j < NUMBER_ALLOWED_CRNS; j++)
      temp[i].CRNs[j] = 0;

  free(*students);
  *students = temp;
} // resize_students()


void deallocate_courses(Course courses[])
{
  free(courses);
} // deallocate_courses()


void deallocate_students(Student students[], int *students_actual)
{
  int i;

  for (i = 0; i < *students_actual; i++)
  {
    free(students[i].first_name);
    free(students[i].last_name);
  } // for (each student)

  free(students);
} // deallocate_students()

