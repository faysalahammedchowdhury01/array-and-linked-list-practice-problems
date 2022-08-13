/* Write a function named insert_node_by_position() that inserts a value at any position of the singly linked list. You can assume that if there are 5 nodes in the list, the positions are 0, 1, 2, 3 and 4.
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

void insert_node_by_position(Node *&head, int pos, int val)
{
    if (pos < 0)
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
    prevNode->next = newNode;
}

int main()
{
    Node *head = NULL;
    insert_node_by_position(head, 0, 1);
    insert_node_by_position(head, 1, 2);
    insert_node_by_position(head, 2, 3);
    insert_node_by_position(head, 3, 4);
    insert_node_by_position(head, 4, 5);
    insert_node_by_position(head, 0, 6);
    insert_node_by_position(head, 1, 7);

    display(head);

    return 0;
}