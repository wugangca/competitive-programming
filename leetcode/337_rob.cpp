#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  std::unordered_map<TreeNode *, int> dp;

  int rob(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    if (dp.find(root) != dp.end()) {
      return dp[root];
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftValue = 0;
    if (left) {
      leftValue = rob(left->left) + rob(left->right);
    }
    int rightValue = 0;
    if (right) {
      rightValue = rob(right->left) + rob(right->right);
    }
    int ans = max(root->val + leftValue + rightValue,
                  rob(root->left) + rob(root->right));
    dp[root] = ans;
    return ans;
  }
};