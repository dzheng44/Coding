#pragma once
#include <string>

using std::string;

class structures // rename this to task and create another data structure. This file is for all data structures
{
private:
	string name;
	// I still need to add when the task was created and finish (2 things)
	string decription;
	structures* next;
	structures* previous;
public:
	structures(string name = "N/a", string desciption = "N/a")
	{
		next = nullptr;
		previous = nullptr;
	}


};