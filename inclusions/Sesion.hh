/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH
#define _SESION_HH

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
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
        \post El resultado es una sesion con id = id_sesion, num_problemas = 0 y un BinTree de strings (de id_problemas) vacío. 
    */
    Sesion(string id_sesion);
    
    
    
    //Modificadora
    
    /** @brief Crea el BinTree de problemas
        \pre <em>Cierto.</em>
        \post El resultado es un BinTree de strings de problemas siguiendo una estructura dada en postorden del parámetro implícito.
    */
    void MakeBinTree();
    
    
    
    
    //Consultoras
    
    /** @brief Consultora del identificador de la sesión.
        \pre <em>Cierto.</em>
        \post El resultado es el identificador del parámetro implícito.
    */
    string GetSesionId() const;
    
    
    /** @brief Consultora del número de problemas.
        \pre <em>Cierto.</em>
        \post El resultado es el número de problemas del parámetro implícito.
    */
    int GetNumProblems() const;
    
    
    /** @brief Consultora del BinTree de la sesión.
        \pre <em>Cierto.</em>
        \post El resultado són los identificadores de los problemas que forman el BinTree, siguiendo la estructura en postorden, del parámetro implícito.
    */
    void GetProblemsId() const;
    
    
    
    
    //Escritura
    
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se han escrito los atributos (num_problemas + id de dichos problemas) del parametro implícito en el canal estandar de salida.
    */
    void PrintSesion() const;
    
    
private:
    string id;
    int num_problemas;
    BinTree<string> BinTree_problemas;      // Leer en Postorden
};
#endif
