#include <iostream>
#include "merge_sort.h"

using namespace std;

// We change the definition to class the rectangle
void merge(rectangle* array1, int na, rectangle* array2, int nb) {
	rectangle* array3 = new rectangle[na + nb];

	int ia = 0, ib = 0;
	for (int ic = 0; ic < na + nb; ic++) {
		if (ia == na) { // we are done with array1
			array3[ic] = array2[ib++];
			continue;
		}
		if (ib == nb) { // we are done with array2.
			array3[ic] = array1[ia++];
			continue;
		}

		// Here we calculate the rectangle area size to have a valid sorting base
		if (array1[ia].area() < array2[ib].area()) {
			array3[ic] = array1[ia++];
		}
		else {
			array3[ic] = array2[ib++];
		}
	}

	for (int i = 0; i < na + nb; i++) {
		array1[i] = array3[i];
	}

	delete[] array3;
}

void merge_sort(rectangle data[], int from, int to) {
	if (from == to) { // stop recursion.
		return;
	}

	int mid = (from + to) / 2;
	merge_sort(data, from, mid);
	merge_sort(data, mid + 1, to);

	merge(data + from, mid - from + 1, data + mid + 1, to - mid);
}

void merge_sort(rectangle data[], int n) {
	merge_sort(data, 0, n - 1);
}