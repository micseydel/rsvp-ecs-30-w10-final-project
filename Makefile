# Michael R Seydel

rsvp: rsvp.o course.o vector.o student.o
	gcc -Wall -g -o rsvp rsvp.o course.o vector.o student.o

rsvp.o: rsvp.c
	gcc -Wall -g -c rsvp.c

course.o: course.c course.h
	gcc -Wall -g -c course.c

vector.o: vector.c vector.h
	gcc -Wall -g -c vector.c

student.o: student.c student.h
	gcc -Wall -g -c student.c

clean:
	rm -f rsvp rsvp.o course.o vector.o student.o
