// driver.cpp
// Testing driver for Assignment 1

#include <iostream>
#include <locale>
#include <string>
#include <list>

// You will provide this header
#include "Data.h"

using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::string;
using std::locale;
using std::tolower;
using std::list;

int main()
{
    // For use with std::tolower (see documentation)
    std::locale loc;

    // Our CoopRecords
    CoopRecords records;

    string prompt;
    do
    {
        // Name
        string hen;
        cout << "What is the hen's name? ";
        getline(cin, hen);  // Using getline allows spaces in name

        // Date
        unsigned int date = 0;
        do
        {
            // Clear any error state
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            cout << "What date did the hen lay [YYMMDD format]? ";
            cin >> date;
        } while (date <= 0);

        cout << "Was the laying verified? [Y/N]";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush newlines
        getline(cin, prompt);
        bool verified = tolower(prompt[0], loc) == 'y';

        // Add to CoopRecords
        records.createRecord(hen, date, verified);

        // Continue?
        cout << "Are there more eggs [Y/N]? ";
        getline(cin, prompt);
    } while (tolower(prompt[0], loc) == 'y');

    // Print the unfiltered set
    cout << "Before removal" << endl;
    records.print();

    // Remove unverified and print again
    records.removeUnverified();

    cout << "\nAfter unverified removal" << endl;
    records.print();

    // Set a date range for May 2021 only
    CoopRecords mayRecords = records.selectRange(210501, 210531);
    cout << "\nEggs laid in May 2021" << endl;
    mayRecords.print();

    return 0;
}