// Michael R Seydel

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "vector.h"

void read_students(char *file, Student *students[], int *students_capacity,
  int *students_actual)
{
  char line[STUDENTS_CSV_LINE_SIZE];
  char temp_buff[STUDENTS_CSV_LINE_SIZE];
  char *temp_ptr;
  FILE *fp = fopen(file, "r");
  int i;

  if (!fp)
  {
    printf("%s not readable\n", file);
    exit(1);
  } // if (bad file)

  init_students(students);

  while (fgets(line, STUDENTS_CSV_LINE_SIZE, fp))
  {
    strcpy(temp_buff, strtok(line, ","));
    (*students)[*students_actual].last_name = malloc(strlen(temp_buff));
    strcpy((*students)[*students_actual].last_name, temp_buff);

    strcpy(temp_buff, strtok(NULL, ","));
    (*students)[*students_actual].first_name = malloc(strlen(temp_buff));
    strcpy((*students)[*students_actual].first_name, temp_buff);

    strcpy((*students)[*students_actual].SID, strtok(NULL, ","));

    for (i = 0; i < NUMBER_ALLOWED_CRNS; i++)
    {
      temp_ptr = strtok(NULL, ",");
      if (!temp_ptr) break;
      (*students)[*students_actual].CRNs[i] = atoi(temp_ptr);
    }
    (*students_actual)++;
    if (*students_actual == *students_capacity)
      resize_students(students, students_capacity);
  } // while (!eof)
} // read_students()

