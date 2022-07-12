#include "btree.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*************** PRIVATNE METODE ****************/

node* btree::create_new_node(string element)
{
	node* new_node = new node;
	new_node->element = element;
	new_node->left_child = nullptr;
	new_node->right_child = nullptr;

	return new_node;
}

void btree::destroy(node* current)
{
	if (current == NULL)
		return;

	destroy(current->left_child);
	destroy(current->right_child);
	delete current;
}

/*************** JAVNE METODE ****************/

btree::btree(string element)
{
	root_node = create_new_node(element);
}

btree::~btree()
{
	destroy(root_node);
}

void btree::insert_left(node* parent, string element)
{
	parent->left_child = create_new_node(element);
}

void btree::insert_right(node* parent, string element)
{
	parent->right_child = create_new_node(element);
}

node* btree::root()
{
	return root_node;
}

node* btree::get_left_child(node* parent)
{
	return parent->left_child;
}

node* btree::get_right_child(node* parent)
{
	return parent->right_child;
}

// Inorder
void btree::inorder(node* current)
{
	if (current == NULL)
		return;
	// First pass
	inorder(current->left_child);

	cout << current->element << " ";

	// Second pass
	inorder(current->right_child);
}

void btree::preorder(node* current)
{
	if (current == NULL)
		return;

	cout << current->element << " ";

	// First pass
	preorder(current->left_child);

	// Second pass
	preorder(current->right_child);
}

void btree::postorder(node* current)
{
	if (current == NULL)
		return;

	//First pass
	postorder(current->left_child);

	//Second pass
	postorder(current->right_child);

	cout << current->element << " ";
}

void btree::bfs(node* current)
{
	if (current == NULL)
		return;

	// Create the empty queue
	queue<node*> q;

	// Enqueue the current node
	q.push(current);

	while (!q.empty())
	{
		// Pop the node of the queue and make some operation, here printing
		node* n = q.front();
		cout << n->element << " ";
		q.pop();

		// If a left child exist enqueu him
		if (n->left_child)
			q.push(n->left_child);

		// Same for right child.
		if (n->right_child)
			q.push(n->right_child);
	}
}

void btree::pretty_print(node* current, int level)
{
	if (current == NULL)
		return;

	if (level > 0)
	{
		for (int i = 0; i < (level - 1) * 4; i++)
		{
			cout << " ";
		}
		cout << "|---";
	}

	cout << current->element << endl;
	pretty_print(current->left_child, level + 1);
	pretty_print(current->right_child, level + 1);

}