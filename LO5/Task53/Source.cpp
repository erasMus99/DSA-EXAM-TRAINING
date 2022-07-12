#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Here we load our file into our vector
void load_file(ifstream& in, vector<string>& v)
{
	string name; // The name that we will fetch
	while (getline(in, name))
	{
		v.push_back(name);
	}
}

// Creating the comparer for longer words first and then the small ones.
bool length_sort(string str1, string str2)
{
	return str1.length() > str2.length();
}

int main()
{
	ifstream in("people.txt");
	if (!in)
	{
		cout << "Error when opening the file" << endl;
		return 1;
	}

	vector<string> vec;
	load_file(in, vec);
	in.close();

	stable_sort(vec.begin(), vec.end(), length_sort); // Here we use stable sort with the comparer created before
	// Why stable_sort, because it preserve the original order for the equivalent elements

	// Printing our names with, as always, lambda function :)
	for_each(vec.begin(), vec.end(), [&](string name)
		{
			cout << name << endl;
		});

	return 0;
}
