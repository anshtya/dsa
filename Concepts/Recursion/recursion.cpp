#include <iostream>
using namespace std;

//number of ways in n * m matrix (moving right and bottom only)
// int count(int n, int m){
//     if (n ==1 || m == 1){
//         return 1;
//     }
//     return count(n-1, m) + count(n, m -1);
// }

// Josephus problem
int jos(int n, int k)
{
    if(n == 1)
    {
        return 0;
    }
    return (jos(n-1, k) + k) % n;
}

//sum of nums in array 
// int sum(int arr[], int len) {
//   if (len <= 0) {
//     return 0;
//   }
//   return arr[len - 1] + sum(arr, len - 1);
// }
int main(){
    // cout << count(4,3);
    cout << jos(5, 3);
    return 0;
}