// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "autoescuela.h"
// Introduce más librerías si son necesarias
using namespace std;

void puntuacion(autoescuela &au,string A){
    int a = au.puntuacion(A);
    cout << "Puntuacion de " << A << ": " << a <<endl;
    return;
}
void examen(autoescuela &au, string P, int N){
    
    vector<string> v = au.examen(P, N);
    cout <<  "Alumnos de " << P << " a examen: "<< std::endl;
    for(int i =0; i < v.size(); i++){
        cout << v[i] << std::endl;
    }
    
    return ;
}

void es_alumno(autoescuela &au, string A, string P){
    if(au.es_alumno(A,P)) std::cout << A << " es alumno de " << P << std::endl;
    else cout << A << " no es alumno de " << P << std::endl;    
}
// función que resuelve el problema



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
autoescuela au = autoescuela();
string orden, alumno,profe;
int punt;
cin >> orden;
if (!std::cin)  // fin de la entrada
return false;

while(orden != "FIN"){
try{
    if(orden == "alta"){
        cin >> alumno >> profe;
        au.alta(alumno, profe);
    }else if(orden == "es_alumno"){
        cin >> alumno >> profe;
        es_alumno(au,alumno, profe);
    }else if(orden == "examen"){
        cin >> profe >> punt;
        examen(au,profe,punt);
    }else if(orden == "puntuacion"){
        cin >> alumno;
        puntuacion(au,alumno);
    }else if(orden == "aprobar"){
        cin >> alumno;
        au.aprobar(alumno);
    }else if (orden =="actualizar"){
        cin >> alumno >> punt;
        au.actualizar(alumno,punt);
    }
}catch(domain_error &e){
    cout << "ERROR" << endl;
}
cin >> orden;
}
// leer los datos de la entrada
cout << "---" << endl;
// escribir sol

return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
   std::ifstream in("datos.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out");
   auto coutbuf = std::cout.rdbuf(out.rdbuf());
   #endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
   #ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
   #endif
   return 0;
}



