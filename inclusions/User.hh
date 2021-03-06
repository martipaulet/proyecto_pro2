/** @file User.hh
    @brief Especificación de la clase User
*/

#ifndef _USER_HH
#define _USER_HH


#include "CourseSet.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class User
    @brief Representa un usuario con el numero de envios_totales que ha realizado, el número de problemas resueltos, el número de problemas intentados en total, el curso en el qual está inscrito (si lo está) y dos ProblemSet con los problemas_resueltos y los problemas_enviables respectivamente.
*/
class User
{
public:
    
    
    //Constructora
    
    /** @brief  Creadora por defecto.
        \pre <em>El string id_user no es vacío.</em>
        \post El resultado es un usuario con id = id_user, con envios_totales = 0, num_problemas_intentados = 0 y curso_inscrito = 0. Los ProblemSet ProblemsSolved y ProblemsReadyToSend estarán vacíos. 
    */
    User(const string id_user);
    
    
    
    //Consultora
    
    
    /** @brief Consultora del curso del usuario.
        \pre <em>Cierto.</em>
        \post Retornará el atributo curso_inscrito del parametro implícito.
    */
    int GetCurso() const;   //DONE
    
    /** @brief Consultora d envios_totales del usuario.
        \pre <em>Cierto.</em>
        \post Retornará el atributo envios_totales del parametro implícito.
    */
    int GetTotalSends() const;
    
    /** @brief Consultora de num_problemas_intentados del usuario.
        \pre <em>Cierto.</em>
        \post Retornará el atributo num_problemas_intentados del parametro implícito.
    */
    int GetTryedProblems() const;
    
    /** @brief Consultora de num_problemas_resueltos del usuario.
        \pre <em>Cierto.</em>
        \post Retornará el atributo num_problemas_resueltos del parametro implícito.
    */
    int GetSolvedProblems() const;
    
    
    
    
    //Modificadora 
    
     /** @brief Modificadora de envios_totales.
        \pre <em>Cierto.</em>
        \post Se incrementarán los envios_totales  del parámetro implícito.
    */
    void IncreasetotalSends();
    
     /** @brief Modificadora de número_problemas_resueltos.
        \pre <em>Cierto.</em>
        \post Se incrementará el número_problemas_resueltos del parámetro implícito.
    */
    void IncreaseSolvedProblems();
    
     /** @brief Modificadora del número_problemas_intentados.
        \pre <em>Cierto.</em>
        \post Se incrementará el número_problemas_intentados del parámetro implícito.
    */
    void IncreaseTryedProblems();
    
     /** @brief Modificadora del curso_inscritos.
        \pre <em>Cierto.</em>
        \post Se modificará el curso_inscrito del parámetro implícito.
    */
    void JoinCourse(int id_course, CourseSet& cursos, SesionSet& sesiones); //DONE
    

    void InitializeReadyToSendProblems(int id_course, CourseSet& cursos, SesionSet& sesiones);
    
    //void UpdateReadyToSendProblems(int id_course, CourseSet& cursos, SesionSet& sesiones, string id_problema);
    
    
    void Update (const string& id_problem, int r, ProblemSet& problemas, SesionSet& sesiones, CourseSet& cursos);
    
    
    //Escritura
    
    /** @brief Operación de escritura.
        \pre <em>Cierto.</em>
        \post Se han escrito los atributos (envios_totales, num_problemas_resueltos, num_problemas_intentados y curso_inscrito) del parametro implícito en el canal estandar de salida.
    */
    void PrintUser() const;
    
    void ListSolvedProblems(); //DONE
    
    void ListReadyToSendProblems(); //DONE
    
private:
    string id;
    int envios_totales;
    int num_problemas_resueltos;
    int num_problemas_intentados;   
    int curso_inscrito;
    
    ProblemSet ProblemsSolved;          //únicamente los problemas resueltos (ProblemSet SolvedProblems)
    ProblemSet ProblemsReadyToSend;     //únicamente los problemas enviables (ProblemSet ReadyToSendProblems)
};
#endif
