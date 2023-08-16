#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

//Approach 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *ptr = head;
        while(ptr != NULL) {
            st.push(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;

        while(ptr != NULL) {
            int element = ptr->val;
            if (st.top() == element) {
                st.pop();
                ptr = ptr->next;
            } else {
                return false;
            }
        }

        return true;
    }
};