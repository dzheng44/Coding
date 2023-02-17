#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Book      //THIS IS FROM THE TEACHER; See previous prog4 and compare
{
private:
	string title;
	string author;
	string genre;
	int ISBN;
	bool isCheckedOut;
	string checkedOutBy;

public:
	//Constructor
	Book(string t = "N/A", string a = "N/A", string g = "N/A", int i = -1)
	{
		title = t;
		author = a;
		ISBN = i;
		genre = g;
		isCheckedOut = false;
		checkedOutBy = "";
	}

	//Getters
	string getTitle() { return title; }
	string getAuthor() { return author; }
	string getGenre() { return genre; }
	int getISBN() { return ISBN; }
	bool getStatus() { return isCheckedOut; }
	string getCheckedOutBy() { return checkedOutBy; }

	//Setters
	void setTitle(string new_t) { title = new_t; }
	void setAuthor(string new_a) { author = new_a; }
	void setISBN(int new_i) { ISBN = new_i; }
	void setGenre(string new_genre) { genre = new_genre; }

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
		cout << "    Genre: " << genre << endl;
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
		this->genre = obj.genre;
		this->checkedOutBy = obj.checkedOutBy;
		this->isCheckedOut = obj.isCheckedOut;

		return *this;
	}

	/*
		Returns true if the book on the left is "less than" the book
		on the right (i.e. obj).
		Example, if we had the following code:
			book1.compareByTitle(book2);

		it would see if book1's title is "less than" book2's title.
		if so, return true.  if not, return false.
		If the titles are equal, it would compare other attributes in
		the following order:
			Author
			Genre
			ISBN
	*/
	bool compareByTitle(const Book& obj)
	{
		if (this->title == obj.title)
		{
			if (this->author == obj.author)
			{
				if (this->genre == obj.genre)
				{
					if (this->ISBN == obj.ISBN)
						return false;
					else
						return this->ISBN < obj.ISBN;
				}
				else
					return this->genre < obj.genre;
			}
			else
				return this->author < obj.author;
		}
		else
			return this->title < obj.title;
	}


	/*
		Returns true if the book on the left is "less than" the book
		on the right (i.e. obj).
		Example, if we had the following code:
			book1.compareByAuthor(book2);

		it would see if book1's author is "less than" book2's author.
		if so, return true.  if not, return false.
		If the authors are equal, it would compare other attributes in
		the following order:
			Title
			Genre
			ISBN
	*/
	bool compareByAuthor(const Book& obj)
	{
		if (this->author == obj.author)
		{
			if (this->title == obj.title)
			{
				if (this->genre == obj.genre)
				{
					if (this->ISBN == obj.ISBN)
						return false;
					else
						return this->ISBN < obj.ISBN;
				}
				else
					return this->genre < obj.genre;
			}
			else
				return this->title < obj.title;
		}
		else
			return this->author < obj.author;
	}

	/*
		Returns true if the book on the left is "less than" the book
		on the right (i.e. obj).
		Example, if we had the following code:
			book1.compareByGenre(book2);

		it would see if book1's genre is "less than" book2's genre.
		if so, return true.  if not, return false.
		If the titles are equal, it would compare other attributes in
		the following order:
			Title
			Author
			ISBN
	*/

	bool compareByGenre(const Book& obj)
	{
		if (this->genre == obj.genre)
		{
			if (this->title == obj.title)
			{
				if (this->author == obj.author)
				{
					if (this->ISBN == obj.ISBN)
						return false;
					else
						return this->ISBN < obj.ISBN;
				}
				else
					return this->author < obj.author;
			}
			else
				return this->title < obj.title;
		}
		else
			return this->genre < obj.genre;
	}
};