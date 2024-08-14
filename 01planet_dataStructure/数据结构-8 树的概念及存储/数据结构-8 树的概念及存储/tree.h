#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define Max 100

// ������������������������˫�ױ�ʾ��������������������������
struct TreeNode {
	int data;	// ����
	int parent;	// ˫�׽����±�
};
struct Tree
{
	TreeNode tree[Max];		// ���ݴ洢��˳���
	int n = 0;				// �������ݵĸ���

	// ������ x ��Ӧ���±�
	int find(int x) {
		for (int i = 0; i < n; i++) {
			if (tree[i].data == x)
				return i;
		}
		return -2;			// δ�ҵ� x
	}

	// ������ x ��˫�׽���±�
	int find_pa(int x) {
		for (int i = 0; i < n; i++) {
			if (tree[i].data == x) {
				if (tree[i].parent == -1)
					cout << "�ý���Ǹ���㣬û��˫�׽��" << endl;
				return tree[i].parent;
			}
		}

		cout << "����������Ϊ" << x << "�Ľ��" << endl;
		return -2;
	}

	// ������ x �ĺ��ӽ���±�
	int find_ch(int x) {
		// ���� x ���±�
		int index = find(x);
		if (index == -2) {
			cout << "����������Ϊ" << x << "�Ľ��" << endl;
			return -2;
		}

		for (int i = index + 1; i < n; i++) {
			if (tree[i].parent == index)
				return i;
		}

		cout << "�ý��û���ӽ��" << endl;
		return -2;
	}

	// ���±�Ϊ index �Ľ�㴴����ֵΪ x ���ӽ��
	void create_ch(int index, int x) {
		if (index < -1 || n == Max) return;	// �±겻�Ϸ�/���Ĵ洢�ռ�����

		tree[n].data = x;
		tree[n].parent = index;
		n++;
	}

	void display() {
		cout << "�±�\t����\t˫�׽ڵ�" << endl;
		for (int i = 0; i < n; i++) {
			cout << i << '\t' << tree[i].data << '\t' << tree[i].parent << endl;
		}
	}
};
// ������������������������˫�ױ�ʾ��������������������������

// ���������������������������ӱ�ʾ��������������������������
/*
�±�	  ����	���ӽ��
0	  R		-> 1 -> 2
1	  A		-> 4 -> 5
2	  B
3	  C		-> 6
*/

struct ChildNode {
	int index;			// ���ӽ����±�
	ChildNode* next;		// ��һ�����ӽ��

	ChildNode() :next(nullptr) {}
	ChildNode(int index) :index(index), next(nullptr) {}
};
struct TreeNode_2 {
	int data;			// ����
	ChildNode* child;	// ����ͷ���

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
	int n;				// �������ݵĸ���
public:
	vector<TreeNode_2*> tree;	// ���ݴ洢��˳���

	Tree_2(int x = 0) :n(1) {
		tree.push_back(new TreeNode_2(x));
	}
	~Tree_2() {
		for (auto node : tree) {
			delete node;
		}
		tree.clear();	// ���vector����������ָ��
	}

	// ������ x ��Ӧ���±�
	int find(int x) {
		if (n == 0) { cout << "��Ϊ�գ��޽��" << endl; return -1; }
		for (int i = 0; i < n; i++) {
			if (tree[i]->data == x)
				return i;
		}
		cout << "����������Ϊ" << x << "�Ľ��" << endl;
		return -2;			// δ�ҵ� x
	}

	// ������ x ��˫�׽���±�
	int find_pa(int x) {
		int index = find(x);		// ���ҵ��õ���±�
		if (index < 0) return index;
		if (index == 0) {
			cout << "�˽��Ϊ����㣬������˫�׽��" << endl;
			return -2;
		}

		for (int i = 0; i < n; i++) {
			if (tree[i]->child) {		// ���ں��ӽ��
				ChildNode* curr = tree[i]->child;
				while (curr) {
					if (curr->index == index) return i;		// ˫�׽���±�
					curr = curr->next;
				}
			}
		}

		cout << "�쳣���ý�㲻�Ǹ������û��˫�׽��" << endl;
		return -2;
	}

	// ������ x �ĺ��ӽ���±�
	int find_ch(int x) {
		int index = find(x);		// ���ҵ��õ���±�
		if (index < 0) return index;

		ChildNode* curr = tree[index]->child;
		if (!curr) { cout << "�ý��û�к��ӽڵ�" << endl; return -2; }
		cout << "����Ϊ" << x << "�ĺ��ӽ���±꣺";
		while (curr) {
			cout << curr->index << ' ';
			curr = curr->next;
		}
		cout << endl;
		return tree[index]->child->index;
	}

	void printTree() {
		if (n == 0) { cout << "��Ϊ�գ�û�н��" << endl; return; }
		cout << "�±�\t����\t���ӽ���±�" << endl;
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

		// ���¸����ĺ�������
		ChildNode* newChild = new ChildNode(n - 1);
		newChild->next = tree[index]->child;
		tree[index]->child = newChild;
	}
};
// ������������������������˫�ױ�ʾ��������������������������