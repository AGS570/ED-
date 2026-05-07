
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:

#include <iostream>
#include <fstream>
#include <set>
#include <bits/stdc++.h>
// Introduce más librerías si son necesarias
using namespace std;
template <typename T>
void resolver(set<T> &tree, T n, int k)
{
   tree.insert(n);
   if(tree.size() > k) tree.erase(tree.begin());
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada

    char op;
    std::cin >> op;
    if (!std::cin) // fin de la entrada
        return false;
    int k;
    cin >> k;
    if (op == 'N'){
        set<int> tree;
        int in;
        cin >> in;
        while (in != -1){

            resolver(tree, in, k);
            cin >> in;
        }
        for (auto it = tree.begin(); it != tree.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }else{
        set<string> tree;
        string in;
        cin >> in;
        while (in != "FIN")
        {
            resolver(tree, in, k);
            cin >> in;
        }
        for (auto it = tree.begin(); it != tree.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    // escribir sol

    return true;
}

int main()
{
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

// función que resuelve el problema
