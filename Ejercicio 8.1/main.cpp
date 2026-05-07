// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <set>
#include <map>
// Introduce más librerías si son necesarias
using namespace std;


// función que resuelve el problema

bool resolver(map<string,set<int>> &jugadores,map<int,set<string>>&afectan, set<string> &ganadores, int num) {
    string nombre;
    if(afectan.count(num) == 1){
        for(auto it = afectan[num].begin(); it != afectan[num].end(); ++it){
            jugadores[*it].erase(num);
            if(jugadores[*it].size()==0){
                ganadores.insert(*it);
            }
        }
        if(!ganadores.empty()) return true;
    }
    return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    int casos;   
    string  nombre;
    int num;
    set<int> nums,njug;
    set<string>ganadores;
    map<string,set<int>> jugadores;
    map<int,set<string>>afectan;
    // leer los datos de la entrada
    cin  >> casos;
    if (casos ==0)
    return false;
    
    for(int i=0; i < casos; i++){
        cin >> nombre;
        cin >>num;
        njug.clear(); 
        while(num!=0){
            if(num != 0){
               
                njug.insert(num);
                afectan[num].insert(nombre);
            }
            cin >> num;
        }
        jugadores[nombre]=njug;
    }

    bool fin= false;

    while (!fin){
        cin >> num;
        fin = resolver(jugadores,afectan,ganadores,num);
    }


    // escribir sol
    for(auto it = ganadores.begin(); it != ganadores.end();++it){
        cout << *it << " ";
    }
    cout << endl;
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
