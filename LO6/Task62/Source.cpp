#include<iostream> 
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
T convert(string& s)
{
	stringstream converter(s);
	T result;
	converter >> result;
	return result;
}

void load_file(ifstream& in, unordered_map<string, int>& m)
{
	string line;
	string name;
	string temp; 
	int number;
	while (getline(in, line))
	{
		stringstream ss(line);
		getline(ss, name, ',');
		getline(ss, temp, ',');
		getline(ss, temp, ',');
		number = convert<int>(temp);

		m[name] = number;
	}
}

int main()
{
	ifstream in("yob1981.txt");
	ofstream out("Number_of_names.txt");

	if (!in || !out)
	{
		cout << "Unable to open one of the files" << endl;
		return 1;
	}

	unordered_map<string, int> m;
	load_file(in, m);
	in.close();

	long long int result = 0;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		result += it->second;
	}

	out << "The total number of name is " << result << endl;
	out.close();

	return 0;
}