
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
void resolver(const BinTree<int>& tree,int &maxGente, int &p, int &equipos) {

   if(tree.empty()){  
      return;
   };
   
  int gi = 0;
  int gd = 0;
  int pi = 0;
  int pd = 0;
  int equiposI = 0;
  int equiposD = 0;
  
  resolver(tree.left(),gi, pi, equiposI);
  resolver(tree.right(), gd, pd, equiposD);

  int gm = max(gd,gi);
  gm += tree.root();

  if(gm > maxGente)
    maxGente = gm ;
  
  p = 1+min(pi, pd);

  if(equiposI == 0 && equiposD == 0 && tree.root() != 0){
    equipos++;
  }else{
    equipos = equiposI + equiposD;
  }
   
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
BinTree<int> tree = read_tree<int>(cin);
// leer los datos de la entrada
int m =0;
int p = 0; 
int e =0;
resolver(tree, m, p, e);

// escribir solución
cout << e << " "<< m << endl;
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
