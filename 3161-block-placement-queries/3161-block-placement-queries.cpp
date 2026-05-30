#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val); 
        } else {
            update(2 * node + 1, mid + 1, end, idx, val); 
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node]; 
        }
        int mid = start + (end - start) / 2;
        int left_max = query(2 * node, start, mid, l, r);
        int right_max = query(2 * node + 1, mid + 1, end, l, r);
        
        return max(left_max, right_max);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = min(50000, (int)queries.size() * 3); 
        set<int> hurdles;
        hurdles.insert(0);
        hurdles.insert(max_x);
        
        SegmentTree st(max_x + 1);
        st.update(1, 0, max_x, max_x, max_x); 
        
        vector<bool> ans;
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = hurdles.upper_bound(x);
                int right = *it;
                int left = *prev(it);
                hurdles.insert(x);
                st.update(1, 0, max_x, right, right - x); 
                st.update(1, 0, max_x, x, x - left);     
            } 
            else if (q[0] == 2) {
                int x = q[1], sz = q[2];
                auto it = hurdles.upper_bound(x);
                int left = *prev(it);
                int max_gap = st.query(1, 0, max_x, 0, left);
                max_gap = max(max_gap, x - left);
                
                ans.push_back(max_gap >= sz);
            }
        }
        return ans;
    }
};