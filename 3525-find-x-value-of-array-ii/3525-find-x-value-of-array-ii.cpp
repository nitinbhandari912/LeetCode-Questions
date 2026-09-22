class Solution {
    struct Node {
        int remain[10] = {0}; 
        int prod = 1;
    };
    int n, k;
    vector < Node > tree;
    Node merge(const Node& left, const Node& right) {
        Node node;
        node.prod = (left.prod * right.prod) % k;
        
        for (int i = 0; i < k; ++i) {
            node.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k; ++i) {
            node.remain[(i * left.prod) % k] += right.remain[i];
        }
        return node;
    }
    void build(const vector < int > & nums, int cur, int lo, int hi) {
        if (lo == hi) {
            tree[cur].remain[nums[lo]] = 1;
            tree[cur].prod = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(nums, 2 * cur + 1, lo, mid);
        build(nums, 2 * cur + 2, mid + 1, hi);
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }
    void update(int cur, int lo, int hi, int i, int val) {
        if (lo == hi) {
            for (int j = 0; j < k; ++j) {
                tree[cur].remain[j] = 0;
            }
            tree[cur].remain[val] = 1;
            tree[cur].prod = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (i <= mid) {
            update(2 * cur + 1, lo, mid, i, val);
        } else {
            update(2 * cur + 2, mid + 1, hi, i, val);
        }
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }
    Node query(int cur, int lo, int hi, int i, int j) {
        if (i <= lo && hi <= j) {
            return tree[cur];
        }
        int mid = lo + (hi - lo) / 2;
        if (j <= mid) return query(2 * cur + 1, lo, mid, i, j);
        if (i > mid) return query(2 * cur + 2, mid + 1, hi, i, j);
        return merge(
            query(2 * cur + 1, lo, mid, i, j), 
            query(2 * cur + 2, mid + 1, hi, i, j)
        );
    }
public:
    vector < int > resultArray(vector < int > & nums, int k_val, vector < vector < int > > & queries) {
        k = k_val;
        n = nums.size();
        tree.assign(4 * n, Node());
        for (int& num : nums) {
            num %= k;
        }
        build(nums, 0, 0, n - 1);
        vector < int > ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1] % k;
            int start = q[2];
            int x = q[3];
            update(0, 0, n - 1, index, value);
            ans.push_back(query(0, 0, n - 1, start, n - 1).remain[x]);
        }
        return ans;
    }
};