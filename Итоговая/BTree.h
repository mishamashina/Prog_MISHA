#pragma once
#include <iostream>
#include <vector>
#include "tree.h"

class BTree : public Tree {
private:
	node* n;
	std::vector<int> data;
	int _size = 0;
	int st = 0;

	int find(node* n, int k, int idx);
	int height(node* p);
	int bfactor(node* p);
	void clear() { for (int i = 0; i < data.size(); i++) data[i] = 0; }
	void fixheight(node* p);
	void print_node(node* root, std::vector<int>& nums, int idx);
	node* insert(node* p, int k);
	node* balance(node* p);
	node* findmin(node* p) { return p->left ? findmin(p->left) : p; }
	node* remove(node* p, int k);
	node* removemin(node* p);
	node* rotateleft(node* q);
	node* rotateright(node* p);
public:
	node* n;
	std::vector<int> data;
	int _size = 0;
	int st = 0;

	int find(node* n, int k, int idx);
	int height(node* p);
	int bfactor(node* p);
	void clear() { for (int i = 0; i < data.size(); i++) data[i] = 0; }
	void fixheight(node* p);
	void print_node(node* root, std::vector<int>& nums, int idx);
	node* insert(node* p, int k);
	node* balance(node* p);
	node* findmin(node* p) { return p->left ? findmin(p->left) : p; }
	node* remove(node* p, int k);
	node* removemin(node* p);
	node* rotateleft(node* q);
	node* rotateright(node* p);
	void add(int k) override;
	void del(int k) override { remove(n, k); }
	void print();

	BTree(int k);
	BTree();
};