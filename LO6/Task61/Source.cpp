#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	// We create our boolean for the  permanent loop
	bool again;
	// Our unordered multi-set
	unordered_multiset<int> ms;
	int current = 1; // Used to know at which number insertion we are
	int limit = 22;
	do
	{
		while (current <= limit)
		{
			ms.insert(current++);
		}
		limit += 22;

		// Displaying the multiset bucket
		for (unsigned i = 0; i < ms.bucket_count(); i++)
		{
			cout << "Bucket: " << i << " ( " <<  ms.bucket_size(i) << " elements" << " )" << endl;
		}

		cout << "Number of elements: " << ms.size() << endl;
		cout << "Number of buckets : " << ms.bucket_count() << endl;

		cout << "Do you want to add more ? (0/1) ";
		cin >> again;
		system("cls");
	} while (again);

	return 0;

}