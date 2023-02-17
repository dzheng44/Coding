#pragma once
#include "BookClass.h"
#include <string>

using std::string;

class Catalog
{
private:
	Book* books;
	int next_slot;
	int capacity;

public:
	Catalog(int init_size = 10)
	{
		books = new Book[init_size];
		capacity = init_size;
		next_slot = 0;
	}

	~Catalog()
	{
		delete[] books;
		books = nullptr;
	}


	int getNumBooks()
	{
		int count = 0;
		for (int i = 0; i < next_slot; i++)
		{
			count++;
		}
		return count;
	}

	void growCatalog()
	{
		Book* temp = books;
		capacity *= 2;
		books = new Book[capacity];
		for (int i = 0; i < next_slot; i++)
		{
			books[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;
	}

	void addBook(Book new_book)
	{
		cout << next_slot << " " << endl;
		if (next_slot == capacity)
			growCatalog();
		books[next_slot] = new_book;
		next_slot++;
	}

	void outputCatalog()
	{
		for (int i = 0; i < next_slot; i++)
		{
			books[i].outputBook();
		}
	}

	bool checkInBook(int isbn)
	{
		int found = -1;  //was gonna put the if statement inside the for loop, but I didn't want it to repeatedly return 1/-1 or end early by mistake; could have used break in the loop if so.
		for (int i = 0; i < next_slot; i++)
		{
			if (isbn == books[i].getISBN() && books[i].getStatus() == true)
			{
				books[i].returnBook();
				found = 1;
				break;
			}

		}
		if (found == 1)
			return true;
		else
			return false;
	}

	bool checkOutBook(int isbn, string name)
	{
		int found = -1;  //was gonna put the if statement inside the for loop, but I didn't want it to repeatedly return 1/-1 or end early by mistake
		for (int i = 0; i < next_slot; i++)
		{
			if (isbn == books[i].getISBN() && books[i].getStatus() == false)
			{
				books[i].checkOutBook(name);
				found = 1;
				break;
			}
		}
		if (found == 1)
			return true;
		else
			return false;
	}

	bool getBookByTitle(string title, Book& book)
	{
		int found = -1;
		for (int i = 0; i < next_slot; i++)
		{
			if (title == books[i].getTitle())
			{
				book = books[i];
				found = 1;
				break;
			}
		}
		if (found == 1)
			return true;
		else { // else if (no book == -1)
			return false;
		}
	}

	bool getBookByISBN(int isbn, Book& book)
	{
		int found = -1;
		for (int i = 0; i < next_slot; i++)
		{
			if (isbn == books[i].getISBN())
			{
				book = books[i];
				found = 1;
				break;
			}
		}
		if (found == 1)
			return true;
		else // else if (no book == -1)
			return false;
	}

	bool listBooksByAuthor(string author)
	{
		int found = -1;
		for (int i = 0; i < next_slot; i++) {
			if (author == books[i].getAuthor())
			{
				cout << books[i].getTitle() << ", ";
				found = 1;
			}
		}
		if (found == 1)
			return true;
		else // else if (author == -1)
			return false;
	}

	void emptyCatalog()
	{
		Book* temp = books;
		books = new Book[10];
		delete[] temp;
	}
};