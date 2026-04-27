 // Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema: 

#include <iostream>
#include <fstream>
#include<queue>
// Introduce más librerías si son necesarias
using namespace std;


// función que resuelve el problema
int resolver(queue<int>cola, int alumnos, int k) {
   
   while (cola.size() != 1){
      for(int i =1 ; i <= k; i++){
         cola.push(cola.front());
         cola.pop();
      }
            cola.pop();
  
     }
   return cola.front();

}
// resuelve un caso de prueba, leyendo de la: entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   queue<int> cola;
   int alumnos, af;  
// leer los datos de la entrada

cin >> alumnos >> af;
if (alumnos == 0 && af == 0)
return false;
for(int i =1; i <= alumnos;i++){
   cola.push(i);
}

int sol = resolver(cola,alumnos, af);
//

// escribir sol
cout << sol << endl;
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
   
   // para dejar todo como estaba al principi

#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf); 
   std::cout.rdbuf(coutbuf); 
#endif
   return 0;
}
