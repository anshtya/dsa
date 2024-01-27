#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }

/*
    1 1 2
    ^   ^
    |   |   since j is not same so nums[i+1 = 1] = nums[j] -> 1,2,2
    i   j
*/