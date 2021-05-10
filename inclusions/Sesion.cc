#include "Sesion.hh"

Sesion::Sesion(const string id_sesion) {
    id = id_sesion;
    num_problemas = 0;
    MakeBinTree(this->BinTree_Problemas, this->num_problemas, this->ProblemsOnSesion_vec ,this->ProblemsSesion_map);
}


void Sesion::MakeBinTree(BinTree<string>& a, int& num_problemas, vector<string>& ProblemsOnSesion_vec, map<string, pair<string,string>>& ProblemsSesion_map) {
    string id_problema;
    cin >> id_problema;
    if (id_problema != "0") {
        ProblemsOnSesion_vec.push_back(id_problema);
        a = BinTree<string>(id_problema);
        BinTree<string> dre = a.right();
        BinTree<string> esq = a.left();
        MakeBinTree(esq, num_problemas, ProblemsOnSesion_vec, ProblemsSesion_map);
        MakeBinTree(dre, num_problemas, ProblemsOnSesion_vec ,ProblemsSesion_map);
        ++num_problemas;
        a = BinTree<string>(id_problema, esq, dre);
        
        if(a.left().empty() and a.right().empty()) ProblemsSesion_map.insert(make_pair(id_problema, make_pair("0", "0")));
        else if(a.left().empty()) ProblemsSesion_map.insert(make_pair(id_problema, make_pair("0", a.right().value())));
        else if(a.right().empty()) ProblemsSesion_map.insert(make_pair(id_problema, make_pair(a.left().value(), "0")));
        else ProblemsSesion_map.insert(make_pair(id_problema, make_pair(a.left().value(), a.right().value())));
    }
}

void Sesion::PrintBinTree_Problemas(const BinTree<string>& a){
    if (not a.empty()) {
        cout << "(";
        PrintBinTree_Problemas(a.left());
        PrintBinTree_Problemas(a.right());
        cout << a.value() << ")";
    }
}

void Sesion::PrintSesion() const{
    cout << id << " " << num_problemas << " ";
    PrintBinTree_Problemas(BinTree_Problemas);
    cout << endl;
}

string Sesion::GetSesionId() const{
    return this->id;
}

string Sesion::GetRootProblem(const BinTree<string>& BinTree_Problemas) {
    return BinTree_Problemas.value();
}

int Sesion::GetNumProblems() const{
    return this->num_problemas;
}

void Sesion::InitializeReadyToSendProblems(ProblemSet& ReadyToSend, const ProblemSet& Solved){
    string aux = GetRootProblem(BinTree_Problemas);
    i_UpdateReadyToSendProblems(ReadyToSend, Solved, ProblemsSesion_map, aux);
}


void Sesion::UpdateReadyToSendProblems(ProblemSet& ReadyToSend, const ProblemSet& Solved, const string& id_problema) {  
    i_UpdateReadyToSendProblems(ReadyToSend, Solved, ProblemsSesion_map, id_problema);
}


void Sesion::i_UpdateReadyToSendProblems(ProblemSet& ReadyToSend, const ProblemSet& Solved, const map<string, pair<string,string>>& ProblemsSesion_map, const string& id_problema) {
    
    if (not Solved.Exist(id_problema)) ReadyToSend.Add(id_problema);
        
    else {
        map<string, pair<string,string>>::const_iterator it = ProblemsSesion_map.find(id_problema);
        if(it->second.first != "0" and it->second.second == "0") i_UpdateReadyToSendProblems(ReadyToSend, Solved, ProblemsSesion_map, it->second.first);
        else if (it->second.first == "0" and it->second.second != "0") i_UpdateReadyToSendProblems(ReadyToSend, Solved, ProblemsSesion_map, it->second.second);
        else if (it->second.first != "0" and it->second.second != "0") {
            i_UpdateReadyToSendProblems(ReadyToSend, Solved, ProblemsSesion_map, it->second.first);
            i_UpdateReadyToSendProblems(ReadyToSend, Solved, ProblemsSesion_map, it->second.second);
        }
    }
}
    

string Sesion::InsertOnMap(int i) {
    return ProblemsOnSesion_vec[i];
}
