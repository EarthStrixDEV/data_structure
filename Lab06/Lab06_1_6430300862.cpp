#include <bits/stdc++.h>
using namespace std;
struct record
{
    int value;
    struct record *left;
    struct record *right;
};
int menu()
{
    int c;
    cout << endl;
    cout << "==Menu==" << endl;
    cout << "1.Insert" << endl;
    cout << "2.Print Preorder ,Inorder ,Postorder" << endl;
    cout << "3.Find Min,Max" << endl;
    cout << "4.Delete" << endl;
    cout << "5.Exit" << endl;
    cout << "Please choose: ";
    cin >> c;
    return c;
}
struct record *insert(struct record *tree, int data)
{
    if (tree == NULL)
    {
        tree = new struct record;
        tree->value = data;
        tree->left = tree->right = NULL;
    }
    else
    {
        if (data < tree->value)
        {
            tree->left = insert(tree->left, data);
        }
        else if (data > tree->value)
        {
            tree->right = insert(tree->right, data);
        }
    }
    return tree;
}
struct record *find_min(struct record *tree)
{
    if (tree->left == NULL)
    {
        cout << tree->left << endl;
    }
    else
    {
        find_min(tree->left);
    }
}
struct record *dTree(struct record *tree ,int data) {
    struct record *tmpCell, *child;
    if (tree == NULL) {
        cout << "No Node\n";
    } else {
        if (data < tree->value) {
            tree->left = dTree(tree->left, data);
        } else {
            if (data > tree->value) {
                tree->right = dTree(tree->right, data);
            } else {
                if (tree->left && tree->right) {
                    tmpCell = find_min(tree->right);
                    tree->value = tmpCell->value;
                    tree->right = dTree(tree->right, tree->value);
                } else {
                    tmpCell = tree;
                    if (tree->left == NULL) {
                        child = tree->right;
                    } 
                    if (tree->right == NULL) {
                        child = tree->left;
                    }
                    delete (tmpCell);
                    return child;
                }
            }
        }
    }
    return tree;
}
struct record *find_max(struct record *tree)
{
    if (tree->right == NULL)
    {
        cout << tree->value << endl;
    }
    else
    {
        find_max(tree->right);
    }
}
void Preorder(struct record *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        cout << tree->value << " ";
        Preorder(tree->left);
        Preorder(tree->right);
    }
    return;
}
void Inorder(struct record *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        Inorder(tree->left);
        cout << tree->value << " ";
        Inorder(tree->right);
    }
    return;
}
void Postorder(struct record *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        Postorder(tree->left);
        Postorder(tree->right);
        cout << tree->value << " ";
    }
    return;
}
int main()
{
    struct record *tree = NULL;
    int data;
    while (true) {
        switch (menu())
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            tree = insert(tree, data);
            cout << "Success!" << endl;
            break;
        case 2:
            cout << "Preorder: ";
            Preorder(tree);
            cout << endl;
            cout << "Inorder: ";
            Inorder(tree);
            cout << endl;
            cout << "Postorder: ";
            Postorder(tree);
            cout << endl;
            break;
        case 3:
            cout << "Min: ";
            find_min(tree);
            cout << "Max: ";
            find_max(tree);
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            tree = dTree(tree, data);
            break;
        default:
            exit(1);
            break;
        }
    }
}