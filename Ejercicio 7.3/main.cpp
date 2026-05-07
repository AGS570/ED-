
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:

#include <iostream>
#include <fstream>
#include <set>
#include <bits/stdc++.h>
// Introduce más librerías si son necesarias
using namespace std;

void resolver( vector<set<int>> &players, int c)
{
    vector<int> descarta;vector<int> pls;
    int num, carta;
    carta = 0;
    
    for (int i = 0; i < c; i++){
        cin >> num;
        if(players[i%players.size()].count(num) ==1){
            players[i%players.size()].erase(num);
        }else
            players[i%players.size()].insert(num);
    }

    return;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int ju, c;
    vector<set<int>> players;
    std::cin >> ju >> c;
    if (!std::cin) // fin de la entrada
        return false;

    for (int i = 0; i < ju; i++)
    {
       set<int> pl;
       players.push_back(pl);
    }


    resolver(players, c);
    // escribir sol
    int j = players.size();
    for (int i=0; i < players.size(); i++)
    {
        auto it = players[i].begin();
        cout << "J" << i+1 << ": {";

        
    if (it != players[i].end()) {
        cout << *it;
        ++it;
    }

        while(it != players[i].end()){
            cout << ", " << *it;
            ++it; 
        }
        cout << "}" << endl;
    }
    cout << "---"<< endl;
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
