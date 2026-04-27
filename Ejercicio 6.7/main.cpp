
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "bintree_V6.h"
// Introduce más librerías si son necesarias
using namespace std;

// función que resuelve el problema
void resolver(const BinTree<char> &tree, int &area, int &prof, int &max_a)
{
  if(tree.empty()) return;
  else prof ++;



  if(tree.root() == 'B'){
    int area_i =0, area_d = 0;
    if(!tree.left().empty()) resolver(tree.left(), area_i, prof, max_a);
    if(!tree.right().empty()) resolver(tree.right(), area_d, prof, max_a);    
    
  }else {

    area ++;
    int area_i =0, area_d = 0;
    if(!tree.left().empty()) resolver(tree.left(), area_i, prof, max_a);
    if(!tree.right().empty()) resolver(tree.right(), area_d, prof, max_a);    

    area += area_i + area_d;
    if (area > max_a) max_a = area;
  }


 
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  BinTree<char> tree = read_tree<char>(cin);
  // leer los datos de la entrada
  int area = 0, prof = 0, max_area = 0;
  
 
  resolver(tree, area, prof, max_area);

  // escribir solución
  cout << max_area << endl;
}

int main()
{
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
