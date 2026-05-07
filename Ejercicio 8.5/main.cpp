// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
// Introduce más librerías si son necesarias
using namespace std;


void resuelveCaso() {
    int si;
    cin >> si;

    unordered_map<int, int> lastSeen;
    int maxDays = 0;
    int windowStart = 0;

    for (int i = 0; i < si; i++) {
        int ep;
        cin >> ep;

        
        if (lastSeen.count(ep) && lastSeen[ep] >= windowStart) {
            windowStart = lastSeen[ep] + 1;
        }

        lastSeen[ep] = i;
        maxDays = max(maxDays, i - windowStart + 1);
    }

    cout << maxDays << "\n";
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
   for (int i = 0; i < numCasos; ++i)
   resuelveCaso();
   
   // para dejar todo como estaba al principio
   #ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   std::cout.rdbuf(coutbuf);
   #endif
   return 0;
}

// función que resuelve el problema


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta