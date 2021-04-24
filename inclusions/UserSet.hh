/** @file UserSet.hh
    @brief Especificación de la clase UserSet
*/

#ifndef _USERSET_HH
#define _USERSET_HH

#include "User.hh"
#include "CourseSet.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class UserSet
    @brief Representa un conjunto de usuario ordenados crecientemente por id.
*/
class UserSet
{
public:
    
    //Constructoras
    
    /** @brief  Creadora por defecto
        \pre <em>Cierto.</em>
        \post El resultado es un conjunto de usuarios vacío.
    */
    UserSet();
    
    
    
    //Consultoras
    
    /** @brief Consultora del tamaño del conjunto.
        \pre <em>Cierto.</em>
        \post Se ha escrito por el canal estandar de salida el tamaño del parámetro implícito.
    */
    int Size()const;    //DONE
     
    /** @brief Consultora de usuario en UserSet.
        \pre El string id_usuario no es vacío.
        \post Devuelve un booleano conforme si existe el usuario con id = id_usuario en el parámetro implícito. True si existe y false en caso contrario.
    */
    bool Exist(string id_usuario)const; //DONE
        
    /** @brief Consultora del curso del usuario.
        \pre El string id_usuario no es vacío y el usuario con id = id_usuario existe en el parámetro implícito.
        \post Busca en el parámetro implícito el usuario con id_usuario y retornará el atributo curso_inscrito.
    */
    int GetCurso(string id_usuario) const;  //DONE
    
    
    
    
    //Modificadoras
    
    /** @brief Añade un usuario en el conjunto.
        \pre El string id_usuario no es vacío.
        \post Si en el parámetro implícito ya existe el usuario con id = id_usuario, no se añadirá el usuario. Retornará -1
                En caso contrario se añadirá el usuario con id = id_usuario al parámetro implícito. Retornará 0.
    */
    int Add(string id_usuario); //DONE
    
    /** @brief Elimina un usuario del conjunto.
        \pre El string id_usuario no es vacío y el usuario con id_usuario existe.
        \post Se eliminará todo lo referente al usuario con id = id_usuario.
    */
    void Delete(string id_usuario); //DONE
    
    /** @brief Actualiza un usuario del conjunto.
        \pre El string id_usuario no es vacío y el usuario con id_usuario existe. 
                El string id_problema no es vacío y el problema con id = id_problema existe para el usuario id = id_usuario y además consta como enviable.
                r ha de valer 1 (catalogar como éxito) o 0 (catalogar como fallo).
        \post   Si r vale 1:
                - Se traspasa el problema con id = id_problema de ReadyToSendProblems a SolvedProblems (conservando los datos de id_problema), teniendo en cuenta que en id_problema se ha de incrementar enviostotales (si 
                envios_totales pasa a       
                    valer 1, se incrementara el num_problemas_intentados) y envios_exito, actualizando el ratio.
                - Se comprobará si todos los problemas de curso_incrito constan como Solved, y en ese caso curso_inscrito se escribirá a 0. (usuarios.Update llamará a cursos.Update con el curso del usuario u antes de poner 
                    curso_inscrito a 0).
                    Se decrementará la variable num_usuarios_inscritos y se incrementará la variable num_usuarios_completados si curso_inscrito=0.
                - Se incrementará la variable enviostotales dentro del usuario id_usuario.
                
        \post   Si r vale 0: 
                - Dentro del problema con id_problema, se ha de incrementar envios_totales (si envios_totales pasa a valer 1, se incrementara el num_problemas_intentados del usuario id_usuario), actualizando el ratio.
                - Se incrementará la variable enviostotales dentro del usuario      
    */
    void Update(string id_usuario, string id_problema, int r);
    
     /** @brief Modificadora de envios_totales.
        \pre El string id_usuario no es vacía y el usuario con id = id_usuario existe en el parámetro implícito.
        \post Se incrementarán los envios_totales del usuario con id = id_usuario del parámetro implícito.
    */
    void IncreaseTotalSends(string id_usuario);
    
     /** @brief Modificadora de número_problemas_resueltos.
        \pre El string id_usuario no es vacía y el usuario con id = id_usuario existe en el parámetro implícito.
        \post Se incrementará el num_problemas_resuletos del usuario con id = id_usuario del parámetro implícito.
    */
    void IncreaseSolvedProblems(string id_usuario);
    
     /** @brief Modificadora del número_problemas_intentados.
        \pre El string id_usuario no es vacía y el usuario con id = id_usuario existe en el parámetro implícito.
        \post Se incrementará el num_problemas_intentados del usuario con id = id_usuario del parámetro implícito.
    */
    void IncreaseTryedProblems(string id_usuario);
    
     /** @brief Modificadora del curso_inscritos.
        \pre El string id_usuario y el int id_curso no son vacíos y el usuario con id = id_usuario existe en el parámetro implícito y el curso con id_curso existe.
        \post Se modificará el curso_inscrito del usuario con id = id_usuario del parámetro implícito.
    */
    void JoinCourse(string id_usuario, int id_curso);   //DONE
    
    void InitializeReadyToSendProblems(string id_usuario, int id_curso, CourseSet& cursos, SesionSet& sesiones);
    
    
    
    //Lectura y escritura

    /** @brief  Operación de lectura
        \pre Hay preparado en el canal estandar de entrada un int = M que es el número de usuarios a leer + M identificadores de los usuarios correspondientes.
        \post Devuelve el conjunto de usuarios completado.
    */
    void AddFromConsole();  //DONE
    
    /** @brief Operación de escritura.
        \pre El parámetro implícito no es vacío.
        \post Se ha escrito por el canal estandar de salida los atributos (envios_totales, num_problemas_resueltos, num_problemas_intentados y curso_inscrito) de los usuarios del parámetro implícito.
    */
    void ListUserSet(); //DONE

    /** @brief Operación de escritura.
        \pre El string id_usuario no es vacío.
        \post Si el usuario con id = id_usuario del parámetro implícito existe, retornará 0 y se escribirá por el canal estandar de salida los atributos (envios_totales, num_problemas_resueltos, num_problemas_intentados y curso_inscrito) de       
                este. Retornará -1 en caso contrario.
    */
    int ListUser(string id_usuario);    //DONE
    
    
    
    /** @brief Operación de escritura.
        \pre El string id_usuario no es vacío y el usuario con id = id_usuario existe.
        \post Mostrará por el canal estandar de salida la lista de problemas resueltos por el usuario con id = id_usuario de la manera id_problema: num_envios_totales.
    */
    void ListSolvedProblems(string id_usuario); //DONE
    
    
    /** @brief Operación de escritura.
        \pre El string id_usuario no es vacío y el usuario con id = id_usuario existe.
        \post Mostrará por el canal estandar de salida la lista de problemas enviables por el usuario con id = id_usuario de la manera id_problema: num_envios_totales.
    */
    void ListReadyToSendProblems(string id_usuario);
    
    
private:
    typedef map<string, User> User_map_t;
    User_map_t user_map;                            // Array[id de la user=string]
};
#endif
