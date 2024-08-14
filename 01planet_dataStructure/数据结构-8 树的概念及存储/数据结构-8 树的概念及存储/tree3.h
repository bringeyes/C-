#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
�ֵܺ��ӱ�ʾ��
������ָ����һ��ָ���һ�����ӣ���һ��ָ�����ֵ�
*/

struct treeNode
{
	char data;
	treeNode* parent;
	treeNode* first_child;
	treeNode* brother;

	treeNode() :data(0), parent(nullptr), first_child(nullptr), brother(nullptr) {}
	treeNode(char x) :data(x), parent(nullptr), first_child(nullptr), brother(nullptr) {}
	// ~treeNode(){} // ע�⣺���ڽ������ڴ���������� Tree ����ͳһ����
};
struct Tree
{
	treeNode* root;				// �����
	vector<treeNode*> tree;		// ��

	Tree(char x = 0) { root = new treeNode(x); tree.push_back(root); }
	~Tree() {
		for (auto node : tree) delete node;
		tree.clear();			// ���vector
	}

	// �ҵ�����Ϊ x �Ľ��
	treeNode* find(char x) const {
		if (!root) { cout << "��Ϊ��" << endl; return nullptr; }

		for (auto node : tree) {
			if (node->data == x) return node;
		}

		cout << "δ�ҵ�����Ϊ " << x << " �Ľ�㡣" << endl;
		return nullptr;
	}

	// ����½�㣬�丸�������x���½������newdata
	bool addNode(char x, char newdata) {
		treeNode* parent = find(x);
		if (!parent) return false;

		treeNode* newNode = new treeNode(newdata);
		newNode->parent = parent;
		tree.push_back(newNode);			// �������β

		treeNode* curr = parent->first_child;
		if (curr) {
			while (curr->brother) {
				curr = curr->brother;
			}
			curr->brother = newNode;		// ������ֵ���β
		}
		else parent->first_child = newNode;		// ����ڵ�һ�����ӽ��

		return true;
	}

	// ɾ������Ϊ x �Ľ��
	bool deleteNode(char x) {
		treeNode* node = find(x);
		if (!node) return false;
		if (node == root) { cout << "����ɾ�������" << endl; return false; }

		// ����˫�׽�㡢�ֵܽ��Ĺ�ϵ
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

		// �ݹ�ɾ����㼰�ӽ��
		deleteNodeHelper(node);

		return true;
	}

	// ��ӡ��
	void printTree()const {
		if (!root) { cout << "��Ϊ��" << endl; return; }
		cout << "Tree:" << endl;
		printTreeHelper(root, 1);
		cout << endl;
	}

private:
	// �ݹ�ɾ����㼰�ӽ��
	void deleteNodeHelper(treeNode* node) {
		if (!node) return;

		// �ݹ�ɾ���ӽ��
		treeNode* curr = node->first_child, * next = nullptr;
		while (curr) {
			next = curr->brother;
			deleteNodeHelper(curr);
			curr = next;
		}

		// ��tree������ɾ�����
		auto it = std::find(tree.begin(), tree.end(), node);		// ʹ��std::����ͬ����Ա����
		if (it != tree.end()) tree.erase(it);

		// ɾ����ǰ���
		delete node;
	}

	// �ݹ��ӡ���Ľ��
	void printTreeHelper(treeNode* node, int depth)const {
		if (!node) return;		// �ݹ���ֹ����

		// ��ӡ��ǰ���
		for (int i = 0; i < depth; i++) cout << "  ";
		cout << node->data << endl;

		// ��ӡ���к��ӽ��
		printTreeHelper(node->first_child, depth + 1);

		// ��ӡ�ֵܽ��
		printTreeHelper(node->brother, depth);
	}
};
