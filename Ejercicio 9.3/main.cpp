
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "CarnetPuntos.h"

// Introduce más librerías si son necesarias

void consultar(CarnetPuntos &carnet, std::string dni){
    int p = carnet.consultar(dni);
    std::cout << "Puntos de " << dni << ": "<< p << std::endl;
}

void cuantos_con_puntos(CarnetPuntos &carnet, int puntos){
    int p = carnet.cuantos_con_puntos(puntos);

    std::cout << "Con " << puntos << " puntos hay " << p << std::endl;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    CarnetPuntos carnet;
    std::string orden, dni;
    int puntos;
    std::cin >> orden;
    if (!std::cin)  // fin de la entrada
        return false;

while(orden != "FIN"){
try{
    if(orden == "nuevo"){
        std::cin >> dni;
        carnet.nuevo(dni);
    }else if(orden == "quitar"){
        std::cin >>dni >> puntos;
        carnet.quitar(dni,puntos);
    }else if(orden == "consultar"){
        std::cin >> dni ;
        consultar(carnet,dni);
       
    }else if(orden == "cuantos_con_puntos"){
        std::cin >> puntos;
        cuantos_con_puntos(carnet,puntos);
    }
}catch(std::domain_error &e){
    std::cout << "ERROR: "<< e.what() << std::endl;
}
std::cin >> orden;
}
// leer los datos de la entrada
std::cout << "---" << std::endl;
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