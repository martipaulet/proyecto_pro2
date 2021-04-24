#include "CourseSet.hh"


CourseSet::CourseSet() {
}

void CourseSet::AddFromConsole(SesionSet& sesiones) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        Course aux(sesiones);
        Course_vec.push_back(aux);
    }
}

int CourseSet::Size() const {
    return Course_vec.size();
}

bool CourseSet:: Exist(int id_course) const{
    return (0 < id_course and id_course <= Size());
}

/*
Course CourseSet::GetCourse(int id_course) const{
    return Course_vec[id_course-1];
}
*/


void CourseSet::ListCourseSet(){
    int size = Size();
    for (int i = 0; i < size; ++i) {
            Course_vec[i].PrintCourse(i);
    }
}

int CourseSet::ListCourse(int id_course){
    if (0 < id_course and id_course <= Size()) {
        Course_vec[id_course-1].PrintCourse(id_course-1);
        return 0;
    }
    return -1;
}

bool CourseSet::ExistProblem(int id_course, string id_problem) const{
    return (Course_vec[id_course-1].ExistProblem(id_problem));
}

int CourseSet::GetNumUsersIn(int id_course) const {
    return Course_vec[id_course-1].GetNumUsersIn();
}

void CourseSet::IncreaseNumUsersDone(int id_course) {
    Course_vec[id_course-1].IncreaseNumUsersDone();
}

void CourseSet::IncreaseNumUsersIn(int id_course) {
    Course_vec[id_course-1].IncreaseNumUsersIn();
}

void CourseSet::DecreaseNumUsersIn(int id_course) {
    Course_vec[id_course-1].DecreaseNumUsersIn();
}

void CourseSet::InitializeReadyToSendProblems(int id_course, SesionSet& sesiones, ProblemSet& problems) {
    Course_vec[id_course-1].InitializeReadyToSendProblems(sesiones, problems);
}

void CourseSet::ProblemSesion(int id_course, string id_problem) {
    Course_vec[id_course-1].ProblemSesion(id_problem);
}
