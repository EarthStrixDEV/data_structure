#include <bits/stdc++.h>
using namespace std;
struct record
{
  int value;
  struct record *next;
};
int menu()
{
  int c;
  cout << endl;
  cout << "==================\n";
  cout << "       Menu       \n";
  cout << "==================\n";
  cout << "1. Insert List\n";
  cout << "2. Print\n";
  cout << "3. Exit \n";
  cout << "Please choose: ";
  cin >> c;
  return c;
}
struct record *insert(struct record *head,int data) {
  struct record *node ,*p;
  if (head == NULL) {
    head = new struct record;
    head->value = data;
    head->next = NULL;
  } else if (data < head->value) {
    node = new struct record;
    node->value = data;
    node->next = head;
    head = node;
  }
  return head;
}
void print(struct record *head)
{
  struct record *p;
  p = head;
  while (p)
  {
    cout << p->value << " ";
    p = p->next;
  }
}
int main()
{
  int data;
  struct record *head = NULL,*p;
  while (true)
  {
    switch (menu())
    {
    case 1:
      cout << "Input: ";
      cin >> data;
      head = insert(head, data);
    break;
    case 2:
      print(head);
      break;
    default:
      return 0;
    }
  }
}