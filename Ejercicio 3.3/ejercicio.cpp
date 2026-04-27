// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 
#include "list_linked_double.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;
// función que resuelve el problema
void resolver(ListLinkedDouble<int> &list, int pivot) {
   list.partition(pivot);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   ListLinkedDouble<int> list;
   int pivot =1;
   // leer los datos de la entrada
   while (pivot != 0){
    cin >> pivot;
    if(pivot != 0)
    list.push_back(pivot);
   }
   cin >> pivot;
   resolver(list, pivot);
   
   // escribir solución
   list.display();
   cout << endl;
   list.rdisplay();
   cout << endl;
}



int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("datos.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out");
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

