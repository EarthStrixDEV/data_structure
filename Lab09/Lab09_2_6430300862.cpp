#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct record
{
    int value;
    struct record *next;
};
int menu()
{
    int data;
    cout << "=========Menu=========" << endl;
    cout << "1. Insert\n";
    cout << "2. Show adj list\n";
    cout << "3. Exit\n";
    cout << "Please choose >> ";
    cin >> data;
    return data;
}
struct record *insert(int round)
{
    int data = 0;
    struct record *head = NULL, *tmp, *p;
    while (data != -99)
    {
        cout << "Input"
             << "#" << round << " : ";
        cin >> data;
        if (data == -99)
        {
            break;
        }
        if (head == NULL)
        {
            head = new struct record;
            head->value = data;
            head->next = NULL;
            p = head;
        }
        else
        {
            tmp = new struct record;
            tmp->value = data;
            tmp->next = NULL;
            p->next = tmp;
            p = tmp;
        }
    }
    return head;
}
void print(struct record *head)
{
    struct record *p = head;
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
}
int main()
{
    struct record *adj[6];
    int nodeNumber;
    while (true)
    {
        switch (menu())
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                adj[i] = insert(i);
                cout << endl;
            }
            break;
        case 2:
            cout << "Enter number: ";
            cin >> nodeNumber;
            if (nodeNumber >= 0 && nodeNumber <= 4)
            {
                struct record *head = adj[nodeNumber];
                cout << "#" << nodeNumber << " : ";
                print(head);
                cout << endl;
            }
            else
            {
                cout << "Unknown Vertex!!" << endl;
            }
            break;
        default:
            exit(1);
            break;
        }
    }
}