#include "ProblemSet.hh"

//Constructoras


ProblemSet::ProblemSet() {
}


//Consultoras

bool ProblemSet::Exist(string id_problema) const{
    Problem_map_t::const_iterator it = problem_map.find(id_problema);
    if (it != problem_map.end()) return true;
    return false;
}

int ProblemSet::Size() const{
    return problem_map.size();
}

/*
Problem ProblemSet::GetProblem(string id_problema) const {
    Problem_map_t::const_iterator it = problem_map.find(id_problema);
    return it->second;
}
*/

//Modificadoras

int ProblemSet::Add(string id_problema){
    Problem_map_t::iterator it = problem_map.find(id_problema);
    if (it != problem_map.end()) return -1;
    else {
        problem_map.insert(make_pair(id_problema,Problem(id_problema)));
    }
    return 0;
}

void ProblemSet::IncreaseTotalSends(string id_problema){
    Problem_map_t::iterator it = problem_map.find(id_problema);
    if (it != problem_map.end()) {
        it->second.IncreaseTotalSends();
    }
}

void ProblemSet::IncreaseSolvedSends(string id_problema){
    Problem_map_t::iterator it = problem_map.find(id_problema);
    if (it != problem_map.end()) {
        it->second.IncreaseSolvedSends();
    }
}

//Lectura y escritura
void ProblemSet::AddFromConsole() {
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        string id_problema;
        cin >> id_problema;
        problem_map.insert(make_pair(id_problema, Problem(id_problema)));
    }    
}

//Struct para hacer la ordenación por ratio
struct Key{
    double ratio;
    string id;
    bool operator<(const Key& a) const;
};
    
bool Key::operator<(const Key& a) const{
    if (ratio == a.ratio) return id < a.id;
    else return ratio > a.ratio;
}

void ProblemSet::ListProblemSetByRatio() { 
    map<Key, Problem> problem_map_aux;
    for (Problem_map_t::const_iterator it = problem_map.begin(); it != problem_map.end(); ++it) {
        Key aux;
        aux.ratio = it->second.GetRatio();
        aux.id = it->first;
        problem_map_aux.insert(make_pair(aux, it->second));
    }
    for (map<Key, Problem>::const_iterator it = problem_map_aux.begin(); it != problem_map_aux.end(); ++it){
        it->second.PrintProblem();
    }
}

void ProblemSet::ListProblemSet() {
    for (Problem_map_t::iterator it = problem_map.begin(); it != problem_map.end(); ++it) {
        it->second.PrintProblem();
    }
}

int ProblemSet::ListProblem(string id_problema) {
    Problem_map_t::const_iterator it = problem_map.find(id_problema);
    if (it == problem_map.end()) return -1;
    else {
        it->second.PrintProblem();
    }
    return 0;
}

void ProblemSet::ListUserProblem() const {
    for (Problem_map_t::const_iterator it = problem_map.begin(); it != problem_map.end(); ++it) {
        it->second.PrintUserProblem();
    }
}




