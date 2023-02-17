/*
Name: David Zheng
NetID: dz183

Program Description: This program will allow multiple functions such as sorting, creating/adding new books, and editing information into a library.
*/
#include "dz183_prog5_CatalogClass.h"
#include <string>

using std::cin;
using std::getline;
using std::cout;
using std::endl;

void populate_catalog(Catalog& my_catalog);
int display_menu();

int main()  //This is from teacher and is based on what prog4 should be on before editing for vectors
{
	Catalog my_catalog;
	populate_catalog(my_catalog);

	cout << "Welcome to the Library!\n";
	int choice = 0;

	do
	{
		cout << "\n\n";
		choice = display_menu();
		cout << "\n\n";

		string input_str;
		int isbn;
		Book book_obj;
		bool result;

		/* ********************************************
			Enter the code for your commands here.
		   ********************************************
		*/

		switch (choice) 
		{
		case 1:
			cout << "What is the title?" << endl;
			cin.ignore();
			getline(cin, input_str);
			result = my_catalog.getBookByTitle(input_str, book_obj);
			if (result == true)
				book_obj.outputBook();
			else
				cout << "Book not found" << endl;
			break;
		case 2:
			cout << "What is the isbn?" << endl;
			cin >> isbn;
			result = my_catalog.getBookByISBN(isbn, book_obj);
			if (result == true)
				book_obj.outputBook();
			else
				cout << "Book not found" << endl;
			break;
		case 3: //did not implement list by genre into the menu due to it not being listed
			cout << "Who is the author?" << endl;
			cin.ignore();
			getline(cin, input_str);
			result = my_catalog.listBookByAuthor(input_str);
			
			break;
		case 4:
			cout << "What is the title of the book?" << endl;
			cin.ignore();
			getline(cin, input_str);
			my_catalog.addBook(input_str);
			break;
		case 5:
			cout << "Which book (title) are you checking?" << endl;
			cin.ignore();	
			getline(cin, input_str);
			result = my_catalog.getBookByTitle(input_str, book_obj);
			if (result == true)
			{
				cout << "0 is false and 1 is true" << endl;
				cout << book_obj.getStatus();
			}
			else
				cout << "Book not found" << endl;
			break;
		case 6:
			cout << "What is the isbn?" << endl;
			cin >> isbn;
			my_catalog.checkInBook(isbn);
			break;
		case 7:
			cout << "What is the isbn?" << endl;
			cin >> isbn;
			cout << "Which book are you checking out?" << endl;
			cin.ignore();
			getline(cin, input_str);
			my_catalog.checkOutBook(isbn, input_str);
			break;
		case 8:
			my_catalog.outputCatalog();
			break;
		case 9:
			my_catalog.sortBooksByTitle();
			break;
		case 10:
			my_catalog.sortBooksByAuthor();
			break;
		case 11:
			my_catalog.sortBooksByGenre();
			break;
		}



	} while (choice >= 1 && choice < 12);

	return 0;
}

int display_menu()
{
	int choice;
	do
	{
		cout << "Main Menu\n";
		cout << "1.  Search by Book Title\n";
		cout << "2.  Search by Book ISBN\n";
		cout << "3.  Output all books by Author\n"; //did not implement list by genre into the menu due to it not being listed
		cout << "4.  Add a New Book to the Catalog\n";
		cout << "5.  Get Check Out Status of Book\n";
		cout << "6.  Check in a book\n";
		cout << "7.  Check out a book\n";
		cout << "8.  Output Catalog\n";
		cout << "9.  Sort Books by Title\n";
		cout << "10.  Sort Books by Author\n";
		cout << "11.  Sort Books by Genre\n";
		cout << "12.  Exit Program\n";

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice < 1 and choice > 12)
		{
			cout << "Error: Not a valid Selection!  ";
		}

	} while (choice < 1 || choice > 12);

	return choice;

}

void populate_catalog(Catalog& my_catalog)
{
	Book temp_obj;
	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Sorcerers Stone");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(98346);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Prisioner of Azkaban");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(88224);
	my_catalog.addBook(temp_obj);


	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Deathly Hallows");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(68304);
	my_catalog.addBook(temp_obj);


	temp_obj.setAuthor("E. B. White");
	temp_obj.setTitle("Charlotte's Web");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(47851);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("F. Scott Fitzgerald");
	temp_obj.setTitle("The Great Gasby");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(34266);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("William Shakespear");
	temp_obj.setTitle("Hamlet");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(55673);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Steinback");
	temp_obj.setTitle("Of Mice and Men");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(28886);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Green");
	temp_obj.setTitle("The Fault in Our Stars");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(31122);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("S. E. Hinton");
	temp_obj.setTitle("The Outsiders");
	temp_obj.setGenre("coming-of-age");
	temp_obj.setISBN(72331);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Andre Aciman");
	temp_obj.setTitle("Call Me by Your Name");
	temp_obj.setGenre("coming-of-age");
	temp_obj.setISBN(94457);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.D. Salinger");
	temp_obj.setTitle("The Catcher in the Rye");
	temp_obj.setGenre("coming-of-age");
	temp_obj.setISBN(55438);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Mary Shelly");
	temp_obj.setTitle("Frankenstien");
	temp_obj.setGenre("science fiction");
	temp_obj.setISBN(32116);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("H. G. Wells");
	temp_obj.setTitle("War of Worlds");
	temp_obj.setGenre("science fiction");
	temp_obj.setISBN(32116);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("H. G. Wells");
	temp_obj.setTitle("The Time Machine");
	temp_obj.setGenre("science fiction");
	temp_obj.setISBN(32116);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Troubled Blood");
	temp_obj.setGenre("crime fiction");
	temp_obj.setISBN(29332);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Grisham");
	temp_obj.setTitle("A Time to Kill");
	temp_obj.setGenre("crime fiction");
	temp_obj.setISBN(32661);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Grisham");
	temp_obj.setTitle("Sycamore Row");
	temp_obj.setGenre("crime fiction");
	temp_obj.setISBN(91023);
	my_catalog.addBook(temp_obj);

	/*
		Feel free to add more books below to experiment
		with the catalog class!
	*/

	return;
}