#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int frontnum;
    int backnum;
    Node *next;
};

struct Node *head = NULL;

void insert(int coef, int exp)
{
    if (head == NULL)
    {
        head = new struct Node;
        head->backnum = coef;
        head->frontnum = exp;
        head->next = NULL;
    }
    else
    {
        if (exp == head->backnum)
        {
            head->frontnum = head->frontnum + coef;
        }
        else if (exp > head->backnum)
        {
            struct Node *node;
            node = new struct Node;
            node->frontnum = coef;
            node->backnum = exp;

            node->next = head;
            head = node;
        }
        else
        {
            struct Node *p;
            p = head;
            while (p->next != NULL)
            {
                if (exp == p->next->backnum)
                {
                    p->next->frontnum = p->next->frontnum + coef;
                    break;
                }
                else if (exp > p->next->backnum)
                {
                    struct Node *node;
                    node = new struct Node;
                    node->frontnum = coef;
                    node->backnum = exp;

                    node->next = p->next;
                    p->next = node;
                    break;
                }
                p = p->next;
            }
            if (p->next == NULL)
            {
                if (exp == p->backnum)
                {
                    p->frontnum = p->frontnum + coef;
                }
                else
                {
                    struct Node *node;
                    node = new struct Node;
                    node->frontnum = coef;
                    node->backnum = exp;
                    node->next = p->next;
                    p->next = node;
                }
            }
        }
    }
}

void print(struct Node *head)
{
    struct Node *p;
    p = head;
    cout << "Output : ";
    while (p != NULL)
    {
        if (p->backnum == 0)
        {
            cout << p->frontnum;
        }
        else if (p->backnum == 1)
        {
            cout << p->frontnum << "x";
        }
        else
        {
            cout << p->frontnum << "x^" << p->backnum;
        }
        if (p->next != NULL)
        {
            cout << " + ";
        }
        p = p->next;
    }
}
int main()
{
    int i, j, k, l;
    int inputCoef;
    int inputExp;
    cout << "Input P1 : ";
    do
    {
        cin >> inputCoef;
        if (inputCoef != -99)
        {
            cin >> inputExp;
            insert(inputCoef, inputExp);
        }
    } while (inputCoef != -99);
    cout << "Input P2 : ";
    do
    {
        cin >> inputCoef;
        if (inputCoef != -99)
        {
            cin >> inputExp;
            insert(inputCoef, inputExp);
        }
    } while (inputCoef != -99);
    print(head);
    return 0;
}