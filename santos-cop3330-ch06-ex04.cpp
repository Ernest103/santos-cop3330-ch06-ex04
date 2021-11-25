/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Ernesto Santos
 */


#include <iostream>
#include <vector>
using namespace std;

class Name_value
{
public:
	Name_value(string name, string value)
	{
		this->name = name;
		this->value = value;
	}

	string name;
	string value;
};


bool isRepeat(vector<Name_value> list, Name_value check);
void printList(vector<Name_value> list);

int main()
{
	vector<Name_value> list;
	string name, value;

	cout << "Enter a Name followed by an intiger value \n"
		<< "To quit enter 'NoName' followed by '0'\n";

	
	do
	{
		cin >> name >> value;
		if (name == "NoName" && value == "0")
			break;
		Name_value temp(name, value);

		if (!isRepeat(list, temp))
		{
			list.push_back(temp);
		}
		else {
			cout << "Repeated name was not added!";
		}

	} while (true);


	cout << "\n All the names in your list are: \n";
	printList(list);
}

void printList(vector<Name_value> list)
{
	for (Name_value item : list)
	{
		cout << item.name << " " << item.value << "\n";
	}
}


bool isRepeat(vector<Name_value> list, Name_value check)
{

	for (Name_value item : list)
	{
		if (item.name == check.name)
			return true;
	}

	return false;
}


/*Ex 04
* Define a class Name_value that holds a string and a
value. Rework exercise 19 in Chapter 4 to use a
vector<Name_value> instead of two vectors.

exercise 19:
Write a program where you first enter a set of name and-
value pairs, such as Joe 17 and Barbara 22. For each
pair, add the name to a vector called names and the
number to a vector called scores (in corresponding
positions, so that if names[7]=="Joe" then scores[7]==17).
Terminate input with NoName 0. Check that each name
is unique and terminate with an error message if a
name is entered twice. Write out all the (name,score)
pairs, one per line.
*/