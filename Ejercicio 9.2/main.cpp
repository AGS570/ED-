
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include"torre.h"
// Introduce más librerías si son necesarias



// función que resuelve el problema
void posicion(std::string nombre,torre &tower){
    std::pair<int,int> p= tower.posicion(nombre);

    std::cout << p.first << " " << p.second << std::endl;
}

void torre_en_posicion(int x,int y, torre &tower){
    std::pair<bool,std::string> p = tower.torre_en_posicion(x,y);
    if(p.first == true) std::cout<< "SI" << " " << p.second <<std::endl;
    else{std::cout << "NO" << std::endl;}
}

void torre_mas_cercana(torre& tower, std::string nombre, std::string dir){
    Direccion d;
    if(dir == "Norte"){
        d = Direccion::Norte;
    }else  if(dir == "Sur"){
        d = Direccion::Sur;
    }else  if(dir == "Este"){
        d = Direccion::Este;
    }else{
        d = Direccion::Oeste   ;
    }
    std::string p = tower.torre_mas_cercana(nombre,d);
    std::cout << p << std::endl;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    torre tower = torre();
    std::string orden, nombre;
    std::string dir;
    int x,y;
    std::cin >> orden;
    if (!std::cin)  // fin de la entrada
        return false;

while(orden != "FIN"){
try{
    if(orden == "anyadir_torre"){
        std::cin >> nombre >> x>> y;
        tower.anyadir_torre(nombre,x,y);
    }else if(orden == "eliminar_torre"){
        std::cin >>nombre;
        tower.eliminar_torre(nombre);
    }else if(orden == "posicion"){
        std::cin >> nombre;
        posicion(nombre,tower);
    }else if(orden == "torre_en_posicion"){
        std::cin >> x >> y;
        
        torre_en_posicion(x,y,tower);
    }else if(orden == "torre_mas_cercana"){
        std::cin >> nombre >> dir;
        torre_mas_cercana(tower,nombre,dir);
    }
}catch(std::domain_error &e){
    std::cout << e.what() << std::endl;
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