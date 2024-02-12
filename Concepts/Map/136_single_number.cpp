#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;

    for (auto i : mp) {
        if (i.second == 1) return i.first;
    }
    return -1;
}

int main()
{

    return 0;
}