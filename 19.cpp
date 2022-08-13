/* Write a function named move_head() which will move the head to the last position of the list.
For example: If the list looks like this,
List: 2 <-> 4 <-> 1 <-> 10 <-> 5
After the operation the list will look like this,
List: 4 <-> 1 <-> 10 <-> 5 <-> 2
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

void delete_node_by_position(Node *&head, int pos)
{
    if (pos < 0 || pos >= length(head))
        return;

    if (pos == 0)
    {
        Node *delNode = head;
        if (delNode->next != NULL)
            delNode->next->prev = NULL;
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
    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;
    delete delNode;
}

void move_head(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = head;
    head->prev = tail;
    head->next->prev = NULL;
    head = head->next;
    tail->next->next = NULL;
}

int main()
{
    Node *head = NULL;
    insert_node_by_position(head, 0, 2);
    insert_node_by_position(head, 1, 4);
    insert_node_by_position(head, 2, 1);
    insert_node_by_position(head, 3, 10);
    insert_node_by_position(head, 4, 5);
    move_head(head);

    display(head);
    displayReverse(head);

    return 0;
}