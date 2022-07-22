#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void display_choice()
{
	cout << "Here is what you can do :" << endl;
	cout << "Choose 1 for saving a new book" << endl;
	cout << "Choose 2 to display book based on it's ISBN" << endl;
	cout << "Choose 3 to remove a book based on the ISBN" << endl;
	cout << "Choose 4 to display all registered books" << endl;
}

void save_book(unordered_map<long int, string>& m)
{
	string book_name;
	long int ISBN;
	cout << "Enter book name: ";
	cin >> book_name;
	cout << endl;
	cout << "Enter corresponding ISBN: ";
	cin >> ISBN;
	
	m[ISBN] = book_name;
	
}

void display_by_ISBN(unordered_map<long int, string>& m)
{
	long int ISBN;
	cout << "Enter the ISBN of the book you're looking for: ";
	cin >> ISBN;
	cout << endl;
	auto it = m.find(ISBN);
	if (it != m.end())
		cout << "The book with the ISBN " << it->first << " is " << it->second << endl;
	else
		cout << "No corresponding ISBN in our database" << endl;
}

void remove_by_ISBN(unordered_map<long int, string>& m)
{
	long int ISBN;
	cout << "Enter the ISBN of the book you want to remove: ";
	cin >> ISBN;
	cout << endl;
	m.erase(ISBN);
}

void display_all(unordered_map<long int, string>& m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << "ISBN: " << it->first << " Name: " << it->second << endl;
	}
}

int main()
{
	unordered_map<long int, string> m;
	bool again;
	do
	{
		system("cls");
		display_choice();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			save_book(m);
			break;
		case 2:
			display_by_ISBN(m);
			break;
		case 3:
			remove_by_ISBN(m);
			break;
		case 4:
			display_all(m);

		}

		cout << "Again ? (0/1) ";
		cin >> again;

	} while (again);

	return 0;
}