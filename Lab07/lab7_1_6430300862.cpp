#include<bits/stdc++.h>
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
    cout << "2.Print Inorder" << endl;
    cout << "3.Delete" << endl;
    cout << "4.Exit" << endl;
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
struct record *dTree(struct record *tree, int data)
{
    struct record *tmpCell, *child;
    if (tree == NULL)
    {
        cout << "No Data\n";
    }
    else
    {
        if (data < tree->value)
        {
            tree->left = dTree(tree->left, data);
        }
        else
        {
            if (data > tree->value)
            {
                tree->right = dTree(tree->right, data);
            }
            else
            {
                if (tree->left && tree->right)
                {
                    tmpCell = find_min(tree->right);
                    tree->value = tmpCell->value;
                    tree->right = dTree(tree->right, tree->value);
                }
                else
                {
                    tmpCell = tree;
                    if (tree->left == NULL)
                    {
                        child = tree->right;
                    }
                    if (tree->right == NULL)
                    {
                        child = tree->left;
                    }
                    cout << "Success!" << endl;
                    delete (tmpCell);
                    return child;
                }
            }
        }
    }
    return tree;
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
int main(){
    int choose;
    int data;
    struct record *tree = NULL;
    while (true) {
        switch (menu())
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            tree = insert(tree, data);
            break;
        case 2:
            cout << "Inorder: ";
            Inorder(tree);
            break;
        case 3:
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