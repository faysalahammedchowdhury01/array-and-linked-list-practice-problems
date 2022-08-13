/* Write a function named insert_node_by_position() that inserts a value at any position of the doubly linked list. You can assume that if there are 5 nodes in the list, the positions are 0, 1, 2, 3 and 4.
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

int length(Node *&head)
{
    Node *node = head;
    int len = 0;
    while (node != NULL)
    {
        len++;
        node = node->next;
    }
    return len;
}

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

void insert_node_by_position(Node *&head, int pos, int val)
{
    if (pos < 0 || pos > length(head))
        return;

    Node *newNode = new Node(val);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prevNode = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prevNode = prevNode->next;
    }

    newNode->next = prevNode->next;
    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;
    newNode->prev = prevNode;
    prevNode->next = newNode;
}

int main()
{
    Node *head = NULL;
    insert_node_by_position(head, 0, 1);
    insert_node_by_position(head, 1, 2);
    insert_node_by_position(head, 2, 3);
    insert_node_by_position(head, 3, 4);
    display(head);
    displayReverse(head);

    return 0;
}