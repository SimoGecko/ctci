/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TN;

TN *pp, *qq;

class TN{
public:
    TN(TreeNode* node, TN* par, TreeNode* p, TreeNode* q) : v(node->val), a(par), m(false), o(node) {
        if(node->left ) l = new TN(node->left,  this, p, q);
        if(node->right) r = new TN(node->right, this, p, q);
        if(node == p) pp = this;
        if(node == q) qq = this;
    }
    
    ~TN(){
        delete l;
        delete r;
    }
    
    int v;
    TN *l, *r, *a;
    TreeNode* o;
    bool m;
};




class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TN* r = new TN(root, nullptr, p, q);
        //mark
        while(pp!=nullptr){
            pp->m = true;
            pp = pp->a;
        }
        //find next
        while(qq!=nullptr){
            if(qq->m) return qq->o;
            qq = qq->a;
        }
        return nullptr;
    }
};

