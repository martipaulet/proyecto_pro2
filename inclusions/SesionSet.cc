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

int SesionSet::AddOneFromConsole(string id_sesion) {
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

bool SesionSet::Exist(string id_sesion) const{
    Sesion_map_t::const_iterator it = sesion_map.find(id_sesion);
    if (it != sesion_map.end()) return false;
    else return true;
}

void SesionSet::ListSesionSet() {
    for (Sesion_map_t::const_iterator it = sesion_map.begin(); it != sesion_map.end(); ++it) {
        it->second.PrintSesion();
    }
}

int SesionSet::ListSesion(string id_sesion) {
    Sesion_map_t::const_iterator it = sesion_map.find(id_sesion);
    if (it == sesion_map.end()) return -1;
    else {
        it->second.PrintSesion();
    }
    return 0;
}

