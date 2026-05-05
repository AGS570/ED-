// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
// Introduce más librerías si son necesarias
using namespace std;


// función que resuelve el problema



void tolowerCase(string &word){
   for(char &c : word){
      c = tolower(c);
   }
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    int lineas;

    map<string,set<int>> mapa;
    cin  >> lineas;
    cin.ignore();
    string line,word;
    if (lineas ==0)
    return false;
    
    for(int i =0; i < lineas; i++){
      getline(cin,line);
      stringstream ss(line);

      while (ss >> word){
         if(word.length() > 2){
           tolowerCase(word);
            mapa[word].insert(i+1);
         }
      }
    }
    
   for(auto it = mapa.begin(); it != mapa.end();++it){
      cout << it->first ;
      for(auto itin = it->second.begin(); itin != it->second.end(); ++itin){
         cout << " "<< *itin ;
      }
      cout << endl;
   }
   cout << "---"<<endl;
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
