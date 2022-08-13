/* Write a function named insert_node() that inserts a value at the end of a singly linked list. If there are no nodes, it will insert a head.
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

void display(Node *&head)
{
    if (head == NULL)
        return;

    Node *node = head;
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void insert_node(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *lastNode = head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

int main()
{
    Node *head = NULL;
    insert_node(head, 5);
    insert_node(head, 15);
    insert_node(head, 35);
    display(head);

    return 0;
}