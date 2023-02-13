#include <iostream>
using namespace std;
int firstOcc (int arr[], int n, int key) {
    int s = 0, e = n - 1, mid, ans;
    while (s <= e) {
        mid = s + (e-s)/2;
        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans; 
}
int secondOcc (int arr[], int n, int key) {
    int s = 0, e = n - 1, mid, ans;
    while (s <= e) {
        mid = s + (e-s)/2;
        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans; 
}
int main(){

    int arr[] = {1,2,3,3,3,3,3,5};
    cout << firstOcc(arr, 8, 3);
    cout << secondOcc(arr, 8, 3);

    return 0;
}