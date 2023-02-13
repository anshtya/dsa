#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int element)
{
    /*
    This search method searches for an element by breaking the search space into half each time it finds the wrong element. 
    This method is limited to a sorted array.
    */
    int low = 0, high = size - 1, mid;
    while(low <= high)
    {
        mid = (high +low)/2;
        if(arr[mid] == element )
            return mid;
        else if(arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
int main(){
    int arr[] = {1, 2, 14, 18, 34, 44, 50};
    int size = sizeof(arr)/sizeof(int);
    int elementFound = binarySearch(arr, size, 100);
    if(!elementFound)
        cout << "Element not found :(";
    else
        cout << "Element found at index "<< elementFound << " :)";
    return 0;
}