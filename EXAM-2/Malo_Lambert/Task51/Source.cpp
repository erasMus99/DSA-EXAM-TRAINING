#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void load_file(ifstream& in, vector<string>& v)
{
	string word;
	while (getline(in, word))
	{
		v.push_back(word);
	}
}

bool length_sort(string str1, string str2)
{
	return str1.length() < str2.length();
}

int main()
{
	ifstream in("nounlist.csv");
	if (!in)
	{
		cout << "Error while opening the file" << endl;
		return 1;
	}
	vector<string> v;
	load_file(in, v);
	in.close();

	stable_sort(v.begin(), v.end(), length_sort);

	for_each(v.begin(), v.end(), [&](string noun)
		{
			cout << noun << endl;
		});

	return 0;
}
