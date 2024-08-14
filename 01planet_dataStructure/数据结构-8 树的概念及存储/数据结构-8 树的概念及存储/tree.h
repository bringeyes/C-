#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define Max 100

// ————————————双亲表示法————————————
struct TreeNode {
	int data;	// 数据
	int parent;	// 双亲结点的下标
};
struct Tree
{
	TreeNode tree[Max];		// 数据存储在顺序表
	int n = 0;				// 树中数据的个数

	// 找数据 x 对应的下标
	int find(int x) {
		for (int i = 0; i < n; i++) {
			if (tree[i].data == x)
				return i;
		}
		return -2;			// 未找到 x
	}

	// 找数据 x 的双亲结点下标
	int find_pa(int x) {
		for (int i = 0; i < n; i++) {
			if (tree[i].data == x) {
				if (tree[i].parent == -1)
					cout << "该结点是根结点，没有双亲结点" << endl;
				return tree[i].parent;
			}
		}

		cout << "树中无数据为" << x << "的结点" << endl;
		return -2;
	}

	// 找数据 x 的孩子结点下标
	int find_ch(int x) {
		// 先找 x 的下标
		int index = find(x);
		if (index == -2) {
			cout << "树中无数据为" << x << "的结点" << endl;
			return -2;
		}

		for (int i = index + 1; i < n; i++) {
			if (tree[i].parent == index)
				return i;
		}

		cout << "该结点没有子结点" << endl;
		return -2;
	}

	// 对下标为 index 的结点创建数值为 x 的子结点
	void create_ch(int index, int x) {
		if (index < -1 || n == Max) return;	// 下标不合法/树的存储空间已满

		tree[n].data = x;
		tree[n].parent = index;
		n++;
	}

	void display() {
		cout << "下标\t数据\t双亲节点" << endl;
		for (int i = 0; i < n; i++) {
			cout << i << '\t' << tree[i].data << '\t' << tree[i].parent << endl;
		}
	}
};
// ————————————双亲表示法————————————

// ————————————孩子表示法————————————
/*
下标	  数据	孩子结点
0	  R		-> 1 -> 2
1	  A		-> 4 -> 5
2	  B
3	  C		-> 6
*/

struct ChildNode {
	int index;			// 孩子结点的下标
	ChildNode* next;		// 下一个孩子结点

	ChildNode() :next(nullptr) {}
	ChildNode(int index) :index(index), next(nullptr) {}
};
struct TreeNode_2 {
	int data;			// 数据
	ChildNode* child;	// 链表头结点

	TreeNode_2() :child(nullptr) {}
	TreeNode_2(int x) :data(x), child(nullptr) {}
	~TreeNode_2() {
		ChildNode* curr = child;
		while (curr) {
			ChildNode* next = curr->next;
			delete curr;
			curr = next;
		}
	}
};
struct Tree_2
{
private:
	int n;				// 树中数据的个数
public:
	vector<TreeNode_2*> tree;	// 数据存储在顺序表

	Tree_2(int x = 0) :n(1) {
		tree.push_back(new TreeNode_2(x));
	}
	~Tree_2() {
		for (auto node : tree) {
			delete node;
		}
		tree.clear();	// 清空vector，避免悬空指针
	}

	// 找数据 x 对应的下标
	int find(int x) {
		if (n == 0) { cout << "树为空，无结点" << endl; return -1; }
		for (int i = 0; i < n; i++) {
			if (tree[i]->data == x)
				return i;
		}
		cout << "树中无数据为" << x << "的结点" << endl;
		return -2;			// 未找到 x
	}

	// 找数据 x 的双亲结点下标
	int find_pa(int x) {
		int index = find(x);		// 先找到该点的下标
		if (index < 0) return index;
		if (index == 0) {
			cout << "此结点为根结点，不存在双亲结点" << endl;
			return -2;
		}

		for (int i = 0; i < n; i++) {
			if (tree[i]->child) {		// 存在孩子结点
				ChildNode* curr = tree[i]->child;
				while (curr) {
					if (curr->index == index) return i;		// 双亲结点下标
					curr = curr->next;
				}
			}
		}

		cout << "异常，该结点不是根结点且没有双亲结点" << endl;
		return -2;
	}

	// 找数据 x 的孩子结点下标
	int find_ch(int x) {
		int index = find(x);		// 先找到该点的下标
		if (index < 0) return index;

		ChildNode* curr = tree[index]->child;
		if (!curr) { cout << "该结点没有孩子节点" << endl; return -2; }
		cout << "数据为" << x << "的孩子结点下标：";
		while (curr) {
			cout << curr->index << ' ';
			curr = curr->next;
		}
		cout << endl;
		return tree[index]->child->index;
	}

	void printTree() {
		if (n == 0) { cout << "树为空，没有结点" << endl; return; }
		cout << "下标\t数据\t孩子结点下标" << endl;
		for (int i = 0; i < n; i++) {
			cout << i << '\t' << tree[i]->data << '\t';
			ChildNode* curr = tree[i]->child;
			while (curr) {
				cout << curr->index << ' ';
				curr = curr->next;
			}
			cout << endl;
		}
		cout << endl;
	}

	void addNode(int x, int newdata) {
		int index = find(x);
		if (index < 0) return;

		TreeNode_2* newNode = new TreeNode_2(newdata);
		tree.push_back(newNode);
		n++;

		// 更新父结点的孩子链表
		ChildNode* newChild = new ChildNode(n - 1);
		newChild->next = tree[index]->child;
		tree[index]->child = newChild;
	}
};
// ————————————双亲表示法————————————