/**
 *  @mainpage Programa usando diseño modular: "Evaluator".
 *  En esta práctica se evalua tanto la especificación como la implementación de una plataforma llamada <em>Evaluator</em> que ofrece un menú de comandos que permiten evaluar ejercicios de programación.
 *  En esta práctica se introducen las clases <em>UserSet</em>, <em>User</em>, <em>CourseSet</em>, <em>Course</em>, <em>SesionSet</em>, <em>Sesion</em>, <em>ProblemSet</em> y <em>Problem</em>
 * 
 * 
 */

/** @file main.cc
    @brief Programa principal EVALUATOR: plataforma de gestión de problemas y cursos de programación.
*/

#ifndef NO_DIAGRAM
#include <iostream>
#endif


//#include "ProblemSet.hh"
//#include "SesionSet.hh"
//#include "CourseSet.hh"
#include "UserSet.hh"

using namespace std;


#define NUEVO_PROBLEMA      1
#define NUEVA_SESION        2
#define NUEVO_CURSO         3
#define ALTA_USUARIO        4
#define BAJA_USUARIO        5
#define INSCRIBIR_CURSO     6
#define CURSO_USUARIO       7
#define SESION_PROBLEMA     8
#define PROBLEMAS_RESUELTOS 9
#define PROBLEMAS_ENVIABLES 10
#define ENVIO               11
#define LISTAR_PROBLEMAS    12
#define ESCRIBIR_PROBLEMA   13
#define LISTAR_SESIONES     14
#define ESCRIBIR_SESION     15
#define LISTAR_CURSOS       16
#define ESCRIBIR_CURSO      17
#define LISTAR_USUARIOS     18
#define ESCRIBIR_USUARIO    19
#define FIN                 20

int main() {
    
    //INICIALIZAR MAP DE COMANDOS
    map<string, int> comandos;
    comandos["nuevo_problema"]      = NUEVO_PROBLEMA;
    comandos["np"]                  = NUEVO_PROBLEMA;
    comandos["nueva_sesion"]        = NUEVA_SESION;
    comandos["ns"]                  = NUEVA_SESION;
    comandos["nuevo_curso"]         = NUEVO_CURSO;
    comandos["nc"]                  = NUEVO_CURSO;
    comandos["alta_usuario"]        = ALTA_USUARIO;
    comandos["a"]                   = ALTA_USUARIO;
    comandos["baja_usuario"]        = BAJA_USUARIO;
    comandos["b"]                   = BAJA_USUARIO;
    comandos["inscribir_curso"]     = INSCRIBIR_CURSO;
    comandos["i"]                   = INSCRIBIR_CURSO;
    comandos["curso_usuario"]       = CURSO_USUARIO;
    comandos["cu"]                  = CURSO_USUARIO;
    comandos["sesion_problema"]     = SESION_PROBLEMA;
    comandos["sp"]                  = SESION_PROBLEMA;
    comandos["problemas_resueltos"] = PROBLEMAS_RESUELTOS;
    comandos["pr"]                  = PROBLEMAS_RESUELTOS;
    comandos["problemas_enviables"] = PROBLEMAS_ENVIABLES;
    comandos["pe"]                  = PROBLEMAS_ENVIABLES;
    comandos["envio"]               = ENVIO;
    comandos["e"]                   = ENVIO;
    comandos["listar_problemas"]    = LISTAR_PROBLEMAS;
    comandos["lp"]                  = LISTAR_PROBLEMAS;
    comandos["escribir_problema"]   = ESCRIBIR_PROBLEMA;
    comandos["ep"]                  = ESCRIBIR_PROBLEMA;
    comandos["listar_sesiones"]     = LISTAR_SESIONES;
    comandos["ls"]                  = LISTAR_SESIONES;
    comandos["escribir_sesion"]     = ESCRIBIR_SESION;
    comandos["es"]                  = ESCRIBIR_SESION;
    comandos["listar_cursos"]       = LISTAR_CURSOS;
    comandos["lc"]                  = LISTAR_CURSOS;
    comandos["escribir_curso"]      = ESCRIBIR_CURSO;
    comandos["ec"]                  = ESCRIBIR_CURSO;
    comandos["listar_usuarios"]     = LISTAR_USUARIOS;
    comandos["lu"]                  = LISTAR_USUARIOS;
    comandos["escribir_usuario"]    = ESCRIBIR_USUARIO;
    comandos["eu"]                  = ESCRIBIR_USUARIO;
    comandos["fin"]                 = FIN ;

    //INICIALIZAR OBJETOS
    ProblemSet  problemas;
    problemas.AddFromConsole();
    
    SesionSet sesiones;
    sesiones.AddFromConsole();
    
    CourseSet   cursos;
    cursos.AddFromConsole(sesiones);
    
    UserSet     usuarios;    
    usuarios.AddFromConsole();

    
    //VARIABLES AUXILIARES
    string comando;
    bool pedir_comando = true;
    string p,s,u;
    int c;
    
    //SWITCH CASE (main body)
    while (pedir_comando) {
        cin >> comando;
        if (comandos.find(comando) != comandos.end()) {
            // Comando válido
            switch (comandos[comando]) {
                
                case NUEVO_PROBLEMA:   
                    cin >> p;
                    cout << "#" << comando << " " << p << endl; 
                    if (problemas.Add(p) == -1)
                        cout << "error: el problema ya existe" << endl;
                    else 
                        cout << problemas.Size() <<  endl;                   
                    break;
                    
                case NUEVA_SESION:
                    cin >> s;
                    cout << "#" << comando << " " <<  s << endl;
                    if (sesiones.AddOneFromConsole(s) == -1) 
                        cout << "error: la sesion ya existe" << endl;
                    else   
                        cout << sesiones.Size() << endl;
                    break;
                
                case NUEVO_CURSO:
                    cout << "#" << comando << endl;
                    if (cursos.AddOneFromConsole(sesiones) == -1)
                        // AddOneFromConsole pedirá el número de sesiones del curso, y posteriormente pedirá los strings de todas las sesiones. 
                        // - Si en el nuevo curso hay intersección de problemas entre sesiones, no se creará el curso. Retornará -1
                        // - Si no hay intersección de problemas entre sesiones, se creará el curso. Dentro del curso rellenaremos el curso_sesion_map, con key id_problema(string), y value id_sesion(string). 
                        //      Después de añadirlo, el identificador del curso será cursos.Size(). Retornará 0 (Ok)
                        cout << "error: curso mal formado" << endl;
                    else   
                        cout << cursos.Size() << endl;
                    break;   
                    
                case ALTA_USUARIO:
                    cin >> u;
                    cout << "#" << comando << " " << u << endl;
                    if (usuarios.Add(u) == -1)
                        cout << "error: el usuario ya existe" << endl;
                    else 
                        cout << usuarios.Size() << endl; 
                    break;
                    
                    
                case BAJA_USUARIO:
                    cin >> u;
                    cout << "#" << comando << " " << u << endl;
                    if (not usuarios.Exist(u))
                         cout << "error: el usuario no existe" << endl;
                    else {
                        int i = usuarios.GetCurso(u);
                        usuarios.Delete(u);
                        if (i != 0) {
                            cursos.DecreaseNumUsersIn(i);
                        }
                        cout << usuarios.Size() << endl; 
                    }
                    break;
                    
                case INSCRIBIR_CURSO:
                    cin >> u >> c;
                    cout << "#" << comando << " " << u << " " << c << endl;
                    if (not usuarios.Exist(u)) {
                        cout << "error: el usuario no existe" << endl;
                    }
                    else if (not cursos.Exist(c)) {
                        cout << "error: el curso no existe" << endl;
                    }
                    else if  (usuarios.GetCurso(u) != 0) {
                        cout << "error: usuario inscrito en otro curso"<< endl;
                    }
                    else {
                        usuarios.JoinCourse(u, c, cursos, sesiones);
                    }
                    break;
                    
                    
                case CURSO_USUARIO:
                    cin >> u;
                    cout << "#" << comando << " " <<  u << endl;
                    if (not usuarios.Exist(u))
                        cout << "error: el usuario no existe" << endl;
                    else 
                        cout << usuarios.GetCurso(u) << endl;
                    break;
                    
                    
                case SESION_PROBLEMA:
                    cin >> c >> p;
                    cout << "#" << comando << " " <<  c << " " << p << endl;
                    if (not cursos.Exist(c)) { 
                        cout << "error: el curso no existe" << endl;
                    }
                    else if (not problemas.Exist(p)) {
                        cout << "error: el problema no existe" << endl;
                    }
                    else if (not cursos.ExistProblem(c,p)) {
                        cout << "error: el problema no pertenece al curso" << endl;
                    }
                    else {
                        cursos.ProblemSesion(c,p);
                    }
                    break;
                    
                    
                case PROBLEMAS_RESUELTOS:
                    cin >> u;
                    cout << "#" << comando << " " << u << endl;
                    if (not usuarios.Exist(u))
                        cout << "error: el usuario no existe" << endl;
                    else {
                        // La clase User contendrá un ProblemSet con únicamente los problemas resueltos (ProblemSet SolvedProblems)
                        // Imprimirá la lista de problemas resueltos por el usuario de la forma id_problema:número de envios totales
                        usuarios.ListSolvedProblems(u);
                    }
                    break;
                
                    
                case PROBLEMAS_ENVIABLES: 
                    cin >> u;
                    cout << "#" << comando << " " << u << endl;
                    if (not usuarios.Exist(u))
                        cout << "error: el usuario no existe" << endl;
                    else if (usuarios.GetCurso(u) == 0) {
                        cout << "error: usuario no inscrito en ningun curso" << endl;
                    }
                    else {
                        // La clase User contendrá un ProblemSet con únicamente los problemas enviables (ProblemSet ReadyToSendProblems)
                        // Imprimirá la lista de problemas enviables por el usuario de la forma id_problema:número de envios totales
                        usuarios.ListReadyToSendProblems(u);
                    }
                    break;
                
                    
                case ENVIO:
                    int r;
                    cin >> u >> p >> r;
                    cout << "#" << comando << " " << u << " " << p << " " << r << endl;
                    // r valdrá 1 si el problema se ha resuelto (éxito) o 0 en caso contrario (fallo)
                    // usuarios.Update: El usuario u ha de estar definido. El problema p ha de estar definido para el usuario u y ha de constar como enviable. 
                    // Si r vale 1: 
                    //  - Estadisticas User: Se traspasará p de ReadyToSendProblems a SolvedProblems(se han de conservar los datos de p), teniendo en cuenta que en p se ha de incrementar enviostotales (si envios_totales pasa a valer 1, se 
                    //     incrementara el num_problemas_intentados) y envios_exito, actualizando el ratio.
                    //     Se comprobará si todos los problemas de curso_incrito constan como Solved, y en ese caso curso_inscrito se escribirá a 0. 
                    //     usuarios.Update llamará a cursos.Update con el curso del usuario u antes de poner curso_inscrito a 0.
                    //     Se incrementará la variable enviostotales dentro del usuario
                    //  - Estadísticas Problem: Se incrementará la variable enviostotales, enviosexito, y se actualizará el ratio.
                    //  - Estadísticas curso: Se decrementará la variable num_usuarios_inscritos y se incrementará la variable num_usuarios_completados si curso_inscrito=0.
                    
                    // Si r vale 0: 
                    //  - Estadisticas User: Dentro de p, se ha de incrementar envios_totales (si envios_totales pasa a valer 1, se incrementara el num_problemas_intentados), actualizando el ratio.
                    //     Se incrementará la variable enviostotales dentro del usuario                    
                    //  - Estadísticas Problem: Se incrementará la variable enviostotales, y se actualizará el ratio.
          
                    usuarios.Update(u, p, r, problemas, sesiones, cursos);
                    break;
                
                    
                case LISTAR_PROBLEMAS:
                    cout << "#" << comando << endl;
                    problemas.ListProblemSetByRatio();
                    break;
                    
                    
                case ESCRIBIR_PROBLEMA:
                    cin >> p;
                    cout << "#" << comando << " " << p << endl;
                    if (problemas.ListProblem(p) == -1)
                        cout << "error: el problema no existe" << endl;                   
                    break;
                    
                    
                case LISTAR_SESIONES:
                    cout << "#"  << comando << endl;
                    sesiones.ListSesionSet();
                    break;
                    
                    
                case ESCRIBIR_SESION:
                    cin >> s;
                    cout << "#" << comando << " " << s << endl;
                    if (sesiones.ListSesion(s) == -1)
                        cout << "error: la sesion no existe" << endl;                      
                    break;
                    
                case LISTAR_CURSOS:
                    cout << "#" << comando <<endl;
                    cursos.ListCourseSet();
                    break;
                    
                    
                case ESCRIBIR_CURSO:
                    cin >> c;
                    cout << "#" << comando << " " << c << endl;
                    if(cursos.ListCourse(c) == -1)
                        cout << "error: el curso no existe" << endl;                   
                    break;
                    
                                    
                case LISTAR_USUARIOS:
                    cout << "#" << comando <<endl;
                    usuarios.ListUserSet();
                    break;
                    
                    
                case ESCRIBIR_USUARIO:
                    cin >> u;
                    cout << "#" << comando << " " << u << endl;
                    if (usuarios.ListUser(u) == -1)
                        cout << "error: el usuario no existe" << endl; 
                    break;
                    
                    
                case FIN:
                    pedir_comando = false;
                    break;
                    
                    
                    
            }
        }
    }
}
