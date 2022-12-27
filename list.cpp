//
//  list.cpp
//  Exercise C
//
//  Created by Syril Jacob on 2022-11-21.
//

#include "list.hpp"

#include<iostream>

#include<fstream>

#include<stdio.h>

#include <iostream>

#include <vector>

#include <iomanip>

#include <sstream>

using namespace std;
Flowlist::Flowlist(): headM(0) {

} // PROMISES: Creates empty list.
Flowlist::Flowlist(const Flowlist & source) {
  copy(source);
}
Flowlist & Flowlist::operator = (const Flowlist & rhs) {
  if (this != & rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}
Flowlist::~Flowlist() {
  destroy();
}
void Flowlist::insert(const ListItem & val) {
  Node * node_new = new Node;
  node_new -> item = val;

  if (headM == 0 || val.year <= headM -> item.year) {
    node_new -> next = headM;
    headM = node_new;
    // point one
  } else {
    Node * previous = headM;
    Node * succeeding = headM -> next;
    while (succeeding != 0 && val.year > succeeding -> item.year) {
      previous = succeeding;
      succeeding = succeeding -> next;
    }
    node_new -> next = succeeding;
    previous -> next = node_new;
   
  }
}
void Flowlist::remove(const ListItem & val) {
  if (headM == 0 || val.year < headM -> item.year)
    return;

  Node * doomed_node = 0;

  if (val.year == headM -> item.year) {
    doomed_node = headM;
    headM = headM -> next;
  } else {
    Node * previous = headM;
    Node * maybe_doomed = headM -> next;
    while (maybe_doomed != 0 && val.year > maybe_doomed -> item.year) {
      previous = maybe_doomed;
      maybe_doomed = maybe_doomed -> next;
    }
    while (previous) {
      if (previous -> next && previous -> next -> item.year == val.year)
        previous -> next = previous -> next -> next;

      else
        previous = previous -> next;
    }
  }

}
void Flowlist::print(int c) const {
  if (c == 1) {
    cout << "[";
    if (headM != 0) {
      cout << "[" << headM -> item.year << ", " << headM -> item.flow << "]";
      for (const Node * p = headM -> next; p != 0; p = p -> next)
        cout << ", {" << p -> item.year << ", " << p -> item.flow << "]";
    }
    cout << " ]\n";
  } else if (c == 0) {
    cout << "\nYear       Flow(in billions of cubic meters)" << endl;
    cout << "----      -------------------------------" << endl;
    if (headM != 0) {
      cout << headM -> item.year << "       " << headM -> item.flow << endl;
      for (const Node * p = headM -> next; p != 0; p = p -> next)
        cout << p -> item.year << "       " << p -> item.flow << endl;
    }
  }
}
double Flowlist::flow_average() {
  double avg, sum = 0, count = 0;
  Node * previous = headM;
  Node * succeeding = headM -> next;
  while (succeeding != 0) {
    sum += previous -> item.flow;
    previous = succeeding;
    succeeding = succeeding -> next;
    count += 1;

    if (succeeding == 0) {
      sum += previous -> item.flow;
      count += 1;
    }
  }
  avg = sum / (count);
  return avg;

}
void Flowlist::copy(const Flowlist & source) {
  if (source.headM == nullptr)
    return;

  Node * tmp = source.headM;
  Node * current = nullptr;

  headM = new Node;

  headM -> item = tmp -> item;

  headM -> next = nullptr;

  current = headM;

  tmp = tmp -> next;

  while (tmp != nullptr) {

    current -> next = new Node;

    current = current -> next;

    current -> item = tmp -> item;

    current -> next = nullptr;

    tmp = tmp -> next;
  }
}
void Flowlist::destroy() {
  Node * current = headM;
  Node * next = NULL;

  while (current != NULL) {
    next = current -> next;
    free(current);
    current = next;

  }
  headM = NULL;
  delete current;
  cout << "Program terminated successfully\n";
}

