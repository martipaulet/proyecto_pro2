#include "User.hh"

User::User(const string id_user){
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

void User::JoinCourse (int id_course, CourseSet& cursos, SesionSet& sesiones) {
    curso_inscrito = id_course;
    cursos.IncreaseNumUsersIn(id_course);
    InitializeReadyToSendProblems(id_course, cursos, sesiones);
    cout << cursos.GetNumUsersIn(id_course) << endl;
}

void User::InitializeReadyToSendProblems(int id_course, CourseSet& cursos, SesionSet& sesiones) {
    cursos.InitializeReadyToSendProblems(id_course, sesiones,  ProblemsReadyToSend, ProblemsSolved);
}



void User::ListSolvedProblems() {
    ProblemsSolved.ListUserProblem();
}

void User::ListReadyToSendProblems() {
    ProblemsReadyToSend.ListUserProblem();
}



// Si r vale 0: 
        //  - Estadisticas User: Dentro de p, se ha de incrementar envios_totales (si envios_totales pasa a valer 1, se incrementara el num_problemas_intentados), actualizando el ratio.
        //     Se incrementará la variable enviostotales dentro del usuario                    
        //  - Estadísticas Problem: Se incrementará la variable enviostotales, y se actualizará el ratio.

// Si r vale 1: 
        //  - Estadisticas User: Se traspasará p de ReadyToSendProblems a SolvedProblems(se han de conservar los datos de p), teniendo en cuenta que en p se ha de incrementar enviostotales (si envios_totales pasa a valer 1, se 
        //     incrementara el num_problemas_intentados) y envios_exito, actualizando el ratio.
        //     Se comprobará si todos los problemas de curso_incrito constan como Solved, y en ese caso curso_inscrito se escribirá a 0. 
        //     usuarios.Update llamará a cursos.Update con el curso del usuario u antes de poner curso_inscrito a 0.
        //     Se incrementará la variable enviostotales dentro del usuario
        //  - Estadísticas Problem: Se incrementará la variable enviostotales, enviosexito, y se actualizará el ratio.
        //  - Estadísticas curso: Se decrementará la variable num_usuarios_inscritos y se incrementará la variable num_usuarios_completados si curso_inscrito=0.
                    

          
void User::Update (const string& id_problem, int r, ProblemSet& problemas, SesionSet& sesiones, CourseSet& cursos) {
    ++envios_totales;
    if (ProblemsReadyToSend.GetTotalSends(id_problem) == 0) ++num_problemas_intentados;
    
    if (r== 0) {
        problemas.IncreaseTotalSends(id_problem);
        ProblemsReadyToSend.IncreaseTotalSends(id_problem);
    }
    
    else {
        ++num_problemas_resueltos;
        problemas.IncreaseSolvedSends(id_problem);
        ProblemsReadyToSend.IncreaseSolvedSends(id_problem);
        
        Problem aux = ProblemsReadyToSend.GetProblem(id_problem);
        ProblemsSolved.AddToUserMap(aux);
        ProblemsReadyToSend.Delete(id_problem);
        
        cursos.UpdateReadyToSendProblems(curso_inscrito, sesiones, ProblemsReadyToSend, ProblemsSolved, id_problem);
  
        
        if (ProblemsReadyToSend.Size() == 0) {
            cursos.IncreaseNumUsersDone(curso_inscrito);
            cursos.DecreaseNumUsersIn(curso_inscrito);
            curso_inscrito = 0;
        }
    }
    
}

