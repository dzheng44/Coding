#include "BookClass.h"
#include <vector> //THIS IS FROM TEACHER; compare to prog4 for error
using std::vector;

class Catalog   
{
private:
	vector<Book> books;

public:
	Catalog()
	{
		//this is here for the sake of being here; not needed as vectors are automatically initialized
	}

	~Catalog()
	{
		emptyCatalog();
	}

	void emptyCatalog()
	{
		books.clear();
	}

	bool listBookByAuthor(string author_name)
	{
		int count = 0;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getAuthor() == author_name)
			{
				books[i].outputBook();
				count++;
			}
		}

		return (bool)count;
	}

	bool listBookByGenre(string genre)
	{
		int count = 0;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getGenre() == genre)
			{
				books[i].outputBook();
				count++;
			}
		}

		return (bool)count;
	}

	bool getBookByTitle(string title, Book& book)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title)
			{
				book = books[i];
				return true;
			}
		}

		return false;
	}

	bool getBookByISBN(int isbn, Book& book)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getISBN() == isbn)
			{
				book = books[i];
				return true;
			}
		}

		return false;
	}

	bool checkOutBook(int isbn, string name)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getISBN() == isbn)
			{
				bool result = books[i].checkOutBook(name);
				return result;
			}
		}

		return false;
	}

	bool checkInBook(int isbn)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getISBN() == isbn)
			{
				books[i].returnBook();
				return true;
			}
		}

		return false;
	}

	void addBook(Book new_book)
	{
		books.push_back(new_book);
	}

	void outputCatalog()
	{
		for (int i = 0; i < books.size(); i++)
		{
			books[i].outputBook();
		}
	}

	void sortBooksByTitle()
	{
		int end = books.size();
		MergeSortTitle(books, 0, end); //Could've just put books.size() instead of end
	}

	void sortBooksByAuthor()
	{
		MergeSort(books, 0, books.size());
	}

	void sortBooksByGenre()
	{
		MergeSort(books, 0, books.size());
	}


	/* 
	Source Title: Advance Sorting Algorithms
	Source Author: Chad McDaniel
	*/

	void MergeSort(vector<Book> books, int start, int end) // I will be changing the Merge function to suit eacb respective function (3 copies). 
	{													   // Same with the MergeSort function (just gotta 	change the respective Merge function (3 copies)
		if (start < end)									// Could have just added an attribute that asks and change which Merge function is used
		{
			int mid = (start + end) / 2;
			MergeSort(books, start, mid);
			MergeSort(books, mid + 1, end);
			Merge(books, start, mid, end);
		}
	}
	void Merge(vector<Book> books, int start, int mid, int end) 
	{
		int p = start, q = mid + 1;
		vector<Book> temp_arr;
		int k = 0;
		for (int i = start; i <= end; i++)
		{
			if (p > mid)
			{
				temp_arr.push_back(books[q]);
				q++;
			}
			else if (q > end)
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else if (p < q)
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else
			{
				temp_arr.push_back(books[q]);
				q++;
			}

			for (int p = 0; p < temp_arr.size(); p++)
			{
				books[start] = temp_arr[p];
				start++;
			}
		}
	}

	void MergeSortTitle(vector<Book> books, int start, int end)  
	{													 
		if (start < end)									
		{
			int mid = (start + end) / 2;
			MergeSortTitle(books, start, mid);
			MergeSortTitle(books, mid + 1, end);
			MergeTitle(books, start, mid, end);
		}
	}
	void MergeTitle(vector<Book> books, int start, int mid, int end)
	{
		int p = start, q = mid + 1;
		vector<Book> temp_arr;
		int k = 0;
		for (int i = start; i <= end; i++)
		{
			if (books[p].compareByTitle(books[mid]))
			{
				temp_arr.push_back(books[q]);
				q++;
			}
			else if (books[q].compareByTitle(books[end]))
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else if (books[p].compareByTitle(books[q]))
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else
			{
				temp_arr.push_back(books[q]);
				q++;
			}

			for (int p = 0; p < temp_arr.size(); p++)
			{
				books[start] = temp_arr[p];
				start++;
			}
		}
	}

	void MergeSortAuthor(vector<Book> books, int start, int end)
	{
		if (start < end)
		{
			int mid = (start + end) / 2;
			MergeSortAuthor(books, start, mid);
			MergeSortAuthor(books, mid + 1, end);
			MergeAuthor(books, start, mid, end);
		}
	}
	void MergeAuthor(vector<Book> books, int start, int mid, int end)
	{
		int p = start, q = mid + 1;
		vector<Book> temp_arr;
		int k = 0;
		for (int i = start; i <= end; i++)
		{
			if (books[p].compareByAuthor(books[mid]))
			{
				temp_arr.push_back(books[q]);
				q++;
			}
			else if (books[q].compareByAuthor(books[end]))
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else if (books[p].compareByAuthor(books[q]))
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else
			{
				temp_arr.push_back(books[q]);
				q++;
			}

			for (int p = 0; p < temp_arr.size(); p++)
			{
				books[start] = temp_arr[p];
				start++;
			}
		}
	}

	void MergeSortGenre(vector<Book> books, int start, int end)
	{
		if (start < end)
		{
			int mid = (start + end) / 2;
			MergeSortGenre(books, start, mid);
			MergeSortGenre(books, mid + 1, end);
			MergeGenre(books, start, mid, end);
		}
	}
	void MergeGenre(vector<Book> books, int start, int mid, int end)
	{
		int p = start, q = mid + 1;
		vector<Book> temp_arr;
		int k = 0;
		for (int i = start; i <= end; i++)
		{
			if (books[p].compareByGenre(books[mid]))
			{
				temp_arr.push_back(books[q]);
				q++;
			}
			else if (books[q].compareByGenre(books[end]))
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else if (books[p].compareByGenre(books[q]))
			{
				temp_arr.push_back(books[p]);
				p++;
			}
			else
			{
				temp_arr.push_back(books[q]);
				q++;
			}

			for (int p = 0; p < temp_arr.size(); p++)
			{
				books[start] = temp_arr[p];
				start++;
			}
		}
	}

};