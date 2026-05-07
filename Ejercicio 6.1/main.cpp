// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "bintree_V6.h"
// Introduce más librerías si son necesarias
using namespace std;

void resolver(const BinTree<char>& tree, int &n, int &h, int &a) {
   
   if (tree.empty()) { 
      return;
   }

   if (tree.right().empty() && tree.left().empty()) {
      h++;
   }

   int ai = 0;
   int ad = 0;
   int ni =0;
   int nd =0;
   resolver(tree.right(), ni, h, ad);
   resolver(tree.left(), nd, h, ai);
   a = 1+max(ai, ad);
   n = 1+ ni + nd;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   int n =0,h=0,a=0;
   BinTree<char> tree = read_tree<char>(cin);
   // leer los datos de la entrada

   resolver(tree, n, h, a);

   // escribir solución
   cout << n << " " << h << " " << a << endl;
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
