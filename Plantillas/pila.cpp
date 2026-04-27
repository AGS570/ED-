/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include <iostream>
#include <string>
#include "stack_array.h"
#include "stack_linkedlist.h"
#include <stack>
using namespace std;

int main() {

	cout << "\n --- Pila implementada con array --- \n" << endl;

	StackArray<string> p1;
	p1.push("Carmen");
	p1.push("Jose");
	p1.push("Conchi");

	cout << " Antes de cambiar la cima: " << p1.top() << endl;
	p1.top() = "Sonia";
	cout << " Ahora la cima es: " << p1.top() << endl;

	cout << " Desapilando elementos: " ;
	while (!p1.empty()) {
		cout << p1.top() << "  ";
		p1.pop();
	}

	cout << "\n\n --- Pila implementada con lista enlazada --- \n" << endl;

	StackLinkedList<string> p2;
	p2.push("Carmen");
	p2.push("Jose");
	p2.push("Conchi");
	
	cout << " Antes de cambiar la cima: " << p2.top() << endl;
	p2.top() = "Sonia";
	cout << " Ahora la cima es: " << p2.top() << endl;

	cout << " Desapilando elementos: ";
	while (!p2.empty()) {
		cout << p2.top() << "  ";
		p2.pop();
	}

	cout << "\n\n --- Pila con la STL stack --- \n" << endl;

	stack<string> p3;
	p3.push("Carmen");
	p3.push("Jose");
	p3.push("Conchi");

	cout << " Antes de cambiar la cima: " << p3.top() << endl;
	p3.top() = "Sonia";
	cout << " Ahora la cima es: " << p3.top() << endl;

	cout << " Desapilando elementos: ";
	while (!p3.empty()) {
		cout << p3.top() << "  ";
		p3.pop();
	}

	return 0;
}
