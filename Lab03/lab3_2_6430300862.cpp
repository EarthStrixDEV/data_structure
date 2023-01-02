#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct record
{
    int value;
    struct record *next;
    struct record *prev;
};
int i, j, k, l;
struct record *tail = NULL;
struct record *insert(struct record *head, struct record **tail, int data)
{
    struct record *node;
    struct record *p;
    if (head == NULL && *tail == NULL)
    {
        head = new struct record;
        head->value = data;
        head->next = head->prev = NULL;
        *tail = head;
    }
    else
    {
        node = new struct record;
        node->value = data;
        if (data < head->value)
        {
            node->next = head;
            node->prev = NULL;
            head->prev = node;
            head = node;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                if (data < p->next->value)
                {
                    node->prev = p;
                    node->next = p->next;
                    p->next->prev = node;
                    p->next = node;
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if (p->next == NULL)
            {
                node->next = p->next;
                p->next = node;
                node->prev = p;
                *tail = node;
            }
        }
    }
    return head;
}
struct record *Delete(struct record *head, int data)
{
    struct record *node, *tmp;
    node = head;
    if (data == node->value)
    {
        tmp = node;
        node->next->prev = node->prev;
        head = node->next;
        delete (tmp);
    }
    else
    {
        while (node->next != NULL)
        {
            if (node->value == data)
            {
                tmp = node;
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete (tmp);
                break;
            }
            else
            {
                node = node->next;
            }
        }
        if (node->value == data && node->next == NULL)
        {
            tmp = node;
            node->prev->next = node->next;
            tail = node->prev;
            delete (tmp);
        }
        cout << "NO " << data << " in list!!!\n";
    }
    return head;
}
void printMaxToMin(struct record *tail)
{
    struct record *p;
    p = tail;
    cout << "Print max to min :";
    while (p != NULL)
    {
        cout << " " << p->value;
        p = p->prev;
    }
    cout << endl;
}
void printMinToMax(struct record *head)
{
    struct record *p;
    p = head;
    cout << "Print min to max :";
    while (p != NULL)
    {
        cout << " " << p->value;
        p = p->next;
    }
    cout << endl;
}
int menu()
{
    int c;
    cout << endl;
    cout << "==Menu==" << endl;
    cout << "1.insert" << endl;
    cout << "2.delete" << endl;
    cout << "3.print max to min and min to max" << endl;
    cout << "4.exit" << endl;
    cout << "Please choose: ";
    cin >> c;
    return c;
}
int main()
{
    struct record *head = NULL;
    int data;
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            head = insert(head, &tail, data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            head = Delete(head, data);
            break;
        case 3:
            printMinToMax(head);
            printMaxToMin(tail);
            break;
        default:
            exit(1);
        }
    }
}