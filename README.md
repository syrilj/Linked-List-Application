# Linked-List-Application

River Flow Data Analysis
This program reads river flow data from a text file and creates a linked list to represent a database of the river's annual records. The program also allows for some statistical analysis of the data.

File Input/Output in C++
To read data from a text file in C++, follow these steps:

Include the fstream header: #include <fstream> and use the std namespace: using namespace std;
Create an ifstream object: ifstream inObj;
Open the file for reading: inObj.open("mydata.txt");
Use the inObj object like cin to read data from the file: inObj >> a >> b;
Use the inObj.eof() function to check for the end of the file. It returns true if the end of the file has been reached during the reading process.
Close the file when you are done reading from it: inObj.close();
To write data to a text file in C++, follow these steps:

Include the fstream header: #include <fstream> and use the std namespace: using namespace std;
Create an ofstream object: ofstream outObj;
Open the file for writing: outObj.open("myoutput.txt");
Use the outObj object like cout to write data to the file: outObj << setw(10) << a << setw(15) << b << endl;
Close the file when you are done writing to it: outObj.close();
Note: When you open a file for writing, the default mode is "truncate," which means that if the file already exists, its data will be lost. To append data to the end of a file (instead of overwriting it), open the file in "append" mode: outObj.open("myoutput.txt", ios::append);

Statistical Analysis
To perform statistical analysis on the data in the linked list, you can write functions that calculate various statistics such as the mean, median, and standard deviation.

The mean of a set of data is the sum of the data values divided by the number of data values. To calculate the mean of the data in the linked list, you can iterate through the list, adding up the data values and keeping a count of the number of values. Then, divide the sum by the count to get the mean.

The median of a set of data is the middle value when the data is sorted in numerical order. To calculate the median of the data in the linked list, you can first sort the data using a sorting algorithm such as bubble sort or merge sort. Then, if the number of data values is odd, the median is the middle value. If the number of data values
