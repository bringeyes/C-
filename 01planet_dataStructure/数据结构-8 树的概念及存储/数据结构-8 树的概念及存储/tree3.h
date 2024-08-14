#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
兄弟孩子表示法
有两个指针域，一个指向第一个孩子，另一个指向亲兄弟
*/

struct treeNode
{
	char data;
	treeNode* parent;
	treeNode* first_child;
	treeNode* brother;

	treeNode() :data(0), parent(nullptr), first_child(nullptr), brother(nullptr) {}
	treeNode(char x) :data(x), parent(nullptr), first_child(nullptr), brother(nullptr) {}
	// ~treeNode(){} // 注意：不在结点进行内存管理，而是在 Tree 类中统一管理
};
struct Tree
{
	treeNode* root;				// 根结点
	vector<treeNode*> tree;		// 树

	Tree(char x = 0) { root = new treeNode(x); tree.push_back(root); }
	~Tree() {
		for (auto node : tree) delete node;
		tree.clear();			// 清空vector
	}

	// 找到数据为 x 的结点
	treeNode* find(char x) const {
		if (!root) { cout << "树为空" << endl; return nullptr; }

		for (auto node : tree) {
			if (node->data == x) return node;
		}

		cout << "未找到数据为 " << x << " 的结点。" << endl;
		return nullptr;
	}

	// 添加新结点，其父结点数据x，新结点数据newdata
	bool addNode(char x, char newdata) {
		treeNode* parent = find(x);
		if (!parent) return false;

		treeNode* newNode = new treeNode(newdata);
		newNode->parent = parent;
		tree.push_back(newNode);			// 添加在树尾

		treeNode* curr = parent->first_child;
		if (curr) {
			while (curr->brother) {
				curr = curr->brother;
			}
			curr->brother = newNode;		// 添加在兄弟链尾
		}
		else parent->first_child = newNode;		// 添加在第一个孩子结点

		return true;
	}

	// 删除数据为 x 的结点
	bool deleteNode(char x) {
		treeNode* node = find(x);
		if (!node) return false;
		if (node == root) { cout << "不能删除根结点" << endl; return false; }

		// 处理双亲结点、兄弟结点的关系
		if (node->parent->first_child == node) {
			node->parent->first_child = node->brother;
		}
		else {
			treeNode* curr = node->parent->first_child;
			while (curr->brother != node) {
				curr = curr->brother;
			}
			curr->brother = node->brother;
		}

		// 递归删除结点及子结点
		deleteNodeHelper(node);

		return true;
	}

	// 打印树
	void printTree()const {
		if (!root) { cout << "树为空" << endl; return; }
		cout << "Tree:" << endl;
		printTreeHelper(root, 1);
		cout << endl;
	}

private:
	// 递归删除结点及子结点
	void deleteNodeHelper(treeNode* node) {
		if (!node) return;

		// 递归删除子结点
		treeNode* curr = node->first_child, * next = nullptr;
		while (curr) {
			next = curr->brother;
			deleteNodeHelper(curr);
			curr = next;
		}

		// 从tree向量中删除结点
		auto it = std::find(tree.begin(), tree.end(), node);		// 使用std::避免同名成员函数
		if (it != tree.end()) tree.erase(it);

		// 删除当前结点
		delete node;
	}

	// 递归打印树的结点
	void printTreeHelper(treeNode* node, int depth)const {
		if (!node) return;		// 递归中止条件

		// 打印当前结点
		for (int i = 0; i < depth; i++) cout << "  ";
		cout << node->data << endl;

		// 打印所有孩子结点
		printTreeHelper(node->first_child, depth + 1);

		// 打印兄弟结点
		printTreeHelper(node->brother, depth);
	}
};
