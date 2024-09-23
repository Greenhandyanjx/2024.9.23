#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    }
};
class Solution {
public:
    vector<int>path;
    vector<vector<int>>res;
    void dfs(TreeNode* root, int target, int sum) {
        if (sum == target && root->left == NULL && root->right == NULL) {
            res.push_back(path);
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            dfs(root->left, target, sum + root->left->val);
            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            dfs(root->right, target, sum + root->right->val);
            path.pop_back();
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)return res;
        path.push_back(root->val);
        dfs(root, targetSum, root->val);
        return res;
    }
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)return true;
        else if (p == NULL || q == NULL)return false;
        bool leftV = isSameTree(p->left, q->left);
        bool rightV = isSameTree(p->right, q->right);
        if (p->val == q->val) {
            return leftV && rightV;
        }
        else return false;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>v;
        vector<int>res;
        vector<vector<int>>graph(numCourses, v);
        vector<int>indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int fro = prerequisites[i][0];
            int sec = prerequisites[i][1];
            indegree[fro]++;
            graph[sec].push_back(fro);
        }
        int count = 0;
        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)q.push(i);
        }
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            count++;
            for (int i = 0; i < graph[temp].size(); i++) {
                indegree[graph[temp][i]]--;
                if (indegree[graph[temp][i]] == 0) {
                    q.push(i);
                }
            }
        }
        if (count == numCourses)return res;
        else return v;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>v;
        vector<vector<int>>graph(numCourses,v);
        vector<int>indegree(numCourses);
        int count = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        for (int i = 0; i < graph.size(); i++) {
            //indegree[i] = graph[i].size();
            if (indegree[i] == 0)q.push(i);
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            count++;
            for (int i = 0; i < graph[temp].size(); i++) {
                indegree[graph[temp][i]]--;
                if (indegree[graph[temp][i]] == 0) {
                    q.push(graph[temp][i]);
                }
            }
        }
        return count == numCourses;
    }
};