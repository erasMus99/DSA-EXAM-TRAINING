#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

void load_file(ifstream& in, multimap<char, string>& m)
{
	string line;
	while (getline(in, line))
	{
		char c = line[0];
		m.emplace(c, line);
	}
}

int main()
{
	ifstream in("nounlist.csv");
	if (!in)
	{
		cout << "Error while opening the file" << endl;
		return 1;
	}
	multimap<char, string> m;
	load_file(in, m);
	in.close();

	cout << "Enter the first char of the words you want: ";
	char res;
	cin >> res;
	cout << endl;

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		if (it->first == res)
			cout << "Noun Starting with " << it->first << " : " << it->second << endl;
	}


	return 0;
}