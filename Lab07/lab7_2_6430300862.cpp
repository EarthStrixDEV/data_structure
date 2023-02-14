#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void menu()
{
    cout << "==========MENU==========" << endl;
    cout << "1. Input postorder" << endl;
    cout << "2. Print Expression tree" << endl;
    cout << "3. Exit" << endl;
    cout << "Please choose > ";
}

struct node
{
    char value;
    struct node *left;
    struct node *right;
};

struct record
{
    struct node *tree;
    struct record *next;
};

void printInorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printInorder(tree->left);
        cout << " " << tree->value;
        printInorder(tree->right);
    }
}

void printPostorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printPostorder(tree->left);
        printPostorder(tree->right);
        cout << " " << tree->value;
    }
}

void push(struct record *stack, struct node *tree)
{
    if (stack != NULL)
    {
        struct record *child;
        child = new struct record;
        child->tree = tree;
        child->next = stack->next;
        stack->next = child;
    }
}

struct node *pop(struct record *stack)
{
    struct record *child;
    struct node *tree;
    child = stack->next;
    stack->next = stack->next->next;
    tree = child->tree;
    delete (child);
    return tree;
}

int main()
{
    int choose;
    struct record *stack = NULL;
    stack = new struct record;
    stack->next = NULL;
    char c;
    while (true)
    {
        menu();
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Input : ";
            c = getchar();
            while (c != '.')
            {
                if (c == '+' || c == '-' || c == '*' || c == '/')
                {
                    struct node *tree = NULL;
                    tree = new struct node;
                    tree->value = c;
                    tree->right = pop(stack);
                    tree->left = pop(stack);
                    push(stack, tree);
                }
                else
                {
                    struct node *tree = NULL;
                    tree = new struct node;
                    tree->value = c;
                    tree->left = tree->right = NULL;
                    push(stack, tree);
                }
                c = getchar();
            }
            break;
        case 2:
            cout << "Inorder :";
            printInorder(stack->next->tree);
            cout << endl;
            cout << "Postorder :";
            printPostorder(stack->next->tree);
            cout << endl;
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Not Choice!!" << endl
                 << endl;
            break;
        }
    }
    return 0;
}