#pragma once
struct node {
	int key;
	int height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};
