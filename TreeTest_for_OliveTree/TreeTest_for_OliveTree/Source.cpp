#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class tree_Node {
private:
	//each node has a data value holding the actual value associated with that node as well as 2 pointewrs for its children
	int data;
	tree_Node* left;
	tree_Node* right;


public:
	//constructor allows for NULL entries for left and right, since those are very real possibilities
	tree_Node(int data, tree_Node* left, tree_Node* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	bool checkSameAs(tree_Node* compared) {
		//if main nodes' data values don't match, return false
		if (data != compared->getData())
			return false;
		//if one node's left child is NULL and the other's is not return false
		if ((left != NULL && compared->left == NULL) || (left == NULL && compared->getLeft() != NULL))
			return false;
		//if both nodes' left children are NULL do nothing so that checkSameAs will not try to run on a non-existant node
		else if (left == NULL && compared->getLeft() == NULL) {}
		//if both nodes' left children exist, run this function on them (recursively), if they do not match, neither do these nodes - return false
		else if (!left->checkSameAs(compared->getLeft()))
			return false;
		//if one node's right child is NULL and the other's is not return false
		if ((right != NULL && compared->getRight() == NULL) || (right == NULL && compared->getRight() != NULL))
			return false;
		//if both nodes' right children are NULL do nothing so that checkSameAs will not try to run on a non-existant node
		else if (right == NULL && compared->getRight() == NULL) {}
		//if both nodes' right children exist, run this function on them (recursively), if they do not match, neither do these nodes - return false
		else if (!right->checkSameAs(compared->getRight()))
			return false;
		//if nothing has prompted a false return, return true
		return true;
	}
	//allows the data value to be returned without being editable outside of the class
	int getData() {
		return data;
	}
	//passes the left child
	tree_Node* getLeft() {
		return left;
	}
	//passes the right child
	tree_Node* getRight() {
		return right;
	}
};

void main() {}
