// Autor/a: <Nombre y apellidos>
// email: <@ucm.es>
// Nombre del problema:

#include <fstream>
#include <iostream>
#include <stack>
// Introduce más librerías si son necesarias
using namespace std;

bool match(char c, char o) {
  if (c == ')' && o == '(')
    return true;
  if (o == '{' && c == '}')
    return true;
  if (o == '[' && c == ']')
    return true;
  return false;
}
// función que resuelve el problema
bool resolver(string str) {
  stack<char> stc;

  for (char c : str) {
    if (c == '(' || c == '[' || c == '{') {
      stc.push(c);
    } else if (c == ')' || c == ']' || c == '}') {

      if (!stc.empty()) {

        if (match(c, stc.top())) {
          stc.pop();
        } else
          return false;
      } else
        return false;
    }
  }

  if (stc.empty())
    return true;
  else
    return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  string st;

  getline(cin, st);
  if (!std::cin) // fin de la entrada
    return false;

  bool sol = resolver(st);

  // escribir sol

  if (sol == true)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  return false;
}

int main() {
// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("datos.in.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
  std::ofstream out("datos.out.txt");
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
