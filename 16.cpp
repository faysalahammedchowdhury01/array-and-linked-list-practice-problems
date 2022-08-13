/* Write a function insert_node() to insert a value at the end of a doubly linked list. If there are no nodes, it will insert a head.
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;
    Node(int val)
    {
        value = val;
        prev = NULL;
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

void displayReverse(Node *&head)
{
    if (head == NULL)
        return;

    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }

    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->prev;
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

    newNode->prev = lastNode;
    lastNode->next = newNode;
}

int main()
{
    Node *head = NULL;
    insert_node(head, 500);
    insert_node(head, 5100);
    insert_node(head, 100);
    display(head);
    displayReverse(head);

    return 0;
}