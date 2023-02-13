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
    // cout<<head->next->data;
    return 0;
}