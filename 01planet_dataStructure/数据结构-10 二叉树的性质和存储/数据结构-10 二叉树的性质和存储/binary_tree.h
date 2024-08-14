#pragma once
#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;
#define TNode TreeNode<T>

template<typename T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;		// 左孩子结点
	TreeNode<T>* right;		// 右孩子结点

	TreeNode(T x) :data(x), left(nullptr), right(nullptr) {}
};

template<typename T>
struct BinaryTree
{
	TNode* root;		// 根结点

	BinaryTree() { root = new TNode(0); }
	~BinaryTree() { deleteTree(root); }

	// 查找值为x的结点
	TNode* find(T x)const {
		return findHelper(root, x);
	}

	// 查找值为x的结点的父结点
	TNode* findParent(T x) const {
		return findParentHelper(root, nullptr, x);
	}

	// 添加值为value的结点，到值为x的结点下，option--0为左结点，1为右结点
	bool addNode(T x, T value, bool option = 0) {
		TNode* parent = find(x);
		if (!parent) return false;

		// 添加到右结点
		if (option && !parent->right) {
			TNode* newNode = new TNode(value);
			parent->right = newNode;
			return true;
		}
		// 添加到左结点
		if (!option && !parent->left) {
			TNode* newNode = new TNode(value);
			parent->left = newNode;
			return true;
		}

		return false;
	}

	// 删除值为x的结点
	bool deleteNode(T x) {
		// 如果删除的是根结点
		if (root->data == x) {
			deleteTree(root); root = nullptr;
			return true;
		}

		TNode* parent = findParent(x);
		if (!parent) return false;	// 如果要删除的结点不存在，返回false

		// 删除左/右分支，并处理双亲结点的指针
		if (parent->left) {
			if (parent->left->data == x) {
				deleteTree(parent->left);
				parent->left = nullptr;
			}
		}
		else {
			deleteTree(parent->right);
			parent->right = nullptr;
		}

		return true;
	}

	// 打印树
	void printTree()const {
		if (!root) { cout << "树为空" << endl; return; }
		cout << "Tree:" << endl;
		printTreeHelper(root, 1);
		cout << endl;
	}

	// 层次遍历并打印
	void levelOrderTraversal()const {
		if (!root) { cout << "树为空" << endl; return; }

		Queue<T>* q = new Queue<T>;
		q->enqueue(root->data);		// 先入队根结点元素，保证队列非空

		// 只要队列不为空
		while (!q->empty()) {
			T x = q->dequeue();		// 出队给x
			cout << x << ' ';

			TNode* curr = find(x);		// 找到当前结点
			// 入队左右结点
			if (curr->left) q->enqueue(curr->left->data);
			if (curr->right) q->enqueue(curr->right->data);
		}
		cout << endl;
	}
	/*
	// 先序遍历（递归）
		void preOrderTraversal(TNode* node)const {
			if (!node) return;

			cout << node->data << ' ';
			preOrderTraversal(node->left);
			preOrderTraversal(node->right);
		}
		// 中序遍历（递归）
		void inOrderTraversal(TNode* node)const {
			if (!node) return;

			inOrderTraversal(node->left);
			cout << node->data << ' ';
			inOrderTraversal(node->right);
		}
		// 后序遍历（递归）
		void postOrderTraversal(TNode* node)const {
			if (!node) return;

			postOrderTraversal(node->left);
			postOrderTraversal(node->right);
			cout << node->data << ' ';
		}
	*/

	// 先序遍历（栈&循环）
	void preOrderTraversal(TNode* node)const {
		if (!node) return;

		Stack<TNode*> s;			// 存放树结点的栈
		s.push(node);

		while (!s.empty()) {		// 栈非空，循环
			TNode* p = s.pop();	// 出栈给 p

			// 访问结点
			cout << p->data << ' ';

			// 先压入右结点，再压入左结点
			// 保证下一个循环中左结点先被处理
			if (p->right) s.push(p->right);
			if (p->left) s.push(p->left);
		}
	}
	// 中序遍历（栈&循环）
	void inOrderTraversal(TNode* node)const {
		if (!node) return;

		Stack<TNode*> s;			// 存放树结点的栈
		TNode* curr = node;

		while (curr || !s.empty()) {		// curr存在或栈非空，循环
			// 走到左子树的尽头
			while (curr) {
				s.push(curr);			// 压入途径的结点
				curr = curr->left;
			}

			// 访问结点并转向右子树
			curr = s.pop();				// curr为空就弹出栈顶（记录的是当前左子树的根结点）
			cout << curr->data << ' ';
			curr = curr->right;
		}
	}
	// 后序遍历（栈&循环）
	void postOrderTraversal(TNode* node)const {
		if (!node) return;

		/*
		使用一个栈实现（思路同中序遍历）：
			curr从node开始向左子树遍历，边走边入栈，走到空结点时，判断栈顶元素
			如果有右子树，则curr指向该右子树。
			先遍历右子树，返回到根结点时才遍历根结点。（设置一个pre指向返回时的结点，
				如果pre是当前根结点的右结点则遍历，否则指向右结点）
		*/
		Stack<TNode*> s;
		TNode* curr = node;
		TNode* lastVisited = nullptr;	// 先前访问的结点

		while (curr || !s.empty()) {
			// 边走边入栈，遍历左子树到尽头
			while (curr) {
				s.push(curr);
				curr = curr->left;
			}

			TNode* peekNode = s.getTop();		// 走到空结点，判断栈顶元素
			// 如果右子结点为空或已访问过，则访问当前结点
			if (!peekNode->right || lastVisited == peekNode->right) {
				cout << peekNode->data << ' ';
				s.pop();					// 访问完把此元素出栈
				lastVisited = peekNode;		// 更新上次访问
			}
			else curr = peekNode->right;	// 否则转向处理右子结点
		}
	}
	// 后序遍历，用两个栈实现
	void postOrderTraversal_2(TNode* node)const {
		if (!node) return;

		Stack<TNode*> s1, s2;
		s1.push(node);			// 须遍历的根结点压入栈

		// 1栈用于按照 根-右-左 的顺序存储结点
		while (!s1.empty()) {
			TNode* curr = s1.pop();
			s2.push(curr);		// 弹出栈顶给2栈

			// 压入左、右结点
			if (curr->left) s1.push(curr->left);
			if (curr->right) s1.push(curr->right);
		}

		// 2栈用于将这些结点重新排列为 左-右-根 的顺序
		while (!s2.empty()) {
			cout << s2.pop()->data << ' ';
		}
		cout << endl;
	}

private:
	void deleteTree(TNode* node) {
		if (!node) return;

		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	TNode* findHelper(TNode* node, T x)const {
		if (!node || node->data == x) return node;
		TNode* found = findHelper(node->left, x);
		if (found) return found;				// 先在左分支找，如果找到返回结果

		return findHelper(node->right, x);	// 不管是否找到都返回右分支结果
	}

	TNode* findParentHelper(TNode* node, TNode* parent, T x)const {
		if (!node) return nullptr;
		if (node->data == x) return parent;

		// 递归逻辑同 findHelper()
		TNode* found = findParentHelper(node->left, node, x);
		if (found) return found;

		return findParentHelper(node->right, node, x);
	}

	// 递归打印树的结点（先序遍历：根结点->左子树->右子树）
	void printTreeHelper(TNode* node, int depth)const {
		if (!node) return;		// 递归中止条件

		// 打印当前结点
		for (int i = 0; i < depth; i++) cout << "  ";
		cout << node->data << endl;

		// 打印所有左孩子结点
		printTreeHelper(node->left, depth + 1);

		// 打印所有右孩子结点
		printTreeHelper(node->right, depth + 1);
	}
};