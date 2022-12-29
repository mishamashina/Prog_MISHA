#include "BTree.h"

int BTree::height(node* p) { return p ? p->height : 0; }
int BTree::bfactor(node* p) { return height(p->right) - height(p->left); }

void BTree::fixheight(node* p) {
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

node* BTree::rotateright(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* BTree::rotateleft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* BTree::balance(node* p) {
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

node* BTree::insert(node* p, int k) {
    if (!p) return new node(k);
    if (k < p->key) p->left = insert(p->left, k);
    else p->right = insert(p->right, k);
    return balance(p);
}

void BTree::add(int k) {
    _size++;
    n = insert(n, k);
    if (_size > data.size()) {
        data.resize(data.size() + std::pow(2, st));
        st++;
    }
}

node* BTree::removemin(node* p) {
    if (p->left == 0) return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node* BTree::remove(node* p, int k) {
    if (!p) return 0;
    if (k < p->key) p->left = remove(p->left, k);
    else if (k > p->key) p->right = remove(p->right, k);
    else
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if (!r) return q;
        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    clear();
    return balance(p);
}

int BTree::find(node* n, int k, int idx = 0) {
    if (n == nullptr) return -1;
    if (n->key < k) return find(n->right, k, idx * 2 + 2);
    if (n->key > k) return find(n->left, k, idx * 2 + 1);
    return idx;
}

void BTree::print_node(node* root, std::vector<int>& nums, int idx = 0) {
    if (root == nullptr) return;
    nums[idx] = root->key;
    print_node(root->left, nums, idx * 2 + 1);
    print_node(root->right, nums, idx * 2 + 2);
}

void BTree::print() {
    print_node(n, data);
    for (int val : data) std::cout << val << ' ';
}

BTree::BTree(int k) {
    n = new node(k);
    data.resize(1);
    _size = 0;
}

BTree::BTree() {
    n = nullptr;
    data.resize(0);
    _size = 0;
}