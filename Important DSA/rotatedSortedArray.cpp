#include <iostream>
#include <vector>
using namespace std;

// 1st approach
int search(vector<int>& nums, int target){
    if(nums.size() == 0) return -1;
    
    //pivot point
    int low = 0, high = nums.size() - 1, mid;
    
    while (low < high)
    {
        mid = low + (high - low)/2;

        if(nums[mid] > nums[high])
            low = mid + 1; //coz we know this element is smallest than other elements to the high
                            // so we did mid + 1;
        else
            high = mid;
    }

    //selecting where to start binary search
    int start = low;
    low = 0;
    high = nums.size() - 1;

    if(target >= nums[start] && target <= nums[high])
        low = start;
    else
        high = start;

    //binary search
    while (low <= high){
        mid = low + (high - low)/2;

        if(nums[mid] == target)
            return mid;
        
        else if(nums[mid] < target)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    return -1; 
}



int main(){
    vector<int> v{3, 1};
    cout << search(v, 1);
    return 0;
}