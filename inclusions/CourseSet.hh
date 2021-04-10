/** @file CourseSet.hh
    @brief Especificación de la clase Curso
*/

#ifndef _COURSESET_HH
#define _COURSESET_HH

#include "Course.hh"
#include "SesionSet.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

using namespace std;

/** @class CourseSet
    @brief Representa un conjunto de cursos
*/
class CourseSet
{
public:
    
    //Constructora
    
    /** @brief  Creadora por defecto
        \pre <em>Cierto.</em>.
        \post El resultado es un conjunto de cursos vacío.
    */
    CourseSet();
    
    
    //Consultora
    
    /** @brief Consultora del tamaño del conjunto.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida el tamaño del parámetro implícito.
    */
    int Size() const;   
    
    /** @brief Consultora de curso en CourseSet.
        \pre El int id_curso no es vacío.
        \post Devuelve un booleano conforme si existe el curso con id = id_curso en el parámetro implícito. True si existe y false en caso contrario.
    */
    bool Exist(int id_curso) const;
    
    /** @brief Consultora de problema en curso
        \pre El int id_curso y el string id_problema no són vacíos y el curso con id = id_curso y el problema con id = id_problem existen.
        \post Devuelve un booleano conforme si el problema con id = id_problem existe en el curso con id = id_curso. True si existe y false en caso contrario.
    */
    bool ExistProblem(int id_curso, string id_problema) const;
    
        
    /** @brief Consultora del número de usuarios completados.
        \pre El int id_curso no es vacío.
        \post Busca en el parámetro implícito el curso con id = id_curso y si lo encuentra retorna el número de usuarios que lo han completado.
    */
    int GetNumUsersDone(int id_curso) const;
    
    /** @brief Consultora del número de usuarios inscritos.
        \pre El int id_curso no es vacío.
        \post Busca en el parámetro implícito el curso con id = id_curso y si lo encuentra retorna el número de usuarios inscritos actualmente en este.
    */
    int GetNumUsersIn(int id_curso) const;
    
    /** @brief Consultora de la sesion que contiene el problema id_problema en el curso id_curso en el parámetro implícito.
        \pre El int id_curso y el problema id_problema no són vacíos.
        \post Busca en el parámetro implícito el curso cond id = id_curso y si lo encuentra retorna la sesión en la que se encuentra el problema con id = id_problema en el curso id_curso.
    */
    void GetSesion(int id_curso, string id_problema) const;
    
    
    
    
    //Modificadoras
    
     /** @brief Modificadora del curso.
        \pre El int id_curso no es vacío y el curso con id = id_curso existe en el parámetro implícito.
        \post Se actualizará el curso con id = id_curso del parámetro ímplicito.
    */
    void Update(int id_curso);
    
    /** @brief Añade un curso en el conjunto.
        \pre Hay preparados en el canal estandar de entrada el número de sesiones del curso + los strings de todas las sesiones respectivas al curso. 
        \post Si en el nuevo curso hay intersección de problemas entre sesiones, no se creará el curso. Retornará -1
                Si no hay intersección de problemas entre sesiones, se creará el curso. Dentro del curso rellenaremos el curso_sesion_map, con key id_problema(string), y value id_sesion(string). 
                Después de añadirlo, el identificador del curso será el tamaño del CourseSet. Retornará 0 (Ok)
    */
    int AddOneFromConsole();
    
    /** @brief Modificadora del número de usuarios completados.
        \pre El int id_curso no es vacío y el curso con id = id_curso existe en el parámetro implícito.
        \post Se incrementará el número de usuarios del curso con id = id_curso del parámetro ímplicito con este completado.
    */
    void IncreaseNumUsersDone(int id_curso);
    
    /** @brief Modificadora del número de usuarios inscritos.
        \pre El int id_curso no es vacío y el curso con id = id_curso existe en el parámetro implícito.
        \post Se incrementará el número de usuarios inscritos (actualmente) del curso id = id_curso del parámetro implícito.
    */
    void IncreaseNumUsersIn(int id_curso);
    
    /** @brief Modificadora del número de usuarios inscritos.
        \pre El int id_curso no es vacío y el curso con id = id_curso existe en el parámetro implícito.
        \post Se decrementará el número de usuarios inscritos (actualmente) del curso id = id_curso  del parámetro implícito.
    */
    void DecreaseNumUsersIn(int id_curso);
    
    

        
    //Lectura y escritura
    
    /** @brief Operación de lectura.
        \pre Hay preparado en el canal estandar de entrada un int = N que es el número de cursos a leer + un int Sc que es el número de sesiones del curso + una secuencia de Sc identificadores de secuencias (strings).
        \post Devuelve el conjunto de problemas completado.
    */
    void AddFromConsole();
    
    /** @brief Operación de escritura.
        \pre El parámetro implícito no es vacío.
        \post Se ha escrito por el canal estandar de salida los atributos (num_usuarios_completados, num_usuarios_inscritos, num_sesiones + id_sesiones de estas en el orden que se creó el curso) de los cursos del parámetro implícito.
    */
    void ListCourseSet();
    
    /** @brief Operación de escritura.
        \pre El int id_curso no es vacío.
        \post Si el curso con id = id_curso del parámetro implícito existe, retornará 0 y se escribirá por el canal estandar de salida los atributos (num_usuarios_completados, num_usuarios_inscritos, num_sesiones + id_sesiones de estas en el        
                orden que se creó el curso) de este. Retornará -1 en caso contrario.
    */
    void ListCourse (int id_curso);
    
private:
    vector<Course> Course_vec;
};
#endif
