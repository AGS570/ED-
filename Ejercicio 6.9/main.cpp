
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
template <typename T>
bool resolver(BinTree<T> tree, T min, T max){
     if(tree.empty()){
         return true;
     }

     T rt = tree.root();

     
        
         if(rt <= min || rt >= max){
             return false; 
        }
        return resolver(tree.left(), min, rt) &&
         resolver(tree.right(),rt,max);
     
    
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

// leer los datos de la entrada
char c;
cin >> c;
if (!std::cin)  // fin de la entrada
return false;

bool sol = true;
if(c == 'N'){
    BinTree<int> tree = read_tree<int>(cin);
    if(!tree.empty()){
        
        sol = resolver(tree,numeric_limits<int>::min(),numeric_limits<int>::max());
    }
    
}else{
    BinTree<string> tree = read_tree<string>(cin);
    if(!tree.empty()){
        sol = resolver(tree,string(""), string("~~~~~~~~~"));
    }
}


if(sol){
    cout << "SI" << endl;
}else{
    cout << "NO" << endl;
}
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



