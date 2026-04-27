
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;


// función que resuelve el problema
list<char> resolver(vector<char> v) {
    list<char> res;
    auto r = res.begin();
   for(auto it = v.begin(); it != v.end(); ++it ){
        if(*it == '-'){
           r =  res.begin();
        }else if(*it == '3'){
          if(r != res.end())    
                r = res.erase(r);
        }
        else if(*it == '*'){
            if(r != res.end())
                ++r;
        }else if(*it == '+'){
          r =  res.end();
        }else{

            r =res.insert(r,*it);
            ++r;
        }
   }

    return res ;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    vector<char> v;
   string f;
   
   // leer los datos de la entrada
   
   cin >> f;
if (!std::cin)
return false;
    for(char c: f){
        v.push_back(c);
    }    
// fin de la entrada
list<char> sol = resolver(v);

// escribir sol
for(char c: sol){
    cout<<c;
}
cout<<endl;
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
