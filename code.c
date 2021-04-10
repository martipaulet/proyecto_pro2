
---------------------INICIALIZACIONES------------------------------------------------------------------------------------------------------------------

// Leer número de problemas (int= P) + leer P strings (identificadores de problemas)
    problemas.AddFromConsole();
        int num_problemas;
        cin >> num_problemas;
        for (int i = 0; i < num_problemas; i++) {
            string p;
            cin >> p;
            problemas.Add(p);
    }
    
// Leer número de sesiones (int= Q) + leer Q strings (identificadores de sesiones) + leer problemas para construir BinTree de cada sesión
    sesiones.AddFromConsole(); 
    
// Leer número de cursos (int=N) + leer número de sesiones (int= Sc) de cada curso + leer Sc strings (identificadores de sesion)
    cursos.AddFromConsole();

// Leer número de usuarios (int= M) + leer M strings (identificadores de usuarios)
    usuarios.AddFromConsole();
---------------------------PROBLEMA----------------------------------------------------------------------------------------------------------------------------- 
        
    void UpdateEnviosTotales(string id_problema) {
        problem_map[id_problema].UpdateEnviosTotales();
    }                             
        
    void UpdateEnviosTotales() {
        ++envios_totales;
        int t = envios_totales;
        int e = envios_exito;
        ratio = (t+1)/(e+1);
    }

------------------------------------------------------------------------------------------------------------------------------------------------------------------

    
    
    
    
    
    
    
    
    
    
    
    void UpdateEnviosExito() {
        ++envios_totales;
        ++envios_exito;
        int t = Problem.GetEnviosTotales;
        int e = Problem.GetEnviosExito;
        Problem.ratio = (t+1)/(e+1)
    }
    

---------------------------------------------------------------------------------------------------------------------------------------------------------
// Pedir identificadores de problemas para construir el BinTree en postorden
// Le paso el string para obtener el objeto Sesion interno
    sesiones.MakeBinTree(s);
