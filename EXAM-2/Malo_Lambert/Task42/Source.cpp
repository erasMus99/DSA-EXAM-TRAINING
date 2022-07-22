#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void load_set(set<int>& s)
{
	for (unsigned i = 0; i < 100; i++)
	{
		s.emplace(i);
	}
}
int main()
{
	set<int> s;
	load_set(s);
	bool again;
	do
	{
		int number;
		cout << "Enter a new number: ";
		cin >> number;

		if (s.find(number) != s.end())
			cout << "Number already exists" << endl;
		
		s.emplace(number);

		cout << "Again ?(0/1)";
		cin >> again;

	} while (again);
	return 0;
}