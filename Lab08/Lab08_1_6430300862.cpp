#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct node
{
    int value;
    int height;
    struct node *left;
    struct node *right;
};
int menu()
{
    int data;
    cout << "=========Menu=========" << endl;
    cout << "1. Insert\n";
    cout << "2. Print inorder\n";
    cout << "3. Print leave node\n";
    cout << "4. Exit\n";
    cout << "Please choose >> ";
    cin >> data;
    return data;
}
int height(struct node *p)
{
    if (p == NULL)
    {
        return -1;
    }
    return p->height;
}
struct node *srleft(struct node *k2)
{
    struct node *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    return k1;
}
struct node *srright(struct node *k2)
{
    struct node *k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
}
struct node *drleft(struct node *k3)
{
    k3->left = srright(k3->left);
    return srleft(k3);
}
struct node *drright(struct node *k3)
{
    k3->right = srleft(k3->right);
    return srright(k3);
}
struct node *insert(struct node *t, int data)
{
    if (t == NULL)
    {
        t = new struct node;
        t->value = data;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else
    {
        if (data < t->value)
        {
            t->left = insert(t->left, data);
            if (height(t->left) - height(t->right) == 2)
            {
                if (data < t->left->value)
                {
                    t = srleft(t);
                }
                else
                {
                    t = drleft(t);
                }
            }
        }
        else if (data > t->value)
        {
            t->right = insert(t->right, data);
            if (height(t->left) - height(t->right) == 2)
            {
                if (data < t->right->value)
                {
                    t = srright(t);
                }
                else
                {
                    t = drright(t);
                }
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}
void Inorder(struct node *tree)
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
void printLeaveNode(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    if (!tree->left && !tree->right)
    {
        cout << tree->value << " ";
    }
    printLeaveNode(tree->left);
    printLeaveNode(tree->right);
}
int main()
{
    struct node *t = NULL;
    int data;
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Insert: ";
            cin >> data;
            t = insert(t, data);
            break;
        case 2:
            cout << "Print inorder: ";
            Inorder(t);
            cout << endl;
            break;
        case 3:
            cout << "Print leave node: ";
            printLeaveNode(t);
            cout << endl;
            break;
        default:
            exit(1);
            break;
        }
    }
}