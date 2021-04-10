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
    @brief Representa un problema con atributos identificador = id, envios totales = t , envios exito = e y ratio = r = (t+1)/(e+1).
*/

class Problem
{
    
public:
    //Constructoras
    
    /** @brief  Creadora por defecto.
        \pre El string id_problema no es vacío.
        \post El resultado es un problema con id = id_problema, envios totales = 0 , envios exito = 0 y ratio = 1.
    */
    Problem(string id_problema);
    
    
    
    //Consultoras
    
    /** @brief Consultora del identificador del problema.
        \pre <em>Cierto.</em>
        \post El resultado es el identificador del parámetro implícito.
    */
    string GetProblemId() const;
    
    /** @brief Consultora de los envios totales.
        \pre <em>Cierto.</em>
        \post El resultado son los envios_totales del parámetro implícito.
    */
    int GetEnviosTotales() const;
    
    /** @brief Consultora de los envios exito.
        \pre <em>Cierto.</em>
        \post El resultado son los envios_exito del parámetro implícito.
    */
    int GetEnviosExito() const;
    
    /** @brief Consultora del ratio.
        \pre <em>Cierto.</em>
        \post El resultado es el ratio del parámetro implícito.
    */
    double GetRatio() const;
    
    
    
    //Modificadora
    
    /** @brief Modificadora de envios_totales (y ratio).
        \pre <em>Cierto.</em>
        \post Se incrementan los envios totales y el ratio del parámetro ímplicito.
    */
    void IncreaseTotalSends();
    
    /** @brief Modificadora de envios_exito (y ratio).
        \pre <em>Cierto.</em>
        \post Se incrementan los envios_exito, los envios_totales y el ratio del parámetro ímplicito.
    */
    void IncreaseSolvedSends();
    
    
    
    //Escritura
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se han escrito los atributos (envios_totales, envios_exito, ratio) del parametro implícito en el canal estandar de salida.
    */
    void PrintProblem() const;
    
    
private:
    string id;
    int envios_totales;
    int envios_exito;
    double ratio;
};
#endif
