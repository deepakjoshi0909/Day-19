class Solution {
public:
    void findNodesAtDistanceK(TreeNode* root, int k, vector<int>& arr) {
        if (!root) return;
        if (k == 0) {
            arr.push_back(root->val);
            return;
        }
        findNodesAtDistanceK(root->left, k - 1, arr);
        findNodesAtDistanceK(root->right, k - 1, arr);
    }

    int solve(TreeNode* root, TreeNode* target, int k, vector<int>& arr) {
        if (!root) return -1;

        if (root == target) {
            findNodesAtDistanceK(root, k, arr);
            return 0;
        }

        int leftDist = solve(root->left, target, k, arr);
        if (leftDist != -1) {
            if (leftDist + 1 == k) {
                arr.push_back(root->val);
            } else {
                findNodesAtDistanceK(root->right, k - leftDist - 2, arr);
            }
            return leftDist + 1;
        }

        int rightDist = solve(root->right, target, k, arr);
        if (rightDist != -1) {
            if (rightDist + 1 == k) {
                arr.push_back(root->val);
            } else {
                findNodesAtDistanceK(root->left, k - rightDist - 2, arr);
            }
            return rightDist + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> arr;
        solve(root, target, k, arr);
        return arr;
    }
};
