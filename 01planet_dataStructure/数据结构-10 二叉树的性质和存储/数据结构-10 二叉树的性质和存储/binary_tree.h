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
	TreeNode<T>* left;		// ���ӽ��
	TreeNode<T>* right;		// �Һ��ӽ��

	TreeNode(T x) :data(x), left(nullptr), right(nullptr) {}
};

template<typename T>
struct BinaryTree
{
	TNode* root;		// �����

	BinaryTree() { root = new TNode(0); }
	~BinaryTree() { deleteTree(root); }

	// ����ֵΪx�Ľ��
	TNode* find(T x)const {
		return findHelper(root, x);
	}

	// ����ֵΪx�Ľ��ĸ����
	TNode* findParent(T x) const {
		return findParentHelper(root, nullptr, x);
	}

	// ���ֵΪvalue�Ľ�㣬��ֵΪx�Ľ���£�option--0Ϊ���㣬1Ϊ�ҽ��
	bool addNode(T x, T value, bool option = 0) {
		TNode* parent = find(x);
		if (!parent) return false;

		// ��ӵ��ҽ��
		if (option && !parent->right) {
			TNode* newNode = new TNode(value);
			parent->right = newNode;
			return true;
		}
		// ��ӵ�����
		if (!option && !parent->left) {
			TNode* newNode = new TNode(value);
			parent->left = newNode;
			return true;
		}

		return false;
	}

	// ɾ��ֵΪx�Ľ��
	bool deleteNode(T x) {
		// ���ɾ�����Ǹ����
		if (root->data == x) {
			deleteTree(root); root = nullptr;
			return true;
		}

		TNode* parent = findParent(x);
		if (!parent) return false;	// ���Ҫɾ���Ľ�㲻���ڣ�����false

		// ɾ����/�ҷ�֧��������˫�׽���ָ��
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

	// ��ӡ��
	void printTree()const {
		if (!root) { cout << "��Ϊ��" << endl; return; }
		cout << "Tree:" << endl;
		printTreeHelper(root, 1);
		cout << endl;
	}

	// ��α�������ӡ
	void levelOrderTraversal()const {
		if (!root) { cout << "��Ϊ��" << endl; return; }

		Queue<T>* q = new Queue<T>;
		q->enqueue(root->data);		// ����Ӹ����Ԫ�أ���֤���зǿ�

		// ֻҪ���в�Ϊ��
		while (!q->empty()) {
			T x = q->dequeue();		// ���Ӹ�x
			cout << x << ' ';

			TNode* curr = find(x);		// �ҵ���ǰ���
			// ������ҽ��
			if (curr->left) q->enqueue(curr->left->data);
			if (curr->right) q->enqueue(curr->right->data);
		}
		cout << endl;
	}
	/*
	// ����������ݹ飩
		void preOrderTraversal(TNode* node)const {
			if (!node) return;

			cout << node->data << ' ';
			preOrderTraversal(node->left);
			preOrderTraversal(node->right);
		}
		// ����������ݹ飩
		void inOrderTraversal(TNode* node)const {
			if (!node) return;

			inOrderTraversal(node->left);
			cout << node->data << ' ';
			inOrderTraversal(node->right);
		}
		// ����������ݹ飩
		void postOrderTraversal(TNode* node)const {
			if (!node) return;

			postOrderTraversal(node->left);
			postOrderTraversal(node->right);
			cout << node->data << ' ';
		}
	*/

	// ���������ջ&ѭ����
	void preOrderTraversal(TNode* node)const {
		if (!node) return;

		Stack<TNode*> s;			// ���������ջ
		s.push(node);

		while (!s.empty()) {		// ջ�ǿգ�ѭ��
			TNode* p = s.pop();	// ��ջ�� p

			// ���ʽ��
			cout << p->data << ' ';

			// ��ѹ���ҽ�㣬��ѹ������
			// ��֤��һ��ѭ���������ȱ�����
			if (p->right) s.push(p->right);
			if (p->left) s.push(p->left);
		}
	}
	// ���������ջ&ѭ����
	void inOrderTraversal(TNode* node)const {
		if (!node) return;

		Stack<TNode*> s;			// ���������ջ
		TNode* curr = node;

		while (curr || !s.empty()) {		// curr���ڻ�ջ�ǿգ�ѭ��
			// �ߵ��������ľ�ͷ
			while (curr) {
				s.push(curr);			// ѹ��;���Ľ��
				curr = curr->left;
			}

			// ���ʽ�㲢ת��������
			curr = s.pop();				// currΪ�վ͵���ջ������¼���ǵ�ǰ�������ĸ���㣩
			cout << curr->data << ' ';
			curr = curr->right;
		}
	}
	// ���������ջ&ѭ����
	void postOrderTraversal(TNode* node)const {
		if (!node) return;

		/*
		ʹ��һ��ջʵ�֣�˼·ͬ�����������
			curr��node��ʼ�����������������߱���ջ���ߵ��ս��ʱ���ж�ջ��Ԫ��
			���������������currָ�����������
			�ȱ��������������ص������ʱ�ű�������㡣������һ��preָ�򷵻�ʱ�Ľ�㣬
				���pre�ǵ�ǰ�������ҽ�������������ָ���ҽ�㣩
		*/
		Stack<TNode*> s;
		TNode* curr = node;
		TNode* lastVisited = nullptr;	// ��ǰ���ʵĽ��

		while (curr || !s.empty()) {
			// ���߱���ջ����������������ͷ
			while (curr) {
				s.push(curr);
				curr = curr->left;
			}

			TNode* peekNode = s.getTop();		// �ߵ��ս�㣬�ж�ջ��Ԫ��
			// ������ӽ��Ϊ�ջ��ѷ��ʹ�������ʵ�ǰ���
			if (!peekNode->right || lastVisited == peekNode->right) {
				cout << peekNode->data << ' ';
				s.pop();					// ������Ѵ�Ԫ�س�ջ
				lastVisited = peekNode;		// �����ϴη���
			}
			else curr = peekNode->right;	// ����ת�������ӽ��
		}
	}
	// ���������������ջʵ��
	void postOrderTraversal_2(TNode* node)const {
		if (!node) return;

		Stack<TNode*> s1, s2;
		s1.push(node);			// ������ĸ����ѹ��ջ

		// 1ջ���ڰ��� ��-��-�� ��˳��洢���
		while (!s1.empty()) {
			TNode* curr = s1.pop();
			s2.push(curr);		// ����ջ����2ջ

			// ѹ�����ҽ��
			if (curr->left) s1.push(curr->left);
			if (curr->right) s1.push(curr->right);
		}

		// 2ջ���ڽ���Щ�����������Ϊ ��-��-�� ��˳��
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
		if (found) return found;				// �������֧�ң�����ҵ����ؽ��

		return findHelper(node->right, x);	// �����Ƿ��ҵ��������ҷ�֧���
	}

	TNode* findParentHelper(TNode* node, TNode* parent, T x)const {
		if (!node) return nullptr;
		if (node->data == x) return parent;

		// �ݹ��߼�ͬ findHelper()
		TNode* found = findParentHelper(node->left, node, x);
		if (found) return found;

		return findParentHelper(node->right, node, x);
	}

	// �ݹ��ӡ���Ľ�㣨��������������->������->��������
	void printTreeHelper(TNode* node, int depth)const {
		if (!node) return;		// �ݹ���ֹ����

		// ��ӡ��ǰ���
		for (int i = 0; i < depth; i++) cout << "  ";
		cout << node->data << endl;

		// ��ӡ�������ӽ��
		printTreeHelper(node->left, depth + 1);

		// ��ӡ�����Һ��ӽ��
		printTreeHelper(node->right, depth + 1);
	}
};