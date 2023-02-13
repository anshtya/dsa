#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void linkedListTraversal(class Node* ptr){
    while(ptr != NULL){
        cout << ptr->data<< " ";
        ptr = ptr->next; 
    }
}

Node* swapNodePair(Node* head, Node* p, Node* q) { //pairwise swapping
    Node* prev = head;
    if(prev == p) {
        p->next = q->next;
        q->next = p;
        return q; //if we return head instead of q, q's element will be deleted. eg.-> 1 2 3 will become 1 3.
    }
    while(prev->next != p) {
        prev = prev->next;
    }
    p->next = q->next;
    prev->next = q;
    q->next = p;
    return head;
}

int main(){

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 34;
    head->next = second;
    
    second->data = 23;
    second->next = third;
    
    third->data = 71;
    third->next = fourth;

    fourth->data = 41;
    fourth->next = NULL;

    linkedListTraversal(head);
    cout << endl;
    // head = swapNodePair(head, second, third);
    // head = swapNodePair(head, third, fourth);
    head = swapNodePair(head, head, second);
    linkedListTraversal(head);

    return 0;
}