#include "UserSet.hh"

UserSet::UserSet() {
}

void UserSet::AddFromConsole() {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string id_user;
        cin >> id_user;
        user_map.insert(make_pair(id_user, User(id_user)));
    }
}

void UserSet::ListUserSet() {
    for (User_map_t::const_iterator it = user_map.begin(); it != user_map.end(); ++it) {
        it->second.PrintUser();
    }
}
    
int  UserSet::ListUser(string id_user) {
    User_map_t::const_iterator it = user_map.find(id_user);
    if (it == user_map.end()) return -1;
    else {
        it->second.PrintUser();
    }
    return 0;
}

int UserSet::Size()const {
    return user_map.size();
}

bool UserSet::Exist(string id_user) const{
    User_map_t::const_iterator it = user_map.find(id_user);
    return (it != user_map.end());
}

int UserSet::Add(string id_user) {
    if (Exist(id_user)) {
        return -1;
    }
    else {
       user_map.insert(make_pair(id_user, User(id_user)));
    }
    return 0;
}

void UserSet::Delete(string id_user) {
    user_map.erase(id_user);
}

int UserSet::GetCurso(string id_user) const{
    User_map_t::const_iterator it = user_map.find(id_user);
    return it->second.GetCurso();
}

void UserSet::JoinCourse(string id_user, int id_course) {
     User_map_t::iterator it = user_map.find(id_user);
     it->second.JoinCourse(id_course);
}

void UserSet::InitializeReadyToSendProblems(string id_user, int id_course, CourseSet& cursos, SesionSet& sesiones) {
    User_map_t::iterator it = user_map.find(id_user);
    it->second.InitializeReadyToSendProblems(id_course, cursos, sesiones);
}

void UserSet::ListSolvedProblems(string id_user) {
     User_map_t::iterator it = user_map.find(id_user);
     it->second.ListSolvedProblems();
}

void UserSet::ListReadyToSendProblems(string id_user) {
    User_map_t::iterator it = user_map.find(id_user);
    it->second.ListReadyToSendProblems();
}
