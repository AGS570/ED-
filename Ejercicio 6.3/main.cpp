
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "bintree_V6.h"
// Introduce más librerías si son necesarias
using namespace std;



// función que resuelve el problema
void resolver(const BinTree<char>& tree, int &m, int &p) {

   if(tree.empty()){
      
      return;
   }else p++;;
   
   int ai = 0;
   int ad = 0;
   int pi = 0;
   int pd = 0;
   
   resolver(tree.right(), ad, pd);
   resolver(tree.left(), ai, pi);

   p = 1+max(pi, pd);
   int mx  = 1 + pi + pd;
   m = max(mx, max(ai, ad));
   
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
BinTree<char> tree = read_tree<char>(cin);
// leer los datos de la entrada
int m =0;
int p = 0;  
resolver(tree, m, p);

// escribir solución
cout << m << endl;
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
