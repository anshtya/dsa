#include <iostream>
#include <stack>
using namespace std;

class Stack {
    public:
        int *arr;
        int top;
        int size;

    Stack(int size) {
        this -> size = size;
        arr = new int(size);
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) { //atleast one empty space
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if(top >=0 ) {
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    // stack<int> s; //a template class
    
    // s.push(1);
    // s.push(2);
    // s.push(3);

    // s.pop();
    // cout << s.size();

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);

    cout << s.peek();


    return 0;
}