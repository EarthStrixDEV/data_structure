#include <iostream>
using namespace std;
typedef struct Node *Stack;
void Pop(Stack S);
int count = 0;
struct Node
{
    char value;
    struct Node *Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = new struct Node;
    if (S == NULL)
        cout << "Out of space!!!" << endl;
    S->Next = NULL;
    return S;
}

void MakeEmpty(Stack S)
{
    if (S == NULL)
        cout << "Must use CreateStack first" << endl;
    else
        while (!IsEmpty(S))
            Pop(S);
}

void Push(int X, Stack S)
{
    Stack TmpCell;
    TmpCell = new struct Node;
    if (TmpCell == NULL)
        ;
    else
    {
        TmpCell->value = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

int Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->Next->value;
    }
    return 0;
}

void Pop(Stack S)
{
    Stack FirstCell;
    if (IsEmpty(S))
        ;
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        delete (FirstCell);
    }
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s, Stack st)
{

    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
            Push('(', st);

        else if (c == ')')
        {
            while (Top(st) != '(')
            {
                result += Top(st);
                Pop(st);
            }
            Pop(st);
        }

        else
        {
            while (!IsEmpty(st) && prec(s[i]) <= prec(Top(st)))
            {
                result += Top(st);
                Pop(st);
            }
            Push(c, st);
        }
    }

    while (!IsEmpty(st))
    {
        result += Top(st);
        Pop(st);
    }
    cout << "Postfix : " << result << endl;
}

void menu()
{
    cout << "=========MENU=========\n"
         << "1) Easy infix expression \n"
         << "2) Infix expression\n"
         << "3) Exit\n"
         << "Please choose >";
}

int main()
{
    string s;
    Stack st = NULL;
    st = CreateStack();
    menu();
    int choose;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "Enter : ";
        cin >> s;
        infixToPostfix(s, st);
        break;
    case 2:
        cout << "Enter : ";
        cin >> s;
        infixToPostfix(s, st);
        break;
    default:
        break;
    }
}
