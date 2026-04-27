
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
void resolver(const vector<int>& inorden, const vector<int>& preorden) {
   BinTree<int> tree = tree.reconstruir(preorden, inorden);
   tree.display(cout);
   cout << endl;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

// leer los datos de la entrada
int num ;
cin >> num;

vector<int> preorden, inorden;
for (int i = 0; i < num; ++i) {
   int elem;
   cin >> elem;
   preorden.push_back(elem);
}
for (int i = 0; i < num; ++i) {
   int elem;
   cin >> elem;
   inorden.push_back(elem);
}
if (!std::cin)  // fin de la entrada
return false;



resolver(inorden, preorden);

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


