#include <iostream>
#include <math.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int height(node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
void printLeafs(node *root)
{
    if (root == NULL)
        return;
    else if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeafs(root->left);
    printLeafs(root->right);
}
node *buildTree(node *root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter in left of " << data << "..." << endl;
    root->left = buildTree(root->left);
    cout << "Enter in right of " << data << "..." << endl;
    root->right = buildTree(root->right);
   // return root;
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 25 20 10 5 -1 -1 12 -1 -1 22 -1 -1 36 30 28 -1 -1 -1 40 38 -1 -1 48 -1 -1
    cout << endl;
    int val;
    do
    {
        cout << "1.Enter 1 for inorder traversal " << endl;
        cout << "2.Enter 2 for preorder traversal " << endl;
        cout << "3.Enter 3 for postorder traversal " << endl;
        cout << "4.Enter 4 for height of tree " << endl;
        cout << "5.Enter 5 for printing leaf nodes " << endl;
        cout << "6.Enter 6 for exit " << endl;
        cout << "Enter val : ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            cout << "Printing inorder traversal..." << endl;
            inorder(root);
            cout << endl;
        }
        break;
        case 2:
        {
            cout << "Printing preorder traversal..." << endl;
            preorder(root);
            cout << endl;
        }
        break;
        case 3:
        {
            cout << "Printing postorder traversal..." << endl;
            postorder(root);
            cout << endl;
        }
        break;
        case 4:
        {
            cout << "The height of the tree of : " << height(root);
            cout << endl;
        }
        break;
        case 5:
        {
            cout << "Printing the leaf Nodes..." << endl;
            printLeafs(root);
            cout << endl;
        }
        }
    } while (val != 6);
}