#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void load_file(ifstream& in, map<string, string>& m)
{
	// Used to store our data
	string line;
	string name;
	string code;

	getline(in, line); // Used as always to skip header
	while (getline(in, line))
	{
		stringstream ss(line); // Used to cut the file
		getline(ss, name, ';'); // Get the name
		getline(ss, code); // Get the Country code

		m[code] = name; // Store in our map as "code : country"
	}
}

// Will be used to search for a country code and print the given country name
void search(map<string, string>& m)
{
	// Lets do it with do while so you can fetch multiple time
	bool loop;
	do
	{
		string code;
		cout << "Enter the country code that you want : ";
		cin >> code;
		cout << endl;

		auto found_name = m.find(code); // Here we try to find the code
		if (found_name != m.end()) // If we find it and it's not the end of the map then print it's value
			cout << found_name->first << " : " << found_name->second << endl;
		else
			cout << "This country code is not linked to any country in the file" << endl;

		cout << "Do you want to search for a new code (0/1) ? ";
		cin >> loop;
		cout << endl;
	} while (loop);

}

int main()
{
	ifstream in("country_codes.csv");
	if (!in)
	{
		cout << "Unable to open the file" << endl;
		return 1;
	}

	map<string, string> m;

	load_file(in, m);
	in.close();

	search(m);

	return 0;
}