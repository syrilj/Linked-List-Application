//
//  list.hpp
//  Exercise C
//
//  Created by Syril Jacob on 2022-11-21.
//

#ifndef list_hpp
#define list_hpp


#include<iostream>
#include<fstream>
#include<stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdio.h>
using namespace std;
struct ListItem
{
    int year;
    double flow;
};
struct Node
{
    ListItem item;
    Node *next;
};
class Flowlist
{
    private:
        void destroy();
        // used to deallocate nodes and sets HeadM to zero
        void copy(const Flowlist& source);
        //copy of source
        
    public:
        Node *headM;
        Flowlist(); // PROMISES: Creates empty list.
        Flowlist(const Flowlist& source);
        Flowlist& operator =(const Flowlist& rhs);
        ~Flowlist();

        void insert(const ListItem& itemA);
        // PROMISES:
        //    A node with a copy of itemA is added in
        //    a way that preserves the nondecreasing
        //    order of items in nodes.

        void remove(const ListItem& inst);
        //  PROMISES:
        //    If no node has an item matching itemA,
        //    list is unchanged.
        //    Otherwise exactly one node with
        //    its item == itemA is removed.
        void print(int x) const;
        // PROMISES:
        //   Prints items in list on a single line, with commas separating
        //   the items and square brackets marking the ends of the list.
        // NOTE:
        //   This is different from the print function presented in lectures.
        double flow_average();
        // used to calcaultae the average flow across all the nodes in the linked list
};
#endif /* list_hpp */
