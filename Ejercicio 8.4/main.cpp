// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
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

void resuelveCaso() {
    
    map<string,string> first,sec;
    set<string>mas,menos,cambio;
    deque<string> cola;
    string input, word,c,valor;
    
    getline(cin, input);
    stringstream ss(input);

    while(ss >> word){
        cola.push_back(word);
        if(cola.size() >= 2){
            first[cola.front()] = cola.back();
            cola.clear();
        }
    }



    getline(cin, input);
    stringstream s2s(input);
    cola.clear();
    while(s2s >> word){
        cola.push_back(word);
            if(cola.size() >= 2){
                sec[cola.front()] = cola.back();
                cola.clear();
            }
    }

   for(auto it = sec.begin(); it != sec.end(); ++it){
        if(first.count(it->first)== 0) mas.insert(it->first);
        else if(first.count(it->first)== 1 && first[it->first]!= it->second)
            cambio.insert(it->first);
   }

   for(auto it = first.begin(); it != first.end(); ++it){
    if(sec.count(it->first)== 0) menos.insert(it->first);
   }


    if(mas.empty() && menos.empty() && cambio.empty()){
        cout << "Sin cambios" << endl;
    }else{

        if(!mas.empty()){
            
        cout << "+" ;
        for(auto it = mas.begin(); it != mas.end(); ++it){
            cout << " " << *it;
        }
        cout << endl;
    }
    if(!menos.empty()){
        cout << "-" ;
        for(auto it = menos.begin(); it != menos.end(); ++it){
            cout << " " << *it;
        }
        cout << endl;
    }
    if(!cambio.empty()){
        cout << "*" ;
        for(auto it = cambio.begin(); it != cambio.end(); ++it){
            cout << " " << *it;
        }
        cout << endl;
    }
    }
    cout << "---" << endl;
    
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
   cin.ignore();
   for (int i = 0; i < numCasos; ++i)
   resuelveCaso();
   
   // para dejar todo como estaba al principio
   #ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
   #endif
   return 0;
}
