/* Write a function named move_tail() which will move the tail to the first position of the list.
For example: If the list looks like this,
List: 2 -> 4 -> 1 -> 10 -> 5
After the operation the list will look like this,
List: 5 -> 2 -> 4 -> 1 -> 10
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

void move_tail(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *prevNode = head;
    while (prevNode->next->next != NULL)
    {
        prevNode = prevNode->next;
    }

    Node *lastNode = prevNode->next;
    prevNode->next = NULL;
    lastNode->next = head;
    head = lastNode;
}

int main()
{
    Node *head = NULL;
    insert_node_by_position(head, 0, 1);
    insert_node_by_position(head, 1, 2);
    insert_node_by_position(head, 2, 3);
    insert_node_by_position(head, 3, 4);

    move_tail(head);
    display(head);
    cout << "Total Node: " << count_node(head) << endl;

    return 0;
}