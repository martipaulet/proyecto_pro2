#include "Course.hh"

Course::Course() {
    num_usuarios_completados = 0;
    num_usuarios_inscritos = 0;
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

//void Course::GetSesion(string id_problema)() const{
    
//}


void Course::IncreaseNumUsersDone() {
    ++num_usuarios_completados;
}

void Course::IncreaseNumUsersIn() {        
    ++num_usuarios_inscritos;
}


void Course::DecreaseNumUsersIn() {
    --num_usuarios_inscritos;
}


void Course::InsertOnList(string id_sesion) {
    Course_sesion_list.push_back(id_sesion);
}

void Course::PrintCourse(int id_course) const{
    cout << id_course+1 << " " << num_usuarios_completados << " " << num_usuarios_inscritos << " " << GetSesionListSize() << " (";
    PrintCourseSesionList(Course_sesion_list);
    cout << ")" << endl;
}

void Course::PrintCourseSesionList(const list<string>& Course_sesion_list){
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
    
