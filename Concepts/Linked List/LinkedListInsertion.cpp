#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void linkedListTraversal(class Node* ptr){
    while(ptr != NULL){
        cout << ptr->data<< " ";
        ptr = ptr->next; //Cant use ptr++ because LList is not contiguous
    }
}

Node* insertAtFirst(class Node* head, int data){
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

Node* insertAtIndex(class Node* head, int data, int index){ //doesnt work for 0th index
    Node* ptr = new Node();
    Node* p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node* insertAtLast(class Node* head, int data){
    Node* ptr = new Node();
    Node* p = head;
    while(p->next != NULL){
        p = p->next; 
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

Node* insertAfterNode(class Node* head, class Node* prevNode, int data){
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main(){
    Node *head;
    Node *second;
    Node *third;

    // Allocate memory for the linked list in the heap
    head = new Node();  //allocates in heap
    second = new Node(); //allocates in heap
    third = new Node(); //allocates in heap

    // Link first and second nodes
    head->data = 1;
    head->next = second;
    
    // Link second and third nodes
    second->data = 2;
    second->next = third;
    
    // Terminate the list at the third node
    third->data = 3;
    third->next = NULL;

    linkedListTraversal(head);
    cout << endl;

    
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtLast(head, 56);
    // head = insertAfterNode(head, second, 56);
    linkedListTraversal(head);
    // cout<<head->next->data;

    /*
    Inserting at the beginning        -> Time complexity:  O(1)
    Inserting in between                 -> Time complexity:  O(n)
    Inserting at the end                   -> Time complexity:  O(n)
    Inserting after a given Node     -> Time complexity:  O(1)
    */
    return 0;
}