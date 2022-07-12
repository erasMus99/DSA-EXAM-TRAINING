#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
	btree tree = btree("a");
	tree.insert_left(tree.root(), "b");
	tree.insert_right(tree.root(), "c");

	node* _c = tree.get_right_child(tree.root());
	tree.insert_right(_c, "d");

	node* _d = tree.get_right_child(_c);
	tree.insert_left(_d, "e");
	tree.insert_right(_d, "f");

	node* _e = tree.get_left_child(_d);
	tree.insert_left(_e, "g");
	tree.insert_right(_e, "h");

	node* _f = tree.get_right_child(_d);
	tree.insert_right(_f, "i");
	
	tree.pretty_print(tree.root(), 2);
	cout << endl;
	tree.preorder(tree.root()); // a b c d e g h f i 
	cout << endl;
	tree.inorder(tree.root()); // b a c g e h d f i 
	cout << endl;
	tree.postorder(tree.root()); // b g h e i f d c a 

	return 0;

}