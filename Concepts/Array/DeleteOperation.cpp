#include <iostream>
using namespace std;
void display(int arr[], int n){
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void indDeletion(int arr[], int size, int capacity, int index)
{
    if(index >= capacity - 1)
    {
        cout<< "Deletion unsuccessful" <<endl;
        return;
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    cout<< "Deletion Successful" <<endl;
}
int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, index = 7;
    indDeletion(arr, size, 100, index);
    size--;
    display(arr, size);
    return 0;
}