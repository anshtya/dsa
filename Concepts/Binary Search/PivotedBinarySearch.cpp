#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int s = 0, e = n - 1, mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] > arr[e])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    if (target <= arr[n - 1])
    {
        e = n - 1;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    else
    {
        e = s - 1;
        s = 0;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
}
int main()
{

    int arr[] = {6, 7, 9, 12, 1, 5};
    cout << binarySearch(arr, 6, 5);

    return 0;
}