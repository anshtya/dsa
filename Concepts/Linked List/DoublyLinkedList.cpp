#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;
};

void linkedListTraversal (Node* head) {
    Node* p = head;
    Node* q;
    while (p != NULL) {
        cout << p->data << " ";
        q = p;
        p = p->next;
    }
    while (q != NULL) {
        cout << q->data << " ";
        q = q->prev;
    }
    cout << endl;
}

Node* insertAtHead(Node* head, int data) {
    Node* p = new Node();
    p->data = data;
    p->next = head;
    head->prev = p;
    p->prev = NULL;
    return p;
}

Node* insertAtIndex(Node* head, int data, int index) {
    Node* ptr = head;
    Node* p = new Node();
    int i = 0;
    while (i != index - 1) {
        ptr = ptr->next;
        i++;
    }
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
    p->prev = ptr;
    p->next->prev = p;
    return head;
}

Node* insertAtTail(Node* head, int data) {
    Node* ptr = head;
    Node* p = new Node();
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    p->data = data;
    p->next = NULL;
    ptr->next = p;
    p->prev = ptr;
    return head;
}

Node* deleteAtIndex(Node* head, int index) {
    Node* ptr = head;
    Node* p;
    int i = 0;
    while (i != index - 1) {
        ptr = ptr->next;
        i++;
    }
    p = ptr->next;
    ptr->next = p->next;
    p->next->prev = ptr;
    delete(p);
    return head;
}

Node* deleteAtHead(Node* head) {
    Node* p = head;
    head = head->next;
    head->prev = NULL;
    delete(p);
    return head;
}

Node* deleteAtTail(Node* head) {
    Node* ptr = head;
    Node* p;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    p = ptr->next;
    ptr->next = NULL;
    delete(p);
    return head;
}

int main(){

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    linkedListTraversal(head);
    // head = insertAtHead(head, 5);
    // head = insertAtIndex(head, 5, 2);
    // head = insertAtTail(head, 5);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtHead(head);
    head = deleteAtTail(head);
    linkedListTraversal(head);

    return 0;
}