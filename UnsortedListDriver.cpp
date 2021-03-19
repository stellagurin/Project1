// Test driver
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "UnsortedList.cpp"
#include "Student.h"

void testIntegerList();
void testStudentList();

int main()
{
	int datatype;
	// Prompt user to enter type of elements
	cout << "Enter Elements Type\n1 for integer\n2 for Student\n";
	cin >> datatype;
	switch (datatype)
	{
	case 1: testIntegerList();
		    break;
	case 2: testStudentList();
		    break;
	}

	return 0;
}


void testIntegerList()
{
	UnsortedList<int> integerList(5);
	string command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("intcommands.txt");
	outFile.open("outFile.txt");
	int number;
	inFile >> command; // read commands from a text file

	while (command != "Quit")
	{
		try
		{
			if (command == "MakeEmpty")
				(integerList.makeEmpty());

			else if (command == "IsEmpty")
				if (integerList.isEmpty())
					outFile << "list is empty\n";
				else
					outFile << "list is not empty\n";
			else if (command == "IsFull")
			{
				if (integerList.isFull())
					outFile << "List is full\n";
				else
					outFile << "List is not full\n";
			}

			else if (command == "PutItem")
			{
				inFile >> number;
				integerList.putItem(number);
			}
			else if (command == "DeleteItem")
			{
				inFile >> number;
				integerList.deleteItem(number);
			}

			else if (command == "GetLength")
				outFile << integerList.getLength() << "\n";
			else if (command == "PrintList")
			{
				outFile << "List Items: ";
				int value;
				for (int index = 0; index < integerList.getLength(); index++)
				{
					value = integerList.getAt(index);
					outFile << value << " ";
				}
				outFile << "\n";
			}

			else if (command == "GetAt")
			{
				int index;
				inFile >> index;
				outFile << "Item at index " << index << " is:" << integerList.getAt(index) << endl;
			}
			else
				outFile << "Unrecognized command";
			inFile >> command;

		} // try

		catch (FullList)
		{
			outFile << "List is full, Insertion failed" << endl;
			inFile >> command;
		}

		catch (EmptyList)
		{
			outFile << "List is empty" << endl;
			inFile >> command;
		}

		catch (DuplicateItem)
		{
			outFile << "Duplicate Item, Insertion failed" << endl;
			inFile >> command;
		}
		catch (OutofBound)
		{
			outFile << "Index is out of range" << endl;
			inFile >>command;
		}
		catch (ItemNotFound)
		{
			outFile << "Item is not in the list"<<endl;
			inFile >> command;
		}
	} // while
} // testIntegerList

void testStudentList() {
    UnsortedList<Student> studentList(10);
    string command;
    ifstream inFile;
    ofstream outFile;
    inFile.open("studcommands.txt");
    outFile.open("outFile.txt");
    int number ;
    string name;
    inFile >> command; // read commands from a text file

    while (command != "Quit") {
        try {
            if (command == "MakeEmpty")
                (studentList.makeEmpty());
            else if (command == "IsEmpty")
                if (studentList.isEmpty())
                    outFile << "list is empty\n";
                else
                    outFile << "list is not empty\n";
             else if (command == "IsFull") {
                if (studentList.isFull())
                    outFile << "List is full\n";
                else
                    outFile << "List is not full\n";
             }
              else if (command == "PutItem")
              {
                inFile >> number;
                inFile >> name;
                Student item;
                item.setStudentId(number);
                item.setStudentName(name);
                studentList.putItem(item);
             }

             else if (command == "DeleteItem")
             {
                 inFile >> number;
                 int del = 0;
                 if (studentList.getLength() == 0) {
                     throw EmptyList();
                 } else {
                     for (int i = 0; i < studentList.getLength(); i++) {
                         if (studentList.getAt(i).getStudentId() == number) {
                             del = i;
                             i = studentList.getLength();
                         } else {
                             del = -1;
                         }
                     }
                     if (del != -1) {
                         studentList.deleteItem(studentList.getAt(del));
                     } else {
                         throw ItemNotFound();
                     }
                 }
             }

             else if (command == "GetLength")
                  outFile << studentList.getLength() << "\n";
             else if (command == "PrintList")
             {
                 outFile << "List Items: ";
                 Student stud;
                 for (int index = 0; index < studentList.getLength(); index++)
                 {
					stud = studentList.getAt(index);
					outFile << stud.getStudentId()  << " " << stud.getStudentName() << " ";
				 }
				outFile << "\n";
             }

             else if (command == "GetAt")
             {
                 int index;
                 inFile >> index;
                 outFile << "Item at index " << index << " is: "
                         << studentList.getAt(index).getStudentId()
                         << " " << studentList.getAt(index).getStudentName() <<  endl;

             }
             else
                 outFile << "Unrecognized command\n";
                 inFile >> command;


        } //try
         catch (FullList)
         {
             outFile << "List is full, Insertion failed" << endl;
             inFile >> command;
         }

         catch (EmptyList)
         {
             outFile << "List is empty" << endl;
             inFile >> command;
         }

         catch (DuplicateItem)
         {
             outFile << "Duplicate Item, Insertion failed" << endl;
             inFile >> command;
         }
         catch (OutofBound)
         {
             outFile << "Index is out of range" << endl;
             inFile >>command;
         }
         catch (ItemNotFound)
         {
             outFile << "Item is not in the list"<<endl;
             inFile >> command;
         }
    }//while
}// test StudentList
