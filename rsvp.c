// Michael R Seydel

#include <stdio.h>
#include <stdlib.h>
#include "course.h"
#include "vector.h"
#include "student.h"


int get_choice();
void display_info(Course courses[], Student students[],
  int courses_actual, int students_actual);


int main(int argc, char *argv[])
{
  Course *courses;
  Student *students;
  int courses_capacity = INITIAL_COURSES_CAPACITY;
  int courses_actual = 0;
  int students_capacity = INITIAL_STUDENTS_CAPACITY;
  int students_actual = 0;

  read_courses(argv[1], &courses, &courses_capacity, &courses_actual);
  read_students(argv[2], &students, &students_capacity, &students_actual);

  display_info(courses, students, courses_actual, students_actual);

  deallocate_courses(courses);
  deallocate_students(students, &students_actual);

  return 0;
} // main()


int get_choice()
{
  int choice;
  char new_line;

  printf("\nRSVP Menu\n"
    "0. Done.\n"
    "1. Find by CRN.\n"
    "2. Find by subject.\n"
    "3. Add course.\n"
    "4. Remove course.\n"
    "Your choice (0 - 4): ");

  scanf("%i", &choice);
  scanf("%c", &new_line);

  return choice;
} // get_choice()


void display_info(Course courses[], Student students[],
  int courses_actual, int students_actual)
{
  int choice;

  do
  {
    choice = get_choice();
    switch (choice)
    {
      case 0: break;
      case 1:
        find_CRN(courses, students, courses_actual, students_actual);
        break;
      case 2: find_subject(courses, courses_actual); break;
      case 3:
        add_course(courses, students, courses_actual, students_actual);
        break;
      case 4:
        remove_course(students, students_actual);
        break;
      default:
        printf("Your choice is outside the acceptable range.  "
          "Please try again.\n");
    } // switch (choice)
  } while (choice != 0);
} // display_info()

