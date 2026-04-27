// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include "dequeue.h"
// Introduce más librerías si son necesarias
using namespace std;
int Max(Dequeue<int> cola){
  int max=cola.front();

  while(!cola.empty()){
    if(cola.front() > max)max = cola.front();
    cola.pop_front();
  }
  return max;
}
// función que resuelve el problema
Dequeue<int> resolver(Dequeue<int> cola, int rango) {
  
  Dequeue<int> res,aux;
  int max, sec;
  max = 0;sec =0;
  for(int i=0; i < rango;i++){

    aux.push_back(cola.front());
    cola.pop_front();
    if(aux.back() > max) max = aux.back();
    else if(aux.back() > sec) sec = aux.back();


  }
  res.push_back(Max(aux));

  while(!cola.empty()){

    aux.pop_front();
    aux.push_back(cola.front());
    cola.pop_front();
    res.push_back(Max(aux));
  }

  return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  Dequeue<int> cola;
  int lon, rango;
  int input;
  cin >> lon >> rango;
  // leer los datos de

  if (!std::cin) // fin de la entrada
    return false;

  for (int i = 0; i < lon; i++) {
    cin >> input;
    cola.push_back(input);
  }
  Dequeue<int> sol = resolver(cola, rango);

  // escribir sol
  while(!sol.empty()){
    cout << sol.front() << " ";
    sol.pop_front();
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

  while (resuelveCaso())
    ;

// para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);
#endif
  return 0;
}
