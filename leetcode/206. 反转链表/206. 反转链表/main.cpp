/*

*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// 返回一个新链表
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return nullptr;

		ListNode* pA = new ListNode;		// pA作为反转链表的头结点
		while (head) {
			ListNode* pB = new ListNode(head->val);		// 新建结点，复制 head 存放的值
			// 使用头插法插入到反转链表
			pB->next = pA->next;
			pA->next = pB;

			head = head->next;
		}

		ListNode* reverse = pA->next;
		delete pA;
		pA = nullptr;
		return reverse;
	}

	// 改变原链表指向，使之反转
	ListNode* reverseList_1(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;

		ListNode* curr = head->next;		// 遍历原链表
		ListNode* pre = nullptr;			// 前继结点
		head->next = nullptr;

		while (curr) {
			pre = curr;
			curr = curr->next;
			pre->next = head;
			head = pre;
		}
		return pre;
	}
};

void printList(ListNode* l) {
	while (l) {
		cout << l->val << ' ' << &(*l) << '\t';
		l = l->next;
	}
	cout << endl;
}

void head_insert(ListNode* l, int x) {
	ListNode* tmp = new ListNode(x);
	tmp->next = l->next;
	l->next = tmp;
}

int main()
{
	ListNode l;
	for (int i = 0; i < 5; i++) {
		head_insert(&l, i + 1);
	}
	printList(&l);

	Solution s;
	ListNode* r1 = s.reverseList(&l);
	printList(r1);

	ListNode* r2 = s.reverseList_1(&l);
	printList(r2);
}