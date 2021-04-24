#include "User.hh"

User::User(string id_user){
    id = id_user;
    envios_totales = 0;
    num_problemas_resueltos = 0;
    num_problemas_intentados = 0;   
    curso_inscrito = 0;    
}




void User::PrintUser() const {
    cout << id << "(" << envios_totales << "," << num_problemas_resueltos << "," << num_problemas_intentados << "," << curso_inscrito << ")" <<  endl;
}

int User::GetCurso() const{
    return this->curso_inscrito;
}

void User::JoinCourse(int id_course) {
    curso_inscrito = id_course;
}

void User::ListSolvedProblems() {
    ProblemsSolved.ListUserProblem();
}

void User::InitializeReadyToSendProblems(int id_course, CourseSet& cursos, SesionSet& sesiones) {
    cursos.InitializeReadyToSendProblems(id_course, sesiones, ProblemsReadyToSend);    
}

void User::ListReadyToSendProblems() {
    ProblemsReadyToSend.ListUserProblem();
}

