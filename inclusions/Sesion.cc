#include "Sesion.hh"

Sesion::Sesion(string id_sesion) {
    id = id_sesion;
    num_problemas = 0;
    BinTree<string> BinTree_Problemas;
    vector<string> ProblemsOnSesion_vec;
    MakeBinTree(this->BinTree_Problemas,this->num_problemas,this->ProblemsOnSesion_vec);
}


void Sesion::MakeBinTree(BinTree<string>& a, int& num_problemas, vector<string>& ProblemsOnSesion_vec) {
    string id_problema;
    cin >> id_problema;
    if (id_problema != "0") {
        ProblemsOnSesion_vec.push_back(id_problema);
        a = BinTree<string>(id_problema);
        BinTree<string> esq = a.left();
        MakeBinTree(esq, num_problemas, ProblemsOnSesion_vec);
        BinTree<string> dre = a.right();
        MakeBinTree(dre, num_problemas, ProblemsOnSesion_vec);
        ++num_problemas;
        a = BinTree<string>(id_problema, esq, dre);
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


int Sesion::GetNumProblems(){
    return this->num_problemas;
}

void Sesion::InitializeReadyToSendProblems(ProblemSet& problems) {
    string value = BinTree_Problemas.value();
    problems.Add(value);
}
    

string Sesion::InsertOnMap(int i) {
    return ProblemsOnSesion_vec[i];
}
