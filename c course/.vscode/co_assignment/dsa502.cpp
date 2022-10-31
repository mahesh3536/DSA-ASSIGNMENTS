#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
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
node *insertinbst(node *&root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertinbst(root->right, d);
    }
    else
    {
        root->left = insertinbst(root->left, d);
    }
    return root;
}
void takeinput(node *&root)
{
    cout << "Enter data ..." << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        insertinbst(root, data);
        cin >> data;
    }
}
node *buildTree(node *root)
{
    int data;
    cout << "Enter data ... " << endl;
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
}
bool searchInBst(node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
    {
        return searchInBst(root->left, key);
    }
    else
    {
        return searchInBst(root->right, key);
    }
}
node *minvalueinbst(node *&root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *maxvalueinbst(node *&root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
node *deletefrombst(node* root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = (root->left);
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            node *temp = (root->right);
            delete root;
            return temp;
        }
        else
        {
            int mini = minvalueinbst(root->right) -> data;
            root->data = mini;
            root->right = deletefrombst(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletefrombst(root->left, val);
    }
    else
    {
        root->right = deletefrombst(root->right, val);
    }
}
int main()
{
    node *root = NULL;
    takeinput(root);
    // 25 20 10 5 12 22 36 30 28 40 38 48 -1
    
    int val;
    do
    {
        cout << "1.Enter 1 for inserting in BST " << endl;
        cout << "2.Enter 2 for deleting in BST " << endl;
        cout << "3.Enter 3 for searching in BST" << endl;
        cout << "4.Enter 4 for inorder traversal " << endl;
        cout << "5.Enter 5 for postorder traversal" << endl;
        cout << "6.Enter 6 for preorder traversal" << endl;
        cout << "7.Enter 7 for exit " << endl;
        cout << "Enter val : ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            cout << "Enter data for inserting : ";
            int data;
            cin >> data;
            
            insertinbst(root, data);
            cout << "Inserting successfully done " << endl;
        }
        break;
        case 2:
        {
            cout << "Enter data for deleting : ";
            int data;
            cin >> data;
            root = deletefrombst(root,val);
            cout << "Deleting successfully done : " << endl;
        }
        break;
        case 3:
        {
            cout << "Enter data for searching : " ;
            int data;
            cin >> data;
            if (searchInBst(root, data))
                cout << "Key found in BST " << endl;
            else
                cout << "Key not foud" << endl;
        }
        break;
        case 4:
        {
            cout << "Inorder traversal of BST..." << endl;
            inorder(root);
            cout << endl;
        }
        break;
        case 5:
        {
            cout << "Preorder traversal of BST..." << endl;
            preorder(root);
            cout << endl;
        }
        break;
        case 6:
        {
            cout << "Postorder traversal of BST..." << endl;
            postorder(root);
            cout << endl;
        }
        }
    } while (val != 7);
}