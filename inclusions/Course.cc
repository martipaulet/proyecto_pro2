#include "Course.hh"

Course::Course() {
    num_usuarios_completados = 0;
    num_usuarios_inscritos = 0;
}

void Course::Read() {        //HACER
    int sc;
    cin >> sc;
    for (int i = 0; i < sc; ++i) {
        string id_sesion;
        cin >> id_sesion;
        InsertOnList(id_sesion);
    }
}

//inicilaizar el map problema-sesion sin comprovar
void Course::Initialize_map(SesionSet& sesiones) {
    for (list<string>::const_iterator it = Course_sesion_list.begin(); it != Course_sesion_list.end(); ++it) {
        int n = sesiones.GetNumProblems(*it);
        for (int i = 0; i < n; ++i) {
            Course_sesion_map.insert(make_pair(sesiones.InsertOnMap(*it, i), *it));
        }
    }
}

//inicializar el map comprovando
bool Course::Validate(SesionSet& sesiones) {
    bool valido = true;
    list<string>::const_iterator it = Course_sesion_list.begin();
    while (valido and it != Course_sesion_list.end()) {
         valido = InsertOnMap(*it, sesiones, valido);
         ++it;
    }
    return valido;    
}

//private
bool Course::InsertOnMap(const string& id_sesion, SesionSet& sesiones, bool& valido) {
    int n = sesiones.GetNumProblems(id_sesion);
    for (int i = 0; valido and i < n; ++i) {
        auto p = Course_sesion_map.insert(make_pair(sesiones.InsertOnMap(id_sesion,i), id_sesion));
        if (not p.second) 
            valido = false;
    }
    return valido;
}


int Course::GetNumUsersDone() const{
    return num_usuarios_completados;
    
}

int Course::GetNumUsersIn() const{
    return num_usuarios_inscritos;
    
}

int Course::GetSesionListSize() const{
    return Course_sesion_list.size();
}

void Course::InitializeReadyToSendProblems(SesionSet& sesiones, ProblemSet& ReadyToSend, const ProblemSet& Solved) {
    for (list<string>::const_iterator it = Course_sesion_list.begin(); it != Course_sesion_list.end(); ++it) {
        sesiones.InitializeReadyToSendProblems(*it, ReadyToSend, Solved);
    }
}


void Course::UpdateReadyToSendProblems(SesionSet& sesiones, ProblemSet& ReadyToSend, const ProblemSet& Solved, const string& id_problema){
    Course_sesion_map_t::iterator it = Course_sesion_map.find(id_problema);
    sesiones.UpdateReadyToSendProblems(it->second, ReadyToSend, Solved, id_problema);
}



void Course::IncreaseNumUsersDone() {
    ++num_usuarios_completados;
}

void Course::IncreaseNumUsersIn() {        
    ++num_usuarios_inscritos;
}


void Course::DecreaseNumUsersIn() {
    --num_usuarios_inscritos;
}

bool Course::ExistProblem(const string& id_problema) const{
    Course_sesion_map_t::const_iterator it = Course_sesion_map.find(id_problema);
    return (it != Course_sesion_map.end());
}
 
 
void Course::InsertOnList(const string& id_sesion) {
    Course_sesion_list.push_back(id_sesion);
}


void Course::PrintCourse(int id_course) const{
    cout << id_course+1 << " " << num_usuarios_completados << " " << num_usuarios_inscritos << " " << GetSesionListSize() << " (";
    PrintCourseSesionList();
    cout << ")" << endl;
}


void Course::PrintCourseSesionList() const{
    bool first = true;
    for (list<string>::const_iterator it = Course_sesion_list.begin(); it != Course_sesion_list.end(); ++it) {
        if (first) {
            cout << *it;
            first = false;
        }
        else {
            cout << " " << (*it);
        }
    }
}

void Course::ProblemSesion(const string& id_problem) {
     Course_sesion_map_t::iterator it = Course_sesion_map.find(id_problem);
     cout << it->second << endl;
}

