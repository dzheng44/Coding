/*
Name: David Zheng
NetID: dz183

Program Description: This program is design to imitate a library. 
It can call and edit book statues and info. We can also check books out
*/

//Note: Change this name to reflect submission instrucions
#include "dz183_prog3_BookClass.h"

using std::cin;
using std::getline;

void populateBookArray(Book library[]);
int lookupByISBN(Book library[]);

const int SIZE = 5;

int main()
{
	//Create an array of Book objects to store our library in.
	Book library[SIZE];

	//Populate our library with sample books.
	populateBookArray(library);

	int choice;
	int index;
	string name;

	do
	{
		cout << endl;
		cout << "1) Search the library of books by ISBN\n2) Checkout a book\n3) Return a book\n4) Quit Program\nWhat would you like to do? ";
		cin >> choice;

		switch (choice) //kept break in so that it doesn't loop back to the start of the case
		{
		case 1:
			//search the library by ISBN
			index = lookupByISBN(library);
			if (index == -1)
				cout << "There seems to be an error. Please try again.";
			else
				library[index].outputBook();
			break;
		case 2:
			//Checkout a book
			index = lookupByISBN(library);
			if (index == -1)
				cout << "There seems to be an error. Please try again.";
			else
				cout << "Who is checking out? " << endl;
				cin.ignore();
				getline(cin, name);
				library[index].checkOutBook(name); //Not sure how to fix. Doesn't work for some like Jamar
			break;
		case 3:
			//Return a book
			index = lookupByISBN(library); 
			if (index == -1)
				cout << "There seems to be an error. Please try again.";
			else
				library[index].returnBook();
			break;
		case 4:
			// Quit Program
			return 0;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}

	} while (choice != 0); //Biggest worry is someone typing 0. Used 0 since that was in the instructions; could use true/false

	return 0;
}

//Note: This function assumes that there are 5 elements in this array.
//Function populates our library with popular novels.   
//ISBN numbers are just random 5 digit numbers.
//You can assume for the rest of your functions that the library
//array is always 5 elements.
void populateBookArray(Book library[])
{
	library[0].setAuthor("JK Rowling");
	library[0].setTitle("Harry Potter and the Sorcerers Stone");
	library[0].setISBN(98346);

	library[1].setAuthor("C.S. Lewis");
	library[1].setTitle("The Lion, the Witch, and the Wardrobe");
	library[1].setISBN(45336);

	library[2].setAuthor("E. B. White");
	library[2].setTitle("Charlotte's Web");
	library[2].setISBN(56432);

	library[3].setAuthor("F. Scott Fitzgerald");
	library[3].setTitle("The Great Gasby");
	library[3].setISBN(11934);

	library[4].setAuthor("S. E. Hinton");
	library[4].setTitle("The Outsiders");
	library[4].setISBN(72331);
}


//Asks the user for the ISBN number of the book
//and searches the library for that book.
//If found, returns the book element's index
//if not found, returns -1.
int lookupByISBN(Book library[])
{
	int ISBN;

	cout << "Enter the ISBN: ";
	cin >> ISBN;

	for (int i = 0; i < SIZE; i++)
	{
		if (ISBN == library[i].getISBN())
			return i;
	}

	return -1;
}