#include <iostream>
#include <fstream>
#include <sstream>
#include "merge_sort.h"
#include "rectangle.h"

using namespace std;

/*
* For the first question of Task51 I decided to choose merge sort as it as a worst case complexity of O(n log(n)) which
* is much better than some other. This will be the algorithm used to sort this rectangle file
*/

void load_file(ifstream& in, rectangle* rec_arr, const int nbr_of_rectangle)
{
	for (int i = 0; i < nbr_of_rectangle; i++)
	{
		// Here we use our structur array and put the corresponding values inside
		in >> rec_arr[i].a >> rec_arr[i].b;
	}
}

// Print in our file
void print(ofstream& out, rectangle* rec_arr, const int nbr_of_rectangle)
{
	for (int i = 0; i < nbr_of_rectangle; i++)
	{
		out << rec_arr[i].a << " " << rec_arr[i].b << endl;
	}
}

int main()
{
	ifstream in("rectangles.txt");
	ofstream out("sorted_rectangle.txt");

	if (!in || !out)
	{
		cout << "There was an error when opening or creating the file" << endl;
		return 1;
	}

	const int nbr_of_rectangle = 1000; // This will serve as a constant because the number of rectangle won't change

	// Let's create an array of our structure so that we can load
	// the corresponding values at a given time here we have rec_arr[i].a rec_arr[i].b 
	rectangle* rec_arr = new rectangle[nbr_of_rectangle];

	load_file(in, rec_arr, nbr_of_rectangle); // We load our array

	in.close(); // Closing our file

	merge_sort(rec_arr, nbr_of_rectangle);

	print(out, rec_arr, nbr_of_rectangle);
	out.close(); // We close our written file

	return 0;
}