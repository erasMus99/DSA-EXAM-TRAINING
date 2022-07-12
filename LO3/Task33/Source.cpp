#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

priority_queue<int, vector<int>, greater<int>> fill_numbers(unsigned n, int min, int max)
{
	srand(time(nullptr));
	priority_queue<int, vector<int>, greater<int>> pq;
	for (unsigned i = 0; i < n; i++)
	{
		pq.push(generate_random(min, max));
	}
	return pq;
}

priority_queue<int, vector<int>> fill_numbers_desc(unsigned n, int min, int max)
{
	srand(time(nullptr));
	priority_queue<int, vector<int>> pq;
	for (unsigned i = 0; i < n; i++)
	{
		pq.push(generate_random(min, max));
	}
	return pq;
}

int main()
{
	cout << "Please choose your direction: ASC or DESC ";
	string choice;
	cin >> choice;

	if (choice == "ASC")
	{
		priority_queue<int, vector<int>, greater<int>> pq = fill_numbers(10, 1, 100);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
		return 0;
	}
	else if (choice == "DESC")
	{
		priority_queue<int, vector<int>> pq2 = fill_numbers_desc(10, 1, 100);
		while (!pq2.empty())
		{
			cout << pq2.top() << " ";
			pq2.pop();
		}
		cout << endl;
		return 0;
	}
	return 0;
}