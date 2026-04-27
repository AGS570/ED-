// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "list_linked_double.h"
// Introduce más librerías si son necesarias
using namespace std;


void resolver(ListLinkedDouble<int> &list) {
   list.sort_and_dedup();
   list.display();
   cout << endl;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   ListLinkedDouble<int> list;
   int input = 0;

   while(input != -1){
      cin >> input;
      if(input != -1){
         list.push_back(input);
      }
   }
   
   // leer los datos de la entrada
   resolver(list);


   // escribir solución
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
   std::ifstream in("datos.in.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out.txt");
   auto coutbuf = std::cout.rdbuf(out.rdbuf());
   #endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
   resuelveCaso();
   
   // para dejar todo como estaba al principio
   #ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
   #endif
   return 0;
}

// función que resuelve el problema

