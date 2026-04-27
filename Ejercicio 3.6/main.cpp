// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include "list_linked_double.h"
// Introduce más librerías si son necesarias
using namespace std;



// función que resuelve el problema
void resolver(ListLinkedDouble<int> list, int index, int sum) {
   list.add_to(index,sum);
   list.display();
   cout << endl;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  ListLinkedDouble<int> list;
  int l, ind,sum, a;
// leer los datos de la entrada
cin >> l >> ind >> sum;
if (l == 0 && ind ==0 &&sum ==0)
return false;

for( int i =0; i < l; i++){
    cin >> a;
    list.push_back(a);
}
resolver(list,ind,sum);

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

