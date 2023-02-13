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

Node* removeFirstNode(class Node* head){
    Node* ptr = head;
    head = head->next;
    delete(ptr);
    return head;
}

Node* removeAtIndex(class Node* head, int index){
    int i = 0;
    Node* p = head;
    Node* ptr;
    while( i != index - 1){
        p = p->next;
        i++;
    }
    ptr = p->next;
    p->next = ptr->next;
    delete(ptr);

    // Another approach
    // Node* p = head;
    // Node* q = head->next;
    // for(int i = 0; i < index - 1; i++){
    //     p = p->next;
    //     q = q->next;
    // }
    // p->next = q->next;
    // delete(q);
    
    return head;
}

Node* removeLastNode(class Node* head){
    Node* p = head;
    Node* ptr;
    while(p->next->next != NULL){
        p = p->next;
    }
    ptr = p->next;
    p->next = NULL;
    delete(ptr);

    // Another approach
    // Node* p = head;
    // Node* q = head->next;
    // while(q->next != NULL)
    //     p = p->next;
    //     q = q->next;
    // }
    // p->next = NULL;
    // delete(q);

    return head;
}

Node* removeByValue(class Node* head, int value){
    Node* p = head;
    Node* q = head->next;
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        delete(q);
    }
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

    // head = removeLastNode(head);
    // head = removeFirstNode(head);
    // head = removeAtIndex(head, 1);
    linkedListTraversal(head);
    return 0;
}

/*
Deleting the first node            -> Time complexity:  O(1)
Deleting a node in between   -> Time complexity:  O(n)
Deleting the last node            -> Time complexity:  O(n)
Deleting the element with a given value from the linked list     -> Time complexity:  O(n)
*/