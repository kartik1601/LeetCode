class Solution {
public:
    struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int cost;
    TrieNode() : cost(INT_MAX) {}
};

void insert(TrieNode* root, const string& word, int cost) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->cost = min(node->cost, cost);
}

int minimumCost(string target, vector<string>& words, vector<int>& costs) {
    TrieNode* root = new TrieNode();
    int n = words.size();
    for (int i = 0; i < n; i++) {
        insert(root, words[i], costs[i]);
    }

    int targetLen = target.size();
    vector<int> dp(targetLen + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < targetLen; i++) {
        if (dp[i] == INT_MAX) continue;
        TrieNode* node = root;
        for (int j = i; j < targetLen; j++) {
            if (node->children.find(target[j]) == node->children.end()) break;
            node = node->children[target[j]];
            if (node->cost != INT_MAX) {
                dp[j + 1] = min(dp[j + 1], dp[i] + node->cost);
            }
        }
    }

    return dp[targetLen] == INT_MAX ? -1 : dp[targetLen];
}
};