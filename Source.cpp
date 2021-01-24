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
void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}
bool printPath (Node *pRoot, int sum)
{
    // base case
    if (sum == 0) {
        return true;
    }
 
    // base case
    if (pRoot == nullptr) {
        return false;
    }
 
    // recur for the left and right subtree with reduced sum
    bool pLeft = printPath(pRoot->pLeft, sum - pRoot->i);
    bool pRight = printPath(pRoot->pRight, sum - pRoot->i);
 
    // print the current node if it lies on a path with a given sum
    if (pLeft || pRight) {
        cout << pRoot->i << " ";
    }
 
    return pLeft || pRight;
}

// Function to calculate the maximum root-to-leaf sum in a binary tree
int rootToLeafSum(Node* pRoot)
{
    // base case: tree is empty
    if (pRoot == nullptr) {
        return 0;
    }
 
    // calculate the maximum node-to-leaf sum for the left child
    int pLeft = rootToLeafSum(pRoot->pLeft);
 
    // calculate the maximum node-to-leaf sum for the right child
    int pRight = rootToLeafSum(pRoot->pRight);
 
    // consider the maximum sum child
    return (pLeft > pRight? pLeft : pRight) + pRoot->i;
}
 void findMaxSumPath(Node *pRoot)
{
    int sum = rootToLeafSum(pRoot);
    cout << "The Maximum sum is " << sum << endl;
    cout << "The Maximum sum path is ";
 
    printPath(pRoot, sum);
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

   PrintTree(pRoot, 1);
   findMaxSumPath(pRoot);

}