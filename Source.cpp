
#include <iostream>

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
}
bool printPath (Node *root, int sum)
{
    // base case
    if (sum == 0) {
        return true;
    }
 
    // base case
    if (root == nullptr) {
        return false;
    }
 
    // recur for the left and right subtree with reduced sum
    bool left = printPath(root->left, sum - root->data);
    bool right = printPath(root->right, sum - root->data);
 
    // print the current node if it lies on a path with a given sum
    if (left || right) {
        cout << root->data << " ";
    }
 
    return left || right;
}




int main()
{

int i;

	Node* pRoot = nullptr;
	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
	}









}