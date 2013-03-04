// Michael R Seydel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "course.h"
#include "vector.h"
#include "student.h"


void read_courses(char file[], Course *courses[], int *courses_capacity,
  int *courses_actual)
{
  FILE *fp = fopen(file, "r");
  char line[LINE_SIZE];
  int CRN;

  if (!fp)
  {
    printf("%s not readable.\n", file);
    exit(1);
  } // if (file_not_found)

  init_courses(courses);

  while (fgets(line, LINE_SIZE, fp))
  {
    if (!isdigit(line[0])) continue; // no useful data on this line
    CRN = atoi(strtok(line, "\t"));
    if (CRN > 10000 && CRN < 100000)
    { // used *courses_actual instead of i, to save lines
      (*courses)[*courses_actual].CRN = CRN;
      strcpy((*courses)[*courses_actual].subject, strtok(NULL, "\t^"));
      strcpy((*courses)[*courses_actual].course, strtok(NULL, "\t"));
      (*courses_actual)++;
      if (*courses_actual == *courses_capacity)
        resize_courses(courses, courses_capacity);
    } // if (CRN) - when a CRN exists, so does a subject, course, etc.
  } // while (!eof)
} // read_courses()


void find_CRN(Course courses[], Student students[],
  int courses_actual, int students_actual)
{
  int CRN;
  int i, j, k;

  printf("Please enter a CRN: ");
  scanf("%i", &CRN);

  for (i = 0; i < courses_actual; i++)
    if (courses[i].CRN == CRN)
    {
      printf("%s %s\n", courses[i].subject, courses[i].course);
      for (j = 0; j < students_actual; j++)
      {
        for (k = 0; k < NUMBER_ALLOWED_CRNS; k++)
        {
          if (students[j].CRNs[k] == CRN)
            printf("%s %s\n", students[j].last_name, students[j].first_name);
        } // for k
      } // for j
      return;
    } // if (CRNs are the same)
  printf("CRN %i not found.\n", CRN);
} // find_CRN()


void find_subject(Course courses[], int courses_actual)
{
  char subject[SUBJECT_SIZE];
  int found_one = FALSE;
  int i;

  printf("Please enter a subject: ");
  fgets(subject, SUBJECT_SIZE, stdin);

  for (i = 0; i < courses_actual; i++)
    if (!strcmp(courses[i].subject, subject))
    {
      printf("%i %s %s\n",
        courses[i].CRN, courses[i].subject, courses[i].course);
      found_one = TRUE;
    } // if (subjects are the same

  if (!found_one)
    printf("No courses were found for %s.\n", subject);
} // find_subject()


void add_course(Course courses[], Student students[],
  int courses_actual, int students_actual)
{
  char SID[SID_STRLEN];
  int CRN;
  int i, j, k;
  int CRNs_full = TRUE;

  printf("Add Course\n");
  printf("Please enter the SID of the student: ");
  fgets(SID, SID_STRLEN, stdin);

  for (i = 0; i < students_actual; i++)
    if (!strcmp(students[i].SID, SID))
    {
      for (j = 0; j < NUMBER_ALLOWED_CRNS; j++)
        if (!students[i].CRNs[j])
        {
          CRNs_full = FALSE;
          break;
        } // if (found an empty CRN)

      if (CRNs_full)
      {
        printf("You are already taking 5 courses.\n");
        return;
      } // if (CRNs_full)

      printf("Please enter the CRN: ");
      scanf("%i", &CRN);

      for (k = 0; k < courses_actual; k++)
        if (courses[k].CRN == CRN)
        {
          students[i].CRNs[j] = CRN;
          return;
        } // if (the course entered was OK)
      printf("There is no course with CRN #%i\n", CRN);
      return;
    } // if (found the student)
  printf("A student with SID #%s was not found.\n", SID);
} // add_course()


void remove_course(Student students[], int students_actual)
{
  char SID[SID_STRLEN];
  int CRN;
  int i, j, k;

  printf("Remove Course\n");

  printf("Please enter the SID of the student: ");
  fgets(SID, SID_STRLEN, stdin);

  for (i = 0; i < students_actual; i++)
    if (!strcmp(students[i].SID, SID))
    {
      printf("Current courses: ");
      for (j = 0; j < NUMBER_ALLOWED_CRNS; j++)
        if (students[i].CRNs[j])
          printf("%i ", students[i].CRNs[j]);
      printf("\n");
      printf("Please enter the CRN: ");
      scanf("%i", &CRN);
      
      for (k = 0; k < NUMBER_ALLOWED_CRNS; k++)
        if (students[i].CRNs[k] == CRN)
        {
          students[i].CRNs[k] = 0;
          return;
        } // if (found the CRN)

      printf("You are not taking that course.\n");
    } // if (found the student)
  printf("A student with SID #%s was not found.\n", SID);
} // remove_course()

