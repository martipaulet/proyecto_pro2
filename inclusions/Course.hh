/** @file Course.hh
    @brief Especificación de la clase Course
*/

#ifndef _COURSE_HH
#define _COURSE_HH
#include "SesionSet.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#include <iostream>
#endif

using namespace std;

/** @class Course
    @brief Representa un curso con el numero de usuarios con el curso completado, el numero de usuarios inscritos actualmente en el curso y el número de sesiones que lo forman con su identificador (en el orden que se leyeron al introducirlas en el curso).
*/
class Course 
{
public:
    
    //Constructora
    
    /** @brief  Creadora por defecto.
        \pre <em>Cierto.</em>
        \post El resultado es un curso sin id, num_usuarios_inscritos = 0, num_usuarios_completado = 0 y su lista de sesiones.
    */
    Course();   //DONE
    
    
    
    //Consultoras
    
    /** @brief Consultora del número de usuarios completados.
        \pre <em>Cierto.</em>
        \post El resultado es el número de usuarios que han completado el parámetro implícito.
    */
    int GetNumUsersDone() const;    //DONE
    
    /** @brief Consultora del número de usuarios inscritos.
        \pre <em>Cierto.</em>
        \post El resultado es el número de usuarios inscritos (actualmente) en el parámetro implícito.
    */
    int GetNumUsersIn() const;  //DONE
    
    
    /** @brief Consultora de la sesion que contiene el problema id_problema en el parametro implícito.
        \pre El problema id_problema no es vacío.
        \post Devuelve la sesión en la que se encuentra el problema con id = id_problema en el parametro implícito.
    */
    void ProblemSesion(string id_problema);
    
    
    bool ExistProblem(string id_problema) const;
    
    int GetSesionListSize() const;  //DONE
    
    bool Validate(SesionSet& sesiones);
    
    void Read();
    
    
    //Modificadoras
    
    /** @brief Modificadora del número de usuarios completados.
        \pre <em>Cierto.</em>
        \post Se incrementará el número de usuarios con el parámetro ímplicito completado.
    */
    void IncreaseNumUsersDone();    //DONE
    
    /** @brief Modificadora del número de usuarios inscritos.
        \pre <em>Cierto.</em>
        \post Se incrementará el número de usuarios inscritos (actualmente) en el parámetro implícito.
    */
    void IncreaseNumUsersIn();  //DONE
    
    /** @brief Modificadora del número de usuarios inscritos.
        \pre <em>Cierto.</em>
        \post Se decrementará el número de usuarios inscritos (actualmente) en  el parámetro implícito.
    */
    void DecreaseNumUsersIn();  //DONE
        
    void InitializeReadyToSendProblems(SesionSet& sesiones,ProblemSet& problems);

    //Escritura
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se han escrito los atributos (num_usuarios_completados, num_usuarios_inscritos, num_sesiones + id_sesiones de estas en el orden que se creó el curso) del parametro implícito con identificador = id_course en el canal estandar de salida. 
    */
    void PrintCourse(int id_course) const;
    


    
private:
    int num_usuarios_completados;
    int num_usuarios_inscritos;
    list<string> Course_sesion_list;
    
    typedef map<string, string> Course_sesion_map_t;
    Course_sesion_map_t Course_sesion_map;                        // Array[id del problema=string] = id_sesion
    

    /** @brief Constructora de la lista de sesiones en curso.
        \pre <em>Existe la sesion con id = id_sesion.</em>
        \post Se añade la sesion con id = id_sesion en la lista Course_sesion_list del parametro implícito. 
    */
    void InsertOnList(string id_sesion);    //DONE
    
    /** @brief Constructora del mapa Course_sesion_map del curso.
        \pre <em>Existe la sesion ses.</em>
        \post Se añade al mapa los problemas como key de la sesion ses (valor). 
    */
    bool InsertOnMap(string id_sesion, SesionSet& sesiones, bool& valido);
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se han escrito los strings de la lista Course_sesion_list del parametro implícito en el canal estandar de salida. 
    */
    static void PrintCourseSesionList(const list<string>& Course_sesion_list); //DONE
    

};
#endif
