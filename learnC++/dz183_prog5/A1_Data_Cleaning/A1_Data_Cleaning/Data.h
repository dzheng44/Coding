#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>

using std::string;
using std::cout;
using std::endl;

class Record {
public:
	//following 3 variables are our data
	string name; //hen name
	int date; //format as YYMMDD
	bool verified; //egg layed?

	Record* next;
	Record* previous;

	Record() { 
		next = previous = nullptr;
	}
};

class CoopRecords {
private:
	Record* head;
	Record* tail;
	int count;

public:
	CoopRecords()
	{
		head = tail = nullptr;
		count = 0;
	}

	void createRecord(string newName = "NA", int curDate = 000000, bool eggVerified = 'y') { //creates a new record and adds it to the list
		Record* new_record = new Record();
		new_record->name = newName;
		new_record->date = curDate;
		new_record->verified = eggVerified;

		if (head == nullptr)
			head = tail = new_record;
		else
		{
			tail->next = new_record;
			new_record->previous = tail;
			tail = new_record;
		}

		++count;
	}

	void removeUnverified() { 

 		Record* temp = head;
		
		while (temp != nullptr)
		{
			if (temp->verified != true && temp->previous == nullptr && temp->next != nullptr)
			{
				if (temp->next->next != nullptr)
				{
					temp->next->next->previous = temp->previous;
					--count;
				}
				else
				{
					temp->next = nullptr;
					--count;
				}
			}
			
			else if (temp->verified != true && temp->previous != nullptr && temp->next == nullptr)
			{
				if (temp->previous->previous != nullptr)
				{
					temp->previous->previous->next = temp->next;
					--count;
				}
				else
				{
					temp->previous = nullptr;
					--count;
				}
			}

			else if (temp->verified != true && temp->previous != nullptr && temp->next != nullptr)
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				--count;
			}

			temp = temp->next;

		}

	}

	CoopRecords selectRange(int start, int end) const {
		Record* temp = head;
		CoopRecords newRecord;
		while (temp != nullptr)
		{
			if ((temp->date >= start) && (temp->date <= end))
			{
				newRecord.createRecord(temp->name, temp->date, temp->verified);
			}

			temp = temp->next;
		}
		return newRecord;
	}

	void print() const {
		Record* temp = head;
		
		cout << "There are " << count << " egg records." << endl;
		while (temp != nullptr)
		{
			cout << "Date: " << temp->date;
			cout << "; Hen: " << temp->name;
			cout << "; Verified: " << temp->verified << endl;

			temp = temp->next;
		}
	}

};