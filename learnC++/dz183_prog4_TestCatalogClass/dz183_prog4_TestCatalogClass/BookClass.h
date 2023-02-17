//Code from Mr. McDaniel in case students made errors in their previous lab to prevent mistakes; could've used program 3 code
//Compare the code from program 3 to this to check for mistakes in previous lab

#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Book
{
private:
	string title;
	string author;
	int ISBN;
	bool isCheckedOut;
	string checkedOutBy;

public:
	//Constructor
	Book(string t = "N/A", string a = "N/A", int i = -1)
	{
		title = t;
		author = a;
		ISBN = i;
		isCheckedOut = false;
		checkedOutBy = "";
	}

	//Getters
	string getTitle() { return title; }
	string getAuthor() { return author; }
	int getISBN() { return ISBN; }
	bool getStatus() { return isCheckedOut; }
	string getCheckedOutBy() { return checkedOutBy; }

	//Setters
	void setTitle(string new_t) { title = new_t; }
	void setAuthor(string new_a) { author = new_a; }
	void setISBN(int new_i) { ISBN = new_i; }


	// If the book is checked out, return false,
	//otherwise, set the checked out status to
	//true and update the name of the user that
	//checked out the book.
	bool checkOutBook(string n)
	{
		if (isCheckedOut == true)
			return false;
		else
		{
			isCheckedOut = true;
			checkedOutBy = n;
			return true;
		}
	}

	void returnBook()
	{
		isCheckedOut = false;
		checkedOutBy = "";
	}

	void outputBook()
	{
		cout << title << endl;
		cout << "    by " << author << endl;
		cout << "    ISBN: " << ISBN << endl;

		if (isCheckedOut == true)
		{
			cout << "    Checked out By: " << checkedOutBy << endl;
		}
	}

	//Add built in support for the assignment operator
	//i.e. Book myBook = book_oj;
	Book& operator=(const Book& obj)
	{
		if (this == &obj)
			return *this;

		this->author = obj.author;
		this->title = obj.title;
		this->ISBN = obj.ISBN;
		this->checkedOutBy = obj.checkedOutBy;
		this->isCheckedOut = obj.isCheckedOut;

		return *this;
	}
};