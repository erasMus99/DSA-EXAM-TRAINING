#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


using namespace std;

// Created a template class using a predicated
template<class RandomAccessIt, class Predicate = std::less<>> inline
void heap_sort(RandomAccessIt first, RandomAccessIt last, Predicate predicate = Predicate())
{
	std::make_heap(first, last, predicate);
	std::sort_heap(first, last, predicate);
}
int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

/*
* Other answer for descending order
* while (!vec.empty())
* {
*		cout << vec.front() << " ";
*		pop_heap(vec.begin(), vec.end());
*		vec.pop_back();
* }
*/

vector<int>  fill_vector(unsigned number, int min, int max)
{
	srand(time(nullptr));
	vector<int> vec;
	for (unsigned int i = 0; i < number; i++)
	{
		vec.push_back(generate_random(min, max));
	}
	return vec;
}


void choice_func(vector<int>& vec)
{
	cout << "Please choose your direction: ASC or DESC ";
	string choice;
	cin >> choice;

	if (choice == "ASC")
	{
		// Making an heap organisation
		make_heap(vec.begin(), vec.end());

		// Sort the Heap for ascending order
		sort_heap(vec.begin(), vec.end());

		for_each(vec.begin(), vec.end(), [&](int n)
			{
				cout << n << " ";
			});
		cout << endl;
	}
	else if (choice == "DESC")
	{
		// Using our template to make the heap with the greater predicate (comp)
		// then sorting using the same predicate (no error ehehe)
		heap_sort(vec.begin(), vec.end(), greater<>());
		for_each(vec.begin(), vec.end(), [&](int n)
			{
				cout << n << " ";
			});
		cout << endl;
	}
	else
		cout << "No correct choice were made. Goodbye" << endl;
}


int main()
{
	// Creating the vector and filling it up
	vector<int> vec = fill_vector(10, 1, 100);

	// Launch choice function
	choice_func(vec);

}