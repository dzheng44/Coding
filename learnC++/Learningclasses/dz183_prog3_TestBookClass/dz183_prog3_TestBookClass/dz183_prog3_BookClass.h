#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>

using std::string;
using namespace std;

class Book {
	private:
		string title;
		string author;
		int ISBN;
		bool status;
		string checkedOutBy;

	public:
		Book(string p_title = "Unknown", string p_author = "Unknown", int p_ISBN = -1) //constructor
		{
			title = p_title;
			author = p_author;
			ISBN = p_ISBN;
			status = false;
		}

		string getTitle() 
		{
			return title;
		}

		string getAuthor()
		{
			return author;
		}

		int getISBN()
		{
			return ISBN;
		}

		bool getStatus()
		{
			return status;
		}

		void setTitle(string new_title)
		{
			title = new_title;
		}

		void setAuthor(string new_author)
		{
			author = new_author;
		}

		void setISBN(int new_ISBN)
		{
			ISBN = new_ISBN;
		}

		bool checkOutBook(string name)
		{
			if (status == false) // if the status is false, it hasn't been checked out
			{
				status = true;
				checkedOutBy = name;
				return true;
			}
			else // this only occurs if status is true meaning it has been checked out
				cout << "Already checked out";
				return false;
		}

		void returnBook()
		{
			status = false;
			checkedOutBy = ""; //Could you use null?
		}

		void outputBook()
		{
			cout << title << endl;
			cout << "by " << author << endl;
			cout << "ISBN: " << ISBN << endl;
			if (status == true)
				cout << "Checked out by: " << checkedOutBy;
		}
};