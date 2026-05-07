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

//bool resolver(map<string,set<int>> &jugadores,map<int,set<string>>&afectan, set<string> &ganadores, int num) {
   


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    int ejs;
    string nombre,result;
    int nota;
    map<string,int> mapa;
    cin  >> ejs;
    if (ejs ==0)
    return false;
    
    cin.ignore();
    for(int i=0; i < ejs; i++){
        getline(cin,nombre);
        cin >>result;
        cin.ignore();
        if(mapa.count(nombre) ==0){
            mapa[nombre] = 0;
        }
        if(result == "CORRECTO"){
            mapa[nombre] += 1;
        }else{
            mapa[nombre] -= 1;
        }
        
    }

    bool fin= false;

    


    // escribir sol
    for(auto it = mapa.begin(); it != mapa.end();++it){
        if(it->second != 0){
            cout << it->first << ", " << it-> second;
            cout << endl;
        }
    }
    cout << "---" <<endl;
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
