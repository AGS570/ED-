
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "set_tree.h"
// Introduce más librerías si son necesarias
using namespace std;


int  resolver(SetTree<int> &tree, int l, int h) {
 return  tree.count_interval(l,h);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
SetTree<int> tree;
int n, m, input,h,l,sol ;

// leer los datos de la entrada
cin >> n >> m;
if (!std::cin)  // fin de la entrada
return false;

for(int i =0; i < n; i++){
   cin >> input;  
   tree.insert(input);
}

for(int i =0; i < m; i++){
   cin >> l >> h;
   sol = resolver(tree, l,h);

   cout << sol << endl;
}


// escribir sol
cout << "---"<< endl;
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

// función que resuelve el problema
