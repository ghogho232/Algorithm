#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int idx;
    int x, y;
    Node *left;
    Node *right;
};

bool Cmp(Node a, Node b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void makeTree(Node* parent, Node* child){
    if(parent->x > child->x){
        if(parent->left == NULL){
            parent->left = child;
        }
        else{
            makeTree(parent->left, child);
        }
    }
    else{
        if(parent->right == NULL){
            parent->right = child;
        }
        else{
            makeTree(parent->right, child);
        }
    }
}

void preorder(Node *root, vector<int> &pre){
    pre.push_back(root->idx);
    if(root->left != NULL) preorder(root->left, pre);
    if(root->right != NULL) preorder(root->right, pre);
}
void postorder(Node *root, vector<int> &post){
    if(root->left != NULL) postorder(root->left, post);
    if(root->right != NULL) postorder(root->right, post);
    post.push_back(root->idx);
}
vector<vector<int>> solution(vector<vector<int>> Nodeinfo) {
    vector<vector<int>> answer;
    vector<Node>Tree;
    for(int i = 0; i < Nodeinfo.size(); i++){
        int x = Nodeinfo[i][0];
        int y = Nodeinfo[i][1];
        int idx = i + 1;
        Tree.push_back({idx, x, y, NULL, NULL});
    }
    sort(Tree.begin(), Tree.end(), Cmp);
    Node *root = &Tree[0];
    
    for(int i = 1; i < Tree.size(); i++){
        makeTree(root, &Tree[i]);
    }
    vector<int>pre;
    vector<int>post;
    preorder(root, pre);
    postorder(root, post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}