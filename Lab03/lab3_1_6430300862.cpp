#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct record
{
    int value;
    struct record *next;
};
int i, j, k, l;
int menu()
{
    int c;
    cout << endl;
    cout << "==Menu==" << endl;
    cout << "1.insert" << endl;
    cout << "2.delete" << endl;
    cout << "3.Print Max To Min" << endl;
    cout << "4.Count number and Print second half and first half" << endl;
    cout << "5.exit" << endl;
    cout << "Please choose: ";
    cin >> c;
    return c;
}
struct record *insert(struct record *head, int data)
{
    // complete
    struct record *p, *node;
    if (head == NULL)
    {
        head = new struct record;
        head->value = data;
        head->next = NULL;
    }
    else
    {
        node = new struct record;
        node->value = data;
        if (data < head->value)
        {
            node->next = head;
            head = node;
        }
        else
        {
            p = head;
            while (p != NULL)
            {
                if (p->next != NULL)
                {
                    if (data < p->next->value)
                    {
                        node->next = p->next;
                        p->next = node;
                        break;
                    }
                    else
                    {
                        p = p->next;
                    }
                }
                else
                {
                    p->next = node;
                    node->next = NULL;
                    break;
                }
            }
        }
    }
    return head;
}
struct record *Delete(struct record *head, int data)
{
    struct record *node, *tmpFree;
    node = head;
    while (node)
    {
        if (node->next != NULL)
        {
            if (data == node->value)
            {
                tmpFree = node;
                node = node->next;
                free(tmpFree);
                break;
            }
            else if (data == node->next->value)
            {
                tmpFree = node->next;
                node->next = node->next->next;
                free(tmpFree);
                break;
            }
            else
            {
                node = node->next;
            }
        }
        else
        {
            cout << "No " << data << " in list!!!" << endl;
            break;
        }
    }
    return node;
}
void printMaxToMin(struct record *head)
{
    struct record *node;
    node = head;
    cout << "Min to Max: ";
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
    cout << "Max to Min: ";
    bool swapped;
    struct record *current;
    struct record *last = NULL;
    do
    {
        swapped = false;
        current = head;
        while (current->next != last)
        {
            if (current->value < current->next->value)
            {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}
int counts(struct record *head)
{
    struct record *node;
    node = head;
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}
void first(struct record *head)
{
    cout << "First = ";
    int num = counts(head) / 2;
    struct record *tmp;
    tmp = head;
    for (int i = 0; i < num; i++)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void seconds(struct record *head)
{
    cout << "Second = ";
    int num = counts(head) / 2;
    struct record *tmp;
    tmp = head;
    for (int i = 0; i < counts(head); i++)
    {
        if (i >= num)
        {
            cout << tmp->value << " ";
        }
        tmp = tmp->next;
    }
    cout << endl;
}
void print(struct record *head)
{
    struct record *p;
    p = head;
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
}
int main()
{
    int c;
    int data;
    struct record *head = NULL;
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            head = insert(head, data);
            print(head);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            head = Delete(head, data);
            print(head);
            break;
        case 3:
            printMaxToMin(head);
            break;
        case 4:
            cout << "number = " << counts(head) << endl;
            first(head);
            seconds(head);
            break;
        default:
            exit(1);
            break;
        }
    }
}