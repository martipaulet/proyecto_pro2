/** @file SesionSet.hh
    @brief Especificación de la clase SesionSet
*/

#ifndef _SESIONSET_HH
#define _SESIONSET_HH

#include "Sesion.hh"
#include "ProblemSet.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class SesionSet
    @brief Representa un conjunto de sesiones ordenados por id.
*/
class SesionSet
{
public:
    
    //Constructoras
    
    /** @brief  Creadora por defecto
        \pre <em>Cierto.</em>.
        \post El resultado es un conjunto de sesiones vacío.
    */
    SesionSet();
    
    
    
    //Consultora
    
    /** @brief Consultora del tamaño del conjunto.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida el tamaño del parámetro implícito.
    */
    int Size() const;   
    
    /** @brief Consultora de sesion en SesionSet.
        \pre El string id_sesion no es vacío.
        \post Devuelve un booleano conforme si existe la sesion con id = id_sesion en el parámetro implícito. True si existe y false en caso contrario.
    */
    bool Exist(string id_sesion) const;
    
    /** @brief Consultora del identificador de la sesión.
        \pre El string id_sesion no es vacío.
        \post Busca en el parámetro implícito la sesión con id = id_sesion y si la encuentra retorna el id de esta.
    */
    string GetSesionId(string id_sesion) const;
    
    /** @brief Consultora del número de problemas.
        \pre El string id_sesion no es vacío.
        \post Busca en el parámetro implícito la sesión con id = id_sesion y si la encuentra retorna el número de problemas de esta.
    */
    int GetNumProblems(string id_sesion) const;
    
    /** @brief Consultora del BinTree de la sesión.
        \pre El string id_sesion no es vacío.
        \post Busca en el parámetro implícito la sesión con id = id_sesion y si la encuentra retorna los id de los problemas (siguiendo la estructura en postorden) de esta.
    */
    void GetProblemsId(string id_sesion) const;
    
    
    
    
    //Modificadoras
    
    /** @brief Añade una sesion en el conjunto.
        \pre El string id_sesion  no es vacío y hay preparados en el canal estandar de entrada un número = P de identificadores de problemas + P identificadores (id_problems).
        \post Si el id_sesion ya estaba en el parámetro implícito, pedirá los id_problemas pero no creará el BinTree ya que esta sesión será desechada. Retornará -1.
                si el id_sesion no existia en el parámetro implícito, pedirá los id_problemas para construir el BinTree respectivo. Retornará 0 (OK).
    */
    int AddOneFromConsole(string id_sesion);
    
    
    /** @brief Creadora del BinTree de problemas.
        \pre El string id_sesion no es vacío y la sesión con id = id_sesion existe
        \post El resultado es un BinTree de strings de problemas siguiendo una estructura dada en postorden de la sesion con id = id_sesion.
    */
    void MakeBinTree(string id_sesion);
    

    
    
    //Lectura y escritura
    

    /** @brief Operación de lectura.
        \pre Hay preparado en el canal estandar de entrada un int = Q que es el número de sesiones a leer + Q strings (identificadores de problemas) en una estructura para construir el BinTree de cada sesion.
        \post Devuelve el conjunto de problemas completado.
    */
    void AddFromConsole();
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida los atributos (num_problemas + id de dichos problemas) de las sesiones del parámetro implícito.
    */
    void ListSesionSet();
    
    /** @brief Operación de escritura.
        \pre El string id_sesion no es vacío.
        \post Si la sesión con id = id_sesion del parámetro implícito existe, retornará 0 y se escribirá por el canal estandar de salida los atributos (num_problemas + id de dichos problemas) de esta. Retornará -1 en caso contrario.
    */
    int ListSesion(string id_sesion);
    
    /** @brief Operación de escritura.
        \pre La sesion con id_sesion tiene un BinTree de strings de id_problemas.
        \post Se ha escrito el identificador de los problemas del parámetro implícito siguiendo la estructura de prerequisitos en postorden.
    */
    void PrintBinTree(string id_sesion);
    

private:
    typedef map<string, Sesion> Sesion_map_t;
    Sesion_map_t sesion_map;                            // Array[id de la sesion=string]
};
#endif
