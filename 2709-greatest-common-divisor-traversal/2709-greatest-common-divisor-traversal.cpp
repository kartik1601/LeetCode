class Solution {
    // Function to find the root of a set using path compression
    int find(vector<int> &parent, int x) {
        return parent[x] == x ? x : (parent[x] = find(parent, parent[x]));
    }
    
    // Function to merge two sets and update the frequency
    void merge(vector<int> &p, vector<int> &num, int x, int y) {
        x = find(p, x);
        y = find(p, y);
        if (x == y) {return;}
        
        if (num[x] < num[y]) {swap(x, y);}
        
        p[y] = x;
        num[x] += num[y];
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {return true;}
        
        // Union Find : DSU
        vector<int> parent(n), num(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            num[i] = 1;
        }
        
        // Map to store the first index encountered for each prime factor
        unordered_map<int, int> have;
        
        // Iterate through the array to find common prime factors and perform Union-Find
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 1) {return false;}
            
            // Iterate through prime factors of x
            for (int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    // If the prime factor is encountered before, merge the sets
                    if (have.find(d)!=have.end()) {
                        merge(parent, num, i, have[d]);
                    } else {
                        // Otherwise, store the index for this prime factor
                        have[d] = i;
                    }
                    while (x % d == 0) {
                        x /= d;
                    } 
                }
            }
            
            // Handle the case where x itself is a prime factor
            if (x > 1) {
                if (have.find(x)!=have.end()) {
                    merge(parent, num, i, have[x]);
                } else {
                    have[x] = i;
                }
            }
        }
        
        // Check if all indices belong to the same connected component
        return num[find(parent, 0)] == n;
    }
};