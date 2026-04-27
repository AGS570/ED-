

// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 
// Introduce más librerías si son necesarias
using namespace std;
#include"ListLinkedSinge.h"
#include <bits/stdc++.h>



void resolver(ListLinkedSingle &list) {
    list.duplicate(list);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    ListLinkedSingle list;
    string input;
    
    while (input != "0")
    {
        cin >> input;
        if(input != "0")
            list.push_back(input);
    }
    
    
    
// leer los datos de la entrada

    resolver(list);

    list.display();
    cout << endl;

// escribir solución

}
int main() {
   // ajustes para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
   std::ifstream in("datos.in.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
   std::ofstream out("datos.out.txt");
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

