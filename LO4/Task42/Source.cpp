#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void load_file(ifstream& in, map<char, int>& m)
{
	string line;
	while (getline(in, line)) // We fetch our line
	{
		// Now we need to go bye every char and do an histogram
		for (unsigned int i = 0; i < line.length(); i++)
		{
			// We create our char that will be our key
			char c = line[i];
			m[c]++; // We had one to our map every time that we pass on the same char;
		}
	}
}

int main()
{
	ifstream in("country_codes.csv");
	if (!in)
	{
		cout << "Unable to open the file" << endl;
		return 1;
	}

	// Creating our map
	map<char, int> m;

	// Loading and closing our file inside the map
	load_file(in, m);
	in.close();

	// Print all our map to see the char
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " has " << it->second << " character" << endl;
	}

	return 0;
}