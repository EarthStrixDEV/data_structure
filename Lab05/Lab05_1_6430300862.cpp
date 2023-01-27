#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    float value;
    struct node *next;
};

struct node *Push(struct node *Stack, float operand)
{
    if (Stack == NULL)
    {
        Stack = new struct node;
        Stack->next = NULL;
    }
    struct node *newNode;
    newNode = new struct node;
    newNode->value = operand;
    newNode->next = Stack->next;
    Stack->next = newNode;
    return Stack;
}

float Pop(struct node *Stack)
{
    float operand = Stack->next->value;
    struct node *temp = Stack->next;
    Stack->next = temp->next;
    delete (temp);
    return operand;
}

int main()
{
    string expression = "";
    struct node *Stack = NULL;
    cout << "Enter : ";
    while (true)
    {
        cin >> expression;
        if (expression != ".")
        {
            if (expression != "+" && expression != "-" && expression != "*" && expression != "/")
            {
                Stack = Push(Stack, stof(expression));
            }
            else
            {
                float result;
                float operand2 = Pop(Stack);
                float operand1 = Pop(Stack);
                switch (expression[0])
                {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                }
                Stack = Push(Stack, result);
            }
        }
        else
        {
            break;
        }
    }
    cout << "Output : " << Pop(Stack);
    return 0;
}