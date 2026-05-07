// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "bintree_V6.h"
// Introduce más librerías si son necesarias
using namespace std;

bool resolver(const BinTree<char>& tree, int &z) {
   
   if(tree.empty()){
      z =0;
      return true;
   }
   
   if(tree.left().empty() && tree.right().empty()){
      z = 1;
      return true;
   }
   

   int izq = 0,der = 0;
   bool l = resolver(tree.left(),izq);
   bool r  = resolver(tree.right(),der);
   z = izq + der + 1;
   if(izq > der && r  && l ){
     return true;
   }
   return false;

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   int n =0,h=0,a=0;
   BinTree<char> tree = read_tree<char>(cin);
   // leer los datos de la entrada

   bool sol = resolver(tree,n);

   // escribir solución
        if(sol){
            cout << "SI" << endl;
        }else{
             cout << "NO" << endl;
        }
}

int main(){
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
