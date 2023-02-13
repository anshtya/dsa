#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void linkedListTraversal(Node* head) {
    Node* ptr = head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}

Node* insertAtFirst(Node* head, int data) {
    Node* ptr = new Node();
    Node* p = head;
    
    ptr->data = data;
    
    while(p->next != head) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){

    Node* head;    
    Node* second;
    Node* third;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 4;
    head->next = second;
    
    second->data = 3;
    second->next = third;
    
    third->data = 6;
    third->next = head;

    cout << "Linked list before insertion: ";
    linkedListTraversal(head);
    cout << endl;

    head = insertAtFirst(head, 10);
    head = insertAtFirst(head, 154);
    head = insertAtFirst(head, 178);
    cout << "Linked list after insertion: ";
    linkedListTraversal(head);
    return 0;
}