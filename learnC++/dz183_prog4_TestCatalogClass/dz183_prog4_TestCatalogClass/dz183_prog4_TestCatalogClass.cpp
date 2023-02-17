#include "dz183_prog4_CatalogClass.h"
#include <string>

using std::cin;
using std::getline;
using std::endl;

void populate_catalog(Catalog& my_catalog);
int display_menu();

int main()
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

		string title = NULL;
		string author = NULL;
		string new_book = NULL;
		string user = NULL;
		Book& Location = nullptr; // maybe need to have to this update within the menu part...
		Book new_book;

		switch (choice) //the 5 variables above were placed above due to it causing my menu to mess up
		{
		case 1: //Search Catalog
			int search;
			cout << "Search by 1) Title or 2) ISBN" << endl;
			cin >> search;
			if (search == 1)
			{
				string title;
				Book location;
				cout << "What is the book title?" << endl;
				cin.ignore();
				getline(cin, title);
				my_catalog.getBookByTitle(title, location); //not sure what the second parameter is...
				location.outputBook();
			}
			else if (search == 2)
			{
				int isbn;
				Book location;
				cout << "What is the ISBN?" << endl;
				cin >> isbn;
				bool check = my_catalog.getBookByISBN(isbn, location);
				if (check == 1)
				{
					cout << "Book found.";
					location.outputBook();
				}
				else {
					cout << "Book not found";
				}
			}
			break;
		case 2: //list books by author
			cout << "Who is the Author?" << endl;
			cin.ignore();
			getline(cin, author);
			bool aut;
			aut = my_catalog.listBooksByAuthor(author);
			if (aut == false) cout << "No books by this author found in catalog." << endl;
			break;
		case 3:  //add a new book to the catalog 
			int isbn;
			cout << "Enter the following information for the new book." << endl;
			cout << "Title:" << endl;
			getline(cin, title);
			cout << "Author: " << endl;
			getline(cin, author);
			cout << "Enter book ISBN: " << endl;
			cin >> isbn;
			new_book.setTitle(title); //if you create a new Book object in the case, it breaks the switch/menu, but if it's outside it breaks the methods...
			new_book.setAuthor(author);
			new_book.setISBN(isbn);
			my_catalog.addBook(new_book);
			break;
		case 4: // get book status
			int isbn;
			cout << "What is the ISBN?" << endl;
			cin >> isbn;
			my_catalog.getBookByISBN(isbn, Location);
			Location.getStatus();
			break;
		case 5: // check in book
			int isbn5;
			cout << "What is the ISBN?" << endl;
			cin >> isbn;
			bool success = my_catalog.checkInBook(isbn5);
			if (success == true)
				cout << "Book successfully checked in." << endl;
			else
				cout << "Book unsuccessfully checked in.";
			break;
		case 6: // check out book
			int isbn6;
			cout << "What is the ISBN?" << endl;
			cin >> isbn;
			bool foundBook = my_catalog.getBookByISBN(isbn, Location);
			if (foundBook != true) {
				cout << "Book not found " << endl;
			break;
			}
			cout << "Who is checking out?" << endl;
			cin.ignore();
			getline(cin, user);
			bool success = my_catalog.checkOutBook(isbn, user);
			if (success) 
				cout << "Book susccessfully checked out.";
			else 
				cout << "Book not checked out successfully.";
			break;
		case 7:
			choice = 8; //This should break the do-while loop; could maybe use exit(1)?
			break;
		default:
			cout << "Error: Not a valid Selection! Error in display_menu! ";
		}

	} while (choice >= 1 && choice < 8);

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
		cout << "3.  Output all books by Author\n";
		cout << "4.  Add a New Book to the Catalog\n";
		cout << "5.  Get Check Out Status of Book\n";
		cout << "6.  Check in a book\n";
		cout << "7.  Check out a book\n";
		cout << "8.  Exit Program\n";

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice < 1 and choice > 8)
		{
			cout << "Error: Not a valid Selection!  ";
		}

	} while (choice < 1 || choice > 8);

	return choice;

}

void populate_catalog(Catalog& my_catalog)
{
	Book temp_obj;
	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Sorcerers Stone");
	temp_obj.setISBN(98346);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Chamber of Secrets");
	temp_obj.setISBN(19285);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Prisioner of Azkaban");
	temp_obj.setISBN(88224);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Goblet of Fire");
	temp_obj.setISBN(21001);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Order of Phoenix");
	temp_obj.setISBN(66754);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Half-Blood Prince");
	temp_obj.setISBN(50125);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Deathly Hallows");
	temp_obj.setISBN(68304);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Lion, the Witch, and the Wardrobe");
	temp_obj.setISBN(45336);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("Prince Caspian");
	temp_obj.setISBN(76689);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Voyage of the Dawn Treader");
	temp_obj.setISBN(34982);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Silver Chair");
	temp_obj.setISBN(45993);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("A Horse and His Boy");
	temp_obj.setISBN(42398);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Magician's Nephew");
	temp_obj.setISBN(39203);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("TheLast Battle");
	temp_obj.setISBN(56342);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("E. B. White");
	temp_obj.setTitle("Charlotte's Web");
	temp_obj.setISBN(47851);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("F. Scott Fitzgerald");
	temp_obj.setTitle("The Great Gasby");
	temp_obj.setISBN(11934);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("S. E. Hinton");
	temp_obj.setTitle("The Outsiders");
	temp_obj.setISBN(72331);
	my_catalog.addBook(temp_obj);

	/*
		Feel free to add more books below to experiment
		with the catalog class!
	*/
}