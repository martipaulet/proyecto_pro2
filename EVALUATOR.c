12)
struct problema_t
{
/* Constructor */
problema_t()
: envios_totales(0),
envios_exito(0),
double_ratio(1)
{}

/* Variables */
int envios_totales;
int envios_exito;
double ratio;
};

typedef map<string, problema_t> problema_map_t;
problema_map_t problema_map;											// Array[id del problema=string]

************************************************************************
12) Ordenar por ratio:

typedef map<int, problema_map_t> problema_ratio_map_t;
problema_ratio_map_t problema_ratio_map;


************************************************************************
13)
class BinTree;

struct sesion_t
{
/* Constructor */
sesion_t()
: num_problemas(0)
{}

/* Variables */
int num_problemas;
BinTree<string> Arbol_problemas;		// Postorden
};

typedef map<string, sesion_t> sesion_map_t;
sesion_map_t sesion_map; 												// Array[id de la sesion=string]
						
						

************************************************************************						


8????) typedef map<string, problema_t> problema_map_t;
typedef map<string, problema_map_t> sesion_problema_map_t;

sesion_problema_map_t sesion_problema_map; 								// Array[sesion=STRING][problema=STRING]
				
************************************************************************
14)struct curso_t
{
/* Constructor */
curso_t()
: num_usuarios_completados(0),
num_usuarios_inscritos(0)
{}

/* Variables */
int num_usuarios_completados;
int num_usuarios_inscritos;
list<string> list_sesion;		// Introducir con push_back, no repetidas
};




typedef map<int, curso_t> curso_map_t;
curso_map_t curso_map; 													// Array[id curso=int] -------> Mirar implementar con vector CourseSet


struct curso_problema_dades_t
{
/* Constructor */
curso_problema_dades_t()
: 
{}

/* Variables */
boolean existe;	// comprobar que no se repita
string sesion;
}
//typedef map<string, curso_problema_dades_t> curso_problema_dades_map_t;
typedef map<int, map<string, curso_problema_dades_t> > curso_problema_map_t;
//typedef map<int, curso_problema_dades_map_t> curso_problema_map_t;
curso_problema_map_t curso_problema_map;								            // Array[id curso=int][id de problema=string
************************************************************************
15) struct usuario_t
{
/* Constructor */
usuario_t()
: envios_totales(0),
num_problemas_resueltos(0), 
num_problemas_intentados(0),
curso_inscrito(0)
{}

/* Variables */
int envios_totales;
int num_problemas_resueltos;     --> Dimension ProblemsSolved (no hace falta variable)
int num_problemas_intentados;   
int curso_inscrito;
};


typedef map<string, usuario_t> usuario_map_t;
usuario_map_t usuario_map; 												// Array[usuario=string]

struct usuario_problema_dades_t
{
/* Constructor */
usuario_problema_dades_t()
: resuelto(false),
prerequisitos_hechos(false),
envios_totales(0)
{}

/* Variables */
boolean resuelto;
boolean prerequisitos_hechos; //PROBLEMAS ENVIABLES
int envios_totales;
}
typedef map<string, usuario_problema_dades_t> usuario_problema_dades_map_t;	// string del problema
typedef map<string, usuario_problema_dades_map_t> usuario_problema_map_t;	//string del usuario
usuario_problema_map_t usuario_problema_map;							// Array[usuario=string][id de problema=string]: resuelto o no
																		// Inicializar a false(no resuelto) en el momento de asignar un curso a un usuario

************************************************************************



