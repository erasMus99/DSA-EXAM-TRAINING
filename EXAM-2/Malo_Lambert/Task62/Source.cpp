#include <iostream>
#include <unordered_set>

using namespace std;

void fill_with_prime(unordered_multiset<int>& ms)
{
	for (unsigned i = 1; i < 1000; i++)
	{
        int n, j, m = 0;
        int flag = 0;
        m = i / 2;
        for (j = 2; j <= m; j++)
        {
            if (i % j == 0)
                flag = 1;
                break;
            
        }
        if (flag == 0)
            ms.emplace(i);
	}
}

int main()
{
	// Our unordered multi-set
	unordered_multiset<int> ms;

	// Displaying the multiset bucket
	for (unsigned i = 0; i < ms.bucket_count(); i++)
	{
		cout << "Bucket: " << i << " ( " << ms.bucket_size(i) << " elements" << " )" << endl;
	}

	cout << "Number of elements: " << ms.size() << endl;
	cout << "Number of buckets : " << ms.bucket_count() << endl;


	return 0;

}