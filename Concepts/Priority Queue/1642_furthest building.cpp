#include <bits/stdc++.h>
using namespace std;

/**
 * This problem works by utilizing a priority queue which will act as a max heap. Here we need to 
 * jump building using ladders and bricks by using them optimally.
 * 
 * Here we are storing differences of buildings in priority queue every time we visit the building.
 * 
 * Suppose we have 5 bricks and 1 ladder. One of the two buildings have a difference of +5 and other 
 * have +3.
 * We used 5 bricks initially so now we will have 0 bricks remaining.
 * When we reach the other two buildings, greedily we could have used ladder before and used 3 bricks 
 * here so that we would have 2 remaining bricks which could be used for overcoming further buildings.
 * 
 * Bricks will become negative and stored in queue. When ladder is used, difference will be popped off 
 * from priority queue and added to bricks such that amount of bricks would become if we used our ladders 
 * and bricks greedily i.e. 2.
*/

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;

        for(int i = 0; i<n-1; i++) {
            int diff = heights[i+1]-heights[i];
            
            if (diff <= 0) {
                continue;
            } else {
                bricks -= diff;
                pq.push(diff);

                if (bricks < 0) {
                    if (ladders == 0) {
                        return i;
                    }
                    ladders--;
                    bricks += pq.top();
                    pq.pop();
                }
            }
        }

        return n-1;
    }

int main() {
    return 0;
}