/** @file Problem.hh
    @brief Especificación de la clase Problem
*/

#ifndef _PROBLEM_HH
#define _PROBLEM_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @class Problem
    @brief Representa un problema con atributos identificador, envios totales = t , envios exito = e y ratio = (t+1)/(e+1).
*/

class Problem
{
    
public:
    
    //Constructoras
    
    /** @brief  Creadora por defecto.
        \pre El string id_problema no es vacío.
        \post El resultado es un problema nuevo con identificador = id_problema.
    */
    Problem(const string id_problema); //DONE
    
    
    
    //Consultoras
    
    /** @brief Consultora del identificador del problema.
        \pre <em>Cierto.</em>
        \post El resultado es el identificador del parámetro implícito.
    */
    string GetProblemId() const;  //DONE
    
    /** @brief Consultora de los envios totales.
        \pre <em>Cierto.</em>
        \post El resultado son los envios totales realizados al parámetro implícito.
    */
    int GetEnviosTotales() const;  //DONE
    
    /** @brief Consultora de los envios exito.
        \pre <em>Cierto.</em>
        \post El resultado son los envios con éxito realizados al parámetro implícito.
    */
    int GetEnviosExito() const;  //DONE
    
    /** @brief Consultora del ratio.
        \pre <em>Cierto.</em>
        \post El resultado es el ratio del parámetro implícito. Este viene dado segun los envios totales realizados y los envios con exito realizados al parámetro implícito.
    */
    double GetRatio() const;    //DONE
    
    
    
    //Modificadora
    
    /** @brief Modificadora de los envios totales realizados, y por tanto del ratio, del parámetro implícito.
        \pre <em>Cierto.</em>
        \post Se incrementan los envios totales (en una unidad) y el ratio del parámetro ímplicito.
    */
    void IncreaseTotalSends();  //DONE
    
    /** @brief Modificadora de los envios realizados con éxito, y por tanto del ratio, del parámetro implícito.
        \pre <em>Cierto.</em>
        \post Se incrementan los envios con éxito (en una unidad), los envios totales (en una unidad) y el ratio del parámetro ímplicito.
    */
    void IncreaseSolvedSends(); //DONE
    
    
    
    //Escritura
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida el identificador, los envios totales realizados, los envios con éxito realizados y el ratio del parámetro implícito. 
    */
    void PrintProblem() const;  //DONE
    
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se ha escrito el identificador y los envios totales realizados al parametro implícito en el canal estandar de salida.
    */
    void PrintUserProblem() const;  //DONE
    
    
private:
    string id;
    int envios_totales;
    int envios_exito;
    double ratio;
};
#endif
