
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
// Introduce más librerías si son necesarias
using namespace std;
// función que resuelve el problema
void resolver(map<string,vector<int>> &relc, int order, string word) {
   if(relc[word].size() < order) {
      cout << "NO JUEGA" << endl;
      return ;
   }else{
      /*for(auto it = relc[word].begin(); it != relc[word].end(); ++it){
         if(order == *it){
            cout << *it << endl;
            return;
         }
      }*/
      cout << relc[word][order-1] << endl;
   }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
map<string,vector<int>> relc;
int lng, questions,in;;
string word;
// leer los datos de la entrada
cin >> lng;
if (!std::cin)  // fin de la entrada
return false;

for(int i =0; i < lng; i++){
   cin >> word;
   relc[word].push_back(i+1) ;
}
cin >> questions;

for(int i =0; i < questions; i++){
   cin >> in;
   cin >> word;
   resolver(relc,in,word);
}
cout << "---" << endl;

// escribir sol

return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
   std::ifstream in("datos.in");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out");
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


