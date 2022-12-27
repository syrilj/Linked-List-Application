//
//  hydro.hpp
//  Exercise C
//
//  Created by Syril Jacob on 2022-11-21.
//

#ifndef hydro_h
#define hydro_h

#include "list.hpp"

#include <sstream>

using namespace std;
int menu();
//display that gives user range of options to select from
void display();
//displays average as ws well as years and flow
void displayHeader();
//intial display for user
int readData(Flowlist &data);
// allows user to read data from txt file
void saveData(Flowlist &data);
// allows user to wrtie content to txt file via linked list
void addData(Flowlist &data);
// allows user to add data into linked list via user input
void removeData(Flowlist &data);
//allows user to remove data via user prompt
double average(Flowlist &data);
//gives the return flow average in the list
void pressEnter();
// takes users input 
#endif /* hydro_h*/


