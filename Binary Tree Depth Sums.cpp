/*
Q1 : Sum of depths of nodes in a binary tree

Q2 : For all trees present in a binary tree (sub-trees too), calculate sum total of depths of nodes
*/

#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

void addBinaryTreeEdge(vector<BinaryTreeNode*> &V, int i, int j, bool left) {
    if (V[i]==NULL) {
        V[i] = new BinaryTreeNode(i);
    }
    if (V[j]==NULL) {
        V[j] = new BinaryTreeNode(j);
    }
    if (left) {
        V[i]->left = V[j];
    } else {
        V[i]->right = V[j];
    }
    V[j]->parent = V[i];
}

int calculateSumOfDepthsUnderNode(BinaryTreeNode* node, int currDepth) {
    cout<<".";
    if (node==NULL) {
        return 0;
    }
    return calculateSumOfDepthsUnderNode(node->left, currDepth+1) + calculateSumOfDepthsUnderNode(node->right, currDepth+1) + currDepth;
}

int calculateSumOfSumOfDepthsUnderNode(BinaryTreeNode* node, int currDepth) {
    if (node==NULL) {
        return 0;
    }
    return calculateSumOfDepthsUnderNode(node, currDepth) + calculateSumOfSumOfDepthsUnderNode(node->left, 0) + calculateSumOfSumOfDepthsUnderNode(node->right, 0);
}

pair<int,int> dfs(BinaryTreeNode* node, vector<pair<int,int>> &treeParameters) {
    cout<<".";
    // treeParameters -> tree sum of depths, number of nodes
    if (node==NULL) {
        return make_pair(0, 0);
    }
    pair<int,int> leftTreeParams = dfs(node->left, treeParameters);
    pair<int,int> rightTreeParams = dfs(node->right, treeParameters);
    treeParameters[node->val] = make_pair(leftTreeParams.first + leftTreeParams.second + rightTreeParams.first + rightTreeParams.second, leftTreeParams.second + rightTreeParams.second + 1);
    return treeParameters[node->val];
}

pair<int,int> dfsWithoutSavingState(BinaryTreeNode* node, int &totalSum) {
    cout<<".";
    if (node==NULL) {
        return make_pair(0, 0);
    }
    pair<int,int> leftTreeParams = dfsWithoutSavingState(node->left, totalSum);
    pair<int,int> rightTreeParams = dfsWithoutSavingState(node->right, totalSum);
    totalSum+=(leftTreeParams.first + leftTreeParams.second + rightTreeParams.first + rightTreeParams.second);
    return make_pair(leftTreeParams.first + leftTreeParams.second + rightTreeParams.first + rightTreeParams.second, leftTreeParams.second + rightTreeParams.second + 1);
}

int calculateSumOfSums(vector<pair<int,int>> &treeParameters) {
    int count=0;
    for(int i=0 ; i<treeParameters.size() ; i++) {
        count+=treeParameters[i].first;
    }
    return count;
}

int calculateSumOfDistancesOfAllNodesFrom(BinaryTreeNode* target, vector<pair<int,int>> &treeParameters, int nodeNum) {
    
    stack<BinaryTreeNode*> ancestorsStack;
    while(target!=NULL) {
        ancestorsStack.push(target);
        target=target->parent;
    }
    pair<int,int> currNodeParams = make_pair(0,0);
    while(ancestorsStack.size()>1) {
        BinaryTreeNode* node = ancestorsStack.top();
        ancestorsStack.pop();
        // get the non inline subtree
        if (node->left!=NULL && node->left!=ancestorsStack.top()) {
            currNodeParams=make_pair(treeParameters[node->left->val].first + treeParameters[node->left->val].second, treeParameters[node->left->val].second+1);
        } else if (node->right!=NULL && node->right!=ancestorsStack.top()) {
            currNodeParams=make_pair(treeParameters[node->right->val].first + treeParameters[node->right->val].second, treeParameters[node->right->val].second+1);
        }
    }
    return treeParameters[nodeNum].first + currNodeParams.first + currNodeParams.second;
}

int main() {
    int N = 9;
    vector<BinaryTreeNode*> V(N, NULL);
    addBinaryTreeEdge(V, 0, 1, true);
    addBinaryTreeEdge(V, 0, 2, false);
    addBinaryTreeEdge(V, 1, 3, true);
    addBinaryTreeEdge(V, 1, 4, false);
    addBinaryTreeEdge(V, 2, 5, true);
    addBinaryTreeEdge(V, 2, 6, false);
    addBinaryTreeEdge(V, 3, 7, true);
    addBinaryTreeEdge(V, 3, 8, false);
    
    cout<<calculateSumOfDepthsUnderNode(V[0], 0)<<endl;
    
    cout<<calculateSumOfSumOfDepthsUnderNode(V[0], 0)<<endl;
    
    int totalSum=0;
    dfsWithoutSavingState(V[0],totalSum);
    cout<<totalSum<<endl;
    
    vector<pair<int,int>> treeParameters(N);
    dfs(V[0], treeParameters);
    cout<<calculateSumOfSums(treeParameters)<<endl;
    
    cout<<calculateSumOfDistancesOfAllNodesFrom(V[2], treeParameters, 2)<<endl;
    cout<<calculateSumOfDistancesOfAllNodesFrom(V[0], treeParameters, 0)<<endl;

    return 0;
}

/*

For tree
              0
        1          2
    3      4    5     6
7      8

Output : 
...................16
...........................................................26
...................26
...................26
2
19
1
16
*/
