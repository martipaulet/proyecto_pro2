/** @file ProblemSet.hh
    @brief Especificación de la clase ProblemSet
*/

#ifndef _PROBLEMSET_HH
#define _PROBLEMSET_HH

#include "Problem.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class ProblemSet
    @brief Representa un conjunto de problemas ordenados crecientemente por id.
*/

class ProblemSet
{
public:
    
    //Constructoras
    
    /** @brief  Creadora por defecto.
        \pre <em>Cierto.</em>.
        \post El resultado es un conjunto de problemas vacío.
    */
    ProblemSet();
    
    
    
    
    //Consultoras
    
    /** @brief Consultora de problema en ProblemSet.
        \pre El string id_problema no es vacío.
        \post Devuelve un booleano conforme si existe el problema con id = id_problema en el parámetro implícito. True si existe y false en caso contrario.
    */
    bool Exist(const string& id_problema) const;   //DONE
    
    /** @brief Consultora del tamaño del conjunto.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida el tamaño del parámetro implícito.
    */
    int Size() const;   //DONE
    
    
    /** @brief Consultora del problema con id = id_problem del conjunto.
        \pre <em>El problema con id_problem existe.</em>
        \post Se devuelve el problema con id = id_problem.
    */
    Problem GetProblem(const string& id_problem) const;
    
    
    /** @brief Consultora de los envios totales.
        \pre El string id_problema no es vacío y el problema con id = id_problema existe.
        \post Busca en el parámetro implícito el problema con id = id_problema y si lo encuentra retorna los envios_totales de este.
    */
    int GetTotalSends(const string& id_problema) const;
    

    

    
    //Modificadoras
    
    /** @brief Añade un problema.
        \pre El string id_problema no es vacio.
        \post Si el id_problema no estaba en el parámetro implícito, lo introduce y retorna 0. En caso que ya existiera retorna -1.
    */
    int Add(const string& id_problema);    //DONE
    
    void AddToUserMap(Problem& problem);
    
    
    void Delete(const string& id_problema);
    


    
    /** @brief Actualiza el problema. 
        \pre El problema con id = id_problema existe y r = 0 (fallo) o r = 1 (aCierto). (r es la información del envio de un problema).
        \post Si r vale 1:
                - Se incrementará la variable enviostotales, enviosexito, y se actualizará el ratio del problema con id = id_problema del parámetro implícito.
            Si r vale 0:
                - Se incrementará la variable enviostotales, y se actualizará el ratio del problema con id = id_problema del parámetro implícito.
    */
    void Update (const string& id_problema, int r);
    
    /** @brief Modificadora de envios_totales (y ratio).
        \pre El string id_problema no es vacio.
        \post Busca en el parámetro implícito el problema con id = id_problema y si lo encuentra incrementa los envios totales y el ratio del problema con id = id_problema del parámetro ímplicito.
    */
    void IncreaseTotalSends(const string& id_problema);    //DONE
    
    /** @brief Modificadora de envios_exito (y ratio).
        \pre El string id_problema no es vacio.
        \post Busca en el parámetro implícito el problema con id = id_problema y si lo encuentra incrementaa los envios_exito, los envios_totales y el ratio del problema con id = id_problema del parámetro ímplicito.
    */
    void IncreaseSolvedSends(const string& id_problema);   //DONE
    
    
    
    
    //Lectura y escritura
    
    /** @brief Operación de lectura.
        \pre Hay preparado en el canal estandar de entrada un int = P que es el número de problemas a leer + P strings (identificadores de problemas).
        \post Devuelve el conjunto de problemas con los P problemas con sus respectivos identificadores.
    */
    void AddFromConsole();  //DONE
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida los atributos (envios_totales, envios_exito, ratio) de los problemas del parámetro implícito ordenados crecientemente por ratio y en caso de empate por string id_problema.
    */
    void ListProblemSetByRatio();   //DONE 
    
     /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida los atributos (envios_totales, envios_exito, ratio) de los problemas del parámetro implícito ordenados crecientemente por string id_problema.
    */
    void ListProblemSet();  //DONE
    
    /** @brief Operación de escritura.
        \pre El string id_problema no es vacío.
        \post Si el problema con id = id_problema del parámetro implícito existe, retornará 0 y se escribirá por el canal estandar de salida los atributos (envios_totales, envios_exito, ratio) de este. Retornará -1 en caso contrario.
    */
    int ListProblem(const string& id_problema);    //DONE
    
    void ListUserProblem() const;
    
    
private:
    typedef map<string, Problem> Problem_map_t;
    Problem_map_t problem_map;                        // Array[id del problema=string]
};
#endif
