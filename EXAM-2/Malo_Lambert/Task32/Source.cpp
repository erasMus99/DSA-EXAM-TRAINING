#include <iostream>
#include <queue>
#include <vector>
#include "Letter.h";

using namespace std;

bool priority_comparer(Letter l1, Letter l2)
{
	return l1.priority < l2.priority;
}

int main()
{

	vector<Letter> v;
	Letter l1;
	l1.name = "John Smith";
	l1.address = "123 viva l'algérie";
	l1.priority = 2;
	v.push_back(l1);

	Letter l2;
	l1.name = "Maria Hutter";
	l1.address = "26 street of beeing fired";
	l1.priority = 1;
	v.push_back(l2);

	Letter l3;
	l1.name = "Mael Lannic";
	l1.address = "85 street of shame";
	l1.priority = 3;
	v.push_back(l3);

	Letter l4;
	l1.name = "Thomas Eychenne";
	l1.address = "96 street of l'arabe";
	l1.priority = 4;
	v.push_back(l4);

	Letter l5;
	l1.name = "Arthur Gosset";
	l1.address = "102 street BG";
	l1.priority = 5;
	v.push_back(l5);

	priority_queue<Letter, vector<Letter>> pq;
	pq.emplace(l1);
	pq.emplace(l2);
	pq.emplace(l3);
	pq.emplace(l4);
	pq.emplace(l5);

	while (!pq.empty())
	{
		cout << pq.top().name << endl;
		cout << pq.top().address << endl;
		cout << pq.top().priority << endl;
		pq.pop();
	}


	


	return 0;
}