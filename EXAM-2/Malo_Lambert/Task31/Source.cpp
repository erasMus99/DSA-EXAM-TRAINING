#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


void prep_and_fill_vector(vector<int>& v, int min, int max)
{
	for (unsigned i = min; i < max; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

priority_queue<int, vector<int>, greater<>> make_queue(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<>> pq;
	for (unsigned i = 0; i < v.size(); i++)
	{
		pq.push(v[i]);
	}
	return pq;
}

int main()
{
	vector<int> v;
	prep_and_fill_vector(v, 1901, 2001);
	priority_queue<int, vector<int>, greater<>> pq = make_queue(v);
	while (!pq.empty())
	{
		if (pq.top() == 2000)
		{
			cout << pq.top() << ".";
			pq.pop();
		}
		else
		{
			cout << pq.top() << ", ";
			pq.pop();
		}
	}
	cout << endl;
	

	return 0;
}