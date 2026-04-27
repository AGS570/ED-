
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
void resolver(const BinTree<int> &tree, queue<BinTree<int>> &q, vector<int> &m, int &p, int &e)
{

  q.push(tree);
  int nivel = 0;
  BinTree<int> current;

  while (!q.empty())
  {
    int numelems = q.size();
    for (int i = 0; i < numelems; ++i)
    {
      if(i==0 && !q.empty())m.push_back(q.front().root());
      current = q.front();
      if(!q.empty())
      q.pop();

      if (!current.left().empty())
        q.push(current.left());
      if (!current.right().empty())
        q.push(current.right());

      
     // m.push_back(q.front().root());

    }
  }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  BinTree<int> tree = read_tree<int>(cin);
  // leer los datos de la entrada
  queue<BinTree<int>> q;
  vector<int> m ;
  int p = 0;
  int e = 0;
  resolver(tree,q, m, p, e);

  // escribir solución
 for(int i = 0; i < m.size(); ++i)
    cout << m[i] << " ";
  cout << endl;
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
