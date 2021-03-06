/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH
#define _SESION_HH
#include "ProblemSet.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <set>
#include <vector>
#endif

using namespace std;

/** @class Sesion
    @brief Representa una sesion con el numero de problemas en esta contenidos en un BinTree
*/
class Sesion 
{
public:
    
    //Constructora
    
    /** @brief  Creadora por defecto.
        \pre La string id no es vacia.
        \post El resultado es una sesion con id = id_sesion, num_problemas = 0 y un BinTree de strings (de id_problemas). 
    */
    Sesion(const string id_sesion);   //DONE
    
    
    //Consultoras
    
    /** @brief Consultora del identificador de la sesión.
        \pre <em>Cierto.</em>
        \post El resultado es el identificador del parámetro implícito.
    */
    string GetSesionId() const; //DONE
    
    
    /** @brief Consultora del número de problemas.
        \pre <em>Cierto.</em>
        \post El resultado es el número de problemas del parámetro implícito.
    */
    int GetNumProblems() const; //DONE
    
    string GetRootProblem(const BinTree<string>& BinTree_Problemas); //DONE
    
    
    
    string InsertOnMap(int i);
    
    
    //Modificadoras
    
    void InitializeReadyToSendProblems(ProblemSet& ReadyToSend, const ProblemSet& Solved);
    
    void UpdateReadyToSendProblems(ProblemSet& ReadyToSend, const ProblemSet& Solved, const string& id_problema);
    
    //Escritura
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se ha escrito los atributos del parámetro implícito en el canal estandar de salida.
    */
    void PrintSesion() const;   //DONE
    
    

    
    
private:
    string id;
    int num_problemas;
    BinTree<string> BinTree_Problemas;      // Leer en Postorden
    vector<string> ProblemsOnSesion_vec;
    map<string, pair <string,string>> ProblemsSesion_map;  //problema con hijos
    
    /** @brief Crea el BinTree de problemas
        \pre <em>Cierto.</em>
        \post El resultado es un BinTree de strings de problemas siguiendo una estructura dada en postorden.
    */
    static void MakeBinTree(BinTree<string>& a, int& num_problemas, vector<string>& ProblemsOnSesion_vec, map<string, pair <string,string>>& ProblemsSesion_map);    //DONE
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se han escrito el atributo (BinTree_Problemas) con los identificadores de los problemas el canal estandar de salida.
    */
    static void PrintBinTree_Problemas(const BinTree<string>& a);    //DONE
        
    static void i_UpdateReadyToSendProblems(ProblemSet& ReadyToSend, const ProblemSet& Solved, const map<string, pair<string,string>>& ProblemsSesion_map, const string& id_problema);
};
#endif
