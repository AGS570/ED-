
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "bintree_V6.h"
// Introduce más librerías si son necesarias
using namespace std;
bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool esmul(int num) {
    if(num % 7 == 0) return true;
    return false;
}
// función que resuelve el problema
void resolver(const BinTree<int> &tree, int &p, int &prime, bool &found)
{
    if (tree.empty() || found)
        return;
    else p++;
    
    if (esPrimo(tree.root()) ) {
        found = false;
        return;
    }
    
    if (esmul(tree.root())) {
        prime = tree.root();
        found = true;
        return;
    }

    int prime_left = 0, prime_right = 0;
    int p0 = 0, p1 = 0;
    bool found_left = false, found_right = false;
    if(!tree.left().empty() )
    resolver(tree.left(), p0, prime_left, found_left);
    if(!tree.right().empty() )
    resolver(tree.right(), p1, prime_right, found_right);

    if (found_left && found_right) {

        if(p0 == p1) {
            prime = prime_left;
            p = p0 + 1;
            found = true;
        }
        else if(p0 < p1) {
            prime = prime_left;
            p = p0 + 1;
            found = true;
        } else {
            prime = prime_right;
            p = p1 + 1;
            found = true;
        }
    }
        else if (found_left) {
            prime = prime_left;
            p = p0 + 1;
            found = true;
        } else if (found_right) {
            prime = prime_right;
            p = p1 + 1;
            found = true;
        }

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  BinTree<int> tree = read_tree<int>(cin);
  // leer los datos de la entrada
  queue<BinTree<int>> q;
  int p = 0;
  int e = 0;
  bool found = false;
  resolver(tree,  p, e, found);

  // escribir solución

   
    if(found){
         cout << e << " " << p << endl;
    }else
    cout << "NO HAY" << endl;
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
