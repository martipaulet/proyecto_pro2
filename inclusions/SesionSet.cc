#include "SesionSet.hh"


SesionSet::SesionSet() {
}


void SesionSet::AddFromConsole() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string id_sesion;
        cin >> id_sesion;
        sesion_map.insert(make_pair(id_sesion, Sesion(id_sesion)));
    }
}

int SesionSet::AddOneFromConsole(const string& id_sesion) {
    Sesion_map_t::iterator it = sesion_map.find(id_sesion);
    if (it != sesion_map.end()) return -1;
    else {
        sesion_map.insert(make_pair(id_sesion,Sesion(id_sesion)));
    }
    return 0;   
}

int SesionSet::Size() const{
    return sesion_map.size();
}

bool SesionSet::Exist(const string& id_sesion) const{
    Sesion_map_t::const_iterator it = sesion_map.find(id_sesion);
    return (it != sesion_map.end());
}


int SesionSet::GetNumProblems(const string& id_sesion) const{
     Sesion_map_t::const_iterator it = sesion_map.find(id_sesion);
     return it->second.GetNumProblems();
    
}


string SesionSet::InsertOnMap(const string& id_sesion, int i){
     Sesion_map_t::iterator it = sesion_map.find(id_sesion);
     return it->second.InsertOnMap(i);
}



void SesionSet::ListSesionSet() {
    for (Sesion_map_t::const_iterator it = sesion_map.begin(); it != sesion_map.end(); ++it) {
        it->second.PrintSesion();
    }
}

int SesionSet::ListSesion(const string& id_sesion) {
    Sesion_map_t::const_iterator it = sesion_map.find(id_sesion);
    if (it == sesion_map.end()) return -1;
    else {
        it->second.PrintSesion();
    }
    return 0;
}

void SesionSet::InitializeReadyToSendProblems(const string& id_sesion, ProblemSet& ReadyToSend, const ProblemSet& Solved) {
    Sesion_map_t::iterator it = sesion_map.find(id_sesion);
    it->second.InitializeReadyToSendProblems(ReadyToSend, Solved);
}

void SesionSet::UpdateReadyToSendProblems(string id_sesion, ProblemSet& ReadyToSend, const ProblemSet& Solved, const string& id_problema) {
    Sesion_map_t::iterator it = sesion_map.find(id_sesion);
    it->second.UpdateReadyToSendProblems(ReadyToSend, Solved, id_problema);
}




