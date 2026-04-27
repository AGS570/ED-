// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 
#include <bits/stdc++.h>
#include "list_linked_double.h"
#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;

// función que resuelve el problema
ListLinkedDouble<int> resolver(ListLinkedDouble<int> list) {
   list.CortaMenores();
   return list;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
// leer los datos de la entrada
int n,a;
ListLinkedDouble<int> list;
cin >> n;
if (n ==0)
return false;

for(int i=0; i < n;i++){
   cin >> a;
   list.push_back(a);
}
ListLinkedDouble<int> sol = resolver(list);
sol.display();
// escribir sol

return true;
}




int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("datos.in.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out.txt");
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
