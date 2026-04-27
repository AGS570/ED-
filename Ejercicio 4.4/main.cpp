
// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:
#include "stack_linkedlist.h"
#include <fstream>
#include <queue>
// Introduce más librerías si son necesarias
using namespace std;

// función que resuelve el problema
StackLinkedList<string> resolver(queue<string> cola) {
  StackLinkedList<string> st, trash, res;

  while (!cola.empty()) {
    if (cola.front() == "<") {

      if (!st.empty()) {
        trash.push(st.top());
        st.pop();
        cola.pop();
      } else
        cola.pop();
    } else if (cola.front() == ">") {
      if (!trash.empty()) {
        st.push(trash.top());
        trash.pop();
        cola.pop();
      } else
        cola.pop();
    } else {
      st.push(cola.front());
      cola.pop();
      while (!trash.empty()) {
        trash.pop();
      }
    }
  }
  while (!st.empty()) {
    res.push(st.top());
    st.pop();
  }
  return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  queue<string> cola;

  string input;

  while (input != ".") {
    cin >> input;
    if (input != ".")
      cola.push(input);
  }

  // leer los datos de la entrada

  StackLinkedList<string> sol = resolver(cola);

  // escribir solución
  while (!sol.empty()) {
    cout << sol.top();
    sol.pop();
    cout << " ";
  }
  cout << endl;
}

int main() {
// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("datos.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
  std::ofstream out("datos.out");
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
