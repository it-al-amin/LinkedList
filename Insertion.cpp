#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    Node(int data) // constructor
    {
        this->data = data;
        this->next = NULL; // Use nullptr instead of NULL in modern C++
    }
    ~Node() // destructor
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free with data " << val << "\n";
    }
};
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d) // insertion order
{
    Node *temp = new Node(d);
    tail->next = temp;
    // tail=tail->next;
    tail = temp;
}
void insertAtPosition(Node *&tail, Node *&head, int pos, int val)
{
    // insert at first;
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }
    Node *Temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        Temp = Temp->next;
        cnt++;
    }
    // insert at last
    if (Temp->next == NULL)
    {
        insertAtTail(tail, val);
        return;
    }
    // creating a node for val
    Node *nodeToInsert = new Node(val);
    nodeToInsert->next = Temp->next; // new node ar next a next node Address;
    Temp->next = nodeToInsert;       // previous node next a new node ar address;
}
void deleteNode(int pos, Node *&head, Node *&tail)
{
    // deleting 1st node
    if (pos == 1)
    {
        Node *Temp = head;
        head = head->next;
        Temp->next = NULL;
        // memory free;
        delete Temp;
    }
    else
    {
        // deleting any middle node or last node
        int cnt = 1;
        Node *cur = head;
        Node *prev = NULL;

        while (cnt < pos)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        prev->next = cur->next;
        if (cur->next == NULL) // update the tail as we deleted the last node;
        {
            tail = prev;
        }
        cur->next = NULL; // previously deleted cur->next should be null

        delete cur;
    }
}
void print(Node *&head) // reverse order
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    print(head);
    // cout << head->data << " " << head->next << "\n";
    insertAtTail(tail, 12);
    insertAtTail(tail, 11);
    insertAtTail(tail, 1);

    insertAtTail(tail, 110);
    print(head);
    insertAtPosition(tail, head, 1, 100);
    print(head);
    insertAtPosition(tail, head, 7, 180);
    print(head);
    insertAtTail(tail, 144);
    print(head);
    deleteNode(1, head, tail);
    print(head);
    cout << head->data << " " << tail->data << "\n";
    deleteNode(7, head, tail);
    print(head);
    cout << head->data << " " << tail->data << "\n";
    // cout << head->data << " " << head->next << "\n";
    return 0;
}