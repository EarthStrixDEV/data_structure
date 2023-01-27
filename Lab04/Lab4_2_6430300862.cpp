#include <bits/stdc++.h>
using namespace std;
struct Node;
typedef struct Node *Stack;
struct Node {
    int value;
    struct Node *next;
};
int menu()
{
    int c;
    cout << endl;
    cout << "==Menu==" << endl;
    cout << "1.Push" << endl;
    cout << "2.Top" << endl;
    cout << "3.Pop" << endl;
    cout << "4.Empty Stack" << endl;
    cout << "5.Exit" << endl;
    cout << "Please choose: ";
    cin >> c;
    return c;
}
Stack CreateStack(void)
{
    Stack s;
    s = new struct Node; //Return
    if (s == NULL)
    {
        cout << "Out of space!!!" << endl;
    }
    s->next = NULL;
    return s;
}
bool isEmpty(Stack s)
{
    return s->next == NULL;
}
void Pop(Stack S)
{
    Stack FirstCell;
    if (isEmpty(S))
        cout << "No data!!";
    else
    {
        FirstCell = S->next;
        S->next = S->next->next;
        free(FirstCell);
    }
}
void Push(int x, Stack s)
{
    Stack tmpCell;
    tmpCell = new struct Node;
    if (tmpCell == NULL)
    {
        cout << "Out of space!!!" << endl;
    }
    else
    {
        tmpCell->value = x;
        tmpCell->next = s->next;
        s->next = tmpCell;
    }
}
void MakeEmpty(Stack S)
{
    if (S == NULL)
    {
        cout << "Must use CreateStack first" << endl;
    }
    else
    {
        while (!isEmpty(S))
        {
            Pop(S);
        }
    }
}
void Top(Stack S)
{
    if (!isEmpty(S))
        cout << S->next->value;
    else {
        cout << "No data!!" << endl;
    }
}
int main(){
    int data;
    Stack s1;
    s1 = CreateStack();
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Push: ";
            cin >> data;
            Push(data, s1);
            break;
        case 2:
            cout << "Top: ";
            Top(s1);
            break;
        case 3:
            cout << "Top: ";
            Top(s1);
            Pop(s1);
            cout << "\n";
            cout << "Pop success!!\n";
            break;
        case 4:
            MakeEmpty(s1);
            cout << "Empty Stack Successfully\n";
            break;
        default:
            exit(1);
        }
    }
}