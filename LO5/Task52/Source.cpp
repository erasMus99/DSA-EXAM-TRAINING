#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// My bubble sort
void bubble_sort(vector<int>& v, int n) 
{
	bool sorted;
	for (int i = 0; i < n - 1; i++) {
		sorted = true;
		for (int j = 0; j < n - 1 - i; j++) { // because the rest is sorted.
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				sorted = false;
			}
		}

		if (sorted) {
			break;
		}
	}
}


void prep_vect(vector<int>& v, int min, int max)
{
	for (unsigned i = min; i < max; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

// Function that will create our vector with even first and then odd
void even_and_odd(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		// If even we pass
		if (v[i] % 2 == 0)
			continue;

		//If not run a loop on all the subsequent number
		// and if not even swap then
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] % 2 == 0)
			{
				swap(v[i], v[j]);
			}
		}
	}
}

int main()
{
	// Creating 3 output files
	ofstream out("sorted_ascending.txt");
	ofstream out2("sorted_descending.txt");
	ofstream out3("sorted_even_and_odd.txt");
	if (!out || !out2 || !out3)
	{
		cout << "Error while creating files" << endl;
		return 1;
	}

	//Creating the vector
	vector<int> vec;
	prep_vect(vec, 1, 101);

	// Bubblesort
	bubble_sort(vec, 100);

	// Print for out file ascending
	for_each(vec.begin(), vec.end(), [&](int n)
		{
			out << n << " ";
		});

	/*
	* For me here we have two choice, we can either reverse our sorted vector
	* or change when print to the outfile.
	*/

	//// Another method of doing what is asked but without touching the vector
	//for_each(vec.rbegin(), vec.rend(), [&](int n)
	//	{
	//		out << n << " ";
	//	});

	// Reverse the vector
	reverse(vec.begin(), vec.end());

	// Print for outfile descending
	for_each(vec.begin(), vec.end(), [&](int n)
		{
			out2 << n << " ";
		});

	// Launch our function
	even_and_odd(vec);

	// Print for outfile even_and_odd

	for_each(vec.begin(), vec.end(), [&](int n)
		{
			out3 << n << " ";
		});
	
	return 0;
}