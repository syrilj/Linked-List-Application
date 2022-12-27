//
//  .cpp
//  Exercise C
//
//  Created by Syril Jacob on 2022-11-21.
//

#include "hydro.h"

#include<iostream>

#include<fstream>

#include<stdio.h>

#include <iostream>

#include <vector>

#include <iomanip>

#include <sstream>

using namespace std;

void displayHeader() {
  cout << "Program: Flow Studies – Fall 2022\t \nVersion: 1.0\nLab section: B1\t\nProduced by: Syril Jacob\t\n\n<<< Press Enter to Continue>>>>\n";
  cin.get();
}
int menu() {
  int option;

  cout << "Please select on the following operations\n\t1. Display flow data, and the average\n\t2. Add data\n\t3. Save data into the file\n\t4. Remove data\n\t5. Quit\n\tEnter your choice (1,2,3,4, of 5): \n";
  cin >> option;
  return option;

}
void display(Flowlist & data) {
  data.print(0);
  cout << "\nThe annual average of the flow is " << average(data) << " billions of cubic meters" << endl;
  

}

int readData(Flowlist & data) {
  int num_records = 0;

  string filename;

  filename = "/Users/syriljacob/Desktop/ENSF 337 /Lab 8 337/Exercise C/flow.txt";
  ifstream file;

  file.open(filename);
  if (file.fail()) {
    cout << "ERROR: cannot open the file for reading..." << endl;
    cout << "Terminating program... " << endl;
    exit(1);
  }
  while (file.good()) {
    int year;
    double flow;
    file >> year >> flow;
    if (file.eof()) break;
    ListItem val;
    val.year = year;
    val.flow = flow;
    data.insert(val);
    num_records += 1;
  }
  file.close();
  return num_records;
}
void saveData(Flowlist & data) {
  string filename;

  filename = "/Users/syriljacob/Desktop/ENSF 337 /Lab 8 337/Exercise C/flow.txt";
  ofstream file;

  file.open(filename);
  if (file.fail()) {
    cout << "ERROR in reading file..." << endl;
    cout << "Program terminating... " << endl;
    exit(1);
  }
  Node * previous = data.headM;
  Node * succeeding = data.headM -> next;
  while (succeeding != 0) {
    file << previous -> item.year << "  " << previous -> item.flow << endl;
    previous = succeeding;
    succeeding = succeeding -> next;

    if (succeeding == 0) {
      file << previous -> item.year << "  " << previous -> item.flow << endl;
    }
  }
  cout << "\nData successfully saved into the file. " << endl;

  file.close();
}

void addData(Flowlist & data) {
  int new_year, error = 0;

  double new_flow;

  cout << "Enter the new year:" << endl;
  cin >> new_year;
  cout << "Enter the associated flow data:" << endl;
  cin >> new_flow;
  Node * previous = data.headM;
  Node * succeeding = data.headM -> next;
  while (succeeding != 0) {
    if (new_year == previous -> item.year) {
      error = 1;
      cout << "Error: duplicate data" << endl;
    }
    previous = succeeding;
    succeeding = succeeding -> next;
  }
  if (error == 0) {
    ListItem new_item;
    new_item.year = new_year;
    new_item.flow = new_flow;
    data.insert(new_item);
    cout << "\nNew record inserted successfully. " << endl;
  }
}
void removeData(Flowlist & data) {
  int year_del, error = 1;
  cout << "Enter the year to remove..." << endl;
  cin >> year_del;
  Node * previous = data.headM;
  Node * succeeding = data.headM -> next;
  while (succeeding != 0) {
    if (year_del == previous -> item.year) {
      error = 0;
    }
    previous = succeeding;
    succeeding = succeeding -> next;
  }
  if (error == 1) {
    cout << "\nError: No such a data." << endl;
  }
  if (error == 0) {
    ListItem item;
    item.year = year_del;
    data.remove(item);
    cout << "\nRecord was successfully removed. " << endl;
  }
}

double average(Flowlist & data) {
  double average_value;
  average_value = data.flow_average();
  return average_value;
}
void pressEnter() {
  cout << "\n<<< Press Enter to Continue>>>>\n" << endl;
  cin.get();
  cin.get();
}

int main() {
  Flowlist x;
  int numRecords;
  displayHeader();
  numRecords = readData(x);
  int quit = 0;
  while (1) {
    switch (menu()) {
    case 1:
      display(x);
      pressEnter();
      break;
    case 2:
      addData(x);
      pressEnter();
      break;
    case 3:
      saveData(x);
      pressEnter();
      break;
    case 4:
      removeData(x);
      pressEnter();
      break;
    case 5:
      cout << "\nProgram terminating\n";
      quit = 1;
     
      break;
    default:
      cout << "\ninvalid input\n";
      pressEnter();
      break;
    }
    if (quit == 1) break;
  }

}
