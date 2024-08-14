/*

*/

#include <iostream>
using namespace std;

// 单链表
typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
}*linklist;

// 返回两个单链表相交的起始节点
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;

		// 双指针法，先分别从两个单链表的头结点后移，
		// 遍历完当前链表后从另一链表头结点后移，并判断相等
		ListNode* pa = headA, * pb = headB;
		while (pa != pb) {
			pa = pa == nullptr ? headB : pa->next;
			pb = pb == nullptr ? headA : pb->next;
		}
		return pa;
	}
};

// 头插法
void head_insert(linklist l, int x) {
	if (l == nullptr) return;
	linklist tmp = new ListNode(x);
	tmp->next = l->next;
	l->next = tmp;
}

void printList(linklist l) {
	if (l == nullptr) return;
	while (l->next) {
		cout << l->next->val << ' ';
		l = l->next;
	}
	cout << endl;
}

void test() {
	// 公共链
	ListNode l1(3);
	for (int i = 0; i < 5; i++) head_insert(&l1, i * 10);
	printList(&l1);

	// 单链表A
	ListNode la(5); for (int i = 0; i < 3; i++) head_insert(&la, i * 2);
	la.next->next->next->next = &l1;
	printList(&la);

	// 单链表B
	ListNode lb(8); for (int i = 0; i < 5; i++) head_insert(&lb, i * 3);
	lb.next->next->next->next->next->next = &l1;
	printList(&lb);

	// 测试解决方案
	Solution s;
	ListNode* s1 = s.getIntersectionNode(&la, &lb);
	printList(s1);
}

int main()
{
	test();
}