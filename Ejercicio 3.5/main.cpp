// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include "list_linked_double.h"
// Introduce más librerías si son necesarias
using namespace std;


void resolver(ListLinkedDouble<int> list) {
   list.swap2by2();
   list.display();
   cout << endl;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   ListLinkedDouble<int> list;
   int input,a;
// leer los datos de la entrada
    cin >> input;
    if (input == 0)
    return false;
    for(int  i =0; i < input;i++){
        cin >> a;
        list.push_back(a);
    }

    resolver(list);

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


// función que resuelve el problema