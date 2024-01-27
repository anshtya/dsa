#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int i=1;
        for (int j = 2; j< nums.size(); j++) {
            if (nums[i-1] != nums[j]) {
                nums[++i]=nums[j];
            }
        }
        return i+1;
}

//  here I took i=1 because atmost 2 instances of same number are allowed