/* Write a function named count_node() to count the number of nodes in that singly linked list.
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

int count_node(Node *&head)
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

void insert_node_by_position(Node *&head, int pos, int val)
{
    if (pos < 0 || pos > count_node(head))
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

void delete_node_by_position(Node *&head, int pos)
{
    if (pos < 0 || pos >= count_node(head))
        return;

    if (pos == 0)
    {
        Node *delNode = head;
        head = delNode->next;
        delete delNode;
        return;
    }

    Node *prevNode = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prevNode = prevNode->next;
    }
    Node *delNode = prevNode->next;
    prevNode->next = delNode->next;
    delete delNode;
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
    delete_node_by_position(head, 0);

    display(head);
    cout << "Total Node: " << count_node(head) << endl;

    return 0;
}