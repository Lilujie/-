https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        connectTwoNodes(root->left, root->right);
        return root;
    }

    void connectTwoNodes(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return;
        }

        // 将传入的两个节点连接
        node1->next = node2;

        // 连接相同父节点的两个子节点
        connectTwoNodes(node1->left, node1->right);
        connectTwoNodes(node2->left, node2->right);
        // 连接跨越父节点的两个子节点
        connectTwoNodes(node1->right, node2->left);
    }
};