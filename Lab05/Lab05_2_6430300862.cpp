#include <iostream>
using namespace std;

struct record
{
    int value;
    struct record *next;
};

struct record *enqueue(struct record *queue, int people)
{
    if (queue == NULL)
    {
        queue = new struct record;
        queue->value = people;
        queue->next = queue;
    }
    else
    {
        struct record *node, *p;
        node = new struct record;
        node->value = people;
        node->next = queue;
        p = queue;
        while (p->next != queue)
        {
            p = p->next;
        }
        p->next = node;
    }
    return queue;
}

struct record *dequeue(struct record *queue)
{
    struct record *temp = queue->next;
    queue->next = temp->next;
    delete (temp);
    return queue->next;
}

int main()
{
    int N, M;
    struct record *queue = NULL;
    cout << "Input N : ";
    cin >> N;
    for (int people = 1; people <= N; people++)
    {
        queue = enqueue(queue, people);
    }
    cout << "Input M : ";
    cin >> M;
    while (queue != queue->next)
    {
        for (int m = 1; m < M; m++)
        {
            queue = queue->next;
        }
        queue = dequeue(queue);
    }
    cout << "The winner is : ";
    cout << queue->value;
    return 0;
}