/**
    Derek J. Russell
    Professor Jonathan Traugott
    Binary Seacrh Trees - (Assignment 4)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: March 1st, 2018
    ===========================================

    - In computer science, binary search trees (BST), sometimes called ordered or sorted binary trees,
      are a particular type of container: data structures that store "items" (such as numbers, names etc.)
      in memory. They allow fast lookup, addition and removal of items, and can be used to implement
      either dynamic sets of items, or lookup tables that allow finding an item by its key (e.g., finding
      the phone number of a person by name).

    - Binary search trees keep their keys in sorted order, so that lookup and other operations can use
      the principle of binary search: when looking for a key in a tree (or a place to insert a new key),
      they traverse the tree from root to leaf, making comparisons to keys stored in the nodes of the
      tree and deciding, on the basis of the comparison, to continue searching in the left or right subtrees.
      On average, this means that each comparison allows the operations to skip about half of the tree, so
      that each lookup, insertion or deletion takes time proportional to the logarithm of the number of
      items stored in the tree. This is much better than the linear time required to find items by key in
      an (unsorted) array, but slower than the corresponding operations on hash tables.
**/
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
Node * CreateNode(int data, Node *left = nullptr, Node * right = nullptr)
{
    Node *root = new Node;
    root->data = data;
    root->left = left;
    root->right = right;

    return root;
}
// Make a random tree with height <= maxheight.
Node * makeTree(int maxheight)
{
    if(maxheight <= 0)
        return nullptr;

    Node * p = rand() % 5 != 0 ? makeTree(maxheight - 1) : nullptr;
    Node * q = rand() % 5 != 0 ? makeTree(maxheight - 1) : nullptr;
    return CreateNode(rand() % 16, p, q);
}
void DrawTree(Node * p, int Indentation = 0)
{
    int dashes = 3;

    for(int count = 0; count < Indentation; count++) cout << " ";

    if(p != nullptr)
    {
        for(int j = 0; j < dashes; j++) cout << "-";
        cout << p->data << endl;
        DrawTree(p->left,  Indentation + 5);
        DrawTree(p->right, Indentation + 5);
    }
    else cout << "~" << endl;
}
int Height(Node *root) // Return height of tree. (Empty tree has height 0.)

{
    if(root == nullptr) // If the tree is empty.
    {
        return 0;

    }
    int Height_1 = Height(root->left), Height_2 = Height(root->right);
    return Height_1 > Height_2 ? Height_1 + 1 : Height_2 + 1;
}
int size(Node *root) // Return number of nodes in the tree.
{
    if(root == nullptr) return 0;
    return (1 + size(root->left) + size(root->right));
}
bool isPerfect(Node *root) // All levels full meaning it has maximum possible nodes for the given height (size = 2^height - 1).
{
    if(root == nullptr)
        return true;

    int Height_1 = Height(root->left);
    int Height_2 = Height(root->right);

    if(Height_1 != Height_2)
        return false;

    return (isPerfect(root->left) && isPerfect(root->right));
}
bool isComplete(Node *root) // All levels full expect possibly bottom level. Nodes on bottom level are filled  in from the left.
{
    if(root == nullptr)
        return (true);

    int Height_1 = Height(root->left);
    int Height_2 = Height(root->right);

    if(!(Height_1 == Height_2 || Height_1 == Height_2 + 1))
                        return (false);

    if(Height_1 == Height_2)
        return (isPerfect(root->left) && isComplete(root->right));
}
bool isDegenerate(Node *root)
{
    // Return if the tree is degenerate and false otherwise.
    if(root == nullptr)
        return (true);

    if(root->left != nullptr && root->right != nullptr)
        return (false);

    if(root->left == nullptr)
        return isDegenerate(root->right);
    else
        return isDegenerate(root->left);
}
// Returns true if the given tree is BST and its values are >= min and <= max.
int isBST_UTil(struct Node *Node, int min, int max)
{
    // An Empty Tree is BST.
    if(Node == nullptr)
        return 1;

    // False if this node violates the min/max constraint.
    if(Node->data < min || Node->data > max)
        return 0;

    // Otherwise, check the subtrees recursively, tightening the min or max constraint.
    return (isBST_UTil(Node->left, min, Node->data - 1) && isBST_UTil(Node->right, Node->data + 1, max));
}
// Returns true if the given tree is a Binary Search Tree (efficient code).
int isBST(struct Node *Node)
{
    return(isBST_UTil(Node, INT_MIN, INT_MAX));
}
// Left and right subtrees are balanced and heights of those subtrees different by at most 1.
bool isBalanced(Node *root)
{
    if(root == nullptr)
        return (true);

    int Height_1 = Height(root->left);
    int Height_2 = Height(root->right);

    if((Height_1 - Height_2 > 1) || (Height_2 - Height_1 > 1))
                        return (false);

    return (isBalanced(root->left) && isBalanced(root->right));
}
// Return length of shortest path root to leaf.
int shortestPath(Node *root)
{
    // Corner case. Should never be hit unless the code is called on root == nullptr.
    if(root == nullptr)
        return -1;

    // Base case: Leaf Node. This accounts for height = 1.
    if(root->left == nullptr && root->right == nullptr)
        return 0;

    // If left subtree is nullptr, recursive for right subtree.
    if(!root->left)
        return shortestPath(root->right) + 1;

    // If right subtree is nullptr, recursive for right subtree.
    if(!root->right)
        return shortestPath(root->left) + 1;

    return min(shortestPath(root->left), shortestPath(root->left)) + 1;
}
// Delete all Nodes recursively.
void deleteTree(struct Node *tree)
{
    if(tree == nullptr) // If the tree is empty.
        return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}
// Output values using level order traversal. Using an STL queue.
void levelOrder(Node *p)
{
    if(p == nullptr) // Base Case.
        return;

    queue<Node *> q; // Created an empty queue for level order traversal.
    q.push(p); // Enqueue P and initialize height.

    while(q.empty() == false)
    {
        // Print front of queue and remove it from queue.
        Node *Node = q.front();
        cout << Node->data << " ";
        q.pop();
        // Enqueue left child.
        if(Node->left != nullptr)
            q.push(Node->left);
        // Enqueue right child.
        if(Node->right != nullptr)
            q.push(Node->right);
    } return;
}
// Output values using an inOrder Traversal.
void inOrder(Node *p)
{
    if(p != nullptr)
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}
// Output values using a postOrder Traversal.
void postOrder(Node *p)
{
    if(p != nullptr)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    } return;
}
// Output values using a preOrder Traversal.
void preOrder(Node *p)
{
    if(p != nullptr)
    {
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);
    } return;
}
// Return the maximum value in the tree.
int getMax(struct Node *root)
{
      // Base Case.
      if(root == nullptr)
        return INT_MIN;
      /**
        Return maximum of 3 values:

            1.) Root's data.
            2.) Max in Left Subtree.
            3.) Max in Right Subtree.
      **/
      int SubTree = root->data;
      int Left_SubTree  = getMax(root->left);
      int Right_SubTree = getMax(root->right);

      if(Left_SubTree > SubTree)
            SubTree = Left_SubTree;

      if(Right_SubTree > SubTree)
        SubTree = Right_SubTree;

      return SubTree;
}
 // Return the minimum value in the tree.
int getMin(struct Node *root)
{
    // Base Case.
    if(root == nullptr)
        return INT_MAX;
    /**
        Return minimum of 3 values:
            1.) Root's data.
            2.) Max in Left Subtree.
            3.) Max in Right Subtree.
    **/
    int SubTree = root->data;
    int Left_SubTree  = getMin(root->left);
    int Right_SubTree = getMin(root->right);

    if(Left_SubTree < SubTree)
            SubTree = Left_SubTree;

    if(Right_SubTree < SubTree)
        SubTree = Right_SubTree;

    return SubTree;
}
int main()
{
    srand((unsigned int) time(0));  // you need to  #include <ctime> to use time(0)
    bool done = false;
    while (!done)
    {
        int maxHeight;
        cout << "Enter the Maximum Height? (or -1 to quit): ";
        cin >> maxHeight;
        if (maxHeight <= -1)
           done = true;
        else
        {
            Node * p = makeTree(maxHeight);
            DrawTree(p);

            cout << "Height: " << Height(p) << endl << endl;
            cout << "Size: " << size(p) << endl << endl;
            cout << "isPerfect: " << isPerfect(p) << endl << endl;
            cout << "isComplete: " << isComplete(p) << endl << endl;
            cout << "isDegenerate: " << isDegenerate(p) << endl << endl;
            cout << "isBST: " << isBST(p) << endl << endl;
            cout << "isBalanced: " << isBalanced(p) << endl << endl;
            cout << "shortestPath: " << shortestPath(p) << endl << endl;
            cout << "levelOrder: ";
            levelOrder(p);
            cout << endl << endl;
            cout << "inOrder: ";
            inOrder(p);
            cout << endl << endl;
            cout << "postOrder: ";
            postOrder(p);
            cout << endl << endl;
            cout << "preOrder: ";
            preOrder(p);
            cout << endl << endl;
            cout << "getMax: " << getMax(p) << endl << endl;
            // Test your functions on the current tree p.
            deleteTree(p); // you write it
        }
    }
    return 0;
}
