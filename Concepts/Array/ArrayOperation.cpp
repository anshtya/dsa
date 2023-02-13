#include <iostream>
using namespace std;
void display(int arr[], int n){
    //traversal operation -> visiting every element of array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // insertion
    if( size >= capacity)
    {
        cout << "Insertion Unsuccessful"<< endl;
        return;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    cout << "Insertion Successful" << endl;
    // return index;
}
int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;
    // display(arr, size);
    indInsertion(arr, size, element, 100, index);
    size++;
    display(arr, size);
    return 0;
}