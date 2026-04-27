/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Implementación del TAD Lista mediante listas doblemente enlazadas circulares.
 *
 * Esta versión introduce genericidad mediante plantillas.
 */

#ifndef __LIST_LINKED_DOUBLE_H
#define __LIST_LINKED_DOUBLE_H

#include <cassert>
#include <iostream>
#include <string>

template <typename Elem> class ListLinkedDouble {
private:
  struct Node {
    Elem value;
    Node *next;
    Node *prev;
  };

public:
  ListLinkedDouble() : num_elems(0) {
    head = new Node;
    head->next = head;
    head->prev = head;
  }

  ListLinkedDouble(const ListLinkedDouble &other) : ListLinkedDouble() {
    copy_nodes_from(other);
    num_elems = other.num_elems;
  }

  ~ListLinkedDouble() { delete_nodes(); }

  void push_front(const Elem &elem) {
    Node *new_node = new Node{elem, head->next, head};
    head->next->prev = new_node;
    head->next = new_node;
    num_elems++;
  }

  void push_back(const Elem &elem) {
    Node *new_node = new Node{elem, head, head->prev};
    head->prev->next = new_node;
    head->prev = new_node;
    num_elems++;
  }

  void pop_front() {
    assert(num_elems > 0);
    Node *target = head->next;
    head->next = target->next;
    target->next->prev = head;
    delete target;
    num_elems--;
  }

  void pop_back() {
    assert(num_elems > 0);
    Node *target = head->prev;
    target->prev->next = head;
    head->prev = target->prev;
    delete target;
    num_elems--;
  }

  int size() const { return num_elems; }

  bool empty() const { return num_elems == 0; };

  const Elem &front() const {
    assert(num_elems > 0);
    return head->next->value;
  }

  Elem &front() {
    assert(num_elems > 0);
    return head->next->value;
  }

  const Elem &back() const {
    assert(num_elems > 0);
    return head->prev->value;
  }

  Elem &back() {
    assert(num_elems > 0);
    return head->prev->value;
  }

  const Elem &operator[](int index) const {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  Elem &operator[](int index) {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  ListLinkedDouble &operator=(const ListLinkedDouble &other) {
    if (this != &other) {
      delete_nodes();
      head = new Node;
      head->next = head->prev = head;
      copy_nodes_from(other);
      num_elems = other.num_elems;
    }
    return *this;
  }

  void display(std::ostream &out) const;

  void display() const { display(std::cout); }

  void rdisplay(std::ostream &out) const;

  void rdisplay() const { rdisplay(std::cout); }

  void zip(ListLinkedDouble &other) {
    Node *mio = head->next->next;
    Node *tuyo = other.head->next;
    while (mio != head && tuyo != other.head) {
      detach(tuyo);
      attach(tuyo, mio);
      this->num_elems++;
      other.num_elems--;
      mio = mio->next;
      tuyo = other.head->next;
    }
    if (tuyo != other.head) {
      while (tuyo != other.head) {
        detach(tuyo);
        attach(tuyo, mio);
        this->num_elems++;
        other.num_elems--;
        tuyo = other.head->next;
      }
    }
  }
  void unzip(ListLinkedDouble &other) {
    Node *pos = head->next->next;
    Node *zp = other.head;
    Node *p = pos->next;

    while (pos != head) {
      p = pos->next;
      this->detach(pos);
      other.attach(pos, zp);
      this->num_elems--;
      other.num_elems++;

      if (p != head)
        pos = p->next;
      else
        pos = head;
    }
  }
  void partition(int pivot) {
    Node *pos = head->next;
    Node *last = head;
    int n = num_elems;

    for (int i = 0; i < n; i++) {
      Node *next = pos->next;
      if (pos->value > pivot) {
        detach(pos);
        attach(pos, head);
        pos = next;

      } else {
        pos = pos->next;
        last = last->next;
      }
    }
  }

  void sort_and_dedup() {
    Node *start = head->next;
    Node *min;

    for (int i = 0; i < num_elems - 1; i++) {
      min = minimum(start, head);
      if (min != start) {

        detach(min);
        attach(min, start);
      }
      start = min->next;
    }

    start = head->next;
    while (start->next != head) {
      if (start->value == start->next->value) {
        Node *del = start->next;
        detach(del);
        delete del;
        num_elems--;
      } else
        start = start->next;
    }
  }

  // coste O(n)
  void swap2by2() {
    Node *end;
    Node *pos = head->next;
    Node *nx = pos->next;

    if (num_elems % 2 == 0) {
      end = head;
    } else
      end = head->prev;

    while (pos != end) {
      detach(nx);
      attach(nx, pos);

      pos = pos->next;
      nx = pos->next;
    }
  }

  // coste O(n)
  void add_to(int index, int sum) {
    int p = 0;
    bool done = false;
    Node *pos = head->next;
    Node *nx;
    while (!done) {
      if (p == index) {
        detach(pos);
        pos->value += sum;
        done = true;
      } else {
        pos = pos->next;
        p++;
      }
    }

    nx = head->next;
    done = false;
    if (pos->value < nx->value) {
      attach(pos, nx);
    } else {

      while (!done) {
        if (pos->value >= nx->value && pos->value < nx->next->value ||
            nx->next == head) {
          attach(pos, nx->next);
          done = true;
        } else
          nx = nx->next;
      }
    }
  }

  void mostraReves(std::ostream &out) const {
    out << "[";
    if (head->prev != head) {
      out << head->prev->value;
      Node *current = head->next->next;
      while (current != head) {
        out << ", " << current->value;
        current = current->prev;
      }
    }
    out << "]";
  }

  void CortaMenores() {
    Node *pos = head->next;
    for (auto it = head->next; it != head->prev->prev; ++it) {
      if (it->next->value < it->value) {
        Node *del = it->next;
        detach(del);
        delete del;
      }
    }
  }

private:
  Node *head;
  int num_elems;

  Node *nth_node(int n) const;
  void delete_nodes();
  void copy_nodes_from(const ListLinkedDouble &other);
  void detach(Node *n);
  void attach(Node *n, Node *pos);
  Node *minimum(Node *start, Node *end) const;
};

template <typename Elem>
typename ListLinkedDouble<Elem>::Node *
ListLinkedDouble<Elem>::nth_node(int n) const {
  int current_index = 0;
  Node *current = head->next;

  while (current_index < n && current != head) {
    current_index++;
    current = current->next;
  }

  return current;
}

template <typename Elem> void ListLinkedDouble<Elem>::delete_nodes() {
  Node *current = head->next;
  while (current != head) {
    Node *target = current;
    current = current->next;
    delete target;
  }

  delete head;
}

template <typename Elem>
void ListLinkedDouble<Elem>::copy_nodes_from(const ListLinkedDouble &other) {
  Node *current_other = other.head->next;
  Node *last = head;

  while (current_other != other.head) {
    Node *new_node = new Node{current_other->value, head, last};
    last->next = new_node;
    last = new_node;
    current_other = current_other->next;
  }
  head->prev = last;
}

template <typename Elem>
void ListLinkedDouble<Elem>::display(std::ostream &out) const {
  out << "[";
  if (head->next != head) {
    out << head->next->value;
    Node *current = head->next->next;
    while (current != head) {
      out << ", " << current->value;
      current = current->next;
    }
  }
  out << "]";
}
template <typename Elem>
void ListLinkedDouble<Elem>::rdisplay(std::ostream &out) const {
  out << "[";
  if (head->prev != head) {
    out << head->prev->value;
    Node *current = head->prev->prev; // ← segundo desde el final
    while (current != head) {
      out << ", " << current->value;
      current = current->prev; // ← hacia atrás
    }
  }
  out << "]";
}
template <typename Elem> void ListLinkedDouble<Elem>::detach(Node *n) {
  assert(n != head);
  n->prev->next = n->next;
  n->next->prev = n->prev;
  n->prev = nullptr;
  n->next = nullptr;
}

template <typename Elem>
void ListLinkedDouble<Elem>::attach(Node *n, Node *pos) {
  n->next = pos;
  n->prev = pos->prev;
  pos->prev->next = n;
  pos->prev = n;
}

template <typename Elem>
typename ListLinkedDouble<Elem>::Node *
ListLinkedDouble<Elem>::minimum(Node *start, Node *end) const {
  Node *min = start;
  while (start != end) {
    if (start->value < min->value) {
      min = start;
    }
    start = start->next;
  }
  return min;
}

template <typename Elem>
std::ostream &operator<<(std::ostream &out, const ListLinkedDouble<Elem> &l) {
  l.display(out);
  return out;
}

#endif
