#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        int max = 0;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow != NULL && !st.empty()) {
            int curr = st.top();
            int val = curr + slow->val;
            if (max <= val) {
                max = val;
            }
            st.pop();
            slow = slow->next;
        }
        return max;
    }
};