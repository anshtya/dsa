#include <iostream>
#include <vector>
using namespace std;

// 1st approach
int search1(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1, mid, pivot = -1;

    while(low<=high) {
        mid = low +(high-low)/2;

        if (nums[mid] == target) return mid;
        else if (nums[low] <= nums[mid]) 
        {
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        else 
        {
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// 2nd approach
int search2(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid, pivot = -1;

        while(low<=high) {
            mid = low +(high-low)/2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid]<=nums[n-1]) {
                pivot = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        if (pivot == -1) return -1;

        low = 0;
        high = pivot - 1;

        while(low<=high) {
            mid = low +(high-low)/2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = pivot;
        high = n - 1;

        while(low<=high) {
            mid = low +(high-low)/2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }



int main()
{
    return 0;
}