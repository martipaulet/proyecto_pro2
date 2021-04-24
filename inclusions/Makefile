OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
# OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: program.o Problem.o ProblemSet.o Sesion.o SesionSet.o Course.o CourseSet.o User.o UserSet.o
	g++ $(OPCIONS) -o program.exe Problem.o ProblemSet.o program.o Sesion.o SesionSet.o Course.o CourseSet.o User.o UserSet.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Problems.o: Problem.cc Problem.hh
	g++ $(OPCIONS) -c Problem.cc

ProblemSet.o: ProblemSet.cc ProblemSet.hh
	g++ $(OPCIONS) -c ProblemSet.cc
	
Sesion.o: Sesion.cc Sesion.hh
	g++ $(OPCIONS) -c Sesion.cc

SesionSet.o: SesionSet.cc SesionSet.hh
	g++ $(OPCIONS) -c SesionSet.cc

Course.o: Course.cc Course.hh
	g++ $(OPCIONS) -c Course.cc
	
CourseSet.o: CourseSet.cc CourseSet.hh
	g++ $(OPCIONS) -c CourseSet.cc
	
User.o: User.cc User.hh
	g++ $(OPCIONS) -c User.cc
	
UserSet.o: UserSet.cc UserSet.hh
	g++ $(OPCIONS) -c UserSet.cc


practica.tar: Makefile program.cc UserSet.hh UserSet.cc User.hh User.cc CourseSet.hh CourseSet.cc Course.hh Course.cc SesionSet.hh SesionSet.cc Sesion.hh Sesion.cc ProblemSet.hh ProblemSet.cc Problem.hh Problem.cc 
	tar -cvf practica.tar *.cc *.hh Makefile 
	
clean: 
	rm -f *.o *.gch *.exe *.tar
