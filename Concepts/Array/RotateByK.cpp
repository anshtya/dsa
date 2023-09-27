#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateByK(int arr[], int n, int k)
{
    // first reverse elements left of k, then right of k.
    // This is right rotate. 
    // 1. Reverse first n-k elements
    Reverse(arr, 0, n - k - 1);
    // 2. Reverse last k elements
    Reverse(arr, n - k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);

    // 5 6 1 2 3 4
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 2;
    rotateByK(arr, n, k);
    int i = 0;
    while ( i <= n - 1) {
        cout << arr[i] << " ";
        i++;
    }

    return 0;
}