/** @file Problem.cc
    @brief Implementación de la clase Problem
*/

#include "Problem.hh"


//Constructora

Problem::Problem(const string id_problema) {
    id = id_problema;
    envios_totales = 0;
    envios_exito = 0;
    ratio = 1;
}



//Consultoras
    
string Problem::GetProblemId() const{
    return id;
}


int Problem::GetEnviosTotales() const {
    return this->envios_totales;
}


int Problem::GetEnviosExito() const{
    return this->envios_exito;
}


double Problem::GetRatio() const{
    return this->ratio;
}


    
//Modificadoras
    
void Problem::IncreaseTotalSends(){
    ++envios_totales;
    ratio = (envios_totales+1.0)/(envios_exito+1.0);
}


void Problem::IncreaseSolvedSends(){
    ++envios_totales;
    ++envios_exito;
    ratio = (envios_totales+1.0)/(envios_exito+1.0);
}



//Escritura

void Problem::PrintProblem() const{
    cout << id <<"(" << envios_totales << "," << envios_exito << "," << ratio <<")" << endl;
}


void Problem::PrintUserProblem() const{
    cout << id << "(" << envios_totales << ")" << endl;
}
